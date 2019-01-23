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
                case 0x2400 :
                    // more interesting functions

                    // stuff | stuff

                    if(token == 0x2300) {
                        // FRAC has the additional functionality of grabbing left

                        // get cursorPos index as insertions can corrupt iterators
                        auto cursorPosIndex(cursorPos - tokenStream.begin());
                        // move 2 to the right to account for inserted elements
                        cursorPosIndex += 2;

                        // insert FRAC separator
                        // and move to left of separator
                        cursorPos = tokenStream.insert(cursorPos, 0x1401) - 1;


                        // move cursor to beginning of left grab sequence
                        MoveOutOfPrimaryChain(false, cursorPos);
                        // add frac func identifier at beginning of left grab sequence
                        tokenStream.insert(cursorPos, 0x2300);

                        // move to after FRAC separator
                        cursorPos = tokenStream.begin() + cursorPosIndex;

                        // frac( stuff , | stuff
                    }
                    else {
                        // if a power function, insert xpowery function initiator
                        if((token & 0xFF00U) == 0x2400) cursorPos = tokenStream.insert(cursorPos,0x2401) + 1;
                        // if cubert, insert xrooty function initiator
                        if(token  == 0x2306) cursorPos = tokenStream.insert(cursorPos,0x2307) + 1;
                        // otherwise insert this function token
                        else cursorPos = tokenStream.insert(cursorPos,token) + 1;

                        // stuff func( | stuff
                    }

                    // we need to return here after insert
                    auto savedPos = cursorPos;

                    if( ( (token & 0xFF00) == 0x2300 && inputMethod )
                    || token == 0x2401) {
                        // with insert mode, grab sequence to right and place in first argument (excluding frac
                        // which is in second pos)

                        // move cursor to end of right grab sequence
                        MoveOutOfPrimaryChain(true, cursorPos);

                        // stuff func( stuff |
                        // or frac( stuff , stuff |
                    }


                    // if square do pow of 2
                    // stuff pow( 2 |
                    if(token==0x2400) cursorPos = tokenStream.insert(cursorPos,0x1002) + 1;
                    // if cube do pow of 3
                    if(token==0x2403) cursorPos = tokenStream.insert(cursorPos,0x1003) + 1;
                    // if reciprocal do pow -1
                    if(token==0x2400) cursorPos = tokenStream.insert(cursorPos,{0x1300,0x1001}) + 2;

                    if(token==0x2302 || token==0x2303 || token==0x2306 || token==0x2307 || token==0x230A ||
                       token==0x230B) {
                        // functions with >= 2 args (except frac)

                        // insert separator and move one to right
                        cursorPos =tokenStream.insert(cursorPos, 0x1402) + 1;

                        // stuff func( stuff? , |
                    }

                    // if cubert do nthroot 3
                    // stuff func( stuff? , 3 |
                    if(token == 0x2306) cursorPos = tokenStream.insert(cursorPos,0x1003) + 1;

                    if(token == 0x2302 || token == 0x230B) {
                        // funcs with 3 args
                        cursorPos =tokenStream.insert(cursorPos, 0x1402) + 1;

                        // stuff func( stuff? , , |
                    }

                    // add func close at end
                    // stuff func(stuff? (,,) ) |
                    // or frac(stuff , stuff ) |
                    tokenStream.insert(cursorPos, 0x1501);

                    // return cursor to rightful place
                    cursorPos = savedPos;

                    break;
                    // TODO: default case
            }
        default:
            break;
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

void InputParser::MoveOutOfPrimaryChain(bool direction, std::vector<unsigned short>::iterator &cursor) {
    // direction :: false: move left; true: move right

    // cursor should start on the first token of the chain

    // move until we hit the end of a
    // if at beginning, stop

    bool exitLoop(false);

    // keep moving in direction until we reach end of primary chain
    while(true) {
        switch((*cursor) & 0xFF00U){
            case 0x1200 :
                // '+' '-'
            case 0x1300 :
                // '-' unary
            case 0x1400 :
                // separator
            case 0x1800 :
                // '*' '/'
            case 0x1900 :
                // ':' '='

                // end here
                exitLoop = true;
                break;

            case 0x1500 :
                //terminators

                // moving right, end here
                if(direction) exitLoop = true;
                // then left
                // move to other side of appropriate environment
                else MoveToPrimaryEnd(*cursor != 0x1500, false, cursor);
                break;

            case 0x1700 :
                // open parenthesis
            case 0x2200 :
                // parenthesis func initialiser

                // if left, exit here
                if(!direction) exitLoop = true;

                // then right
                // move out of parenthesis env
                else MoveToPrimaryEnd(false, true, cursor);

                break;
            case 0x2300 :
            case 0x2400:
                // function initator

                // moving left, end here
                if(!direction) exitLoop = true;

                // otherwise, move through environment
                else MoveToPrimaryEnd(true, true, cursor);

                break;
            default:
                break;
                // otherwise, ignore
        }

        // if moving right and not at end of stream, move 1 more to right to exit primary
        if(direction) {
            if (cursor != tokenStream.end()) cursor++;
            else exitLoop = true;
        }
        // otherwise moving left and not at beginning move one more to left to exit
        else if((cursor != tokenStream.begin() )) cursor--;
        else exitLoop = true;


        if(exitLoop) break;
    }
    // move forward to correct pos
    // TODO: move backward (direction dependant)

}

void InputParser::MoveToPrimaryEnd(bool envType, bool direction, std::vector<unsigned short>::iterator &cursor) {
    // move cursor to other side of relevant Primary environment
    // ie  ->(123012 +) to (123012 + ->) for parenthesis primary
    // and ->frac( 2123 , 2398 *) to frac( 2123 , 2398 ->*)

    // envtype :: false: parenthesis environment; true: function environment
    // direction :: false: move left; true: move right

    // cursor should start on the environment initiator (ie on a '(' or 'f(' for moving right
    // and a ')' or '*)' for left

    // cursor will finish on the environment terminator ( on a ')' etc)

    // if we land inside of a func environment, ignore all parenthesis until we leave.
    // due to the nature of func environments, they MUST be terminated at both ends to be valid


    bool exitLoop(false);

    // count depth of parenthesis
    int parenthDepth(0);
    // count depth of func
    int funcDepth(0);

    // move in direction until we escape environment
    while(true){
        // move cursor in correct direction
        if(direction) cursor++;
        else cursor--;

        // if we are at tokenStream.begin(), exit here
        if(cursor == tokenStream.begin()) break;

        // if we are at tokenStream.end(), exit here
        if(cursor == tokenStream.end()) break;

        switch(*cursor & 0xFF00U) {
            case 0x1400 :
                // separator
                // if we see a function separator and we are in parenth mode, end here
                if( ((*cursor == 0x1401) || (*cursor == 0x1402)) && !envType ){
                    exitLoop = true;
                    break;
                }
                break;

            case 0x1500 :
                // terminators

                // close parenthesis
                // in func mode, ignore
                // if inside a func, ignore
                if((*cursor == 0x1500) && !envType && funcDepth==0) {
                    // if moving right, decrease parenthesis depth and check for exit
                    if(direction) {
                        // if we leave depth, exit loop
                        if ((--parenthDepth) <= 0){
                            exitLoop = true;
                            break;
                        }
                    }
                    // moving left, increase depth
                    else {
                        parenthDepth++;
                    }
                }
                // function terminator
                else if(*cursor == 0x1501) {
                    // moving left, increase funcDepth
                    if(!direction) funcDepth++;
                    // in func mode decrease depth and exit check
                    else if(envType) {
                        if((--funcDepth)==0) {
                            exitLoop = true;
                            break;
                        }
                    }
                    // parenthesis mode right -> exit loop
                    else exitLoop = true;
                }
                break;

            case 0x1700 :
                // open parenth
            case 0x2200 :
                // parenth func initialisers

                // in func mode, ignore
                // inside a func, ignore
                if(!envType && funcDepth==0) {

                    // if moving right, increase parenthesis depth
                    if(direction) parenthDepth++;
                    // if moving left, decrease parenthesis depth and check for exit
                    else if((--parenthDepth) <= 0) {
                        exitLoop = true;
                        break;
                    }
                }
                break;
            case 0x1900 :
                // expression separators

                // if in func mode, ignore
                // inside a func, ignore
                if(!envType && funcDepth == 0) {
                    // either direction, this marks the end of the parenthesis environment
                    exitLoop = true;
                    break;
                }
                break;

            case 0x2300 :
                // type 3 func initialisers
            case 0x2400 :
                // type 4 func initialisers

                // if moving right, increase funcDepth
                if(direction) {
                    funcDepth++;
                }
                // otherwise, if in func mode, decrease funcDepth and test exit
                else if(envType){
                    if((funcDepth--)==0) {
                        exitLoop = true;

                    }
                }
                // otherwise -> we are left and in parenthesis so leave environment
                else {
                    exitLoop = true;
                }

                break;
            default:
                // otherwise, do nothing
                break;
        }

        if(exitLoop) break;
    }

}

