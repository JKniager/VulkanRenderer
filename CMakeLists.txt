# Author: Jeremy Kniager
# Last edit: 03/19/2019

# This version was picked because it is the same minimum version for
# KhronosGroup/Vulkan-Tools on GitHub.
cmake_minimum_required(VERSION 3.4)

# Some rudimentary checking to make sure we have a link to a Vulkan SDK.
if (NOT VULKAN_HEADERS_INSTALL_DIR)
    message(FATAL_ERROR "VULKAN_HEADERS_INSTALL_DIR is not set.")
endif()

message(STATUS "Vulkan Headers found at ${VULKAN_HEADERS_INSTALL_DIR}")

if (NOT VULKAN_LOADER_INSTALL_DIR)
    message(FATAL_ERROR "VULKAN_LOADER_INSTALL_DIR is not set.")
endif()

message(STATUS "Vulkan Loader found at ${VULKAN_LOADER_INSTALL_DIR}")

# We set the flags here.
# I'm using all of the warning flags because I want my code to be
# NEAT UND TIDY!
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++11")

include_directories(
    ${PROJECT_SOURCE_DIR}/Source
    ${VULKAN_HEADERS_INSTALL_DIR}/include
    /home/kniager/Documents/VulkanFun/glm/build/install/include
    /home/kniager/Documents/VulkanFun/glfw/build/install/include
    )
link_libraries(
    ${VULKAN_LOADER_INSTALL_DIR}/lib/libvulkan.so
    /home/kniager/Documents/VulkanFun/glfw/build/install/lib/libglfw3.a
    )

add_executable(
    VulkanRenderer
    ${PROJECT_SOURCE_DIR}/Source/Main.cpp
    ${PROJECT_SOURCE_DIR}/Source/VulkanRenderer.cpp
    ${PROJECT_SOURCE_DIR}/Source/VulkanInstance.cpp
    ${PROJECT_SOURCE_DIR}/Source/VulkanRenderErrorHandling.cpp
)
