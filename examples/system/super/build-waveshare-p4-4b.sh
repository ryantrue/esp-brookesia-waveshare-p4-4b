#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$PROJECT_DIR"

: "${IDF_PATH:?ESP-IDF environment is not active; source export.sh first}"

python -m pip install --disable-pip-version-check --upgrade -r requirements.waveshare-p4-4b.txt

rm -rf build sdkconfig managed_components dependencies.lock components/gen_bmgr_codes build.log
idf.py gen-bmgr-config -b esp32_p4_wifi6_touch_lcd_4b

# esp_board_manager 0.5.15 has project/board defaults precedence reversed.
# Keep upstream project defaults untouched and explicitly place the generated
# board defaults last so Waveshare-specific values win.
SDKCONFIG_DEFAULTS_ORDER="$PROJECT_DIR/sdkconfig.defaults;$PROJECT_DIR/components/gen_bmgr_codes/board_manager.defaults"

idf.py -B build \
  -D BROOKESIA_CXX_JOBS="${BROOKESIA_CXX_JOBS:-3}" \
  -D "SDKCONFIG_DEFAULTS=$SDKCONFIG_DEFAULTS_ORDER" \
  build
