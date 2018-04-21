//
// Created by Joseph Holland  on 09/04/2018.
//

#include "Calculator.h"
#include "../input/buttonMaps/Maths.h"
#include "../input/buttonMaps/Menu.h"
#include "../input/buttonMaps/BaseN.h"


unsigned char Calculator::ManageUserInput() {


    unsigned char returnError;

    // user menu selection
    unsigned short menuSelection(0x0000);

    // NULL token
    if(currentButtonToken == 0x0000) return {};

    // simple tokens and functions (add to stream)
    if (
        // simple single tokens
        ((currentButtonToken & 0xF000U) == 0x1000) ||

        // simple functions
        // Type 0 - Type 2
        ( ((currentButtonToken & 0xFF00U) >= 0x2000) && ((currentButtonToken & 0xFF00U) < 0x2300) ) ||
        // Type 5 - Type 7
        ( ((currentButtonToken & 0xFF00U) >= 0x2500) && ((currentButtonToken & 0xFF00U) < 0x2800) )
    ) {
        returnError = inputParser.AddToStream(currentButtonToken, &inputMethod);
        graphicsController.PrintTokenStream(inputParser.GetTokenStream());
    }


    // TODO : implement Type 3 and Type 4 functions



    // execution command
    if((currentButtonToken & 0xFF00U) == 0x5000) {
        // TODO: implement special executions

        returnError = CalculateResult();

    }

    // DEL key
    if(currentButtonToken == 0x5100) {
        inputParser.DelFromStream();
        graphicsController.PrintTokenStream(inputParser.GetTokenStream());
        return 0;
    }

    // AC
    if(currentButtonToken == 0x5101) {
        inputParser.ClearStream();
        graphicsController.PrintTokenStream(inputParser.GetTokenStream());
        return 0;
    }

    if((currentButtonToken & 0xFF00U) == 0x5200) {
        switch (currentButtonToken) {
            case 0x5200 :
                returnError = ManageUserInput(&ButtonMapMaths::RCL);
            case 0x5201 :
                returnError = ManageUserInput(&ButtonMapMaths::Shift);
                break;
            case 0x5202 :
                returnError = ManageUserInput(&ButtonMapMaths::Alpha);
                break;
            case 0x5203 :
                returnError = ManageUserInput(&ButtonMapsBaseN::Shift);
                break;
            case 0x5204 :
                returnError = ManageUserInput(&ButtonMapsBaseN::Alpha);
                break;
            default:
                break;
        }
    }

    // open menu
    if ( (currentButtonToken & 0xFF00U) == 0x5400 ) {
        while(!(menuSelection = GetMenuToken(0))){
            // TODO: implement incorrect option flash
        }
        currentButtonToken = menuSelection;

        return ManageUserInput();
    }

    if(currentButtonToken == 0x5500) {
        inputParser.MoveCursorLeft();
        graphicsController.PrintTokenStream(inputParser.GetTokenStream());
    }

    if(currentButtonToken == 0x5503) {
        inputParser.MoveCursorRight();
        graphicsController.PrintTokenStream(inputParser.GetTokenStream());
    }

    // change calculator mode
    if( (currentButtonToken & 0xFF00U) == 0x5800 )
        calcMode = currentButtonToken;


    return returnError; // TODO: create fallthrough error
}

unsigned char Calculator::ManageUserInput(std::map<unsigned char, unsigned short> *buttonMap) {

    currentButtonToken = userInputController.GetUserInput(buttonMap);

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
    newSelection = userInputController.GetUserInput(&((*menuMap)[page]));

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

    unsigned char returnError;


    for (;;) {
        // TODO: add assignment to CalculationResult
        CalculationResult currentResult(evaluator.Expr(false));

        if(!(returnError = evaluator.returnError)) {
            resultHistory.push_back(currentResult);
            if (*(++evalCursor) != 0x1900) break;
        }
    }

    return returnError;
}

unsigned char Calculator::Mainloop() {

    unsigned char returnError;

    while(!(returnError = ManageUserInput(GetDefaultButtonMap()) ) );

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
            // Flora is (not) Gay?
            return nullptr;
    }
}



