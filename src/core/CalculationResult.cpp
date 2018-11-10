//
// Created by Joseph Holland  on 08/11/2018.
//


#include <cmath>
#include "CalculationResult.h"
#include "SurdFrac.h"
#include <limits>
#include <stdint.h>
#include "MathFunc.h"

CalculationResult &CalculationResult::operator+=(const CalculationResult &rhs) {
    // attempt SurdFrac + SurdFrac
    try{
        SurdFrac lhsReal;
        SurdFrac rhsReal;

        // try to get lhs as SurdFrac
        if(!realIsSurd) lhsReal = SurdFrac(GetFractionalApproximation(resultValueReal.floatingPoint,255U,255U));
        else lhsReal = resultValueReal.surdFrac;

        // try to get rhs as SurdFrac
        if(!rhs.realIsSurd) rhsReal = SurdFrac(GetFractionalApproximation(rhs.resultValueReal.floatingPoint,255U,255U));
        else rhsReal = rhs.resultValueReal.surdFrac;

        // try to add
        resultValueReal.surdFrac = lhsReal + rhsReal;

    }
    catch(const std::bad_cast&){
        resultValueReal.floatingPoint+=rhs.resultValueReal.floatingPoint;
    }

    // attempt SurdFrac + SurdFrac
    try{
        SurdFrac lhsImaj;
        SurdFrac rhsImaj;

        // try to get lhs as SurdFrac
        if(!imajIsSurd) lhsImaj = SurdFrac(GetFractionalApproximation(resultValueImaj.floatingPoint,255U,255U));
        else lhsImaj = resultValueImaj.surdFrac;

        // try to get rhs as SurdFrac
        if(!rhs.realIsSurd) rhsImaj = SurdFrac(GetFractionalApproximation(rhs.resultValueImaj.floatingPoint,255U,255U));
        else rhsImaj = rhs.resultValueImaj.surdFrac;

        // try to add
        resultValueImaj.surdFrac = lhsImaj + rhsImaj;

    }
    catch(const std::bad_cast&){
        resultValueImaj.floatingPoint+=rhs.resultValueImaj.floatingPoint;
    }

    return *this;
}

std::tuple<bool, unsigned int, unsigned int, double, uint8_t> CalculationResult::GetFractionalApproximation(double floatingValue,
        unsigned int maxnum, unsigned int maxden) {

    bool isNegative(false);
    if (floatingValue < 0) isNegative = true;

    double floatingValueMag = std::abs(floatingValue);

    if(floatingValueMag > (double)(std::numeric_limits<unsigned int>::max() ))
        // integer repr too big
        return std::make_tuple(false,0,0,0,1);

    double floatRemainder(floatingValueMag);
    unsigned int remainderFloor;
    unsigned int m[2][2];

    unsigned int numerator;
    unsigned int denominator;

    double error;


    /* initialize matrix */
    m[0][0] = m[1][1] = 1;
    m[0][1] = m[1][0] = 0;

    /* loop finding terms until denom gets too big */
    while ( (denominator = m[1][0] *  ( remainderFloor = static_cast<unsigned int>(floatRemainder) ) + m[1][1]) <= maxden
            && (numerator = m[0][0]*remainderFloor + m[0][1])  <= maxnum) {
        m[0][1] = m[0][0];
        m[0][0] = numerator;

        m[1][1] = m[1][0];
        m[1][0] = denominator;

        if(floatRemainder==(double)remainderFloor) break;     // AF: division by zero
        floatRemainder = 1/(floatRemainder - (double)remainderFloor);
        if(floatRemainder>(double)0x7FFFFFFF) break;  // AF: representation failure
    }

    error = floatingValueMag - ( (double) numerator / (double) denominator );

    return std::make_tuple(isNegative,numerator,denominator,error,0);
}
