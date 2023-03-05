#include <iostream>

#include "vex.h"
using namespace vex;

#include "kalium/selector.h"

namespace kalium {
  namespace autonomous {
    namespace selector {      
      void draw() {
        Brain.Screen.drawLine(0, 120, 480, 120);
        Brain.Screen.drawLine(240, 0, 240, 240);
        Brain.Screen.setCursor(5, 5);
        Brain.Screen.print("Far Roller"); // Top left
        Brain.Screen.setCursor(15, 5);
        Brain.Screen.print("Close Roller"); // Bottom left
        Brain.Screen.setCursor(5, 40);
        Brain.Screen.print("Skills"); // Top right
        Brain.Screen.setCursor(15, 40);
        Brain.Screen.print("Tie-breaker"); // Bottom right
      }

      int check() {
        // Ordered like math quadrants
        while (true) {
          if (Brain.Screen.pressing()) {
            if (Brain.Screen.xPosition() < 240) {
              if (Brain.Screen.yPosition() < 120) {
                return 2;
                Controller.Screen.print("Selected Far Roller");
                Brain.Screen.clearScreen();
              } else {
                return 3;
                Controller.Screen.print("Selected Close Roller");
                Brain.Screen.clearScreen();
              }
            } else {
              if (Brain.Screen.yPosition() < 120) {
                return 1;
                Controller.Screen.print("Selected Skills");
                Brain.Screen.clearScreen();
              } else {
                return 4;
                Controller.Screen.print("Selected Tie-breaker");
                Brain.Screen.clearScreen();
              }
            }
          }
          wait(20, msec);
        }
        
      }
    }
  }
}