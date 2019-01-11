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
 * Implements casting between types and operations between given results
 * */
struct CalculationResult {

    CalculationResult(double Real, double Imaj):
            realIsSurd(false),imajIsSurd(false),resultValueReal(Real),resultValueImaj(Imaj){};

    CalculationResult(double Real, SurdFrac<short, unsigned short, uint8_t> Imaj):
            realIsSurd(false),imajIsSurd(true),resultValueReal(Real),resultValueImaj(Imaj){};

    CalculationResult(SurdFrac<short, unsigned short, uint8_t> Real, double Imaj):
            realIsSurd(true),imajIsSurd(false),resultValueReal(Real),resultValueImaj(Imaj){};

    CalculationResult(SurdFrac<short, unsigned short, uint8_t> Real, SurdFrac<short, unsigned short, uint8_t> Imaj):
            realIsSurd(true),imajIsSurd(true),resultValueReal(Real),resultValueImaj(Imaj){};

    explicit CalculationResult(double real = 0):
        CalculationResult(real, 0){};

    explicit CalculationResult(SurdFrac<short, unsigned short, uint8_t> real):
        CalculationResult(real, 0){};


    bool realIsSurd;
    bool imajIsSurd;

    ResultValue resultValueReal;
    ResultValue resultValueImaj;

    // (numerator,denominator,error,exception)
    std::tuple<long, unsigned long, double> GetFractionalApproximation(double, unsigned long, unsigned long);
    // TODO: add PiFractionalApproximation
    //double GetFloatingApproximation(const SurdFrac<short, unsigned short, uint8_t> &);



    CalculationResult& operator+=(const CalculationResult&);
    CalculationResult  operator+(const CalculationResult&);

    CalculationResult& operator-=(const CalculationResult&);
    CalculationResult operator-(const CalculationResult&);

    CalculationResult& operator*=(const CalculationResult&);
    CalculationResult operator*(const CalculationResult&) const;


    CalculationResult& operator/=(const CalculationResult&);

    CalculationResult operator-() const;

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
    //TODO: implement
    /*
    CalculationResult& XPowY(const CalculationResult&);
    CalculationResult& Permute(const CalculationResult&);
    CalculationResult& Combine(const CalculationResult&);
    CalculationResult& Factorial(const CalculationResult&);
     */

    CalculationResult& Conjugate();
    const CalculationResult GetConjugate() const;


};


#endif //JCALC_CALCULATIONRESULT_H
