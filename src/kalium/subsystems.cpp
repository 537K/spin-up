#include "vex.h"

namespace kalium {
  namespace subsystems {
    class Catapult {
      private:
        motor_group* motors;
        limit* limitSwitch;
      public:
        Catapult(motor_group MotorGroup, limit lSwitch) {
          motors = &MotorGroup;
          limitSwitch = &lSwitch;
        }

        void prime() {
          while (limitSwitch->pressing() != true) {
            motors->spin(forward);
          }
          motors->stop();
        }

        void fire() {
          motors->spinFor(1.5, seconds);
        }
    };

    class Roller {
      private:
        motor* rollerMotor;
        optical* sensor;
      public:
        Roller(motor motors, optical opticalSensor) {
          rollerMotor = &motors;
          sensor = &opticalSensor;
        }

        void roll(color Color) {
          while (sensor->color() != Color) {
            rollerMotor->spin(forward);
          }
          rollerMotor->stop();
        }
    };
  }
}