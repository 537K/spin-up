/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Rohan Malhi of 537K                                       */
/*    Created:      Wed Dec 28 2022                                           */
/*    Description:  Kalium's competition code                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*
TODO
  Auton Scenarios
    Rewrite selector
  PID
  Odometry?
  PROS migration [VERY VERY long-term]
  Disable turning roller motor
  
*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    2, 20           
// catapultMotors       motor_group   1, 10           
// intakeMotor          motor         11              
// Controller1          controller                    
// rollerMotor          motor         19              
// limitSwitch          limit         A               
// opticalSensor        optical       3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

// All custom systems are under kalium namespace
#include "kalium/AutonSelector.h" // kalium::selector namespace
#include "kalium/Autonomous.h"

competition Competition;
bool skills {false};

void setup(void) { // Important: Only called upon first boot, NOT whenever robot is disabled
  vexcodeInit(); // Initializing Robot Configuration. DO NOT REMOVE!

  Drivetrain.setDriveVelocity(87, percent);
  Drivetrain.setTurnVelocity(87, percent);
  
  catapultMotors.setVelocity(200, percent);
  rollerMotor.setVelocity(200, percent);
  intakeMotor.setVelocity(200, percent);
  catapultMotors.setStopping(hold);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void auton(void) {
  Drivetrain.setDriveVelocity(47, percent);
  Drivetrain.setTurnVelocity(47, percent);

  //Initialize capabilities for buttons
  // Replace this with custom conditions relevant for spin up
  skills = kalium::selector::buttons[0].state;
}


void usercontrol(void) {
  while (1) {
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() { // Entry point
  if (skills) {
    Competition.autonomous(kalium::autonomous::skills);
  } else {
    Competition.autonomous(kalium::autonomous::autonPeriod);
  }
  Competition.drivercontrol(usercontrol);

  setup();
  kalium::selector::init();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    // Allow other tasks to run
    if (!Competition.isEnabled()) {
      Brain.Screen.setFont(fontType::mono40);
    }
    Brain.Screen.setFillColor(color(0xFFFFFF));

    Brain.Screen.setPenColor(color(0xc11f27));
    Brain.Screen.printAt(0, 135, "    Kalium 537K    ");

    if (Controller1.ButtonA.pressing()) {
      usercontrol();
    }

    // this_thread::sleep_for(10);
    wait(20, msec);
  }
}