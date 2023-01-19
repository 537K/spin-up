#include <iostream>
#include "vex.h"

#include "kalium/subsystems.h"

namespace kalium {
  namespace autonomous {

    kalium::subsystems::Catapult catapult(catapultMotors, limitSwitch);
    kalium::subsystems::Roller roller(rollerMotor, opticalSensor);

    void skills() {
      catapult.prime();
      Drivetrain.driveFor(reverse, 5, inches);
      roller.roll(red);
      Drivetrain.turnFor(left, 10, degrees, true);
      Drivetrain.driveFor(forward, 15, inches, true);
      Drivetrain.turnFor(left, 80, degrees, true);
      Drivetrain.driveFor(forward, 10, inches, true);
      Drivetrain.turnFor(left, 180, degrees, true);
      Drivetrain.driveFor(reverse, 2, inches, true);
      roller.roll(red);
      Drivetrain.turnFor(right, 45, degrees, true);
      Drivetrain.driveFor(forward, 17, inches, true);
      Drivetrain.turnFor(left, 17, degrees, true);
      catapult.fire();
      catapult.prime();
      Drivetrain.turnFor(right, 17, degrees, true);
      Drivetrain.driveFor(forward, 17, inches, true);
      Drivetrain.turnFor(left, 45, degrees, true);
      catapult.fire();
      catapult.prime();
      Drivetrain.turnFor(right, 45, degrees, true);
      Drivetrain.driveFor(forward, 34, inches, true);
      Drivetrain.turnFor(right, 135, degrees, true);
      Drivetrain.driveFor(reverse, 12, inches, true);
      roller.roll(red);
      Drivetrain.driveFor(forward, 3, inches, true);
      Drivetrain.turnFor(left, 5, degrees, true);
      Drivetrain.driveFor(forward, 12, inches, true);
      Drivetrain.turnFor(right, 90, degrees, true);
      Drivetrain.driveFor(reverse, 24, inches, true);
      roller.roll(red);
      Drivetrain.driveFor(forward, 12, inches, true);
      Drivetrain.turnFor(left, 90, degrees, true);
      Drivetrain.driveFor(forward, 36, inches, true);
      catapult.fire();
    }
    void anirudh() {
      // Skills
      // Must be adapted for current bot
      Drivetrain.setDriveVelocity(200, percent);
      Drivetrain.setTurnVelocity(200, percent);
      rollerMotor.setVelocity(500, percent);
      Drivetrain.turnFor(left, 92, degrees);
      Drivetrain.driveFor(forward, 12, inches);
      rollerMotor.spin(reverse);
      wait(1, seconds);
      Drivetrain.turnFor(right, 92, degrees);
      Drivetrain.driveFor(reverse, 2, inches);
      wait(0.25, seconds);
      Drivetrain.turnFor(left, 88, degrees);
      Drivetrain.driveFor(forward, 2, inches);
      wait(1.25, seconds);
      rollerMotor.stop();
      Drivetrain.turnFor(right, 100, degrees);
      rollerMotor.spinFor(reverse, 120, degrees);
      Drivetrain.driveFor(forward, 6, inches);
      Drivetrain.turnFor(left, 95, degrees);
      rollerMotor.spinFor(reverse, 90, degrees);
      Drivetrain.turnFor(right, 45, degrees);
      Drivetrain.driveFor(forward, 16, inches);
      Drivetrain.turnFor(right, 130, degrees);
      Drivetrain.driveFor(reverse, 1.5, inches);
      rollerMotor.spin(reverse);
      wait(0.25, seconds);
      rollerMotor.stop();
      Drivetrain.driveFor(forward, 9, inches);
      Drivetrain.turnFor(left, 10, degrees);
      Drivetrain.driveFor(forward, 7, inches);
      rollerMotor.spinFor(reverse, 125, degrees);
      Drivetrain.turnFor(right, 96, degrees);
      rollerMotor.spinFor(reverse, 180, degrees);
      Drivetrain.turnFor(left, 150, degrees);
      Drivetrain.driveFor(forward, 22, inches);
      rollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 18, degrees);
      Drivetrain.driveFor(forward, 12, inches);
      rollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.driveFor(forward, 20, inches);
      rollerMotor.spinFor(reverse, 60, degrees);
      Drivetrain.turnFor(left, 90, degrees);
      rollerMotor.spinFor(reverse, 120, degrees);
      Drivetrain.turnFor(left, 30, degrees);
      Drivetrain.driveFor(forward, 40, inches);
      Drivetrain.turnFor(right, 150, degrees);
      Drivetrain.driveFor(forward, 3, inches);
      rollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 10, degrees);
      Drivetrain.driveFor(forward, 9, inches);
      rollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 3, degrees);
      Drivetrain.driveFor(forward, 9, inches);
      rollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 3, degrees);
      Drivetrain.driveFor(forward, 9, inches);
      rollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 50, degrees);
      rollerMotor.spinFor(reverse, 120, degrees);
      Drivetrain.driveFor(forward, 5, inches);
      Drivetrain.turnFor(left, 140, degrees);
      Drivetrain.driveFor(forward, 35, inches);
      rollerMotor.spinFor(reverse, 90, degrees); 
    }

    void autonPeriod() {
      rollerMotor.spin(forward);
      Drivetrain.driveFor(2, inches);
      Drivetrain.turnFor(45, degrees, true);
      Drivetrain.driveFor(/*Idk*/, inches, true);
      Drivetrain.turnFor(/*Until facing*/, degrees, true);
      //Fire
      Drivetrain.turnFor(15, degrees, true);
      Drivetrain.driveFor(28, inches, true);
      Drivetrain.turnFor(left, 15, degrees, true);
      Drivetrain.driveFor(12, inches, true);
      Drivetrain.turnFor(left, 75, degrees, true);
      Drivetrain.driveFor(reverse, 2, inches, true);
    }
  }
}