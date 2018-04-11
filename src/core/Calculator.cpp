//
// Created by Joseph Holland  on 09/04/2018.
//

#include <iostream>
#include "Calculator.h"

Error Calculator::ManageUserInput() {

    if(userInputController.GetUserInput()!=255)
        currentButton = {userInputController.GetModifier(), userInputController.GetLastButtonPress()};
    else return {}; // TODO: implement invalid user input error

    if (calcMode==InputDefs::CalcMode::complex){
        if(userInputController.GetShiftPressed()){
            switch (static_cast<InputDefs::ButtonDefsComplexShift >(currentButton.value)) {
                case InputDefs::ButtonDefsComplexShift::imaginary :
                case InputDefs::ButtonDefsComplexShift::arguement :
                    return inputParser.AddToStream(&currentButton);

                case InputDefs::ButtonDefsComplexShift::complexMenu:
                    return OpenMenu();

                case InputDefs::ButtonDefsComplexShift::IGNORE0:
                case InputDefs::ButtonDefsComplexShift::IGNORE2:
                case InputDefs::ButtonDefsComplexShift::IGNORE3:
                case InputDefs::ButtonDefsComplexShift::IGNORE4:
                case InputDefs::ButtonDefsComplexShift::IGNORE5:
                case InputDefs::ButtonDefsComplexShift::IGNORE41:
                case InputDefs::ButtonDefsComplexShift::IGNORE10:
                case InputDefs::ButtonDefsComplexShift::IGNORE11:
                case InputDefs::ButtonDefsComplexShift::IGNORE12:
                case InputDefs::ButtonDefsComplexShift::IGNORE15:
                case InputDefs::ButtonDefsComplexShift::IGNORE25:
                case InputDefs::ButtonDefsComplexShift::IGNORE32:
                case InputDefs::ButtonDefsComplexShift::IGNORE56:
                case InputDefs::ButtonDefsComplexShift::IGNORE60:
                case InputDefs::ButtonDefsComplexShift::IGNORE61:
                case InputDefs::ButtonDefsComplexShift::IGNORE62:
                case InputDefs::ButtonDefsComplexShift::IGNORE63:
                case InputDefs::ButtonDefsComplexShift::IGNORE65:
                case InputDefs::ButtonDefsComplexShift::IGNORE66:
                case InputDefs::ButtonDefsComplexShift::IGNORE70:
                case InputDefs::ButtonDefsComplexShift::IGNORE71:
                case InputDefs::ButtonDefsComplexShift::IGNORE72:
                case InputDefs::ButtonDefsComplexShift::IGNORE73:
                case InputDefs::ButtonDefsComplexShift::IGNORE74:
                case InputDefs::ButtonDefsComplexShift::IGNORE75:
                case InputDefs::ButtonDefsComplexShift::IGNORE76:
                    return {}; //TODO: make ignore button press error

                default:
                    // all NULL fall here
                    break;
            }
        }else if(!userInputController.GetAlphaPressed()){
            switch (static_cast<InputDefs::ButtonDefsComplex >(currentButton.value)) {
                case InputDefs::ButtonDefsComplex::IGNORE5 :
                case InputDefs::ButtonDefsComplex::IGNORE15 :
                case InputDefs::ButtonDefsComplex::IGNORE25 :
                case InputDefs::ButtonDefsComplex::IGNORE56 :
                case InputDefs::ButtonDefsComplex::IGNORE60 :
                case InputDefs::ButtonDefsComplex::IGNORE61 :
                case InputDefs::ButtonDefsComplex::IGNORE66 :
                case InputDefs::ButtonDefsComplex::IGNORE75 :
                case InputDefs::ButtonDefsComplex::IGNORE76 :
                    return {}; //TODO: make ignore button press error

                default:
                    // all NULL fall here
                    break;
            }
        } // in case that user has pressed alpha complex alpha is same as standard alpha

    } else if (calcMode==InputDefs::CalcMode::baseN)
    {
        if(userInputController.GetShiftPressed()) {
            switch (static_cast<InputDefs::ButtonDefsBaseNShift>(currentButton.value)) {
                case InputDefs::ButtonDefsBaseNShift::baseNMenu:
                    return OpenMenu();

                case InputDefs::ButtonDefsBaseNShift::hexA:
                case InputDefs::ButtonDefsBaseNShift::hexB:
                case InputDefs::ButtonDefsBaseNShift::hexC:
                case InputDefs::ButtonDefsBaseNShift::hexD:
                case InputDefs::ButtonDefsBaseNShift::hexE:
                case InputDefs::ButtonDefsBaseNShift::hexF:
                    return inputParser.AddToStream(&currentButton);

                case InputDefs::ButtonDefsBaseNShift::decimal:
                case InputDefs::ButtonDefsBaseNShift::hexedecimal:
                case InputDefs::ButtonDefsBaseNShift::binary:
                case InputDefs::ButtonDefsBaseNShift::octal:
                    return SetCalculatorBase();

                case InputDefs::ButtonDefsBaseNShift::clear :
                case InputDefs::ButtonDefsBaseNShift::insert :
                case InputDefs::ButtonDefsBaseNShift::off :
                    // default to basic action
                    break;

                default:
                    // INGORE cases fall here
                    return {}; // TODO: make ignore button press error
            }
        } else if (userInputController.GetAlphaPressed()) {
            switch (static_cast<InputDefs::ButtonDefsBaseNAlpha>(currentButton.value)) {
                case InputDefs::ButtonDefsBaseNAlpha::varX :
                case InputDefs::ButtonDefsBaseNAlpha::varY :
                case InputDefs::ButtonDefsBaseNAlpha::varM :
                case InputDefs::ButtonDefsBaseNAlpha::varA :
                case InputDefs::ButtonDefsBaseNAlpha::varB :
                case InputDefs::ButtonDefsBaseNAlpha::varC :
                case InputDefs::ButtonDefsBaseNAlpha::varD :
                case InputDefs::ButtonDefsBaseNAlpha::varE :
                case InputDefs::ButtonDefsBaseNAlpha::varF :
                    return inputParser.AddToStream(&currentButton);
                default:
                    // IGNORE cases fall here
                    return {}; // TODO: make ignore button press error
            }
        } else {
            switch (static_cast<InputDefs::ButtonDefsBaseN>(currentButton.value)) {
                case InputDefs::ButtonDefsBaseN::hexA:
                case InputDefs::ButtonDefsBaseN::hexB:
                case InputDefs::ButtonDefsBaseN::hexC:
                case InputDefs::ButtonDefsBaseN::hexD:
                case InputDefs::ButtonDefsBaseN::hexE:
                case InputDefs::ButtonDefsBaseN::hexF:
                    return inputParser.AddToStream(&currentButton);

                case InputDefs::ButtonDefsBaseN::decimal:
                case InputDefs::ButtonDefsBaseN::hexedecimal:
                case InputDefs::ButtonDefsBaseN::binary:
                case InputDefs::ButtonDefsBaseN::octal:
                    return SetCalculatorBase();


                case InputDefs::ButtonDefsBaseN::IGNORE5:
                case InputDefs::ButtonDefsBaseN::IGNORE15:
                case InputDefs::ButtonDefsBaseN::IGNORE25:
                case InputDefs::ButtonDefsBaseN::IGNORE26:
                case InputDefs::ButtonDefsBaseN::IGNORE31:
                case InputDefs::ButtonDefsBaseN::IGNORE34:
                case InputDefs::ButtonDefsBaseN::IGNORE36:
                case InputDefs::ButtonDefsBaseN::IGNORE50:
                case InputDefs::ButtonDefsBaseN::IGNORE51:
                case InputDefs::ButtonDefsBaseN::IGNORE56:
                case InputDefs::ButtonDefsBaseN::IGNORE60:
                case InputDefs::ButtonDefsBaseN::IGNORE61:
                case InputDefs::ButtonDefsBaseN::IGNORE64:
                case InputDefs::ButtonDefsBaseN::IGNORE65:
                case InputDefs::ButtonDefsBaseN::IGNORE66:
                case InputDefs::ButtonDefsBaseN::IGNORE75:
                case InputDefs::ButtonDefsBaseN::IGNORE76:
                    return {}; // TODO: make ignore button press error

                default:
                    // all of NULL## fall in here
                    break;
            }
        }

    } // TODO: implement all other calculator modes
    else {
        // all fallthrough and maths mode
        if(userInputController.GetShiftPressed()){
            switch (static_cast<InputDefs::ButtonDefsShift>(currentButton.value)) {
                case :
            }
        }
    }
    return {}; // TODO: create fallthrough error
}

Error Calculator::SetCalculatorBase()
{
    // TODO: implement setting calc base given a button

    calculatorBase = InputDefs::CalculatorBase::decimal;

    return {};
}
