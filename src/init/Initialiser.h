//
// Created by Joseph Holland  on 10/04/2018.
//

#ifndef JCALC_INITIALISER_H
#define JCALC_INITIALISER_H

#include "../OperationMode.h"


#include "../core/Calculator.h"
#include "MbedInit.h"


#ifdef TERMINAL_EMULATE

#include "TermInit.h"

#endif

/* handles init of primary calculator components
 * calculator: handles calculation functionality
 * TermInit/MbedInit: handles user input/output for terminal/embedded platforms
 */

class Initialiser {
public:
    Initialiser(): calculator(), returnError() {Initialise();};

private:
    Calculator calculator;
    int returnError;

    TermInit termInit;
    MbedInit mbedInit;

    void Initialise();
};


#endif //JCALC_INITIALISER_H
