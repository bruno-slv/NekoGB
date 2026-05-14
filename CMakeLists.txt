cmake_minimum_required(VERSION 3.16)

project(NekoGB)

add_subdirectory(core)

add_executable(nekogb main.cpp)

target_include_directories(
    nekogb
    PRIVATE
    core
)

target_link_libraries(
    nekogb
    PRIVATE
    emu-core
)
