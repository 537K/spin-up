#include "vex.h"
namespace kalium {
  namespace PID {

    class GlobalSettings { 
      public: 
        static bool enableDrivePID;

      // Settings
      const double kP = 0.0;
      const double kI = 0.0;
      const double kD = 0.0;
      int error; //SensorValue - DesiredValue
      int prevError; //Position 20 milliseconds ago
      int derivative;
      int totalError;

      //Autonomous Settings
      int desiredValue;
    };

    int globalVar;
    
    int drivePID();

    class Foo {
      int i;
      int bar();
    };
  }
}