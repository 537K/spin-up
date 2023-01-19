#include "vex.h"
using namespace vex;

#include "kalium/AutonSelector.h"

//Code is adapted from Liam Donovan, CJ Crocker, James Pearman, and Pascal Chesnais
//https://www.vexforum.com/t/walshbots-autonomous-feature-selector/51534
//In the future, this will be rewritten using Andrew Simonson's button code

namespace kalium {
  namespace selector {
    int autonomousSelection = -1;
    // Button array definitions for each software button. The purpose of each button data structure
    // is defined above.  The array size can be extended, so you can have as many buttons as you 
    // wish as long as it fits.
    button buttons[] = { 
      {   30,  30, 60, 60,  false, 0xE00000, 0x0000E0, "Skills" },
      {  150,  30, 60, 60,  false, 0x303030, 0xD0D0D0, "Start" },
      {  270,  30, 60, 60,  false, 0x303030, 0xF700FF, "Park" },
      {  390,  30, 60, 60,  false, 0x303030, 0xDDDD00, "Shoot" },
      {   30, 150, 60, 60,  false, 0x404040, 0xC0C0C0, "4-" },
      {  150, 150, 60, 60,  false, 0x404040, 0xC0C0C0, "5-" },
      {  270, 150, 60, 60,  false, 0x404040, 0xC0C0C0, "6-" },
      {  390, 150, 60, 60,  false, 0x404040, 0xC0C0C0, "7-" }
    };

    int findButton(  int16_t xpos, int16_t ypos ) { // Check if touch is inside button
      int nButtons = sizeof(buttons) / sizeof(button);

      for( int index=0;index < nButtons;index++) {
        button *pButton = &buttons[ index ];
        if( xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width) )
          continue;

        if( ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height) )
          continue;

        return(index);
      }
      return (-1);
    }

    void initButtons() { // Init buttons states
      int nButtons = sizeof(buttons) / sizeof(button);
      for (int index = 0; index < nButtons; index++) {
        buttons[index].state = false;
      }
    }

    void userTouchCallbackPressed() { // Screen has been touched
      int index;
      int xpos = Brain.Screen.xPosition();
      int ypos = Brain.Screen.yPosition();

      if ((index = findButton(xpos, ypos) >= 0)) {
        displayButtonControls(index, true);
      }
    }

    void userTouchCallbackReleased() {
      int index;
      int xpos = Brain.Screen.xPosition();
      int ypos = Brain.Screen.yPosition();

      if( (index = findButton( xpos, ypos )) >= 0 ) {
      // clear all buttons to false, ie. unselected
      //      initButtons(); 

      // now set this one as true
      if( buttons[index].state == true) {
        buttons[index].state = false; }
      else    {
        buttons[index].state = true;}

      // save as auton selection
      autonomousSelection = index;

      displayButtonControls( index, false );
      }
    }

    void displayButtonControls(int index, bool pressed) {
      color c;
      Brain.Screen.setPenColor(color(0xe0e0e0));

      for (int i=0; i < sizeof(button)/sizeof(button);i++) {
        if (buttons[i].state) {c = buttons[i].onColor;}
        else {c = buttons[i].offColor;}

        Brain.Screen.setFillColor(c);

        // Button fill
        if (i == index && pressed == true) {
          Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, c );
        }
        else {
          Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height );
        }

        //outline
        Brain.Screen.drawRectangle( buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height, vex::color::transparent );

        //draw label
        if (buttons[i].label != NULL) {
          Brain.Screen.printAt( buttons[i].xpos + 8, buttons[i].ypos + buttons[i].height - 8, buttons[i].label );
        }
      }
    }

    // Insert 537K helper functions here


    void init() {
      // register events for button selection
      Brain.Screen.pressed(kalium::selector::userTouchCallbackPressed);
      Brain.Screen.released(kalium::selector::userTouchCallbackReleased);

      // make nice background
      Brain.Screen.setFillColor( vex::color(0x404040) );
      Brain.Screen.setPenColor( vex::color(0x404040) );
      Brain.Screen.drawRectangle( 0, 0, 480, 120 );
      Brain.Screen.setFillColor( vex::color(0x808080) );
      Brain.Screen.setPenColor( vex::color(0x808080) );
      Brain.Screen.drawRectangle( 0, 120, 480, 120 );

      // initial display
      kalium::selector::displayButtonControls(0, false);
    }
  }
}