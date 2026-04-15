cmake_minimum_required(VERSION 3.10)
project(c_staff_management VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.c)
add_executable(c_staff_management ${SOURCES})
