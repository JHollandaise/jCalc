//
// Created by Joseph Holland  on 08/11/2018.
//

#ifndef JCALC_SURDFRAC_H
#define JCALC_SURDFRAC_H


#include <cstdint>
#include <tuple>


// ( ± n1*sqrt(s1) ± n2*sqrt(s2) ) / d

// ensure S and D are unsigned
template <typename N, typename S, typename D>
struct SurdFrac{
    SurdFrac():n1(0),n2(0),s1(0),s2(0),d(0){};
    SurdFrac(N _n1, N _n2, S _s1, S _s2, D _d):
            n1(_n1),n2(_n2),s1(_s1),s2(_s2),d(_d){};
    // init with FractionalApproximation
    explicit SurdFrac(std::tuple<long, unsigned long, double>);

    N n1;
    N n2;
    S s1;
    S s2;
    D d;

    SurdFrac<N,S,D>& operator+=(const SurdFrac&);
    SurdFrac<N,S,D> operator+(const SurdFrac&);

    SurdFrac<N,S,D>& operator-=(const SurdFrac&);
    SurdFrac<N,S,D> operator-(const SurdFrac&);

    SurdFrac<N,S,D>& operator*=(const SurdFrac&);
    SurdFrac<N,S,D> operator*(const SurdFrac&);

    SurdFrac<N,S,D>& operator/=(const SurdFrac&);
    SurdFrac<N,S,D> operator/(const SurdFrac&);


private:
    void SimplifyDenominator();
    void TidySurd();
};

#endif //JCALC_SURDFRAC_H
