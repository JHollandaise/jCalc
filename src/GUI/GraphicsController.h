//
// Created by Joseph Holland  on 15/04/2018.
//

#ifndef JCALC_GRAPHICSCONTROLLER_H
#define JCALC_GRAPHICSCONTROLLER_H

#include <vector>
#include "GUI/tigr.h"


class GraphicsController {

public:
    GraphicsController():screen(nullptr){};

    void PrintTokenStream(std::vector<unsigned short>* tokenStream);

    inline void SetScreen(Tigr *newScreen) {screen = newScreen;}

private:
    Tigr *screen;
};


#endif //JCALC_GRAPHICSCONTROLLER_H
