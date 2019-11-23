@echo OFF
SET top_dir=%CD%

REM I want to start with a clean build directory, so if one exists, I delete it
REM to start from new.
if exist "%top_dir%/build" (
    rm -rf %top_dir%/build
)

mkdir build
cd build

REM Now we run CMake to generate the Solution file.
cmake -D SUPPORT_REPOS_DIR=%1 -G "Visual Studio 15 2017 Win64" ..