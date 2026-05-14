cmake_minimum_required(VERSION 3.16)

project(core)

add_library(
    emu-core
    STATIC
    emulator.h
    emulator.cpp
    cartridge/cartridge.h
    cartridge/cartridge.cpp
    device/device.h
    device/device.cpp
)

target_include_directories(
    emu-core
    PUBLIC
    cartridge
    device
    ../common
    ${CMAKE_CURRENT_SOURCE_DIR}
)
