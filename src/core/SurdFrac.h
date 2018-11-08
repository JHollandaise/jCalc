//
// Created by Joseph Holland  on 08/11/2018.
//

#ifndef JCALC_SURDFRAC_H
#define JCALC_SURDFRAC_H


#include <cstdint>

// ( ± n1*sqrt(s1) ± n2*sqrt(s2) ) / d
struct SurdFrac{
    SurdFrac(bool _n1Sign, bool _n2Sign, uint8_t _n1, uint8_t _n2, uint8_t _s1, uint8_t _s2, uint8_t _d):
            n1Sign(_n1Sign),n2Sign(_n2Sign),n1(_n1),n2(_n2),s1(_s1),s2(_s2),d(_d){};
    bool n1Sign;
    bool n2Sign;
    uint8_t n1;
    uint8_t n2;
    uint8_t s1;
    uint8_t s2;
    uint8_t d;
};

#endif //JCALC_SURDFRAC_H
