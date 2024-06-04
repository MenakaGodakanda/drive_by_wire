# Drive-By-Wire System

This project implements a software simulation for a drive-by-wire vehicle system using C++. The project includes a vehicle interface, control system, and tests to ensure functionality.

A drive-by-wire system replaces traditional mechanical and hydraulic control systems with electronic controls. This project simulates the core functionality of such a system, including acceleration, braking, and steering, using object-oriented design principles in C++.

## Features

- Vehicle Interface: Abstract class defining the basic control functions (accelerate, brake, steer).
- Drive-By-Wire Vehicle: Concrete implementation of the VehicleInterface.
- Control System: Class to handle the execution of control commands.
- Unit Tests: Google Test-based unit tests to validate the functionality of the system.
- Open Source Tools: Utilizes CMake for build configuration and Google Test for unit testing.

## Project Structure
```
drive_by_wire/
├── CMakeLists.txt
├── README.md
├── src/                            # Contains the source files for the main functionality.
│   ├── main.cpp
│   ├── vehicle_interface.cpp
│   ├── control_system.cpp
├── include/                        # Contains the header files for class definitions and declarations.
│   ├── vehicle_interface.h
│   ├── control_system.h
│   ├── drive_by_wire_vehicle.h
├── tests/                          # Contains unit tests for the system using Google Test framework.
│   ├── CMakeLists.txt
│   ├── test_vehicle_interface.cpp
│   ├── test_control_system.cpp
└── build/                          # Directory where the project will be built.
```

## Software Requirements

- Operating System: Linux (Ubuntu recommended)
- Compiler: GCC or any C++17 compatible compiler
- Build System: CMake (version 3.10 or higher)
- Testing Framework: Google Test

### Dependencies

- Google Test: For unit testing
  ```
  sudo apt-get install -y libgtest-dev
  cd /usr/src/gtest
  sudo cmake .
  sudo make
  sudo cp *.a /usr/lib
  ```
  
- CMake: For building the project
  ```
  sudo apt-get update
  sudo apt-get install -y cmake
  ```

## Installation
To set up the project on your local machine, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/MenakaGodakanda/drive_by_wire.git
   cd drive_by_wire
   ```

2. Create a build directory and run CMake:
   ```
   mkdir build
   cd build
   cmake ..
   ```

3. Build the project:
   ```
   make
   ```

## Usage

After building the project, you can run the main executable:
```
./drive_by_wire
```

### Output of Main Executable
When you run the main executable (drive_by_wire), the program creates an instance of a DriveByWireVehicle and a ControlSystem. The ControlSystem then sends commands to the DriveByWireVehicle to simulate various driving actions like accelerating, braking, and steering. This output represents the simulated responses of the vehicle to the control commands issued by the ControlSystem.

<Image>



## Running Tests

The project includes unit tests to validate the functionality of the drive-by-wire system.

1. Navigate to the build directory:
```
cd build
```

2. Run the tests using CTest:
```
ctest
```

### Output of Test
Running the unit tests with ctest produces output indicating whether the tests have passed or failed. These tests validate the behavior of the DriveByWireVehicle and the ControlSystem to ensure they function correctly. Each test executable will also print detailed information about the test cases it runs, which helps in identifying the exact point of failure if any test fails.


<Image>

## Troubleshooting


## License
This project is licensed under the MIT License.
