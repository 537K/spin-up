#pragma once
#include "vex.h"
using namespace vex;

namespace kalium {
  namespace selector {
    extern int autonomousSelection;
    typedef struct _button {
      int xpos;
      int ypos;
      int width;
      int height;
      bool state;
      color offColor;
      color onColor;
      const char *label;
    } button;
    extern button buttons[];
    
    void displayButtonControls(int index, bool pressed);
    int findButton(int16_t xpos, int16_t ypos);
    void initButtons();
    void userTouchCallbackPressed();
    void userTouchCallbackReleased();
    void init();
  }
}