#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H

class VehicleInterface; // Forward declaration

class ControlSystem {
public:
    ControlSystem(VehicleInterface* vehicle);
    void execute(double throttle, double brake, double steering);

private:
    VehicleInterface* vehicle_;
};

#endif // CONTROL_SYSTEM_H
