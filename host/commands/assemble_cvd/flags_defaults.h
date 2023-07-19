/*
 * Copyright (C) 2022 The Android Open Source Project
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
#pragma once

#include "host/libs/config/cuttlefish_config.h"

#define CF_DEFAULTS_DYNAMIC_STRING ""
#define CF_DEFAULTS_DYNAMIC_INT 0

// Common configs paramneters
#define CF_DEFAULTS_NUM_INSTANCES 1
#define CF_DEFAULTS_INSTANCE_NUMS CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_BASE_INSTANCE_NUM cuttlefish::GetInstance()
#define CF_DEFAULTS_ASSEMBLY_DIR \
  (StringFromEnv("HOME", ".") + "/cuttlefish_assembly")
#define CF_DEFAULTS_INSTANCE_DIR (StringFromEnv("HOME", ".") + "/cuttlefish")

#define CF_DEFAULTS_SYSTEM_IMAGE_DIR CF_DEFAULTS_DYNAMIC_STRING

// Instance specific parameters
//  VM default parameters
#define CF_DEFAULTS_DISPLAY_DPI 320
#define CF_DEFAULTS_DISPLAY_REFRESH_RATE 60
#define CF_DEFAULTS_DISPLAY_WIDTH 720
#define CF_DEFAULTS_DISPLAY_HEIGHT 1280
#define CF_DEFAULTS_DISPLAYS_TEXTPROTO ""
#define CF_DEFAULTS_CPUS 2
#define CF_DEFAULTS_RESUME true
#define CF_DEFAULTS_DAEMON false
#define CF_DEFAULTS_VM_MANAGER CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VSOCK_GUEST_CID cuttlefish::GetDefaultVsockCid()
#define CF_DEFAULTS_ENABLE_MINIMAL_MODE false
#define CF_DEFAULTS_RESTART_SUBPROCESSES false
#define CF_DEFAULTS_SETUPWIZARD_MODE "DISABLED"
#define CF_DEFAULTS_SMT false
#define CF_DEFAULTS_USE_ALLOCD false
#define CF_DEFAULTS_USE_SDCARD true
#define CF_DEFAULTS_UUID \
  cuttlefish::ForCurrentInstance(cuttlefish::kDefaultUuidPrefix)
#define CF_DEFAULTS_FILE_VERBOSITY "DEBUG"
#define CF_DEFAULTS_VERBOSITY "INFO"
#define CF_DEFAULTS_RUN_FILE_DISCOVERY true
#define CF_DEFAULTS_MEMORY_MB CF_DEFAULTS_DYNAMIC_INT
#define CF_DEFAULTS_SHARE_SCHED_CORE false
#define CF_DEFAULTS_TRACK_HOST_TOOLS_CRC false
// TODO: defined twice, please remove redundant definitions
#define CF_DEFAULTS_USE_OVERLAY true
#define CF_DEFAULTS_DEVICE_EXTERNAL_NETWORK "tap"

// crosvm default parameters
#define CF_DEFAULTS_CROSVM_BINARY HostBinaryPath("crosvm")
#define CF_DEFAULTS_SECCOMP_POLICY_DIR cuttlefish::GetSeccompPolicyDir()
#define CF_DEFAULTS_ENABLE_SANDBOX false

// Qemu default parameters
#define CF_DEFAULTS_QEMU_BINARY_DIR "/usr/bin"

// Gem5 default parameters
#define CF_DEFAULTS_GEM5_BINARY_DIR HostBinaryPath("gem5")
#define CF_DEFAULTS_GEM5_CHECKPOINT_DIR CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_GEM5_DEBUG_FILE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_GEM5_DEBUG_FLAGS CF_DEFAULTS_DYNAMIC_STRING

// Boot default parameters
#define CF_DEFAULTS_BOOT_SLOT CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_BOOTLOADER CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_ENABLE_BOOTANIMATION true
#define CF_DEFAULTS_EXTRA_BOOTCONFIG_ARGS CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_PAUSE_IN_BOOTLOADER false
#define CF_DEFAULTS_REBOOT_NOTIFICATION_FD (-1)

// Security default parameters
#define CF_DEFAULTS_GUEST_ENFORCE_SECURITY true
#define CF_DEFAULTS_USE_RANDOM_SERIAL false
#define CF_DEFAULTS_SERIAL_NUMBER \
  cuttlefish::ForCurrentInstance("CUTTLEFISHCVD")
#define CF_DEFAULTS_SECURE_HALS "keymint,gatekeeper,oemlock"
#define CF_DEFAULTS_PROTECTED_VM false
#define CF_DEFAULTS_MTE false

// Kernel default parameters
#define CF_DEFAULTS_ENABLE_KERNEL_LOG true
#define CF_DEFAULTS_KGDB false
#define CF_DEFAULTS_GDB_PORT CF_DEFAULTS_DYNAMIC_INT
#define CF_DEFAULTS_CONSOLE false
#define CF_DEFAULTS_EXTRA_KERNEL_CMDLINE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_INITRAMFS_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_KERNEL_PATH CF_DEFAULTS_DYNAMIC_STRING

// Disk default parameters
#define CF_DEFAULTS_BLANK_METADATA_IMAGE_MB "64"
#define CF_DEFAULTS_BLANK_SDCARD_IMAGE_MB "2048"
#define CF_DEFAULTS_BOOT_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_DATA_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_INIT_BOOT_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_LINUX_INITRAMFS_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_LINUX_KERNEL_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_LINUX_ROOT_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_FUCHSIA_ZEDBOOT_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_FUCHSIA_MULTIBOOT_BIN_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_FUCHSIA_ROOT_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_CUSTOM_PARTITION_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_SUPER_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VBMETA_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VBMETA_SYSTEM_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VBMETA_VENDOR_DLKM_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VBMETA_SYSTEM_DLKM_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VENDOR_BOOT_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_DEFAULT_TARGET_ZIP CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_SYSTEM_TARGET_ZIP CF_DEFAULTS_DYNAMIC_STRING

// Policy default parameters
#define CF_DEFAULTS_DATA_POLICY "use_existing"
#define CF_DEFAULTS_USERDATA_FORMAT "f2fs"
#define CF_DEFAULTS_BLANK_DATA_IMAGE_MB CF_DEFAULTS_DYNAMIC_INT

// Graphics default parameters
#define CF_DEFAULTS_HWCOMPOSER cuttlefish::kHwComposerAuto
#define CF_DEFAULTS_GPU_MODE cuttlefish::kGpuModeAuto
#define CF_DEFAULTS_RECORD_SCREEN false
#define CF_DEFAULTS_GPU_CAPTURE_BINARY CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_ENABLE_GPU_UDMABUF false
#define CF_DEFAULTS_ENABLE_GPU_VHOST_USER false
#define CF_DEFAULTS_DISPLAY0 CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_DISPLAY1 CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_DISPLAY2 CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_DISPLAY3 CF_DEFAULTS_DYNAMIC_STRING

// Camera default parameters
#define CF_DEFAULTS_CAMERA_SERVER_PORT CF_DEFAULTS_DYNAMIC_INT

// Connectivity default parameters
#define CF_DEFAULTS_RIL_DNS "8.8.8.8"
// Default network handler
#define CF_DEFAULTS_NETSIM false
#define CF_DEFAULTS_NETSIM_BT true

// Netsim default parameters
#define CF_DEFAULTS_NETSIM_ARGS ""

// Wifi default parameters
#define CF_DEFAULTS_AP_KERNEL_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_AP_ROOTFS_IMAGE CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_VHOST_NET false
#define CF_DEFAULTS_VHOST_USER_MAC80211_HWSIM CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_WMEDIUMD_CONFIG CF_DEFAULTS_DYNAMIC_STRING

// UWB default parameters
#define CF_DEFAULTS_ENABLE_HOST_UWB false
#define CF_DEFAULTS_ENABLE_PICA_INSTANCE_NUM 0

// Bluetooth default parameters
#define CF_DEFAULTS_ENABLE_HOST_BLUETOOTH true
#define CF_DEFAULTS_ROOTCANAL_INSTANCE_NUM 0
#define CF_DEFAULTS_ROOTCANAL_ARGS CF_DEFAULTS_DYNAMIC_STRING

// NFC default parameters
#define CF_DEFAULTS_ENABLE_HOST_NFC true
#define CF_DEFAULTS_CASIMIR_INSTANCE_NUM 0
#define CF_DEFAULTS_CASIMIR_ARGS CF_DEFAULTS_DYNAMIC_STRING

// Modem Simulator default parameters
#define CF_DEFAULTS_ENABLE_MODEM_SIMULATOR true
#define CF_DEFAULTS_MODEM_SIMULATOR_SIM_TYPE 1
#define CF_DEFAULTS_MODEM_SIMULATOR_COUNT 1

// Audio default parameters
#define CF_DEFAULTS_ENABLE_AUDIO true

// Streaming default parameters
#define CF_DEFAULTS_START_WEBRTC false
#define CF_DEFAULTS_START_WEBRTC_SIG_SERVER true
#define CF_DEFAULTS_WEBRTC_DEVICE_ID "cvd-{num}"
#define CF_DEFAULTS_VERIFY_SIG_SERVER_CERTIFICATE false
#define CF_DEFAULTS_WEBRTC_ASSETS_DIR \
  DefaultHostArtifactsPath("usr/share/webrtc/assets")
#define CF_DEFAULTS_WEBRTC_CERTS_DIR \
  DefaultHostArtifactsPath("usr/share/webrtc/certs")
#define CF_DEFAULTS_WEBRTC_SIG_SERVER_ADDR CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_WEBRTC_SIG_SERVER_PATH "/register_device"
#define CF_DEFAULTS_WEBRTC_SIG_SERVER_PORT 443
#define CF_DEFAULTS_WEBRTC_SIG_SERVER_SECURE true
#define CF_DEFAULTS_TCP_PORT_RANGE "15550:15599"
#define CF_DEFAULTS_UDP_PORT_RANGE "15550:15599"

// Adb default parameters
// TODO : Replaceconstants with these flags, they're currently defined throug
// GflagsCompatFlag
#define CF_DEFAULTS_RUN_ADB_CONNECTOR true
#define CF_DEFAULTS_ADB_MODE "vsock_half_tunnel"

// Vehicle default parameters
#define CF_DEFAULTS_ENABLE_VEHICLE_HAL_GRPC_SERVER true

// Location default parameters
#define CF_DEFAULTS_START_GNSS_PROXY true
#define CF_DEFAULTS_FIXED_LOCATION_FILE_PATH CF_DEFAULTS_DYNAMIC_STRING
#define CF_DEFAULTS_GNSS_FILE_PATH CF_DEFAULTS_DYNAMIC_STRING

// Metrics default parameters
// TODO: Defined twice , please remove redundant definitions
#define CF_DEFAULTS_REPORT_ANONYMOUS_USAGE_STATS CF_DEFAULTS_DYNAMIC_STRING
