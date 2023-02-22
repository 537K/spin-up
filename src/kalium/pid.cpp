// /* psuedo
// void Pid(int setpoint) {
//   while (some condition) {
//     error = setpoint - sensor val

//     integral += error
//     if (error = 0 or passes setpoint)
//       integral = 0
//     if (error is outside useful range)
//       integral = 0

//     derivative = error - prevError
//     prevError = error

//     power = (error*kP) + (integral*kI) + (derivative*kD)
//     wait 15 mSec;
//   }
// }
// */

// #include "vex.h"
// #include "kalium/pid.h"

// namespace kalium {
//   namespace pid {
//     int drivePID() {
//       while (settings::enableDrivePID) {
//         int leftMotorPosition = LeftDriveMotors.position(degrees);
//         int rightMotorPosition = RightDriveMotors.position(degrees);
//         int averagePosition = (leftMotorPosition + rightMotorPosition) / 2;
//         error = averagePosition - desiredValue;

//         prevError = error;
//         vex::task::sleep(20);
//       }

//       return 1;
//     }

//     void drivePID(double desiredDistance, double desiredTurn) {
//       double leftMotorPosition = LeftDriveMotors.position(degrees);
//       double rightMotorPosition = RightDriveMotors.position(degrees);
//       double averagePosition = (leftMotorPosition + rightMotorPosition) / 2;


//     }
//   }
// }