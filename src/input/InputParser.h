//
// Created by Joseph Holland  on 09/04/2018.
//

#ifndef JCALC_INPUTPARSER_H
#define JCALC_INPUTPARSER_H

#include <vector>
#include "Button.h"
#include "../GUI/GraphicsStream.h"
#include "../ErrorMgt/Error.h"

class InputParser {
public:
    InputParser(){};

    Error AddToStream(Button*);



private:
    std::vector<Button> buttonStream;

    GraphicsStream graphicsStream;
};


#endif //JCALC_INPUTPARSER_H
