#pragma once
#include "vex.h"
using namespace vex;

namespace kalium {
  namespace subsystems {

      class Roller : public motor {
        public:
          Roller(int32_t port, gearSetting ratio, bool polarity) : motor(port, ratio, polarity) {

          }

          bool mustRun;
          bool ranLast;
          directionType direction;
    };
  }
}