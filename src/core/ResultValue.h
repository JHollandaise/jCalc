//
// Created by Joseph Holland  on 30/04/2018.
//

#ifndef JCALC_RESULTVALUE_H
#define JCALC_RESULTVALUE_H

#include <cstdint>

union ResultValue {

    double floatingPoint;


    uint8_t fractional[8];

};


#endif //JCALC_RESULTVALUE_H
