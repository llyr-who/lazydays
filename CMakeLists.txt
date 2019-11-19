cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
project(lazydays)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/..) 

set(CMAKE_CXX_FLAGS "-Wall -mavx -mfma -Ofast")

add_executable(lazydays main.cpp)

