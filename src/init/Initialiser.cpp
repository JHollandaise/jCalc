//
// Created by Joseph Holland  on 10/04/2018.
//


#include "Initialiser.h"

/**
 * Handles initialisation of tigrWindow and runs mainloop
 */

void Initialiser::  Initialise() {

#ifdef TERMINAL_EMULATE
    termInit = TermInit();
#else
    mbedInit = MbedInit();
#endif

    screen = tigrWindow(320, 240, "Hello", TIGR_2X);

    // pass screen to calculator
    calculator.AddScreen(screen);

    // paste background
    tigrClear(screen, tigrRGB(221, 219, 155));


    // mainloop
    while (!tigrClosed(screen))
    {

        calculator.Mainloop();

        // push set frame to screen
        tigrUpdate(screen);

    }
    tigrFree(screen);



    // deconstruct init (de-init)

}
