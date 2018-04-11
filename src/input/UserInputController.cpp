//
// Created by Joseph Holland  on 05/04/2018.
//

#include "UserInputController.h"

// DEBUG: remove before compile
#define TERMINAL_EMULATE

#ifdef TERMINAL_EMULATE

char UserInputController::GetUserInput() {

    int userKeypress(getch());

    if(InputDefs::KeypressMap[userKeypress]) return lastButtonPress = InputDefs::KeypressMap[userKeypress];

    else return lastButtonPress = (char)255;

}
#else

// TODO: implement mbed
#endif
