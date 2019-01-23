//
// Created by Joseph Holland  on 10/04/2018.
//

#ifndef JCALC_INITIALISER_H
#define JCALC_INITIALISER_H

#include "OperationMode.h"


#include "core/Calculator.h"
#include "MbedInit.h"
#include "ErrorMgt/ErrorManager.h"

#ifdef TERMINAL_EMULATE

#include "TermInit.h"

#endif

/**
 * handles init of primary calculator components
 * calculator: handles calculation functionality
 *
 */

class Initialiser {
public:
    Initialiser(): returnError(0) {Initialise();};

private:
    Calculator calculator;
    int returnError;

    // handles User IO depending on platform
    TermInit termInit;
    MbedInit mbedInit;


    // TODO: aquire functionality with screen in termInit
    Tigr *screen;

    // initialise screen and start mainloop
    void Initialise();

};


#endif //JCALC_INITIALISER_H
