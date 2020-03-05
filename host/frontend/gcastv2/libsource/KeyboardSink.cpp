/*
 * Copyright (C) 2020 The Android Open Source Project
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

#include <source/KeyboardSink.h>

#include <linux/input.h>

#include <android-base/logging.h>

namespace android {

KeyboardSink::KeyboardSink(std::shared_ptr<RunLoop> runLoop, int serverFd,
                           bool write_virtio_input)
    : sink_(
          std::make_shared<InputSink>(runLoop, serverFd, write_virtio_input)) {}

void KeyboardSink::injectEvent(bool down, uint16_t code) {
    LOG(VERBOSE)
        << "Received keyboard (down="
        << down
        << ", code="
        << code;
    auto buffer = sink_->getEventBuffer();
    buffer->addEvent(EV_KEY, code, down);
    buffer->addEvent(EV_SYN, 0, 0);
    sink_->SendEvents(std::move(buffer));
}

}  // namespace android

