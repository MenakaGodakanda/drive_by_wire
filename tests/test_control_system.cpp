#include <gtest/gtest.h>
#include "control_system.h"
#include "drive_by_wire_vehicle.h"

TEST(ControlSystemTest, Execute) {
    DriveByWireVehicle vehicle;
    ControlSystem control(&vehicle);

    control.execute(0.5, 0.1, 15.0);
    // Assertions can be added as needed
    control.execute(0.2, 0.3, -10.0);
    // Assertions can be added as needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
