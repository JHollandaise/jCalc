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

    calculator.Mainloop();

    // deconstruct init (de-init)

}
