#!/bin/bash

set -e

cmake -S .. -B ../release_build -DCMAKE_BUILD_TYPE=Release

cmake --build ../release_build --config Release

mkdir -p ../game_pkg/assets

cp -r ../assets/* ../game_pkg/assets/

cp ../release_build/*.out ../game_pkg/ 2>/dev/null || true

read -p "Build complete. Press enter to exit."