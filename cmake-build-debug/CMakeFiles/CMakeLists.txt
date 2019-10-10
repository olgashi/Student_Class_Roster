cmake_minimum_required(VERSION 3.13)
project(Class_Roster)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

set(SOURCE_FILES ../../roster.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(Class_Roster ${SOURCE_FILES})