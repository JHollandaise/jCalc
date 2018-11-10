//
// Created by Joseph Holland  on 08/11/2018.
//

#ifndef JCALC_SURDFRAC_H
#define JCALC_SURDFRAC_H


#include <cstdint>
#include <tuple>


// ( ± n1*sqrt(s1) ± n2*sqrt(s2) ) / d
struct SurdFrac{
    SurdFrac():n1Sign(false),n2Sign(false),n1(0),n2(0),s1(0),s2(0),d(0){};
    SurdFrac(bool _n1Sign, bool _n2Sign, uint8_t _n1, uint8_t _n2, unsigned short _s1, unsigned short _s2, uint8_t _d):
            n1Sign(_n1Sign),n2Sign(_n2Sign),n1(_n1),n2(_n2),s1(_s1),s2(_s2),d(_d){};
    // init with FractionalApproximation
    explicit SurdFrac(std::tuple<bool, unsigned int, unsigned int, double, uint8_t>);


    bool n1Sign;
    bool n2Sign;
    uint8_t n1;
    uint8_t n2;
    unsigned short s1;
    unsigned short s2;
    uint8_t d;

    SurdFrac& operator+=(const SurdFrac&);
    SurdFrac operator+(const SurdFrac&);

    SurdFrac& operator-=(const SurdFrac&);
    SurdFrac operator-(const SurdFrac&);

    SurdFrac& operator*=(const SurdFrac&);
    SurdFrac operator*(const SurdFrac&);

private:
    void SimplifyDenominator();
};

#endif //JCALC_SURDFRAC_H
