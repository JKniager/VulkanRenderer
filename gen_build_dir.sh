#!/bin/bash

top_dir=$PWD

# I want to start with a clean build directory, so if one exists, I delete it
# to start from new.
if [ -d $top_dir/build ]; then
    rm -rf $top_dir/build
fi

mkdir build
cd build

# Now we run CMake to generate the MakeFile.
# We also want it to export its compile commands to a file so linters can
# properly check the source code we write in this project.
cmake -D VULKAN_HEADERS_INSTALL_DIR=/home/kniager/Documents/VulkanFun/Vulkan-Headers/build/install -D VULKAN_LOADER_INSTALL_DIR=/home/kniager/Documents/VulkanFun/Vulkan-Loader/build/install ..
