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
        SurdFrac<short, unsigned short, uint8_t> lhsReal;
        SurdFrac<short, unsigned short, uint8_t> rhsReal;

        // try to get lhs as SurdFrac
        if(!realIsSurd) lhsReal = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(resultValueReal.floatingPoint,std::numeric_limits<short>::max(),std::numeric_limits<uint8_t>::max() ) );
        else lhsReal = resultValueReal.surdFrac;

        // try to get rhs as SurdFrac
        if(!rhs.realIsSurd) rhsReal = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(rhs.resultValueReal.floatingPoint,std::numeric_limits<short>::max(),std::numeric_limits<uint8_t>::max() ) );
        else rhsReal = rhs.resultValueReal.surdFrac;

        // try to add
        resultValueReal.surdFrac = lhsReal + rhsReal;

    }
    catch(const std::bad_cast&){
        resultValueReal.floatingPoint+=rhs.resultValueReal.floatingPoint;
    }

    // attempt SurdFrac + SurdFrac
    try{
        SurdFrac<short, unsigned short, uint8_t> lhsImaj;
        SurdFrac<short, unsigned short, uint8_t> rhsImaj;

        // try to get lhs as SurdFrac
        if(!imajIsSurd) lhsImaj = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(resultValueImaj.floatingPoint,255U,255U));
        else lhsImaj = resultValueImaj.surdFrac;

        // try to get rhs as SurdFrac
        if(!rhs.realIsSurd) rhsImaj = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(rhs.resultValueImaj.floatingPoint,255U,255U));
        else rhsImaj = rhs.resultValueImaj.surdFrac;

        // try to add
        resultValueImaj.surdFrac = lhsImaj + rhsImaj;

    }
    catch(const std::bad_cast&){
        resultValueImaj.floatingPoint+=rhs.resultValueImaj.floatingPoint;
    }

    return *this;
}

CalculationResult CalculationResult::operator+(const CalculationResult& rhs) {
    CalculationResult lhs(*this);

    return lhs += rhs;
}

CalculationResult &CalculationResult::operator-=(const CalculationResult &rhs) {
    return *this +=(-rhs);
}

CalculationResult CalculationResult::operator-(const CalculationResult& rhs) {
    CalculationResult lhs(*this);

    return lhs -= rhs;
}

CalculationResult CalculationResult::operator-() const{
    CalculationResult negResult(*this);

    if(realIsSurd) negResult.resultValueReal.surdFrac = ( -negResult.resultValueReal.surdFrac);
    else negResult.resultValueReal.floatingPoint = ( -negResult.resultValueReal.floatingPoint);

    if(imajIsSurd) negResult.resultValueImaj.surdFrac = ( -negResult.resultValueImaj.surdFrac);
    else negResult.resultValueImaj.floatingPoint = ( -negResult.resultValueImaj.floatingPoint);

    return negResult;
}

CalculationResult &CalculationResult::operator*=(const CalculationResult &rhs) {

    try {
        SurdFrac<short, unsigned short, uint8_t> lhsReal;
        SurdFrac<short, unsigned short, uint8_t> rhsReal;
        SurdFrac<short, unsigned short, uint8_t> lhsImaj;
        SurdFrac<short, unsigned short, uint8_t> rhsImaj;

        // attempt to develop SurdFrac representation
        if(!realIsSurd) lhsReal = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(resultValueReal.floatingPoint,std::numeric_limits<short>::max(),std::numeric_limits<uint8_t>::max() ) );
        else lhsReal = resultValueReal.surdFrac;

        if(!rhs.realIsSurd) rhsReal = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(rhs.resultValueReal.floatingPoint,std::numeric_limits<short>::max(),std::numeric_limits<uint8_t>::max() ) );
        else rhsReal = rhs.resultValueReal.surdFrac;

        if(!imajIsSurd) lhsImaj = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(resultValueImaj.floatingPoint,std::numeric_limits<short>::max(),std::numeric_limits<uint8_t>::max() ) );
        else lhsImaj = resultValueImaj.surdFrac;

        if(!rhs.imajIsSurd) rhsImaj = SurdFrac<short, unsigned short, uint8_t>(GetFractionalApproximation(rhs.resultValueImaj.floatingPoint,std::numeric_limits<short>::max(),std::numeric_limits<uint8_t>::max() ) );
        else rhsImaj = rhs.resultValueImaj.surdFrac;

        try {
            // attempt to get surd real part
            resultValueReal.surdFrac = lhsReal*rhsReal - lhsImaj*rhsImaj;
        }
        catch (const std::bad_cast&) {
            resultValueReal.floatingPoint = (resultValueReal.floatingPoint*rhs.resultValueReal.floatingPoint)
                                            -(resultValueImaj.floatingPoint*rhs.resultValueImaj.floatingPoint);
        }

        try {
            // attempt to get surd real part
            resultValueImaj.surdFrac = lhsReal*rhsImaj + lhsImaj*rhsReal;
        }
        catch (const std::bad_cast&) {
            resultValueImaj.floatingPoint = (resultValueReal.floatingPoint*rhs.resultValueImaj.floatingPoint)
                                            +(resultValueImaj.floatingPoint*rhs.resultValueReal.floatingPoint);
        }

        return *this;

    }
    catch (const std::bad_cast&) {
        resultValueReal.floatingPoint = (resultValueReal.floatingPoint*rhs.resultValueReal.floatingPoint)
                            -(resultValueImaj.floatingPoint*rhs.resultValueImaj.floatingPoint);

        resultValueImaj.floatingPoint = (resultValueReal.floatingPoint*rhs.resultValueImaj.floatingPoint)
                                        +(resultValueImaj.floatingPoint*rhs.resultValueReal.floatingPoint);
        return *this;
    }
}

CalculationResult CalculationResult::operator*(const CalculationResult &) const{
    return CalculationResult();
}

CalculationResult &CalculationResult::operator/=(const CalculationResult &rhs) {
    CalculationResult devisor(rhs * rhs.GetConjugate());

    return *this;
}


std::tuple<long, unsigned long, double> CalculationResult::GetFractionalApproximation(double floatingValue,
        unsigned long maxnum, unsigned long maxden) {

    int8_t sign(floatingValue>=0?(int8_t)1:(int8_t)-1);

    double floatingValueMag = std::abs(floatingValue);

    if(floatingValueMag > (double)(std::numeric_limits<long>::max() ) ||
        floatingValueMag == 0)
        // integer repr too big or is 0
        throw std::bad_cast();

    double floatRemainder(floatingValueMag);
    unsigned long remainderFloor;
    unsigned long m[2][2];

    unsigned long numerator;
    unsigned long denominator;

    double error;


    /* initialize matrix */
    m[0][0] = m[1][1] = 1;
    m[0][1] = m[1][0] = 0;

    /* loop finding terms until denom gets too big */
    while ( (denominator = m[1][0] *  ( remainderFloor = static_cast<unsigned long>(floatRemainder) ) + m[1][1]) <= maxden
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

    return std::make_tuple((long)(numerator*sign),denominator,error);
}

CalculationResult &CalculationResult::Conjugate() {
    if(imajIsSurd) resultValueImaj.surdFrac = -resultValueImaj.surdFrac;
    else resultValueImaj.floatingPoint = -resultValueImaj.floatingPoint;

    return *this;
}

const CalculationResult CalculationResult::GetConjugate() const{
    CalculationResult conjugate(*this);

    return conjugate.Conjugate();
}
