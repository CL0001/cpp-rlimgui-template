@echo off

cmake -S .. -B "..\release_build" -DCMAKE_BUILD_TYPE="Release"

cmake --build "..\release_build" --config Release

xcopy /E /I /Y ..\assets ..\game_pkg\assets

copy ..\release_build\Release\*.exe ..\game_pkg

PAUSE
