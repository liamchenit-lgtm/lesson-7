#include "main.h"
#include "pros/adi.hpp"
#include "pros/rtos.hpp"
#include "pros/motors.hpp"
#include "pros/vision.hpp"

using namespace pros;


#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT -5
#define ARM_PORT 4
#define CLAW_PORT 7

Motor left_wheels (LEFT_WHEELS_PORT);
Motor right_wheels (RIGHT_WHEELS_PORT);

// Claw and arm definitions
Motor claw (CLAW_PORT);
Motor arm (ARM_PORT);

// Controller definitions
Controller master (CONTROLLER_MASTER);

ADIButton bumperSensor('A');


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}


/*
Practice:
	1) Using the bumper sensor, make the robot raise its arm, pause for 2 second
	   then lower its arm again. Write it in the function below.
	2) Now try this on the field while continuously driving the robot. 
		Are you still able to drive after the bumber is pressed?
	
	3) Now try to make raise_arm a task instead!
		Here is the syntax: Task TASK_NAME(TASK_FUNCTION);
	4) What is the differece after running the code?

	Full list of Task Parameters:
		Task::Task(task_fn_t function,
			void* parameters = NULL,								// Any Parameters you want to pass
			std::uint32_t prio = TASK_PRIORITY_DEFAULT,				// Priority of the task, default is 8
			std::uint16_t stack_depth = TASK_STACK_DEPTH_DEFAULT,	// Amount of memory to allocate, default is 32,768 bytes
			const char* name = "")									// An additionalfor debugging
	
	5) Now try to make a task that closes the claw when it senses that a ball is nearby with the distance sensor
	6) Try using the AI vision sensor instead so that it only picks up a certain color of ball!
		- Here you may need to use delays or a combination of the ai sensor and distance sensor
*/

void raise_arm(void*) {
}

void opcontrol() {
	arm.set_brake_mode(MOTOR_BRAKE_HOLD);
	
	while (true) {
		int power = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
		int turn = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
		// What input from the controller will control the turning?
		int left = power + turn;
		int right = power - turn;
		
		left_wheels.move(left);
		right_wheels.move(right);
	}

}

/*
What other common uses do you think there are for tasks?
Write them below:
	1) 
	2) 
	3) 

Why can't we just use a while loop in the opcontrol function?
Think of three reasons why we can't do this.
	1) 
	2) 
	3)
	
*/
