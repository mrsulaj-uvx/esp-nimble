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

enum gap_status {
    BLE_GAP_STATUS_ADV = 0,
    BLE_GAP_STATUS_EXT_ADV,
    BLE_GAP_STATUS_SCAN,
    BLE_GAP_STATUS_CONN,
    BLE_GAP_STATUS_PAIRED,
    BLE_GAP_STATUS_GATTS,
    BLE_GAP_STATUS_HOST_PRIVACY,
    BLE_GAP_STATUS_PERIODIC,
};

typedef enum gap_status gap_status_t;

/**
 * This API gives the current status of various stack operations
 *
 * @return                      0 on success; nonzero bits indicating different
 *                              operations as per enum gap_status.
 */
int ble_gap_host_check_status(void);

#if MYNEWT_VAL(BLE_HCI_VS)
/**
 * This API is used to clean up residue memory in controller for legacy advertisement
 *
 * @return                0 on success; nonzero on failure.
 */
int ble_gap_clear_legacy_adv(void);

#define BLE_DUPLICATE_SCAN_EXCEPTIONAL_INFO_ADV_ADDR             0
#define BLE_DUPLICATE_SCAN_EXCEPTIONAL_INFO_MESH_LINK_ID         1
#define BLE_DUPLICATE_SCAN_EXCEPTIONAL_INFO_MESH_BEACON_TYPE     2
#define BLE_DUPLICATE_SCAN_EXCEPTIONAL_INFO_MESH_PROV_SRV_ADV    3
#define BLE_DUPLICATE_SCAN_EXCEPTIONAL_INFO_MESH_PROXY_SRV_ADV   4

/**
 * This API  is used to send the Duplicate Exception list VSC to controller
 *
 * @param subcode	  The operation to be done (add/remove/clean)
 *
 * @param type            Exception list type
 *
 * @param value           Device address
 *
 * @cb 		          Registered callback
 *
 * @return                0 on success; nonzero on failure.
 */

int ble_gap_duplicate_exception_list(uint8_t subcode, uint8_t type, uint8_t *value, void *cb);
#endif

void ble_gap_rx_test_evt(const void *buf, uint8_t len);
void ble_gap_tx_test_evt(const void *buf, uint8_t len);
void ble_gap_end_test_evt(const void *buf, uint8_t len);

#ifdef __cplusplus
}
#endif

#endif
