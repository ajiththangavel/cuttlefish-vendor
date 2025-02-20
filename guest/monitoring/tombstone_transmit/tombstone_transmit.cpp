/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <errno.h>
#include <log/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <fstream>
#include <regex>

#include <cutils/properties.h>
#include <gflags/gflags.h>

#include "common/libs/fs/shared_fd.h"
#include "common/libs/utils/inotify.h"
#include "common/libs/utils/subprocess.h"

static const char TOMBSTONE_DIR[] = "/data/tombstones/";

// returns a fd which when read from, provides inotify events when tombstone
// creations are completed.
static int new_tombstone_creation_complete_notifier(void) {
  int file_close_notification_handle = inotify_init1(IN_CLOEXEC);
  if (file_close_notification_handle == -1) {
    ALOGE("%s: inotify_init failure error: '%s' (%d)", __FUNCTION__,
      strerror(errno), errno);
    return -1;
  }

  int watch_descriptor = inotify_add_watch(file_close_notification_handle,
                                           TOMBSTONE_DIR, IN_CREATE);
  if (watch_descriptor == -1) {
    ALOGE("%s: Could not add watch for '%s', error: '%s' (%d)", __FUNCTION__,
      TOMBSTONE_DIR, strerror(errno), errno);
    close(file_close_notification_handle);
    return -1;
  }

  return file_close_notification_handle;
}

DEFINE_uint32(port,
              static_cast<uint32_t>(
                  property_get_int64("ro.boot.vsock_tombstone_port", 0)),
              "VSOCK port to send tombstones to");
DEFINE_uint32(cid, 2, "VSOCK CID to send logcat output to");
DEFINE_bool(remove_tombstones_after_transmitting, false,
            "Whether to remove the tombstone from VM after transmitting it");
#define TOMBSTONE_BUFFER_SIZE (1024)

static void tombstone_send_to_host(const std::string& ts_path) {
  auto log_fd = cuttlefish::SharedFD::VsockClient(
      FLAGS_cid, FLAGS_port, SOCK_STREAM, false /* it's guest */);
  std::ifstream ifs(ts_path);
  char buffer[TOMBSTONE_BUFFER_SIZE];
  size_t num_transfers = 0;
  size_t num_bytes_read = 0;
  while (log_fd->IsOpen() && ifs.is_open() && !ifs.eof()) {
    ifs.read(buffer, sizeof(buffer));
    num_bytes_read += ifs.gcount();
    log_fd->Write(buffer, ifs.gcount());
    num_transfers++;
  }

  if (!log_fd->IsOpen()) {
    auto error = log_fd->StrError();
    ALOGE("Unable to connect to vsock:%u:%u: %s", FLAGS_cid, FLAGS_port,
          error.c_str());
  } else if (!ifs.is_open()) {
    ALOGE("%s closed in the middle of readout.", ts_path.c_str());
  } else {
    LOG(INFO) << num_bytes_read << " bytes transferred from "
              << ts_path.c_str() << " over " << num_transfers << " "
              << TOMBSTONE_BUFFER_SIZE << " byte sized transfers";
  }

  if (FLAGS_remove_tombstones_after_transmitting) {
    remove(ts_path.c_str());
  }
}

int main(int argc, char** argv) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  if(FLAGS_port == 0) {
    LOG(FATAL_WITHOUT_ABORT) << "Port flag is required";
    while(1) {sleep(1);};
  }

  int tombstone_create_notification_handle =
      new_tombstone_creation_complete_notifier();
  if (tombstone_create_notification_handle == -1) {
    return -1;
  }

  LOG(INFO) << "tombstone watcher successfully initialized";

#ifdef MICRODROID
  property_set("tombstone_transmit.init_done", "true");
#endif

  std::regex re(R"(tombstone_\d+(\.pb)?)");
  while (true) {
    std::vector<std::string> ts_names = cuttlefish::GetFileListFromInotifyFd(
        tombstone_create_notification_handle, IN_CREATE);
    for (auto& ts_name : ts_names) {
      if (regex_match(ts_name, re)) {
        tombstone_send_to_host(std::string(TOMBSTONE_DIR) + ts_name);
      }
    }
  }

  return 0;
}
