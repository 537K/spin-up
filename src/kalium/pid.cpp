// //#include "vex.h"
// //using namespace vex;
// #include "kalium/pid.h"


// namespace kalium {
//   namespace PID {
//     // Settings
//     prevError = 0; //Position 20 milliseconds agoS
//     totalError = 0;

//     //globalVar = 0;

//     // Autonomous Settings
//     desiredValue = 200;

//     bool enableDrivePID = false;
//     int drivePID() {

//       globalVar = 0;
//       GlobalSettings::enableDrivePID = false;

//       while (enableDrivePID) {
//         int leftMotorPOS = LeftDriveSmart.position(degrees);
//         int rightMotorPOS = RightDriveSmart.position(degrees);
//         int averagePOS = (leftMotorPOS + rightMotorPOS) / 2;

//         error = averagePOS - desiredValue; // Potential
//         derivative = error - prevError; // Derivative
//         totalError += error; // Integral

//         double motorPower = (error * kP + derivative * kD + totalError + kI);

//         prevError = error;
//         task::sleep(20);
//       }

//       return 1;
//     }

//     int Foo::bar() { i = 0;}
    
//   }
// }
