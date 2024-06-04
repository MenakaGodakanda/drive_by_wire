cmake_minimum_required(VERSION 3.10)
project(drive_by_wire)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Define a library for the core functionality
add_library(drive_by_wire_lib
    src/vehicle_interface.cpp
    src/control_system.cpp
)

add_executable(drive_by_wire
    src/main.cpp
)

target_link_libraries(drive_by_wire drive_by_wire_lib)

enable_testing()

add_subdirectory(tests)
