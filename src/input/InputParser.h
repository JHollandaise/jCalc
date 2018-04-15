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
    InputParser() : tokenStream(), graphicsStream() {cursorPos = tokenStream.end();};

    unsigned char AddToStream(unsigned short, bool *);

    unsigned char DelFromStream();

    unsigned char ClearStream();

    std::vector<unsigned short>* GetTokenStream(){ return &tokenStream; }

private:

    std::vector<unsigned short>::iterator cursorPos;

    std::vector<unsigned short> tokenStream;

    GraphicsStream graphicsStream;
};


#endif //JCALC_INPUTPARSER_H
