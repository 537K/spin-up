#pragma once
#include "vex.h"
using namespace vex;

namespace kalium {
  namespace subsystems {

      class Roller : public motor {
        public:
          Roller(int32_t port, gearSetting ratio, bool polarity) : motor(port, ratio, polarity) {

          }

          bool new_x_press = true;
          bool new_b_press = true;
          bool new_l1_press = true;
          bool new_l2_press = true;
          bool running = false;
          directionType direction;
    };
  }
}