//
// Created by Joseph Holland  on 10/04/2018.
//


#include "Initialiser.h"


void Initialiser::Initialise() {

#ifdef TERMINAL_EMULATE
    termInit = TermInit();
#else
    mbedInit = MbedInit();
#endif

    while(!returnError)
    {
        returnError = calculator.ManageUserInput(&ButtonMapMaths::Default);
        // Manage returnErrors
    }
    // deconstruct init (de-init)

}
