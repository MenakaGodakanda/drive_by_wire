add_executable(test_vehicle_interface test_vehicle_interface.cpp)
target_link_libraries(test_vehicle_interface gtest gtest_main pthread drive_by_wire_lib)
add_test(NAME TestVehicleInterface COMMAND test_vehicle_interface)

add_executable(test_control_system test_control_system.cpp)
target_link_libraries(test_control_system gtest gtest_main pthread drive_by_wire_lib)
add_test(NAME TestControlSystem COMMAND test_control_system)
