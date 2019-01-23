//
// Created by Joseph Holland  on 09/04/2018.
//

#ifndef JCALC_CALCULATOR_H
#define JCALC_CALCULATOR_H

#include "errorMgt/ErrorManager.h"
#include "input/InputParser.h"
#include "input/UserInputController.h"
#include "input/Button.h"
#include "InputDefs.h"
#include "GUI/GraphicsController.h"
#include "CalculationResult.h"
#include "Evaluator.h"
#include "GUI/tigr.h"

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
                               calculatorBase(0x5B00),
                               currentButtonToken(0x0000U),
                               evaluator(&evalCursor),
                               graphicsController(),
                               errorManager(&graphicsController){};
    /**
     * Takes a given user input and determines the next operation the calculator will carry out.
     *
     * @param buttonMap button press -> token
     * @return error code (0 for successful)
     */
    void ManageUserInput();
    void ManageUserInput(std::map< unsigned char, unsigned short>* buttonMap);

    /**
     * Primary loop for calculator operation
     * @param screen
     * @return
     */
    unsigned char Mainloop();


    // push initialised screen to objects
    void AddScreen(Tigr* screen) {graphicsController.SetScreen(screen); userInputController.SetScreen(screen);}


private:

    // holds onto any errors and controls the distribution of error messages
    ErrorManager errorManager;

    // returns, based on the current calcMode, the appropriate button to token map
    std::map< unsigned char, unsigned short>* GetDefaultButtonMap();

    // manages the conversion of physical user input to a coherent datastream
    UserInputController userInputController;

    // manages the pushing of data to screen
    GraphicsController graphicsController;

    // controls tokenStream layout from user input order
    InputParser inputParser;

    // manages mathematical result calculation
    Evaluator evaluator;

    // current operation mode (COMP, CMPLX, etc)
    unsigned short calcMode;

    // mathematical base (binary, dec, ..)
    unsigned short calculatorBase;

    // previous calculation history
    std::vector<CalculationResult> resultHistory;

    // ,
    std::vector<unsigned short>::iterator evalCursor;
    std::vector<unsigned short>::iterator tokenStreamEnd;

    // insert(1)/replace(0)
    bool inputMethod;

    // most recent user-input token
    unsigned short currentButtonToken;

    // perform menu related action
    void ManageMenuInput();

    unsigned  char CalculateResult();


};


#endif //JCALC_CALCULATOR_H
