//
// Created by Joseph Holland  on 10/04/2018.
//

#ifndef JCALC_INITIALISER_H
#define JCALC_INITIALISER_H


#include "../core/Calculator.h"
#include "TermInit.h"
#include "MbedInit.h"

class Initialiser {
public:
    Initialiser(): calculator(), returnError() {Initialise();};

private:
    Calculator calculator;
    int returnError;

    TermInit termInit;
    MbedInit mbedInit;

    void Initialise();
};


#endif //JCALC_INITIALISER_H
