#include <iostream>
#include "vex.h"

#include "kalium/subsystems.h"

namespace kalium {
  namespace auton {

    // kalium::subsystems:://Catapult //catapult(//catapultMotors, limitSwitch);
    // kalium::subsystems:://Roller //roller(//rollerMotor, opticalSensor);

    void primeCata() {
      while (Switch.pressing() == false) {
        catapultMotors.spin(reverse);
      }
      catapultMotors.stop();
    }
    
    void fireCata() {
      if (Switch.pressing()) {
        catapultMotors.spin(reverse);
        wait(0.25, seconds);
        catapultMotors.stop();
      }
    }

    void skills() {
      double time = Brain.Timer.time(seconds);
      //rollerMotor.setStopping(hold);
      //primeCata();
      Drivetrain.setDriveVelocity(100, percent);
      Drivetrain.setTurnVelocity(100, percent);
      rollerMotor.setVelocity(20000, percent);
      wait(1, seconds);
      // intakeMotor.spin(reverse);
      //catapult.prime();
      //Drivetrain.driveFor(reverse, 5, inches);
      //roller.roll(red);

      // Roller 1
      rollerMotor.spinFor(forward, 6, turns, false);
      Drivetrain.driveFor(reverse, 1, inches, true);
      
      // Roller 2
      Drivetrain.setDriveVelocity(50, percent);
      Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.driveFor(forward, 19, inches, true);
      intakeMotor.spin(reverse);
      wait(0.5, seconds);
      Drivetrain.turnFor(right, 45, degrees, true);
      wait(0.5, seconds);
      Drivetrain.driveFor(reverse, 18, inches, true);
      //Drivetrain.turnFor(left, 5, degrees, true);
      wait(1, seconds);

      Drivetrain.setDriveVelocity(100, percent);
      Drivetrain.setTurnVelocity(100, percent);
      rollerMotor.spinFor(forward, 1, turns, false);
      Drivetrain.driveFor(reverse, 1, inches, true);
      Drivetrain.driveFor(forward, 1, inches, true);

      // Roller 3
      Drivetrain.setDriveVelocity(50, percent);
      Drivetrain.setTurnVelocity(50, percent);
      Drivetrain.driveFor(forward, 40, inches, true);
      wait(0.5, seconds);
      Drivetrain.turnFor(left, 45, degrees, true);
      wait(0.5, seconds);
      Drivetrain.driveFor(forward, 55, inches, true);
      wait(0.5, seconds);
      Drivetrain.turnFor(right, 45, degrees, true);
      wait(0.5, seconds);
      Drivetrain.driveFor(forward, 35, inches, true);
      wait(0.5, seconds);
      Drivetrain.turnFor(right, 50, degrees, true);
      wait(0.5, seconds);
      //Drivetrain.driveFor(reverse, 15, inches, true);

      Drivetrain.setDriveVelocity(100, percent);
      Drivetrain.setTurnVelocity(100, percent);
      rollerMotor.spinFor(forward, 1, turns, false);
      Drivetrain.driveFor(reverse, 4.5, inches, false);
      wait(5, seconds);
      Drivetrain.driveFor(forward, 4, inches, true);
      Drivetrain.turnFor(45, degrees, true);

      // Roller 4
      // Drivetrain.setDriveVelocity(50, percent);
      // Drivetrain.setTurnVelocity(50, percent);
      // Drivetrain.driveFor(forward, 18, inches, true);
      // intakeMotor.spin(reverse);
      // wait(0.5, seconds);
      // Drivetrain.turnFor(right, 45, degrees, true);
      // wait(0.5, seconds);
      // Drivetrain.driveFor(reverse, 3.5, inches, true);
      // //Drivetrain.turnFor(left, 5, degrees, true);
      // wait(1, seconds);

      // Drivetrain.setDriveVelocity(100, percent);
      // Drivetrain.setTurnVelocity(100, percent);
      // rollerMotor.spinFor(forward, 1, turns, false);
      // Drivetrain.driveFor(reverse, 1, inches, true);
      // Drivetrain.driveFor(forward, 1, inches, true);

      // Expansion
      Expansion1.set(true);
      Expansion2.set(true);

      Brain.Screen.print(Brain.Timer.time(seconds) - time);

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
    // void closeRoller() {
    //   Drivetrain.setDriveVelocity(100, percent);
    //   Drivetrain.setTurnVelocity(100, percent);
    //   rollerMotor.setVelocity(20000, percent);
    //   wait(1, seconds);
    //   // Roller 1
    //   rollerMotor.spinFor(forward, 3.5, turns, false);
    //   Drivetrain.driveFor(reverse, 1, inches, true);
    // }
  }
}