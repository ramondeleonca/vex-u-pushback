#include "main.h"

// * Subsystems
// Chassis
const int maxVoltageMv = 12 * 1000;
const float chassisDriveConstants[7] = {9.0, 0.0, 0.0, 250.0, 1.0, 0.0, 0.0};
const float chassisTurnConstants[7] = {1.75, 0.0, 0.0, 300.0, 1.0, 0.0, 0.0};
lightning::TankChassis chassis(
	lightning::tank_odom_e_t::NO_ODOM,
	{-1, -2, -3, -4}, // Left motors
	{5, 7, 8, 9}, // Right motors
	10, // IMU port
	pros::E_MOTOR_GEAR_GREEN, // Motor gearset
	3.25, // Wheel diameter (in)
	1 // TODO: Change this gear ratio
);

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "ITESM1");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	chassis.set_drive_constants(
		chassisDriveConstants[0],
		chassisDriveConstants[1],
		chassisDriveConstants[2],
		chassisDriveConstants[3],
		chassisDriveConstants[4],
		chassisDriveConstants[5],
		chassisDriveConstants[6]
	);

	chassis.set_turn_constants(
		chassisTurnConstants[0],
		chassisTurnConstants[1],
		chassisTurnConstants[2],
		chassisTurnConstants[3],
		chassisTurnConstants[4],
		chassisTurnConstants[5],
		chassisTurnConstants[6]
	);

	chassis.set_brake(pros::E_MOTOR_BRAKE_BRAKE);

	chassis.drive_distance(10, 0);
}

void opcontrol() {
	// Controller
	pros::Controller controller(pros::E_CONTROLLER_MASTER);

	while (true) {
		chassis.arcade(controller, lightning::E_TANK_OP_ARCADE_DOUBLE);
		pros::delay(lightning::util::DELAY_TIME);
	}
}
