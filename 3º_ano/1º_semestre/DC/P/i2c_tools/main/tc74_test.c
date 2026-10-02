#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/i2c_master.h"

static const char *TAG = "TC74";

/* ---- I2C configuration ---- */
#define I2C_MASTER_SCL_IO           GPIO_NUM_7
#define I2C_MASTER_SDA_IO           GPIO_NUM_6 
#define I2C_MASTER_NUM              I2C_NUM_0
#define I2C_MASTER_FREQ_HZ          100000
#define I2C_MASTER_TX_BUF_DISABLE   0
#define I2C_MASTER_RX_BUF_DISABLE   0
#define I2C_MASTER_TIMEOUT_MS       1000

/* ---- TC74 specifics ---- */
#define TC74_ADDR                   0x49
#define TC74_REG_TEMP               0x00
#define TC74_REG_CONFIG             0x01


/* ---- I2C helper functions ---- */
static esp_err_t tc74_register_read(i2c_master_dev_handle_t dev_handle, uint8_t reg_addr, uint8_t *data, size_t len)
{
    return i2c_master_transmit_receive(dev_handle, &reg_addr, 1, data, len,
                                       I2C_MASTER_TIMEOUT_MS);
}

static esp_err_t tc74_register_write_byte(i2c_master_dev_handle_t dev_handle, uint8_t reg_addr, uint8_t data)
{
    uint8_t buf[2] = {reg_addr, data};
    return i2c_master_transmit(dev_handle, buf, sizeof(buf),
                               I2C_MASTER_TIMEOUT_MS);
}

/* ---- I2C bus/device initialization ---- */
static void i2c_master_init(i2c_master_bus_handle_t *bus_handle, i2c_master_dev_handle_t *dev_handle)
{
    i2c_master_bus_config_t bus_config = {
        .i2c_port = I2C_MASTER_NUM,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_config, bus_handle));

    i2c_device_config_t dev_config = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = TC74_ADDR,
        .scl_speed_hz = I2C_MASTER_FREQ_HZ,
    };
    ESP_ERROR_CHECK(i2c_master_bus_add_device(*bus_handle, &dev_config, dev_handle));
}

/* ---- Main application ---- */
void app_main(void)
{
    uint8_t temp_reg;
    uint8_t config_reg;
    i2c_master_bus_handle_t bus_handle;
    i2c_master_dev_handle_t dev_handle;

    i2c_master_init(&bus_handle, &dev_handle);
    ESP_LOGI(TAG, "I2C initialized successfully");

    // Read configuration register
    ESP_ERROR_CHECK(tc74_register_read(dev_handle, TC74_REG_CONFIG, &config_reg, 1));
    ESP_LOGI(TAG, "Initial config = 0x%02X", config_reg);

    // Ensure sensor is in normal mode (bit7 = 0)
    if (config_reg & 0x80) {
        ESP_LOGW(TAG, "Sensor in standby, switching to normal mode...");
        config_reg &= 0x7F;
        ESP_ERROR_CHECK(tc74_register_write_byte(dev_handle, TC74_REG_CONFIG, config_reg));
        vTaskDelay(pdMS_TO_TICKS(200));
    }

    while (1) {
        ESP_ERROR_CHECK(tc74_register_read(dev_handle, TC74_REG_TEMP, &temp_reg, 1));

        int8_t temp_signed = (int8_t)temp_reg;  // Temperatura in C
        ESP_LOGI(TAG, "Temperatura: %d C", temp_signed);

        vTaskDelay(pdMS_TO_TICKS(2000));
    }

    // Normally we never reach this, but here for completeness:
    ESP_ERROR_CHECK(i2c_master_bus_rm_device(dev_handle));
    ESP_ERROR_CHECK(i2c_del_master_bus(bus_handle));
    ESP_LOGI(TAG, "I2C de-initialized successfully");
}