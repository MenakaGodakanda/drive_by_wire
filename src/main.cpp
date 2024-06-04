#include "control_system.h"
#include "drive_by_wire_vehicle.h"

int main() {
    DriveByWireVehicle vehicle;
    ControlSystem control(&vehicle);

    control.execute(0.5, 0.1, 15.0);
    control.execute(0.2, 0.3, -10.0);

    return 0;
}
