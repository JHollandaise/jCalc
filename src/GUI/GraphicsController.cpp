//
// Created by Joseph Holland  on 15/04/2018.
//

#include <curses.h>
#include "GraphicsController.h"
#include "OperationMode.h"
#include "tigr.h"


#ifdef TERMINAL_EMULATE
void GraphicsController::PrintTokenStream(std::vector<unsigned short>* tokenStream,Tigr *screen) {
    // clear the window
    tigrClear(screen, tigrRGB(221, 219, 155));
    tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), "{ ");
    for (auto token = tokenStream->begin(); token != tokenStream->end(); token++) {

        if(token == tokenStream->begin())
            tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), "0x%x", *token);

        else tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), " ,0x%x", *token);

    }

    tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), " }");
}
#else
void GraphicsController::PrintTokenStream(std::vector<unsigned short> tokenStream) {

}
#endif