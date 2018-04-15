//
// Created by Joseph Holland  on 15/04/2018.
//

#include <curses.h>
#include "GraphicsController.h"
#include "../OperationMode.h"



#ifdef TERMINAL_EMULATE
void GraphicsController::PrintTokenStream(std::vector<unsigned short>* tokenStream) {
    // clear the window
    erase();
    mvprintw(0,0,"{ ");

    for (auto token = tokenStream->begin(); token != tokenStream->end(); token++) {

        if(token == tokenStream->begin()) printw("0x%x", *token);

        else printw(" ,0x%x", *token);

    }

    printw(" }");
}
#else
void GraphicsController::PrintTokenStream(std::vector<unsigned short> tokenStream) {

}
#endif