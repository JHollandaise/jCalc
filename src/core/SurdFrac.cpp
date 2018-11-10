//
// Created by Joseph Holland  on 08/11/2018.
//

#include "SurdFrac.h"
#include "MathFunc.h"


SurdFrac::SurdFrac(std::tuple<bool, unsigned int, unsigned int, double, uint8_t> fractionalApprox) :
        n1Sign(std::get<0>(fractionalApprox)), n1((uint8_t)std::get<1>(fractionalApprox)),
        d((uint8_t)std::get<2>(fractionalApprox))
{
    const unsigned int& numerator(std::get<1>(fractionalApprox));
    const unsigned int& denominator(std::get<2>(fractionalApprox));
    const double& error(std::get<3>(fractionalApprox));
    const uint8_t& exception(std::get<4>(fractionalApprox));

    if(numerator>255U || denominator>255U || error>0 || exception) throw std::bad_cast();

}

SurdFrac &SurdFrac::operator+=(const SurdFrac &rhs) {
    if(MathFunc::LCM(d,rhs.d) > 255U) throw std::bad_cast();
    auto newDenominator((uint8_t)MathFunc::LCM(d,rhs.d));

    if (rhs.s1 == s1) {
        if ((n1 * newDenominator / d + rhs.n1 * newDenominator / rhs.d) > 255U) throw std::bad_cast();

        n1 = n1 * newDenominator / d + rhs.n1 * newDenominator / rhs.d;
    }
    else if(!s2) {
        s2 = rhs.s1;
        n2 = rhs.n1;
    }
    else if (rhs.s1 == s2) {
        if ((n2 * newDenominator / d + rhs.n1 * newDenominator / rhs.d) > 255U) throw std::bad_cast();
        n2 = n2 * newDenominator / d + rhs.n1 * newDenominator / rhs.d;
    } else throw std::bad_cast();

    if(rhs.s2){
        // n1+n1
        if (rhs.s2 == s1) {
            if ((n1 * newDenominator / d + rhs.n2 * newDenominator / rhs.d) > 255U) throw std::bad_cast();

            n1 = n1 * newDenominator / d + rhs.n2 * newDenominator / rhs.d;
        }
        else if(!s2) {
            s2 = rhs.s2;
            n2 = rhs.n2;
        }
            //n2+n1
        else if (rhs.s2 == s2) {
            if ((n2 * newDenominator / d + rhs.n2 * newDenominator / rhs.d) > 255U) throw std::bad_cast();
            n2 = n2 * newDenominator / d + rhs.n2 * newDenominator / rhs.d;
        } else throw std::bad_cast();
    }

    d = newDenominator;

    // clean up
    SimplifyDenominator();

    return *this;

}

SurdFrac SurdFrac::operator+(const SurdFrac &rhs) {
    SurdFrac lhs(*this);
    return lhs+=rhs;
}



void SurdFrac::SimplifyDenominator() {
    uint8_t devisor;

    if((devisor = (uint8_t )MathFunc::GCD({n1,n2,d}))>1){
        n1 /= devisor;
        n2 /= devisor;
        d  /= devisor;
    }
}

