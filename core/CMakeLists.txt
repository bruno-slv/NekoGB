cmake_minimum_required(VERSION 3.16)

project(core)

add_library(
    emu-core
    STATIC

    emulator.cpp
    emulator.h

    cartridge/cartridge.cpp
    cartridge/cartridge.h
)

target_include_directories(
    emu-core
    PUBLIC
    cartridge
    ../common
)
