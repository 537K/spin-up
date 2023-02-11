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
  - finish abstractions
  - write basic auton selector
  Later:
  - test auton
  - determine feasability of far roller auton period
  - figure out why roller wasn;t working at highland games
  - put cata in auton (limit switch)
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

#include <iostream>

#include "vex.h"
using namespace vex;

// All custom systems are under kalium namespace
#include "kalium/selector.h" // kalium::selector namespace
#include "kalium/autonomous.h"
#include "kalium/pid.h"

competition Competition;
// int auton;

void setup(void) { // Important: Only called upon first boot, NOT whenever robot is disabled
  vexcodeInit(); // Initializing Robot Configuration. DO NOT REMOVE!
  Expansion.set(false);
  Drivetrain.setDriveVelocity(87, percent);
  Drivetrain.setTurnVelocity(87, percent);
  
  catapultMotors.setVelocity(200, percent);
  rollerMotor.setVelocity(200, percent);
  intakeMotor.setVelocity(200, percent);
  catapultMotors.setStopping(hold);
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  //kalium::autonomous::selector::draw();
  //auton = kalium::autonomous::selector::check();
}

void usercontrol(void) {
  Brain.Screen.clearScreen();
  rollerMotor.setVelocity(50, percent);
  //Drivetrain.driveFor(reverse, 1, inches, true);
  while (1) {
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void autonControl(void) {
  kalium::auton::closeRoller();
}

int main() { // Entry point
  setup();
  
  // if (auton == 1)
  //   Competition.autonomous(kalium::auton::skills);
  // else if (auton == 2)
  //   Competition.autonomous(kalium::auton::farRoller);
  // else if (auton == 3)
  //   Competition.autonomous(kalium::auton::closeRoller);
  // else if (auton == 4)
  //   Competition.autonomous(kalium::auton::tieBreaker);

  Competition.autonomous(autonControl);

  Competition.drivercontrol(usercontrol);
}