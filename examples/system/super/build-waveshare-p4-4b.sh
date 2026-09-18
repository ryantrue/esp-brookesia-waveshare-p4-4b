#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$PROJECT_DIR"

: "${IDF_PATH:?ESP-IDF environment is not active; source export.sh first}"

python -m pip install --disable-pip-version-check --upgrade -r requirements.waveshare-p4-4b.txt

rm -rf build sdkconfig managed_components dependencies.lock components/gen_bmgr_codes build.log
idf.py gen-bmgr-config -b esp32_p4_wifi6_touch_lcd_4b

# esp_board_manager 0.5.15 intentionally loads generated board defaults
# before project sdkconfig.defaults. Environment SDKCONFIG_DEFAULTS entries are
# appended afterwards, so re-apply this board's own defaults as the final
# board-local overlay without modifying upstream System Super defaults.
BOARD_DEFAULTS="$PROJECT_DIR/../../../hal/brookesia_hal_boards/boards/waveshare/esp32_p4_wifi6_touch_lcd_4b/sdkconfig.defaults.board"

SDKCONFIG_DEFAULTS="$BOARD_DEFAULTS" idf.py -B build \
  -D BROOKESIA_CXX_JOBS="${BROOKESIA_CXX_JOBS:-3}" \
  build
