#include <iostream>
#include "vex.h"

namespace kalium {
  namespace autonomous {
    void skills() {
      std::cout << "pass";
    }
    void anirudh() {
      // Skills
      // Must be adapted for current bot
      Drivetrain.setDriveVelocity(200, percent);
      Drivetrain.setTurnVelocity(200, percent);
      RollerMotor.setVelocity(500, percent);
      Drivetrain.turnFor(left, 92, degrees);
      Drivetrain.driveFor(forward, 12, inches);
      RollerMotor.spin(reverse);
      wait(1, seconds);
      Drivetrain.turnFor(right, 92, degrees);
      Drivetrain.driveFor(reverse, 2, inches);
      wait(0.25, seconds);
      Drivetrain.turnFor(left, 88, degrees);
      Drivetrain.driveFor(forward, 2, inches);
      wait(1.25, seconds);
      RollerMotor.stop();
      Drivetrain.turnFor(right, 100, degrees);
      RollerMotor.spinFor(reverse, 120, degrees);
      Drivetrain.driveFor(forward, 6, inches);
      Drivetrain.turnFor(left, 95, degrees);
      RollerMotor.spinFor(reverse, 90, degrees);
      Drivetrain.turnFor(right, 45, degrees);
      Drivetrain.driveFor(forward, 16, inches);
      Drivetrain.turnFor(right, 130, degrees);
      Drivetrain.driveFor(reverse, 1.5, inches);
      RollerMotor.spin(reverse);
      wait(0.25, seconds);
      RollerMotor.stop();
      Drivetrain.driveFor(forward, 9, inches);
      Drivetrain.turnFor(left, 10, degrees);
      Drivetrain.driveFor(forward, 7, inches);
      RollerMotor.spinFor(reverse, 125, degrees);
      Drivetrain.turnFor(right, 96, degrees);
      RollerMotor.spinFor(reverse, 180, degrees);
      Drivetrain.turnFor(left, 150, degrees);
      Drivetrain.driveFor(forward, 22, inches);
      RollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 18, degrees);
      Drivetrain.driveFor(forward, 12, inches);
      RollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.driveFor(forward, 20, inches);
      RollerMotor.spinFor(reverse, 60, degrees);
      Drivetrain.turnFor(left, 90, degrees);
      RollerMotor.spinFor(reverse, 120, degrees);
      Drivetrain.turnFor(left, 30, degrees);
      Drivetrain.driveFor(forward, 40, inches);
      Drivetrain.turnFor(right, 150, degrees);
      Drivetrain.driveFor(forward, 3, inches);
      RollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 10, degrees);
      Drivetrain.driveFor(forward, 9, inches);
      RollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 3, degrees);
      Drivetrain.driveFor(forward, 9, inches);
      RollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 3, degrees);
      Drivetrain.driveFor(forward, 9, inches);
      RollerMotor.spinFor(reverse, 30, degrees);
      Drivetrain.turnFor(right, 50, degrees);
      RollerMotor.spinFor(reverse, 120, degrees);
      Drivetrain.driveFor(forward, 5, inches);
      Drivetrain.turnFor(left, 140, degrees);
      Drivetrain.driveFor(forward, 35, inches);
      RollerMotor.spinFor(reverse, 90, degrees); 
    }
  }
}