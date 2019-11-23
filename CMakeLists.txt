# Author: Jeremy Kniager

# This version was picked because it is the same minimum version for
# KhronosGroup/Vulkan-Tools on GitHub.
cmake_minimum_required(VERSION 3.4)

# Some rudimentary checking to make sure we have a link to a Vulkan SDK.
if (NOT SUPPORT_REPOS_DIR)
    message(FATAL_ERROR "SUPPORT_REPOS_DIR is not set.")
endif()

message(STATUS "Using directory ${SUPPORT_REPOS_DIR} for support repos.")

# We set the flags here.
# I'm using all of the warning flags because I want my code to be
# NEAT UND TIDY!
if(WIN32)
    set(CMAKE_CXX_FLAGS "-std=c++11")
else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++11")
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/Source
    ${SUPPORT_REPOS_DIR}/Vulkan-Headers/build/install/include
    ${SUPPORT_REPOS_DIR}/glm
    ${SUPPORT_REPOS_DIR}/glfw/build/install/include
    )

if(WIN32)
    link_libraries(
        ${SUPPORT_REPOS_DIR}/Vulkan-Loader/build/install/lib/vulkan-1.lib
        ${SUPPORT_REPOS_DIR}/glfw/build/install/lib/glfw3.lib
        )
else()
    link_libraries(
        ${SUPPORT_REPOS_DIR}/Vulkan-Loader/build/install/lib/libvulkan.so
        ${SUPPORT_REPOS_DIR}/glfw/build/install/lib/libglfw3.a
        )
endif()

add_executable(
    VulkanRenderer
    ${PROJECT_SOURCE_DIR}/Source/Main.cpp
    ${PROJECT_SOURCE_DIR}/Source/VulkanRenderer.cpp
    ${PROJECT_SOURCE_DIR}/Source/VulkanInstance.cpp
    ${PROJECT_SOURCE_DIR}/Source/VulkanRenderErrorHandling.cpp
)
