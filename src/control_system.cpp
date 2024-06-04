#include "control_system.h"
#include "vehicle_interface.h"

ControlSystem::ControlSystem(VehicleInterface* vehicle) : vehicle_(vehicle) {}

void ControlSystem::execute(double throttle, double brake, double steering) {
    vehicle_->accelerate(throttle);
    vehicle_->brake(brake);
    vehicle_->steer(steering);
}
