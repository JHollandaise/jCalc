//
// Created by Joseph Holland  on 09/04/2018.
//

#include "InputParser.h"

unsigned char InputParser::AddToStream(unsigned short token, bool *inputMethod)
{

    // if insert mode
    if(*inputMethod)
        cursorPos = tokenStream.insert(cursorPos,token) + 1;

    // replace mode
    else {
        // at end, add element
        if (cursorPos == tokenStream.end()){
            tokenStream.push_back(token);
            cursorPos = tokenStream.end();
        }

        // otherwise replace
        else *(cursorPos++) = token;
    }

    // TODO: error handling for AddToStream
    return {};
}

unsigned char InputParser::DelFromStream() {

    if (!tokenStream.empty()) cursorPos = tokenStream.erase(cursorPos-1);

    return 0;
}

unsigned char InputParser::ClearStream() {

    tokenStream.clear();

    cursorPos = tokenStream.end();
    return 0;
}

unsigned char InputParser::MoveCursorRight() {

    return MoveCursorRight(1);
}

unsigned char InputParser::MoveCursorRight(int distance) {

    if(cursorPos != tokenStream.end()) cursorPos += distance;

    return 0;
}

unsigned char InputParser::MoveCursorLeft(int distance) {

    if(cursorPos != tokenStream.begin()) cursorPos-= distance;

    return 0;
}

unsigned char InputParser::MoveCursorLeft() {

    return MoveCursorLeft(1);
}
