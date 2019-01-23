//
// Created by Joseph Holland  on 30/04/2018.
//

#ifndef JCALC_RESULTVALUE_H
#define JCALC_RESULTVALUE_H

#include <cstdint>
#include "SurdFrac.h"

union ResultValue {
    explicit ResultValue(double _floatingPoint):
        floatingPoint(_floatingPoint){};

    explicit ResultValue(SurdFrac<short, unsigned short, unsigned short> _surdFrac):
        surdFrac(_surdFrac){};

    double floatingPoint;

    // ( ± n1*sqrt(s1) ± n2*sqrt(s2) ) / d
    SurdFrac<short, unsigned short, unsigned short> surdFrac;


};


#endif //JCALC_RESULTVALUE_H
