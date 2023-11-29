/*
 * SPDX-FileCopyrightText: 2021-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#ifndef H_BLE_ESP_GAP_
#define H_BLE_ESP_GAP_

#ifdef __cplusplus
extern "C" {
#endif


/**
 * This API is used to clean up residue memory in controller for legacy advertisement
 *
 * @return                0 on success; nonzero on failure.
 */
int ble_gap_clear_legacy_adv(void);

#ifdef __cplusplus
}
#endif

#endif
