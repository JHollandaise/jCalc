//
// Created by Joseph Holland  on 05/04/2018.
//

#include "UserInputController.h"

// DEBUG: remove before compile
#define TERMINAL_EMULATE

#ifdef TERMINAL_EMULATE

unsigned short UserInputController::GetUserInput(std::map<unsigned char, unsigned short>* buttonMap) {

    unsigned char buttonPress(0);
    int userKeypress(getch());

    // check for invalid input -> return NULL input
    if(!(buttonPress = InputDefs::KeypressMap[userKeypress]) && userKeypress != '1') return (unsigned short) 0x0000;

    return (*buttonMap)[buttonPress];
}

#else

// TODO: implement mbed
#endif

