cmake_minimum_required(VERSION 3.29)
project(OOPUzduotis1)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(OOPUzduotis1 ${SOURCES})
