#include "vex.h"
namespace kalium {
  namespace PID {
    void test() {
      Controller1.Screen.clearLine(1);
      Controller1.Screen.setCursor(1, 1);
      double leftMotorVal = LeftDriveSmart.position(degrees);
      Controller1.Screen.print(leftMotorVal);
      wait(0.25, seconds);
    }
  }
}
