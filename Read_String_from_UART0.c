// Read a string send via UART0 and print it in the serial monitor

#include "driver/uart.h"
#include "esp_log.h"
#include <string.h>

#define UART_PORT UART_NUM_0
#define BUF_SIZE 128

static const char *TAG = "UART_RX";

void app_main(void)
{
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    uart_param_config(UART_PORT, &uart_config);
    uart_driver_install(UART_PORT, BUF_SIZE * 2, 0, 0, NULL, 0);
    uint8_t data[BUF_SIZE];

    while (1) {
        int len = uart_read_bytes(
            UART_PORT,
            data,
            BUF_SIZE - 1,
            pdMS_TO_TICKS(1000)
        );

        if (len > 0) {
            data[len] = '\0';  
            ESP_LOGI(TAG, "Received: %s", (char *)data);
        }
    }
}

