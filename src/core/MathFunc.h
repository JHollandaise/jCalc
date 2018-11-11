//
// Created by Joseph Holland  on 09/11/2018.
//

#ifndef JCALC_MATHFUNC_H
#define JCALC_MATHFUNC_H

#include <vector>

namespace MathFunc {
    unsigned long GCD(unsigned long, unsigned long);
    unsigned long GCD(std::vector<unsigned long>);
    unsigned long LCM(unsigned long, unsigned long);

    unsigned long DivideSurd(unsigned long);

    bool ProductTupleSort(std::tuple<unsigned long, long, char>,
            std::tuple<unsigned long, long, char>);
}

#endif //JCALC_MATHFUNC_H
