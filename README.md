# Drive-By-Wire System

This project implements a software simulation for a drive-by-wire vehicle system using C++. The project includes a vehicle interface, control system, and tests to ensure functionality.<br>
<a href="https://github.com/MenakaGodakanda/drive_by_wire/blob/main/Project_Description.md">Project Description</a>

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
![Screenshot 2024-06-05 061356](https://github.com/MenakaGodakanda/drive_by_wire/assets/156875412/bfd19bbb-267b-4e91-8181-c64bad829572)

3. Build the project:
   ```
   make
   ```
![Screenshot 2024-06-05 061407](https://github.com/MenakaGodakanda/drive_by_wire/assets/156875412/6c07b4c2-728d-4c83-b62e-12d423afe263)

## Usage

After building the project, you can run the main executable:
```
./drive_by_wire
```

### Output of Main Executable
When you run the main executable (drive_by_wire), the program creates an instance of a DriveByWireVehicle and a ControlSystem. The ControlSystem then sends commands to the DriveByWireVehicle to simulate various driving actions like accelerating, braking, and steering. This output represents the simulated responses of the vehicle to the control commands issued by the ControlSystem.

![Screenshot 2024-06-05 061419](https://github.com/MenakaGodakanda/drive_by_wire/assets/156875412/8f2f105d-0aa7-4283-b920-6fa7eea7313d)

Explaining the output:

- `Accelerating by 0.5`: This line indicates that the vehicle is accelerating. The value `0.5` represents the amount by which the vehicle is accelerating.

- `Braking by 0.1`: This line indicates that the vehicle is braking. The value `0.1` represents the amount by which the vehicle is braking.

- `Steering by 15 degrees`: This line indicates that the vehicle is steering. The value `15` represents the angle in degrees by which the vehicle is steering.

- `Accelerating by 0.2`: This line indicates another acceleration event, but this time with a different acceleration amount (`0.2`).

- `Braking by 0.3`: This line indicates another braking event, but this time with a different braking amount (`0.3`).

- `Steering by -10 degrees`: This line indicates another steering event, but this time with a negative angle (`-10` degrees). A negative angle could represent steering in the opposite direction.

- Overall, this output demonstrates the sequence of actions taken by the drive-by-wire system, including acceleration, braking, and steering, along with the corresponding values for each action.


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

![Screenshot 2024-06-05 061429](https://github.com/MenakaGodakanda/drive_by_wire/assets/156875412/34015fb8-fb16-4310-8ed8-6111a4fbc086)

Explaining the output:

- `Start 1: TestVehicleInterface`: This line marks the beginning of the first test named `TestVehicleInterface`.

- `1/2 Test #1: TestVehicleInterface ............. Passed 0.00 sec`: This line indicates the result of the first test. It shows that the test labeled as `TestVehicleInterface` has passed (`Passed`) and took `0.00` seconds to execute.

- `Start 2: TestControlSystem`: This line marks the beginning of the second test named `TestControlSystem`.

- `2/2 Test #2: TestControlSystem ................ Passed 0.00 sec`: This line indicates the result of the second test. It shows that the test labeled as `TestControlSystem` has passed (`Passed`) and took `0.00` seconds to execute.

- `100% tests passed, 0 tests failed out of 2`: This line summarizes the test results. It indicates that all tests (`100%`) passed and there were `0` failed tests out of a total of `2` tests.

- `Total Test time (real) = 0.00 sec`: This line provides the total time taken to execute all tests. In this case, it took `0.00` seconds.

- In summary, the output confirms that both tests (`TestVehicleInterface` and `TestControlSystem`) have passed successfully, with no failures.

## Troubleshooting (Optional)

### Google Test installation
In some cases, the `sudo cp *.a /usr/lib` command cannot be executed. This command copies the compiled library files to the `/usr/lib` directory, making them available for linker access during application build processes. The error `cp: cannot stat '*.a': No such file or directory` indicates that the .a files (static library files) were not created during the `make` process. Here are some steps to troubleshoot and resolve this issue:

1. Ensure Installation of Required Packages:
Make sure that you have all necessary build tools installed.
```
sudo apt update
sudo apt install build-essential cmake
```

2. Clean the Build Directory:
It's possible that there might be some remnants from a previous build that are causing issues. Clean the build directory and try again.
```
sudo rm -rf CMakeFiles/ CMakeCache.txt
sudo cmake .
sudo make
```

3. Check the Output of the Make Command:
Review the output from the `make` command to see if there were any errors or warnings that could indicate why the `.a` files were not created.

4. Manually Locate the Static Libraries:
The static libraries might have been created in a different directory or with different naming conventions. You can try searching for `.a` files.
```
sudo find /usr/src/gtest -name '*.a'
```
If the `.a` files are found in a different directory, copy them from there. If they were created with different naming conventions, adjust the `cp` command accordingly.

5. Build and Install Google Test Separately:
As an alternative, you can manually download, build, and install Google Test from its GitHub repository.
```
cd /tmp
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
sudo cp lib/*.a /usr/lib
```
This approach builds Google Test in a separate directory and then copies the resulting `.a` files to `/usr/lib`.


### Rebuild the project
1. Clean the build directory (optional but recommended):
```
rm -rf build
mkdir build
cd build
```

2. Run CMake and Make:
```
cmake ..
make
```

3. Run the tests using CTest:
```
ctest
```

## License
This project is licensed under the MIT License.
