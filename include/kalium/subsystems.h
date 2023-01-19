#include "vex.h"

namespace kalium {
  namespace subsystems {
    class Catapult {
      private:
        motor_group* motors;
        limit* limitSwitch;
      public:
        Catapult(motor_group MotorGroup, limit lSwitch);

        void prime();
        void fire();
    };

    class Roller {
      private:
        motor* rollerMotor;
        optical* sensor;
      public:
        Roller(motor motors, optical opticalSensor);

        void roll(color Color);
    };
  }
}