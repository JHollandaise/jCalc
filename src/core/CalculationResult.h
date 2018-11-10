//
// Created by Joseph Holland  on 19/04/2018.
//

#ifndef JCALC_CALCULATIONRESULT_H
#define JCALC_CALCULATIONRESULT_H

#include <tuple>
#include "ResultValue.h"

/*
 * 16 byte struct as a general representation for a calculation result
 *
 * Implements casting between
 * */
struct CalculationResult {

    CalculationResult(double Real, double Imaj):
            realIsSurd(false),imajIsSurd(false),resultValueReal(Real),resultValueImaj(Imaj){};

    CalculationResult(double Real, SurdFrac Imaj):
            realIsSurd(false),imajIsSurd(true),resultValueReal(Real),resultValueImaj(Imaj){};

    CalculationResult(SurdFrac Real, double Imaj):
            realIsSurd(true),imajIsSurd(false),resultValueReal(Real),resultValueImaj(Imaj){};

    CalculationResult(SurdFrac Real, SurdFrac Imaj):
            realIsSurd(true),imajIsSurd(true),resultValueReal(Real),resultValueImaj(Imaj){};

    explicit CalculationResult(double real = 0):
        CalculationResult(real, 0){};

    explicit CalculationResult(SurdFrac real):
        CalculationResult(real, 0){};


    bool realIsSurd;
    bool imajIsSurd;

    ResultValue resultValueReal;
    ResultValue resultValueImaj;

    // (numerator,denominator,error,exception)
    std::tuple<bool, unsigned int, unsigned int, double, uint8_t> GetFractionalApproximation(double, unsigned int, unsigned int);
    // TODO: add PiFractionalApproximation
    double GetFloatingApproximation(const SurdFrac&);



    CalculationResult& operator+=(const CalculationResult&);
    CalculationResult& operator-=(const CalculationResult&);

    CalculationResult& operator*=(const CalculationResult&);
    CalculationResult& operator/=(const CalculationResult&);

    CalculationResult operator-();

//            Square(result);
//            XPowY(result);
//            XPowNegOne(result);
//            XPowThree(result);
//            Permute(result);
//            Combine(result);
//            Degree(result);
//            Radian(result);
//            Gradian(result);
//            Percent(result);
//            Factorial(result);
//
    CalculationResult& xPowY(const CalculationResult&);
    CalculationResult& Permute(const CalculationResult&);
    CalculationResult& Combine(const CalculationResult&);
    CalculationResult& Factorial(const CalculationResult&);


};


#endif //JCALC_CALCULATIONRESULT_H
