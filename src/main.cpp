/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Rohan Malhi of 537K                                       */
/*    Created:      Wed Dec 28 2022                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// rollerMotor          motor         8               
// catapultMotors       motor_group   2, 3            
// Drivetrain           drivetrain    6, 1, 4, 5      
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

#include "kalium/AutonSelector.h"

competition Competition;

// define your global instances of motors and other devices here

void setup(void) { // Important: Only called upon first boot, NOT whenever robot is disabled
  vexcodeInit(); // Initializing Robot Configuration. DO NOT REMOVE!
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

void auton(void) {
  // Initialize capabilities for buttons
  // Replace this with custom conditions relevant for spin up
  bool allianceBlue = kalium::selector::buttons[0].state;
  bool startTileFar = kalium::selector::buttons[1].state;
  bool doPark = kalium::selector::buttons[2].state;
  bool shootPreload = kalium::selector::buttons[3].state;
}

void usercontrol(void) {
  while (1) {
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() { // Entry point
  Competition.autonomous(auton);
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
    Brain.Screen.printAt(0, 135, "    Kalium Competiton    ");
    this_thread::sleep_for(10);
    //wait(100, msec);
  }
}
