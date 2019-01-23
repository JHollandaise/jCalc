//
// Created by Joseph Holland  on 05/04/2018.
//



#ifndef JCALC_USERINPUTCONTROLLER_H
#define JCALC_USERINPUTCONTROLLER_H

#include "OperationMode.h"

#include "Button.h"
#include "InputDefs.h"
#include "buttonMaps/Maths.h"
#include "ErrorMgt/Error.h"
#include "GUI/tigr.h"

#ifdef TERMINAL_EMULATE
#include <curses.h>
#include <vector>

#endif

/* Controls the inflow of data from the user
 * Manages the button presses and determines the appropriate action to take
 * given the current mode
 */

class UserInputController {

public:
    UserInputController() : shiftPressed(false), alphaPressed(false),
                            recallPressed(false),screen(nullptr){};

    // listens for a user button press then returns the value of the button pressed
    unsigned short GetUserInput(std::map<unsigned char, unsigned short>* buttonMap);


    bool GetShiftPressed()  {return shiftPressed;}
    bool GetAlphaPressed()  {return alphaPressed;}
    bool GetRecallPressed() {return recallPressed;}

    void SetShiftPressed(bool value)  {shiftPressed = value;}
    void SetAlphaPressed(bool value)  {alphaPressed = value;}
    void SetRecallPressed(bool value) {recallPressed = value;}

    inline void SetScreen(Tigr* newScreen) {screen = newScreen;}




private:

    Tigr *screen;

    bool shiftPressed;
    bool alphaPressed;

    bool recallPressed;

};


#endif //JCALC_USERINPUTCONTROLLER_H
