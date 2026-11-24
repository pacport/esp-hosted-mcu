/*
* SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
*
* SPDX-License-Identifier: Apache-2.0
*/

#include "os_header.h"
#include "os_wrapper.h"
#include "esp_log.h"
#include "esp_hosted.h"
#include "esp_private/startup_internal.h"

DEFINE_LOG_TAG(host_init);

/*
 * The P4 application owns the C5 reset and recovery-flash sequence.  Do not
 * initialize ESP-Hosted from a C++ global constructor: rpc_core_init() creates
 * FreeRTOS tasks, while constructors run before the scheduler, and the C5 may
 * still be held in reset.  The application calls esp_hosted_init() explicitly
 * after c5_full_flash()/c5_release_normal_boot_public().
 */
