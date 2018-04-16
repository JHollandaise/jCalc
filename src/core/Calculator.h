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
#include "../GUI/GraphicsController.h"

/**
 * Manages the control of action depending on user input and configuration options.
 *
 * @brief Main manager class
 */
class Calculator {

public:
    Calculator(): userInputController(), inputParser(),
                  calcMode(0x5800),
                  inputMethod(true),
                  calculatorBase(0x5C00),
                  currentButtonToken(0x0000U) {};

    /**
     * Takes a given user input and determines the next operation the calculator will carry out.
     *
     * @param buttonMap button press -> token
     * @return error code (0 for successful)
     */
    unsigned char ManageUserInput();
    unsigned char ManageUserInput(std::map< unsigned char, unsigned short>* buttonMap);

    unsigned char Mainloop();


private:

    std::map< unsigned char, unsigned short>* GetDefaultButtonMap();

    unsigned char returnError;

    UserInputController userInputController;

    GraphicsController graphicsController;

    InputParser inputParser;

    unsigned short calcMode;

    unsigned short calculatorBase;

    // insert(1)/replace(0)
    bool inputMethod;

    unsigned short currentButtonToken;

    unsigned short GetMenuToken(unsigned char page, unsigned short selectedOption);
    unsigned short GetMenuToken(unsigned char page);

    unsigned  char CalculateResult();



};


#endif //JCALC_CALCULATOR_H
