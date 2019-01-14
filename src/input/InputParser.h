//
// Created by Joseph Holland  on 09/04/2018.
//

#ifndef JCALC_INPUTPARSER_H
#define JCALC_INPUTPARSER_H

#include <vector>
#include "Button.h"
#include "../ErrorMgt/Error.h"

class InputParser {
public:
    InputParser() : tokenStream(){cursorPos = tokenStream.end();};

    unsigned char AddToStream(unsigned short, bool *);

    unsigned char DelFromStream();

    unsigned char ClearStream();

    unsigned char MoveCursorRight();
    unsigned char MoveCursorRight(int);

    unsigned char MoveCursorLeft();
    unsigned char MoveCursorLeft(int);

    std::vector<unsigned short>* GetTokenStream(){ return &tokenStream; }

private:

    void MoveOutOfPrimaryChain(bool direction,
                               std::vector<unsigned short, std::__1::allocator<unsigned short>>::iterator &cursor);

    void MoveToPrimaryEnd(bool envType, bool direction, std::vector<unsigned short>::iterator &cursor);

    std::vector<unsigned short>::iterator cursorPos;

    std::vector<unsigned short> tokenStream;

};


#endif //JCALC_INPUTPARSER_H
