//
// Created by Joseph Holland  on 05/04/2018.
//

// DEBUG: remove before compile
#define TERMINAL_EMULATE


#ifndef JCALC_USERINPUTCONTROLLER_H
#define JCALC_USERINPUTCONTROLLER_H

#include "Button.h"
#include "../InputDefs.h"

#ifdef TERMINAL_EMULATE
#include <curses.h>
#endif

/* Controls the inflow of data from the user
 * Manages the button presses and determines the appropriate action to take
 * given the current mode
 */

class UserInputController {

public:
    UserInputController() : shiftPressed(false), alphaPressed(false), recallPressed(false), lastButtonPress((char)255) {};

    // listens for a user button press then returns the value of the button pressed
    char GetUserInput();

    bool GetShiftPressed()  {return shiftPressed;}
    bool GetAlphaPressed()  {return alphaPressed;}
    bool GetRecallPressed() {return recallPressed;}

    char GetModifier() {return shiftPressed + (alphaPressed << 1) + (recallPressed<<2);}

    char GetLastButtonPress() {return lastButtonPress;}


private:

    bool shiftPressed;
    bool alphaPressed;

    bool recallPressed;

    char lastButtonPress;

};


#endif //JCALC_USERINPUTCONTROLLER_H
