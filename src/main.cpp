#include "main.h"

// * Subsystems
// Chassis
const int maxVoltageMv = 12 * 1000;
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

void autonomous() {}

void opcontrol() {
	// Controller
	pros::Controller controller(pros::E_CONTROLLER_MASTER);

	while (true) {
		chassis.move_voltage(
			((float)controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) / 127.0) * maxVoltageMv,
			((float)controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) / 127.0) * maxVoltageMv
		);

		pros::delay(lightning::util::DELAY_TIME);
	}
}
