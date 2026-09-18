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
- [x] Initial Brookesia Board Manager profile added for Waveshare P4-4B.
- [x] Board profile uses the maintained Waveshare ST7703 driver and the published BSP pin/timing contract.
- [x] 32 MB OTA-ready partition layout added with dual 10.5 MB application slots.
- [x] Dedicated ESP-IDF 6.1 System Super CI workflow added.
- [ ] CI-validate the new board profile and resolve schema/build compatibility issues.
- [ ] Hardware-validate 720x720 display and GT911 touch in System Super.
- [ ] Hardware-validate ESP32-C6 Wi-Fi / ESP-Hosted.
- [ ] Hardware-validate microSD as external storage for Files and App Store.
- [ ] Hardware-validate ES8311 playback and ES7210 microphone capture.
- [ ] Validate official Brookesia App Store and local `.bpk` installation.
- [ ] Produce downloadable release firmware artifacts.
- [ ] Enable and validate the OTA updater after the base system is stable.

## Current feature work

`feature/waveshare-p4-4b-hal` introduces the first complete board description for the new ESP-Brookesia System Super stack. The profile targets ESP32-P4 rev1.x silicon, 32 MB flash/PSRAM, ST7703/GT911, microSD, audio and ESP32-C6 hosted Wi-Fi. CI is the first gate; hardware flashing happens only after the configuration builds cleanly on ESP-IDF 6.1.

## Upstream hardware source

The board integration follows the maintained Waveshare BSP from the Espressif Component Registry instead of copying its low-level implementation into this fork. Board-specific Brookesia Board Manager metadata and minimal device-factory glue remain in this repository.

## Development policy

Changes should remain small and reviewable. Hardware bring-up should be landed in stages (display/touch, Wi-Fi, storage, audio, App Store, OTA) so upstream merges remain manageable.
