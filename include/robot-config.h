#pragma once
#include "vex.h"
using namespace vex;

#include "kalium/subsystems.h"

extern brain Brain;

// VEXcode devicese

extern motor LeftDriveMotorA;
extern motor LeftDriveMotorB;
extern motor_group LeftDriveMotors;
extern motor RightDriveMotorA;
extern motor RightDriveMotorB;
extern motor_group RightDriveMotors;
extern drivetrain Drivetrain;
extern motor CatapultMotorA;
extern motor CatapultMotorB;
extern motor_group catapultMotors;
extern kalium::subsystems::Roller intakeMotor;
extern controller Controller;
extern kalium::subsystems::Roller rollerMotor;
extern digital_out Expansion1;
extern digital_out Expansion2;
extern limit Switch;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );