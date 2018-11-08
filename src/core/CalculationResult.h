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


    // TODO: RESULT TYPE
    explicit CalculationResult(double _resultValueReal = 0):
        resultType(0x00),resultValueReal(_resultValueReal),resultValueImaj(0){};
    CalculationResult(double _resultValueReal, double _resultValueImaj):
        resultType(0x00),resultValueReal(_resultValueReal),resultValueImaj(_resultValueImaj){};

    CalculationResult(bool n1SignReal, bool n2SignReal, uint8_t n1Real, uint8_t n2Real, uint8_t s1Real, uint8_t s2Real, uint8_t dReal,
                      bool n1SignImaj, bool n2SignImaj, uint8_t n1Imaj, uint8_t n2Imaj, uint8_t s1Imaj, uint8_t s2Imaj,uint8_t dImaj):
        resultType(0x11),resultValueReal(n1SignReal,n2SignReal,n1Real,n2Real,s1Real,s2Real,dReal),
        resultValueImaj(n1SignImaj,n2SignImaj,n1Imaj,n2Imaj,s1Imaj,s2Imaj,dImaj){};


    // 00: d d; 10: s d; 20; p d
    uint8_t resultType;

    ResultValue resultValueReal;
    ResultValue resultValueImaj;


    CalculationResult& operator+=(const CalculationResult&);
    CalculationResult& operator-=(const CalculationResult&);

    CalculationResult& operator*=(const CalculationResult&);
    CalculationResult& operator/=(const CalculationResult&);

    CalculationResult operator-();
};

CalculationResult &CalculationResult::operator+=(const CalculationResult &C) {
    // TODO: check for which result type to default to
    return *this;
}


#endif //JCALC_CALCULATIONRESULT_H
