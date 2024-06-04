#include "vehicle_interface.h"
#include <iostream>

class DriveByWireVehicle : public VehicleInterface {
public:
    void accelerate(double amount) override {
        std::cout << "Accelerating by " << amount << std::endl;
    }

    void brake(double amount) override {
        std::cout << "Braking by " << amount << std::endl;
    }

    void steer(double angle) override {
        std::cout << "Steering by " << angle << " degrees" << std::endl;
    }
};
