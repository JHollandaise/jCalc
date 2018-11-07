//
// Created by Joseph Holland  on 19/04/2018.
//

#ifndef JCALC_CALCULATIONRESULT_H
#define JCALC_CALCULATIONRESULT_H

#include "ResultValue.h"

/*
 * 16 byte struct as a general representation for a calculation result
 *
 * Implements casting between
 * */
struct CalculationResult {

    // TODO: add initialisation
    CalculationResult(const CalculationResult& _calculationResult)
    {};
    CalculationResult(double _resultValueReal);

    CalculationResult();

    unsigned short resultType;

    ResultValue resultValueReal;
    ResultValue resultValueImaj;

    CalculationResult& operator=(const CalculationResult&);

    CalculationResult& operator+=(const CalculationResult&);
    CalculationResult& operator-=(const CalculationResult&);

    CalculationResult& operator*=(const CalculationResult&);
    CalculationResult& operator/=(const CalculationResult&);

    CalculationResult operator-();
};


#endif //JCALC_CALCULATIONRESULT_H
