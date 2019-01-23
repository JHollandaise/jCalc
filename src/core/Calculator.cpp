//
// Created by Joseph Holland  on 09/04/2018.
//

#include "Calculator.h"
#include "input/buttonMaps/Maths.h"
#include "input/buttonMaps/BaseN.h"
#include "GUI/tigr.h"
#include "input/MenuPage.h"


void Calculator::ManageUserInput() {


    // user menu selection
    unsigned short menuSelection(0x0000);

    try {
        switch (currentButtonToken & 0xFF00U) {
            case 0x0000 :
                // NULL token
                // nothing pressed so just refresh the screen
                graphicsController.PrintTokenStream(inputParser.GetTokenStream());
                break;
            case 0x5000 :
                // executions
                // TODO: add special execute tokens (M+ etc...)
                // TODO: add error handle in here
                CalculateResult();
                break;
            case 0x5100 :
                if (currentButtonToken == 0x5100) {
                    // DEL key
                    inputParser.DelFromStream();
                    break;
                } else if (currentButtonToken == 0x5101) {
                    // AC key
                    inputParser.ClearStream();
                    break;
                }
                throw std::range_error("invalid user input: ManageUserInput");

            case 0x5200 :
                // change button map
                switch (currentButtonToken) {
                    case 0x5200 :
                        ManageUserInput(&ButtonMapMaths::RCL);
                        break;
                    case 0x5201 :
                        ManageUserInput(&ButtonMapMaths::Shift);
                        break;
                    case 0x5202 :
                        ManageUserInput(&ButtonMapMaths::Alpha);
                        break;
                    case 0x5203 :
                        ManageUserInput(&ButtonMapsBaseN::Shift);
                        break;
                    case 0x5204 :
                        ManageUserInput(&ButtonMapsBaseN::Alpha);
                        break;
                    default:
                        throw std::range_error("invalid user input: ManageUserInput");
                }
            case 0x5400 :
                // manage menu selection
                ManageMenuInput();
                break;
            case 0x5500 :
                // move cursor
                if (currentButtonToken == 0x5500) {
                    inputParser.MoveCursorLeft();
                    break;
                }
                    // TODO: add move cursor up/down
                else if (currentButtonToken == 0x5503) {
                    inputParser.MoveCursorRight();
                    break;
                }
                throw std::range_error("invalid user input: ManageUserInput");
            case 0x5600 :
                // toggle insert mode
                // TODO: add check for end of stream
                inputMethod = !inputMethod;
                break;
            case 0x5800 :
                calcMode = currentButtonToken;
            default :
                // this will throw appropriate range exception
                // add to stream
                inputParser.AddToStream(currentButtonToken, &inputMethod);

        }
    }
    catch (const std::range_error& e) {
        errorManager.AddToStream(&e);
    }

    graphicsController.PrintTokenStream(inputParser.GetTokenStream());

}

void Calculator::ManageUserInput(std::map<unsigned char, unsigned short> *buttonMap) {
    try {
        currentButtonToken = userInputController.GetUserInput(buttonMap);
    }
    catch(const std::range_error &e) {
        errorManager.AddToStream(&e);
    }

    return ManageUserInput();
}


void Calculator::ManageMenuInput() {
    MenuPage* selectedMenu;

    switch(currentButtonToken) {
        case 0x5400 :
            // hyperbolic
            selectedMenu = &MenuPages::hyperbolic;
            break;
        case 0x5401 :
            // mode
            selectedMenu = &MenuPages::mode;
            break;
        case 0x5402 :
            // drg
            selectedMenu = &MenuPages::drg;
            break;
        case 0x5406 :
            // setup
            selectedMenu = &MenuPages::setup;
        // TODO: implement remaining menus
    }

    // provide IO to menu
    selectedMenu->setIOControllers(&graphicsController,&userInputController);

}

unsigned char Calculator::CalculateResult() {

    // TODO: this makes no sense, move to Evaluator
    evalCursor = inputParser.GetTokenStream()->begin();
    tokenStreamEnd = inputParser.GetTokenStream()->end();
    evaluator.evalCursor = &evalCursor;
    evaluator.tokenStreamEnd = &tokenStreamEnd;
    unsigned char returnError;

    CalculationResult currentResult(0);
    for (;;) {
        currentResult=evaluator.Expr(false);
        // TODO: clean up result at end

        if(!(returnError = evaluator.returnError)) {
            resultHistory.push_back(currentResult);
            if (*(++evalCursor) != 0x1900) break;
        }
    }

    return returnError;
}

unsigned char Calculator::Mainloop() {


    // manage current user input
    // TODO: multithreading?
    try {
        ManageUserInput(GetDefaultButtonMap());
    }
    catch (const std::range_error& e){
        // add error to errorStream
        errorManager.AddToStream(&e);
    }


    // TODO: manage returnError.
    return 0;
}

std::map<unsigned char, unsigned short> * Calculator::GetDefaultButtonMap(){
    switch (calcMode) {
        case 0x5800 :
            return &ButtonMapMaths::Default;

        //TODO: implement remaining button maps x (CMPLX etc.)
        case 0x5803 :
            return &ButtonMapsBaseN::Default;
        default:
            throw std::range_error("invalid calcMode");
    }
}



