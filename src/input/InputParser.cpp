//
// Created by Joseph Holland  on 09/04/2018.
//

#include "InputParser.h"

unsigned char InputParser::AddToStream(unsigned short token, bool *inputMethod)
{
    // token :: token to add to stream
    // inputMethod :: FALSE: normal add; TRUE: insert mode
        // places followng tokens into added function

    switch (token & 0xF000U) {
        case 0x1000 :
            // simple token -> just add to stream and move right 1 space
            cursorPos = tokenStream.insert(cursorPos,token) + 1;
            break;
        case 0x2000 :
            switch (token & 0xFF00U) {
                case 0x2000 :
                case 0x2100 :
                case 0x2200 :
                case 0x2500 :
                case 0x2600 :
                case 0x2700 :
                    // Simple single token functions
                    cursorPos = tokenStream.insert(cursorPos,token) + 1;
                    break;
                case 0x2300 :
                    // more interesting functions
                    if(token == 0x2300) {
                        // FRAC

                        // store current position
                        auto startPos(cursorPos);
                        MoveToFuncInsertPointLeft();




                    }
                // TODO: default case
            }
    // TODO: default case (exception: unexpected token)
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

void InputParser::MoveToFuncInsertPointLeft() {
    // move left until we hit a breaker (+,-,*, etc)
    // if at beginning, stop
    int parenthCount(0);
    int funcParenthCount(0);
    bool exitLoop(false);

    while( ((cursorPos--) != tokenStream.begin()) && (parenthCount>=0 || funcParenthCount >= 0)) {
        switch(*(cursorPos) & 0xFF00U){
            case 0x1500 :
                // close parenthesis
                // if parenth: parenth level increase
                if(*(cursorPos) == 0x1500) GoToOpenParenthesis();

                // if func parenth: func parenth level increase
                if(*(cursorPos) == 0x1501) GoToFuncInitiator();
                break;
            case 0x1200 :
                // +, -
            case 0x1300 :
                // (-)
            case 0x1400 :
                // func separator
            case 0x1800 :
                // *, /
            case 0x1900 :
                // :, =

                // leave here if not in parenth
                if(parenthCount == 0 && funcParenthCount == 0) exitLoop = true;
                else{
                    // TODO: ERRRORRRRSS
                }
                break;
            default:
                //otherwise do nothing
                break;

        }
    }
    // move forward to correct
    // TODO: move backward (direction dependant)
    cursorPos++;
}

