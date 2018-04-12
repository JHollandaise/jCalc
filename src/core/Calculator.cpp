//
// Created by Joseph Holland  on 09/04/2018.
//

#include "Calculator.h"
#include "../input/buttonMaps/Maths.h"
#include "../input/buttonMaps/Menu.h"


Error Calculator::ManageUserInput(bool getInput) {

    unsigned short menuSelection(0x0000);

    // get new user input
    if (getInput){
        currentButtonToken = userInputController.GetUserInput();
    }
    // otherwise assume currentButtonToken is correct


    // NULL token
    if(currentButtonToken == 0x0000) return {};

    // simple tokens and functions (add to stream)
    if (
        // simple single tokens
        ((currentButtonToken & 0xFF00U) == 0x1000) ||

        // simple functions
        // Type 0 - Type 2
        ( ((currentButtonToken & 0xFF00U) >= 0x2000) && ((currentButtonToken & 0xFF00U) < 0x2300) ) ||
        // Type 5 - Type 7
        ( ((currentButtonToken & 0xFF00U) >= 0x2500) && ((currentButtonToken & 0xFF00U) < 0x2800) )
    )
        return inputParser.AddToStream(currentButtonToken, &inputMethod);

    // open menu
    // TODO: implement special menus
    if ( (currentButtonToken & 0xFF00U) == 0x5400 ) {
        while(!(menuSelection = GetMenuToken(0))){
            // TODO: implement incorrect option flash
        }
        currentButtonToken = menuSelection;

        return ManageUserInput(false);
    }

    return {}; // TODO: create fallthrough error
}




Error Calculator::SetCalculatorBase() {

    // TODO: implement SetCalculatorBase
    return Error();
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


