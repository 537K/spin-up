#include <iostream>
#include "vex.h"

#include "kalium/subsystems.h"

namespace kalium {
  namespace auton {

    // kalium::subsystems:://Catapult //catapult(//catapultMotors, limitSwitch);
    // kalium::subsystems:://Roller //roller(//rollerMotor, opticalSensor);

    void skills() {
      //rollerMotor.setStopping(hold);
      Drivetrain.setDriveVelocity(50, percent);
      Drivetrain.setTurnVelocity(50, percent);
      wait(2, seconds);
      intakeMotor.spin(reverse);
      //catapult.prime();
      //Drivetrain.driveFor(reverse, 5, inches);
      //roller.roll(red);

      // Roller 1
      Drivetrain.driveFor(reverse, 1, inches, false);
      rollerMotor.spinFor(forward, 180, degrees, true);
      // Roller 2
      Drivetrain.driveFor(forward, 19, inches, true);
      Drivetrain.turnFor(right, 90, degrees, true);
      Drivetrain.driveFor(reverse, 19, inches, true);
      Drivetrain.driveFor(reverse, 1, inches);
      rollerMotor.spinFor(forward, 180, degrees, true);
      // Roller 3
      Drivetrain.driveFor(forward, 3*24, inches, true);
      Drivetrain.turnFor(left, 70, degrees, true);
      Drivetrain.driveFor(forward, 24, inches, true);
      Drivetrain.turnFor(right, 70, degrees, true);
      Drivetrain.driveFor(forward, 24, inches, true);
      Drivetrain.turnFor(right, 70, degrees, true);
      Drivetrain.driveFor(reverse, 3*24, inches, true);
      Drivetrain.driveFor(reverse, 1, inches);
      rollerMotor.spinFor(forward, 180, degrees, true);
      // Roller 4
      Drivetrain.driveFor(forward, 19, inches, true);
      Drivetrain.turnFor(right, 70, degrees, true);
      Drivetrain.driveFor(reverse, 19, inches, true);
      Drivetrain.driveFor(reverse, 1, inches);
      rollerMotor.spinFor(forward, 180, degrees, true);
    }
    void tieBreaker() {
      Drivetrain.driveFor(reverse, 24, inches, true);
      wait(1, seconds);
      Drivetrain.driveFor(forward, 24, inches, true);
    }
    void farRoller() {

    }
    void closeRoller() {
      rollerMotor.setStopping(hold);
      Drivetrain.driveFor(reverse, 1, inches);
      rollerMotor.spinFor(forward, 180, degrees, true);
    }
  }
}