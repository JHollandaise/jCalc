//
// Created by Joseph Holland  on 09/04/2018.
//

#ifndef JCALC_CALCULATOR_H
#define JCALC_CALCULATOR_H

#include "../ErrorMgt/Error.h"
#include "../input/InputParser.h"
#include "../input/UserInputController.h"
#include "../input/Button.h"
#include "../InputDefs.h"

class Calculator {

public:
    Calculator(): userInputController(), inputParser(),
                  calcMode(InputDefs::CalcMode::maths),
                  calculatorBase(InputDefs::CalculatorBase::decimal) {};

    Error ManageUserInput(bool getInput);

private:

    void SetCalcMode(InputDefs::CalcMode newCalcMode) {calcMode = newCalcMode;}

    Error SetCalculatorBase();

    UserInputController userInputController;

    InputParser inputParser;

    InputDefs::CalcMode calcMode;

    InputDefs::CalculatorBase calculatorBase;

    // insert(1)/replace(0)
    bool inputMethod;

    unsigned short currentButtonToken;

    unsigned short GetMenuToken(unsigned char page, unsigned short selectedOption);
    unsigned short GetMenuToken(unsigned char page);



};


#endif //JCALC_CALCULATOR_H
