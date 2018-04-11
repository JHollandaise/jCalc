//
// Created by Joseph Holland  on 05/04/2018.
//

// DEBUG: remove before compile
#define TERMINAL_EMULATE


#ifndef JCALC_USERINPUTCONTROLLER_H
#define JCALC_USERINPUTCONTROLLER_H

#include "Button.h"
#include "../InputDefs.h"
#include "buttonMaps/Maths.h"
#include "../ErrorMgt/Error.h"

#ifdef TERMINAL_EMULATE
#include <curses.h>

#endif

/* Controls the inflow of data from the user
 * Manages the button presses and determines the appropriate action to take
 * given the current mode
 */

class UserInputController {

public:
    UserInputController() : currentButtonMap(&ButtonMapMaths::Default),
                            shiftPressed(false), alphaPressed(false),
                            recallPressed(false), lastButtonPress((char)255) {};

    // listens for a user button press then returns the value of the button pressed
    unsigned char GetUserInput();

    bool GetShiftPressed()  {return shiftPressed;}
    bool GetAlphaPressed()  {return alphaPressed;}
    bool GetRecallPressed() {return recallPressed;}

    unsigned char GetModifier() {return shiftPressed + (alphaPressed << 1) + (recallPressed<<2);}

    unsigned char GetLastButtonPress() {return lastButtonPress;}

    std::map<char,short>* GetCurrentButtonMap() { return currentButtonMap;}
    Error SetCurrentButtonMap();


private:

    std::map<char,short>* currentButtonMap;

    bool shiftPressed;
    bool alphaPressed;

    bool recallPressed;

    unsigned char lastButtonPress;

};


#endif //JCALC_USERINPUTCONTROLLER_H
