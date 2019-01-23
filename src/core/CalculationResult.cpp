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

    // if either is surd
    if(realIsSurd||rhs.realIsSurd){
        // attempt SurdFrac + SurdFrac
        try{
            SurdFrac<short, unsigned short, unsigned short> lhsReal;
            SurdFrac<short, unsigned short, unsigned short> rhsReal;

            // try to get lhs as SurdFrac
            if(!realIsSurd) lhsReal = SurdFrac<short, unsigned short, unsigned short>(
                    GetFractionalApproximation(resultValueReal.floatingPoint,(unsigned)std::numeric_limits<short>::max(),
                            std::numeric_limits<unsigned short>::max() ) );
            else lhsReal = resultValueReal.surdFrac;

            // try to get rhs as SurdFrac
            if(!rhs.realIsSurd) rhsReal = SurdFrac<short, unsigned short, unsigned short>(
                    GetFractionalApproximation(rhs.resultValueReal.floatingPoint,(unsigned)std::numeric_limits<short>::max(),std::numeric_limits<unsigned short>::max() ) );
            else rhsReal = rhs.resultValueReal.surdFrac;

            // try to add
            resultValueReal.surdFrac = lhsReal + rhsReal;
            // now is surd
            realIsSurd=true;
        }
        catch(const std::bad_cast&){
            if(realIsSurd) resultValueReal.floatingPoint = GetFloatingApproximation(resultValueReal.surdFrac);

            if(rhs.realIsSurd) resultValueReal.floatingPoint += GetFloatingApproximation(rhs.resultValueReal.surdFrac);
            else resultValueReal.floatingPoint += rhs.resultValueReal.floatingPoint;
            realIsSurd=false;

        }
    }
    //otherwise just get floating
    else resultValueReal.floatingPoint += rhs.resultValueReal.floatingPoint;

    // if either is a surd
    if(imajIsSurd||rhs.imajIsSurd) {
        // attempt SurdFrac + SurdFrac
        try {
            SurdFrac<short, unsigned short, unsigned short> lhsImaj;
            SurdFrac<short, unsigned short, unsigned short> rhsImaj;

            // try to get lhs as SurdFrac
            if (!imajIsSurd) lhsImaj = SurdFrac<short, unsigned short, unsigned short>(
                        GetFractionalApproximation(resultValueImaj.floatingPoint, std::numeric_limits<short>::max(),
                                                   std::numeric_limits<unsigned short>::max()));
            else lhsImaj = resultValueImaj.surdFrac;

            // try to get rhs as SurdFrac
            if (!rhs.realIsSurd) rhsImaj = SurdFrac<short, unsigned short, unsigned short>(
                        GetFractionalApproximation(rhs.resultValueImaj.floatingPoint, std::numeric_limits<short>::max(),
                                                   std::numeric_limits<unsigned short>::max()));
            else rhsImaj = rhs.resultValueImaj.surdFrac;

            // try to add
            resultValueImaj.surdFrac = lhsImaj + rhsImaj;
            // now is surd
            imajIsSurd = true;

        }
        catch (const std::bad_cast &) {
            if (imajIsSurd) resultValueImaj.floatingPoint = GetFloatingApproximation(resultValueImaj.surdFrac);
            if (rhs.imajIsSurd) {

                resultValueImaj.floatingPoint += GetFloatingApproximation(rhs.resultValueImaj.surdFrac);
            } else resultValueImaj.floatingPoint += rhs.resultValueImaj.floatingPoint;
            imajIsSurd = false;
        }
    }
    //otherwise just get floating
    else resultValueImaj.floatingPoint += rhs.resultValueImaj.floatingPoint;

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

    // calculates (lr + li*i)(rr + ri*i) = (lrrr - liri) + (lrri lirr)i
    // has increased complexity due to conversion between floating and SurdFrac representations


    bool lrSuccess(false);
    bool rrSuccess(false);
    bool liSuccess(false);
    bool riSuccess(false);

    SurdFrac<short, unsigned short, unsigned short> lrSurd;
    SurdFrac<short, unsigned short, unsigned short> rrSurd;
    SurdFrac<short, unsigned short, unsigned short> liSurd;
    SurdFrac<short, unsigned short, unsigned short> riSurd;

    SurdFrac<short, unsigned short, unsigned short> realSurd;
    SurdFrac<short, unsigned short, unsigned short> imajSurd;

    bool newRealIsSurd(false);
    bool newImajIsSurd(false);

    // double values may be used

    double lrDouble(0);
    double liDouble(0);
    double rrDouble(0);
    double riDouble(0);

    // attempt lr surd calc?
    if((realIsSurd||rhs.realIsSurd||imajIsSurd||rhs.imajIsSurd) &&
       (resultValueReal.floatingPoint!=0 || rhs.resultValueReal.floatingPoint!=0) &&
       rhs.resultValueImaj.floatingPoint!=0  ) {

        // need to estimate
        if(!realIsSurd) {
            try {
                lrSurd = SurdFrac<short, unsigned short, unsigned short>(GetFractionalApproximation(
                        resultValueReal.floatingPoint,(unsigned)std::numeric_limits<short>::max(),
                        std::numeric_limits<unsigned short>::max()));
                lrSuccess = true;
            }
            catch(const std::bad_cast&){
                // do nothing
            }
        }
        else {
            lrSurd = resultValueReal.surdFrac;
            lrSuccess = true;
        }
    }

    // attempt rr surd calc
    if( (lrSuccess || resultValueImaj.floatingPoint!=0) && rhs.resultValueReal.floatingPoint!=0 ) {

        if(!rhs.realIsSurd) {
            try {
                rrSurd = SurdFrac<short, unsigned short, unsigned short>(GetFractionalApproximation(
                        rhs.resultValueReal.floatingPoint,(unsigned)std::numeric_limits<short>::max(),
                        std::numeric_limits<unsigned short>::max()));
                rrSuccess = true;
            }
            catch(std::bad_cast&) {
                // do nothing
            }
        }
        else {
            rrSurd = rhs.resultValueReal.surdFrac;
            rrSuccess = true;
        }
    }

    // attempt li surd calc
    if( (rrSuccess || rhs.resultValueImaj.floatingPoint!=0) && resultValueImaj.floatingPoint!=0 ) {

        if(!imajIsSurd) {
            try {
                liSurd = SurdFrac<short, unsigned short, unsigned short>(GetFractionalApproximation(
                        resultValueImaj.floatingPoint,(unsigned)std::numeric_limits<short>::max(),
                        std::numeric_limits<unsigned short>::max()));
                liSuccess = true;
            }
            catch(std::bad_cast&) {
                // do nothing
            }
        }
        else {
            liSurd = resultValueImaj.surdFrac;
            liSuccess = true;
        }
    }

    // attempt ri surd calc
    if( (liSuccess || lrSuccess || rrSuccess) && rhs.resultValueImaj.floatingPoint!=0) {
        if(!rhs.imajIsSurd) {
            try {
                riSurd = SurdFrac<short, unsigned short, unsigned short>(GetFractionalApproximation(
                        rhs.resultValueImaj.floatingPoint,(unsigned)std::numeric_limits<short>::max(),
                        std::numeric_limits<unsigned short>::max()));
                riSuccess = true;
            }
            catch(std::bad_cast&) {
                // do nothing
            }
        }
        else {
            riSurd = rhs.resultValueImaj.surdFrac;
            riSuccess = true;
        }
    }

    // now determine calc

    // for newReal
    if( ( (resultValueReal.floatingPoint==0 || rhs.resultValueReal.floatingPoint==0) ||
          (lrSuccess&&rrSuccess) ) &&
        ( (resultValueImaj.floatingPoint==0 || rhs.resultValueImaj.floatingPoint==0) ||
          (liSuccess&&riSuccess) ) ) {

        SurdFrac<short, unsigned short, unsigned short>lrrrSurd;
        SurdFrac<short, unsigned short, unsigned short>liriSurd;

        try {
            // for lrrr
            if (resultValueReal.floatingPoint != 0 && rhs.resultValueReal.floatingPoint != 0) {
                lrrrSurd = SurdFrac<short, unsigned short, unsigned short>(lrSurd * rrSurd);
            } else lrrrSurd = SurdFrac<short, unsigned short, unsigned short>(0, 0, 0, 0, 1);

            // for liri
            if (resultValueImaj.floatingPoint != 0 && rhs.resultValueImaj.floatingPoint != 0) {
                liriSurd = SurdFrac<short, unsigned short, unsigned short>(liSurd * riSurd);
            } else liriSurd = SurdFrac<short, unsigned short, unsigned short>(0, 0, 0, 0, 1);

            newRealIsSurd = true;
            realSurd = lrrrSurd - liriSurd;

            if(realSurd == SurdFrac<short, unsigned short, unsigned short>(0, 0, 0, 0, 1)) newRealIsSurd = false;
        }
        catch(std::bad_cast&) {
            // do nothing
        }
    }

    // for newImaj
    if( ( (resultValueReal.floatingPoint==0 || rhs.resultValueImaj.floatingPoint==0) ||
          (lrSuccess&&riSuccess) ) &&
        ( (resultValueImaj.floatingPoint==0 || rhs.resultValueReal.floatingPoint==0) ||
          (liSuccess&&rrSuccess) ) ) {

        SurdFrac<short, unsigned short, unsigned short>lrriSurd;
        SurdFrac<short, unsigned short, unsigned short>lirrSurd;

        try {

            // for lrri
            if (resultValueReal.floatingPoint != 0 && rhs.resultValueImaj.floatingPoint != 0) {
                lrriSurd = SurdFrac<short, unsigned short, unsigned short>(lrSurd * riSurd);

            } else lrriSurd = SurdFrac<short, unsigned short, unsigned short>(0, 0, 0, 0, 1);

            // for lirr
            if (resultValueImaj.floatingPoint != 0 && rhs.resultValueReal.floatingPoint != 0) {
                lirrSurd = SurdFrac<short, unsigned short, unsigned short>(liSurd * rrSurd);
            } else lirrSurd = SurdFrac<short, unsigned short, unsigned short>(0, 0, 0, 0, 1);

            newImajIsSurd = true;
            imajSurd = lrriSurd + lirrSurd;

            if(imajSurd == SurdFrac<short, unsigned short, unsigned short>(0, 0, 0, 0, 1)) newImajIsSurd = false;

        }
        catch(std::bad_cast&){
            // do nothing
        }
    }

    // now set values

    // need to get doubles
    if(!newRealIsSurd || !newImajIsSurd) {
        if(realIsSurd) lrDouble = GetFloatingApproximation(resultValueReal.surdFrac);
        else lrDouble = resultValueReal.floatingPoint;
        if(imajIsSurd) liDouble = GetFloatingApproximation(resultValueImaj.surdFrac);
        else liDouble = resultValueImaj.floatingPoint;
        if(rhs.realIsSurd) rrDouble = GetFloatingApproximation(rhs.resultValueReal.surdFrac);
        else rrDouble = rhs.resultValueReal.floatingPoint;
        if(rhs.imajIsSurd) riDouble = GetFloatingApproximation(rhs.resultValueImaj.surdFrac);
        else riDouble = rhs.resultValueImaj.floatingPoint;
    }

    if(newRealIsSurd) {
        resultValueReal.surdFrac = realSurd;
        realIsSurd = true;
    } else {
        resultValueReal.floatingPoint = lrDouble*rrDouble - liDouble*riDouble;
        realIsSurd = false;
    }

    if(newImajIsSurd ) {
        resultValueImaj.surdFrac = imajSurd;
        imajIsSurd = true;
    } else {
        resultValueImaj.floatingPoint = lrDouble*riDouble + liDouble*rrDouble;
        imajIsSurd = false;
    }

    return *this;



}

CalculationResult CalculationResult::operator*(const CalculationResult &rhs) const{
    CalculationResult lhs(*this);

    return lhs *= rhs;
}

CalculationResult &CalculationResult::operator/=(const CalculationResult &rhs) {
    CalculationResult devisor(rhs * rhs.GetConjugate());

    return *this;
}

bool CalculationResult::operator==(const CalculationResult &rhs) {
    bool realEqual(false);
    bool imajEqual(false);

    // type mismatch
    if(this->realIsSurd!=rhs.realIsSurd || this->imajIsSurd!=rhs.imajIsSurd) return false;

    // note we just compare the fractional representation as the data is the same either way

    // real part
    realEqual = this->resultValueReal.floatingPoint==rhs.resultValueReal.floatingPoint;

    // imaj part
    imajEqual = this->resultValueImaj.floatingPoint==rhs.resultValueImaj.floatingPoint;

    return realEqual&&imajEqual;
}



std::tuple<long, unsigned long, double> CalculationResult::GetFractionalApproximation(double floatingValue,
        unsigned long maxnum, unsigned long maxden) {

    int8_t sign(floatingValue>=0?(int8_t)1:(int8_t)-1);

    double floatingValueMag = std::abs(floatingValue);

    // in case of zero, skip the crap yo
    // just keep as floating
    if(floatingValue == 0) return std::make_tuple(0,1,100);

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

double CalculationResult::GetFloatingApproximation(const SurdFrac<short, unsigned short, unsigned short> &surdFrac) {
    return ( surdFrac.n1*std::sqrt(surdFrac.s1) + surdFrac.n2*std::sqrt(surdFrac.s2) )/surdFrac.d;
}

