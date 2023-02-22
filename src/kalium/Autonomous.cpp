#include <iostream>
#include "vex.h"

#include "kalium/subsystems.h"

namespace kalium {
  namespace auton {

    // kalium::subsystems:://Catapult //catapult(//catapultMotors, limitSwitch);
    // kalium::subsystems:://Roller //roller(//rollerMotor, opticalSensor);

    void skills() {
      //rollerMotor.setStopping(hold);
      Drivetrain.setDriveVelocity(100, percent);
      Drivetrain.setTurnVelocity(100, percent);
      rollerMotor.setVelocity(20000, percent);
      wait(1, seconds);
      // intakeMotor.spin(reverse);
      //catapult.prime();
      //Drivetrain.driveFor(reverse, 5, inches);
      //roller.roll(red);

      // Roller 1
      rollerMotor.spinFor(forward, 3.5, turns, false);
      Drivetrain.driveFor(reverse, 1, inches, true);
      // Roller 2
      Drivetrain.setDriveVelocity(50, percent);
      Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.driveFor(forward, 19, inches, true);
      //intakeMotor.spin(reverse);
      wait(0.5, seconds);
      Drivetrain.turnFor(right, 55, degrees, true);
      wait(0.5, seconds);
      Drivetrain.driveFor(reverse, 19
      , inches, true);
      Drivetrain.turnFor(left, 5, degrees, true);
      wait(1, seconds);

      Drivetrain.setDriveVelocity(100, percent);
      Drivetrain.setTurnVelocity(100, percent);
      rollerMotor.spinFor(forward, 0.5, turns, false);
      Drivetrain.driveFor(reverse, 1, inches, true);

      // Roller 3
      Drivetrain.setDriveVelocity(50, percent);
      Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.driveFor(forward, 40, inches, true);
      Drivetrain.turnFor(left, 55, degrees, true);
      Drivetrain.driveFor(forward, 60, inches, true);
      Drivetrain.turnFor(right, 60, degrees, true);
      Drivetrain.driveFor(forward, 20, inches, true);
      Drivetrain.turnFor(right, 30, degrees, true);

      // Drivetrain.driveFor(reverse, 1, inches);
      // rollerMotor.spinFor(forward, 180, degrees, true);
      // // Roller 3
      // Drivetrain.driveFor(forward, 3*24, inches, true);
      // Drivetrain.turnFor(left, 70, degrees, true);
      // Drivetrain.driveFor(forward, 24, inches, true);
      // Drivetrain.turnFor(right, 70, degrees, true);
      // Drivetrain.driveFor(forward, 24, inches, true);
      // Drivetrain.turnFor(right, 70, degrees, true);
      // Drivetrain.driveFor(reverse, 3*24, inches, true);
      // Drivetrain.driveFor(reverse, 1, inches);
      // rollerMotor.spinFor(forward, 180, degrees, true);
      // // Roller 4
      // Drivetrain.driveFor(forward, 19, inches, true);
      // Drivetrain.turnFor(right, 70, degrees, true);
      // Drivetrain.driveFor(reverse, 19, inches, true);
      // Drivetrain.driveFor(reverse, 1, inches);
      // rollerMotor.spinFor(forward, 180, degrees, true);

      // Expansion1.set(true);
      // Expansion2.set(true);
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