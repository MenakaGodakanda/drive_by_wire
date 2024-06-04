#ifndef VEHICLE_INTERFACE_H
#define VEHICLE_INTERFACE_H

class VehicleInterface {
public:
    virtual void accelerate(double amount) = 0;
    virtual void brake(double amount) = 0;
    virtual void steer(double angle) = 0;
    virtual ~VehicleInterface() = default;
};

#endif // VEHICLE_INTERFACE_H
