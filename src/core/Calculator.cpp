//
// Created by Joseph Holland  on 09/04/2018.
//

#include <iostream>
#include "Calculator.h"
#include "../input/buttonMaps/Maths.h"

Error Calculator::ManageUserInput() {

    if(userInputController.GetUserInput()!=255)
        currentButton = {userInputController.GetModifier(), userInputController.GetLastButtonPress()};
    else return {}; // TODO: implement invalid user input error

    short buttonToken = (*userInputController.GetCurrentButtonMap())[currentButton.value];

    // simple tokens (add to stream)
    if(buttonToken<0x1000) inputParser.AddToStream(currentButton);
    return {}; // TODO: create fallthrough error
}

Error Calculator::SetCalculatorBase()
{
    // TODO: implement setting calc base given a button

    calculatorBase = InputDefs::CalculatorBase::decimal;

    return {};
}
