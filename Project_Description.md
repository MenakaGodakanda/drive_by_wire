# Drive-By-Wire Library - Version 1

A drive-by-wire system replaces traditional mechanical and hydraulic control systems with electronic controls. This project simulates the core functionality of such a system, including acceleration, braking, and steering, using object-oriented design principles in C++.

## Drive-by-wire
Drive-by-wire refers to a system that replaces traditional mechanical and hydraulic control systems in a vehicle with electronic control systems. These systems use electronic signals to control various functions such as steering, braking, and throttle. The key components and functions of a drive-by-wire system include:

## Features of the project:
1. Vehicle Interface Abstraction
  - Interface Definition: The project defines a `VehicleInterface` class that provides pure virtual functions for essential vehicle controls: `accelerate`, `brake`, and `steer`.
  - Polymorphism: By using virtual functions, the project allows for polymorphic behavior, enabling different implementations of vehicle controls.

2. Drive-By-Wire Vehicle Implementation
  - Concrete Class: The `DriveByWireVehicle` class implements the `VehicleInterface`, providing specific implementations for the `accelerate`, `brake`, and `steer` methods.
  - Logging: Each method in `DriveByWireVehicle` outputs a message indicating the action taken, providing a way to track the control commands issued to the vehicle.

3. Control System
  - Control System Class: The `ControlSystem` class is designed to manage the vehicle controls. It takes a pointer to a `VehicleInterface` object, allowing it to issue control commands (throttle, brake, steering) to any vehicle that implements the interface.
  - Execute Method: The `execute` method in `ControlSystem` takes throttle, brake, and steering parameters and calls the corresponding methods on the `VehicleInterface` object.

4. Modular and Extensible Design
  - Header and Source Separation: The project separates interface definitions and class implementations into header and source files, promoting modularity and maintainability.
  - Easy to Extend: New vehicle control implementations can be added by creating new classes that inherit from `VehicleInterface`.

5. Testing Framework
  - Unit Tests: The project includes unit tests for both the `DriveByWireVehicle` and `ControlSystem` classes using the Google Test framework.
  - CTest Integration: The project uses CTest to manage and run tests, providing a straightforward way to verify the functionality of the components.

6. Build System
  - CMake Build System: The project uses CMake as its build system, which is widely used and supports cross-platform development.
  - Dependency Management: CMake handles dependencies and ensures that all necessary components are correctly linked.

## Model-based Diagram:

Below is a sequence diagram illustrating the flow of messages between the Modbus client and server, describing how they interact during communication:

```
Main            ControlSystem           DriveByWireVehicle
 |                    |                           |
 |----create()------->|                           |
 |                    |----create(vehicle)------->|
 |                    |                           |
 |                    |                           |
 |----execute-------->|                           |
 | (0.5, 0.1, 15.0)   |                           |
 |                    |----accelerate(0.5)------->|
 |                    |                           |----output: "Accelerating by 0.5"
 |                    |                           |
 |                    |----brake(0.1)------------>|
 |                    |                           |----output: "Braking by 0.1"
 |                    |                           |
 |                    |----steer(15.0)----------->|
 |                    |                           |----output: "Steering by 15 degrees"
 |                    |                           |
 |----execute-------->|                           |
 | (0.2, 0.3, -10.0)  |                           |
 |                    |----accelerate(0.2)------->|
 |                    |                           |----output: "Accelerating by 0.2"
 |                    |                           |
 |                    |----brake(0.3)------------>|
 |                    |                           |----output: "Braking by 0.3"
 |                    |                           |
 |                    |----steer(-10.0)---------->|
 |                    |                           |----output: "Steering by -10 degrees"
 |                    |                           |
```

In this diagram:

1. Main Function:

  - Creates an instance of `DriveByWireVehicle`.
  - Creates an instance of `ControlSystem` and passes the `DriveByWireVehicle` instance to it.
  - Calls the `execute` method of `ControlSystem` with control parameters.

2. ControlSystem:

  - Receives the `execute` method call from the `main` function.
  - Calls `accelerate` on the `DriveByWireVehicle` instance.
  - Calls `brake` on the `DriveByWireVehicle` instance.
  - Calls `steer` on the `DriveByWireVehicle` instance.

3. DriveByWireVehicle:

  - Executes the `accelerate`, `brake`, and `steer` methods, outputting the corresponding actions.

## Project Structure:
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

## Coding Details:

### Main Program (main.cpp)

The main program creates instances of `DriveByWireVehicle` and `ControlSystem` and executes control commands.

- Instance Creation: An instance of `DriveByWireVehicle` named `vehicle` is created.
- Control System: An instance of `ControlSystem` named `control` is created, passing a pointer to `vehicle`.
- Executing Commands: The control object executes a series of commands, causing the vehicle to accelerate, brake, and steer. These commands are logged to the console as described in the `DriveByWireVehicle` class.

### Header File (vehicle_interface.h)

The VehicleInterface is an abstract base class that defines the interface for vehicle controls.

- Purpose: This interface provides a contract that any vehicle class must follow. It defines three pure virtual functions (`accelerate`, `brake`, and `steer`) that must be implemented by any derived class.
- Pure Virtual Functions: The `= 0` syntax indicates that these functions are pure virtual, making `VehicleInterface` an abstract class. This means you cannot create an instance of `VehicleInterface` directly; it must be subclassed.

### Header File (vehicle_interface.h)

The `DriveByWireVehicle` class implements the `VehicleInterface`, providing specific implementations for the vehicle controls.

- Inheritance: `DriveByWireVehicle` inherits from `VehicleInterface` and implements the pure virtual functions.
- Implementations: Each method logs a message to the console, indicating the action taken. For example, `accelerate(double amount)` outputs `Accelerating by <amount>`.

### Header File (control_system.h)

The `ControlSystem` class manages the vehicle by calling the appropriate control functions on the `VehicleInterface`.


### Control System Implementation (control_system.cpp)

- Constructor: The `ControlSystem` constructor takes a pointer to a `VehicleInterface` object and stores it in a private member variable `vehicle_`.
- Execute Method: The `execute` method calls `accelerate`, `brake`, and `steer` on the `VehicleInterface` object with the provided parameters. This method is responsible for issuing control commands to the vehicle.

### Unit Test (test_vehicle_interface.cpp and test_control_system.cpp)

The project includes unit tests for both `DriveByWireVehicle` and `ControlSystem` using Google Test.

- Test Cases: Each test case creates instances of the relevant classes and calls their methods. Google Test provides the `TEST` macro to define test cases and the `ASSERT_* and EXPECT_*` macros for assertions (though no specific assertions are included here).
- Main Function: The `main` function initializes Google Test and runs all the test cases.

### Root CMake Configuration (CMakeLists.txt)

The project uses CMake to define the build process.

- Core Library: The `drive_by_wire_lib` library is defined to include the core source files (`vehicle_interface.cpp` and `control_system.cpp`).
- Main Executable: The `drive_by_wire` executable is defined and linked with the core library.
- Testing: The `enable_testing` command is used to enable CTest. The tests directory is added as a subdirectory.

### Test CMake Configuration (CMakeLists.txt)

- Test Executables: The `tests/CMakeLists.txt` file defines the test executables and links them with Google Test and the core library. It also registers the tests with CTest using the `add_test` command.

### Summary

- This drive-by-wire system project demonstrates a robust and modular software design for vehicle control systems using C++. 
- It showcases essential software engineering principles such as abstraction, inheritance, and polymorphism. 
- The inclusion of unit tests ensures the reliability and correctness of the code, making it an excellent example for a GitHub portfolio.
