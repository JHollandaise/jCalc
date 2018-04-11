//
// Created by Joseph Holland  on 10/04/2018.
//

#include "TermInit.h"
#include <curses.h>

Error TermInit::Initialise() {

    // required initialisation of curses window
    initscr();
    noecho();
    // allows reading of special characters
    keypad(stdscr,true);

    refresh();

    // TODO: set up error checking for curses window initialisation
    return Error();
}

void TermInit::DeInitialise()
{
    endwin();
}
