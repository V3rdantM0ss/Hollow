cmake_minimum_required(VERSION 4.1)
project(Hollow)

set(CMAKE_CXX_STANDARD 17)

add_library(Hollow STATIC
        source/Hollow.cpp
        source/Version.cpp
        source/Color.cpp
        source/aurora/Aurora.cpp)
target_include_directories(Hollow PUBLIC include include/aurora)


add_executable(HollowTest tests/test.cpp)
target_link_libraries(HollowTest Hollow)