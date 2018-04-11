//
// Created by Joseph Holland  on 05/04/2018.
//

#include "UserInputController.h"

// DEBUG: remove before compile
#define TERMINAL_EMULATE

#ifdef TERMINAL_EMULATE

unsigned char UserInputController::GetUserInput() {

    int userKeypress(getch());

    if(InputDefs::KeypressMap[userKeypress]) return lastButtonPress = InputDefs::KeypressMap[userKeypress];
    else if (userKeypress=='1') return lastButtonPress = (unsigned char)0;
    else return lastButtonPress = (unsigned char)255;

}
#else

// TODO: implement mbed
#endif
