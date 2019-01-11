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
    screen = tigrWindow(320, 240, "Hello", TIGR_2X);
    tigrClear(screen, tigrRGB(221, 219, 155));


    // mainloop
    while (!tigrClosed(screen))
    {


        calculator.Mainloop(screen);

        tigrUpdate(screen);

    }
    tigrFree(screen);



    // deconstruct init (de-init)

}
