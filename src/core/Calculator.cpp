//
// Created by Joseph Holland  on 09/04/2018.
//

#include "Calculator.h"
#include "../input/buttonMaps/Maths.h"
#include "../input/buttonMaps/Menu.h"
#include "../input/buttonMaps/BaseN.h"
#include "../GUI/tigr.h"


unsigned char Calculator::ManageUserInput() {


    // user menu selection
    unsigned short menuSelection(0x0000);

    switch (currentButtonToken & 0xFF00U){
        case 0x0000 :
            // NULL token
            // TODO: add error throw
            break;
        case 0x5000 :
            // executions
            // TODO : add special execute tokens (M+ etc...)
            // TODO : add error handle in here
            CalculateResult();
            break;
        case 0x5100 :
            if(currentButtonToken == 0x5100) {
                // DEL key
                inputParser.DelFromStream();
            } else if(currentButtonToken == 0x5101) {
                // AC key
                inputParser.ClearStream();
            }
            // TODO: manage exception (else)
            break;
        case 0x5200 :
            // change button map
            switch (currentButtonToken) {
                case 0x5200 :
                    ManageUserInput(&ButtonMapMaths::RCL);
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
                    break;
            }
            break;
        case 0x5400 :
            // open menu
            if ( (currentButtonToken & 0xFF00U) == 0x5400 ) {
                while(!(menuSelection = GetMenuToken(0))){
                    // TODO: implement incorrect option flash
                }
                currentButtonToken = menuSelection;

                return ManageUserInput();
            }
            break;
        case 0x5500 :
            // move cursor
            if(currentButtonToken == 0x5500) {
                inputParser.MoveCursorLeft();
            }
            // TODO: add move cursor up/down
            else if(currentButtonToken == 0x5503) {
                inputParser.MoveCursorRight();
            }
            break;
        case 0x5600 :
            // toggle insert mode
            // TODO: add check for end of stream
            inputMethod = !inputMethod;
            break;
        case 0x5800 :
            calcMode = currentButtonToken;
        default :
            // add to stream
            inputParser.AddToStream(currentButtonToken,&inputMethod);

    }
    graphicsController.PrintTokenStream(inputParser.GetTokenStream(),screen);
    // TODO: error handling
    return 0;

}

unsigned char Calculator::ManageUserInput(std::map<unsigned char, unsigned short> *buttonMap) {

    currentButtonToken = userInputController.GetUserInput(buttonMap,screen);

    return ManageUserInput();
}


unsigned short Calculator::GetMenuToken(unsigned char page) {
    return GetMenuToken(page,currentButtonToken);
}

unsigned short Calculator::GetMenuToken(unsigned char page, unsigned short selectedOption) {

    std::vector<std::map<unsigned char, unsigned short> >* menuMap;

    unsigned short newSelection;

    switch (selectedOption){
        // hyperbolic menu
        case 0x5400 :
            menuMap = &ButtonMapMenu::Hyperbolic;
            break;

        // mode menu
        case 0x5401 :
            menuMap = &ButtonMapMenu::Mode;
            break;

        // DRG menu
        case 0x5402:
            menuMap = &ButtonMapMenu::DRG;
            break;

        // const menu
        case 0x5403 :
            menuMap = &ButtonMapMenu::ConstantCategory;
            break;

        // conv menu
        case 0x5404:
            menuMap = &ButtonMapMenu::ConvertCategory;
            break;

        // clear menu
        case 0x5405:
            menuMap = &ButtonMapMenu::Clear;
            break;

        // setup menu
        case 0x5406:
            menuMap = &ButtonMapMenu::SetupCategory;
            break;

        // baseN menu
        case 0x5407:
            menuMap = &ButtonMapMenu::BaseN;
            break;

        // const menu -> category
        case 0x3000:
        case 0x3001:
        case 0x3002:
        case 0x3003:
        case 0x3004:
        case 0x3005:
            menuMap = &ButtonMapMenu::ConstantValue;
            break;

        // convert menu -> category
        case 0x3100:
        case 0x3101:
        case 0x3102:
        case 0x3103:
        case 0x3104:
        case 0x3105:
        case 0x3106:
        case 0x3107:
        case 0x3108:
            menuMap = &ButtonMapMenu::ConvertValue;
            break;

        // setup Menu -> category
        case 0x3200:
        case 0x3201:
        case 0x3202:
        case 0x3203:
        case 0x3204:
        case 0x3205:
        case 0x3206:
        case 0x3207:
        case 0x3208:
        case 0x3209:
        case 0x320A:
        case 0x320B:
        case 0x320C:
        case 0x320D:
        case 0x320E:
            menuMap = &ButtonMapMenu::SetupValue;
            break;

        default:
            return 0x0000;
    }

    // TODO: show graphical menu

    // get selection from user
    newSelection = userInputController.GetUserInput(&((*menuMap)[page]),screen);

    // check for page change
    // page up
    if(newSelection == 0x5502) {
        // get the menu for the same selectedOption but prev page
        if(page) return GetMenuToken(page - (char)1,selectedOption);

        // TODO: show incorrect option
        return GetMenuToken(page,selectedOption);
    }
    // page down
    else if(newSelection == 0x5501) {
        // get the menu for the same selectedOption but next page
        if(page + 1 != menuMap->size() ) return GetMenuToken(page + (char)1, selectedOption);

        // TODO: show incorrect option
        return GetMenuToken(page,selectedOption);
    }

    // multi-depth (INCLUDE REMAINING OPTIONS)
    else if((newSelection & 0xF000U ) == 0x3000)
        {
        // get correct lower depth menu page
        return GetMenuToken( (unsigned char)(newSelection & (0x00FFU) ), newSelection);
    }

    // newSelection is a selectable option
    else return newSelection;

}

unsigned char Calculator::CalculateResult() {

    evalCursor = inputParser.GetTokenStream()->begin();
    tokenStreamEnd = inputParser.GetTokenStream()->end();
    evaluator.evalCursor = &evalCursor;
    evaluator.tokenStreamEnd = &tokenStreamEnd;
    unsigned char returnError;

    CalculationResult currentResult(0);
    for (;;) {
        currentResult=evaluator.Expr(false);

        if(!(returnError = evaluator.returnError)) {
            resultHistory.push_back(currentResult);
            if (*(++evalCursor) != 0x1900) break;
        }
    }

    return returnError;
}

unsigned char Calculator::Mainloop(Tigr *bmp) {

    unsigned char returnError;

    screen = bmp;
    ManageUserInput(GetDefaultButtonMap());


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
            return nullptr;
    }
}



