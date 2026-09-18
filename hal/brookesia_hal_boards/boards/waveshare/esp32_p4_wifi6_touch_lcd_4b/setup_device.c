/*
 * SPDX-FileCopyrightText: 2026 Espressif Systems (Shanghai) CO., LTD
 * SPDX-License-Identifier: LicenseRef-Espressif-Modified-MIT
 *
 * See LICENSE file for details.
 */

#include "esp_log.h"
#include "dev_display_lcd.h"

#if __has_include(<esp_lcd_st7703.h>)
#define HAS_ST7703 1
#include "esp_lcd_st7703.h"
#endif

#if __has_include(<esp_lcd_touch_gt911.h>)
#define HAS_GT911 1
#include "esp_lcd_touch_gt911.h"
#endif

static const char *TAG = "WAVESHARE_P4_4B_SETUP";

#if defined(HAS_ST7703)
__attribute__((weak)) esp_err_t lcd_dsi_panel_factory_entry_t(
    esp_lcd_dsi_bus_handle_t dsi_handle,
    dev_display_lcd_config_t *lcd_cfg,
    dev_display_lcd_handles_t *lcd_handles)
{
    st7703_vendor_config_t vendor_config = {
        .mipi_config = {
            .dsi_bus = dsi_handle,
            .dpi_config = &lcd_cfg->sub_cfg.dsi.dpi_config,
        },
        .flags = {
            .use_mipi_interface = 1,
        },
    };

    const esp_lcd_panel_dev_config_t lcd_dev_config = {
        .reset_gpio_num = lcd_cfg->sub_cfg.dsi.reset_gpio_num,
        .rgb_ele_order = lcd_cfg->rgb_ele_order,
        .data_endian = lcd_cfg->data_endian,
        .bits_per_pixel = lcd_cfg->bits_per_pixel,
        .flags = {
            .reset_active_high = lcd_cfg->sub_cfg.dsi.reset_active_high,
        },
        .vendor_config = &vendor_config,
    };

    ESP_LOGI(TAG, "Install ST7703 LCD panel driver");
    esp_err_t ret = esp_lcd_new_panel_st7703(
        lcd_handles->io_handle,
        &lcd_dev_config,
        &lcd_handles->panel_handle);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to create ST7703 panel: %s", esp_err_to_name(ret));
        return ret;
    }

    return ESP_OK;
}
#endif

#if defined(HAS_GT911)
__attribute__((weak)) esp_err_t lcd_touch_factory_entry_t(
    esp_lcd_panel_io_handle_t io,
    const esp_lcd_touch_config_t *touch_dev_config,
    esp_lcd_touch_handle_t *ret_touch)
{
    esp_err_t ret = esp_lcd_touch_new_i2c_gt911(io, touch_dev_config, ret_touch);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to create GT911 touch: %s", esp_err_to_name(ret));
        return ret;
    }

    return ESP_OK;
}
#endif
