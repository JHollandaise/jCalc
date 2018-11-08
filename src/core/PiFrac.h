//
// Created by Joseph Holland  on 08/11/2018.
//

#ifndef JCALC_PIFRAC_H
#define JCALC_PIFRAC_H

// ( ± n1*PI ± n2) / d

struct PiFrac{
    PiFrac(bool _n1Sign, bool _n2Sign, unsigned short _n1, unsigned short _n2, unsigned short _d):
            n1Sign(_n1Sign),n2Sign(_n2Sign),n1(_n1),n2(_n2),d(_d){};
    bool n1Sign;
    bool n2Sign;
    unsigned short n1;
    unsigned short n2;
    unsigned short d;
};

#endif //JCALC_PIFRAC_H
