//
// Created by Joseph Holland  on 30/04/2018.
//

#ifndef JCALC_RESULTVALUE_H
#define JCALC_RESULTVALUE_H

#include <cstdint>
#include "SurdFrac.h"
#include "PiFrac.h"

union ResultValue {
    explicit ResultValue(double _floatingPoint):floatingPoint(_floatingPoint){};
    ResultValue(bool n1Sign, bool n2Sign, uint8_t n1, uint8_t n2, uint8_t s1, uint8_t s2, uint8_t d):
        surdFrac(n1Sign,n2Sign,n1,n2,s1,s2,d){};
    ResultValue(bool n1Sign, bool n2Sign, unsigned short n1, unsigned short n2, unsigned short d):
        piFrac(n1Sign,n2Sign,n1,n2,d){};

    double floatingPoint;

    // ( ± n1*sqrt(s1) ± n2*sqrt(s2) ) / d
    SurdFrac surdFrac;

    // ( ± n1*PI ± n2) / d
    PiFrac piFrac;

};


#endif //JCALC_RESULTVALUE_H
