# Waveshare ESP32-P4-WIFI6-Touch-LCD-4B development status

This document tracks the public development status of the Waveshare ESP32-P4-WIFI6-Touch-LCD-4B port.

## Repository model

- `master` stays aligned with `espressif/esp-brookesia` and is not used for product changes.
- `waveshare-p4-4b` is the long-lived product branch for this board.
- Feature work is developed in short-lived `feature/*` branches and merged through pull requests.
- Upstream changes are synchronized into `master`, then merged into `waveshare-p4-4b` through CI-checked pull requests.

## Hardware target

- Board: Waveshare ESP32-P4-WIFI6-Touch-LCD-4B
- SKU: 31416
- ESP32-P4 silicon: revision v1.3
- Flash: 32 MB
- PSRAM: 32 MB
- Display: 4-inch 720x720 ST7703 MIPI DSI
- Touch: GT911
- Wireless: ESP32-C6 via ESP-Hosted
- Storage: microSD
- Audio: ES8311 output + ES7210 input

## Current status

- [x] Fork created from upstream ESP-Brookesia.
- [x] Product branch created: `waveshare-p4-4b`.
- [x] Default branch switched to `waveshare-p4-4b`.
- [x] Upstream synchronization workflow added.
- [x] Command-bot workflow scaffold added.
- [x] ESP-IDF 6.1 validated locally against the previous Waveshare Brookesia firmware.
- [ ] Add Brookesia HAL board profile for Waveshare P4-4B.
- [ ] Integrate the published `waveshare/esp32_p4_wifi6_touch_lcd_4b` BSP where appropriate.
- [ ] Bring up 720x720 display and GT911 touch in System Super.
- [ ] Bring up ESP32-C6 Wi-Fi / ESP-Hosted.
- [ ] Expose microSD as external storage for Files and App Store.
- [ ] Validate audio playback and microphone capture.
- [ ] Enable official Brookesia App Store and local `.bpk` installation.
- [ ] Add ESP-IDF 6.1 CI build for this board.
- [ ] Produce downloadable firmware artifacts.
- [ ] Add OTA update path after the base system is stable.

## Upstream hardware source

The board integration should prefer the published Waveshare BSP from the Espressif Component Registry instead of copying low-level board code into this fork. Board-specific Brookesia HAL glue remains in this repository.

## Development policy

Changes should remain small and reviewable. Hardware bring-up should be landed in stages (display/touch, Wi-Fi, storage, audio, App Store, OTA) so upstream merges remain manageable.
