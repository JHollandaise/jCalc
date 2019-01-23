//
// Created by Joseph Holland  on 05/04/2018.
//

#include "UserInputController.h"
#include "OperationMode.h"
#include "GUI/tigr.h"

#ifdef TERMINAL_EMULATE

unsigned short UserInputController::GetUserInput(std::map<unsigned char, unsigned short>* buttonMap) {

    unsigned char buttonPress(0);

    // read user buttonpress
    int userKeypress(tigrReadChar(screen));
    // return null input
    if (!userKeypress) return 0x0000;

    // check for invalid input -> return NULL input
    if(!(buttonPress = InputDefs::KeypressMap[userKeypress]) && userKeypress != '1')
        throw std::range_error("unmapped keypress");


    return (*buttonMap)[buttonPress];
}

#else

// TODO: implement mbed
#endif

