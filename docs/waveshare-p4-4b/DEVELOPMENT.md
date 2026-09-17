# Waveshare ESP32-P4 4B development workflow

This fork keeps upstream ESP-Brookesia updates easy to consume while isolating board-specific work.

## Branch model

- `master` — exact mirror of `espressif/esp-brookesia:master`. Do not commit project-specific changes here.
- `waveshare-p4-4b` — long-lived product branch for Waveshare ESP32-P4-WIFI6-Touch-LCD-4B.
- `feature/*` — short-lived development branches created from `waveshare-p4-4b` and merged back by pull request.

The repository default branch should be `waveshare-p4-4b`. This lets project automation live on the product branch while leaving `master` clean for upstream synchronization.

## Upstream update flow

1. `.github/workflows/upstream-sync.yml` fetches `espressif/esp-brookesia:master`.
2. The workflow updates this fork's `master` only when the update is a fast-forward.
3. If upstream changed, it opens a pull request from `master` into `waveshare-p4-4b`.
4. CI runs against that pull request before the upstream update is merged into the product branch.
5. Conflicts are resolved on the product branch; upstream history is never rewritten.

Never rebase or force-push `waveshare-p4-4b` as part of routine upstream synchronization.

## Target hardware

- Board: Waveshare ESP32-P4-WIFI6-Touch-LCD-4B
- Waveshare SKU: 31416
- SoC: ESP32-P4 rev1.3
- Flash: 32 MB
- PSRAM: 32 MB
- Display: 4-inch 720x720 MIPI-DSI ST7703
- Touch: GT911
- Wireless coprocessor: ESP32-C6 via ESP-Hosted
- External storage: onboard microSD via SDMMC

## Product baseline

The target system is ESP-Brookesia `System Super` with:

- the built-in App Store as the single remote application store;
- Files and Settings applications;
- microSD as external application/media storage;
- JavaScript runtime initially, with additional runtimes enabled only when justified;
- board-specific HAL integration kept as narrow as possible to simplify future upstream merges;
- CI builds for ESP-IDF 6.1 and ESP32-P4 rev1.3;
- OTA/release automation added after the board port boots reliably.

## Development rules

1. No project-specific commits on `master`.
2. New work starts from `waveshare-p4-4b`.
3. Prefer small board-specific files over invasive edits to upstream components.
4. Keep patches to upstream code minimal and documented.
5. Every upstream-sync pull request must build before merge.
6. Keep a USB-flashable recovery artifact for each known-good release.
