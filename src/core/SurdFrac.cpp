//
// Created by Joseph Holland  on 08/11/2018.
//

#include "SurdFrac.h"
#include "MathFunc.h"
#include <cmath>
#include <cstdlib>
#include <limits>

template<typename N, typename S, typename D>
SurdFrac<N, S, D>::SurdFrac(std::tuple<long, unsigned long, double> fractionalApprox) :
        n1((N) std::get<1>(fractionalApprox)), n2(0), s1(1), s2(0),
        d((D) std::get<2>(fractionalApprox)) {
    const long &numerator(std::get<0>(fractionalApprox));
    const unsigned long &denominator(std::get<1>(fractionalApprox));
    const double &error(std::get<2>(fractionalApprox));

    if (std::abs(numerator) > std::numeric_limits<N>::max() || denominator > std::numeric_limits<D>::max() || error > 0)
        throw std::bad_cast();

}

template<typename N, typename S, typename D>
SurdFrac<N,S,D>& SurdFrac<N,S,D>::operator+=(const SurdFrac<N,S,D> &rhs) {
    if (MathFunc::LCM(d, rhs.d) > std::numeric_limits<D>::max() ) throw std::bad_cast();

    auto newDenominator((D) MathFunc::LCM(d, rhs.d));


    if (rhs.s1 == s1) {
        if (std::abs(n1 * newDenominator / d + rhs.n1 * newDenominator / rhs.d) > std::numeric_limits<N>::max())
            throw std::bad_cast();

        n1 = (N)(n1 * newDenominator / d + rhs.n1 * newDenominator / rhs.d);

    } else if (!s2) {
        s2 = rhs.s1;
        n2 = rhs.n1;
    } else if (rhs.s1 == s2) {
        if (std::abs(n2 * newDenominator / d + rhs.n1 * newDenominator / rhs.d) > std::numeric_limits<N>::max() )
            throw std::bad_cast();

        n2 = (N)( n2 * newDenominator / d + rhs.n1 * newDenominator / rhs.d );

    } else throw std::bad_cast();

    if (rhs.s2) {
        // n1+n1
        if (rhs.s2 == s1) {
            if (std::abs( n1 * newDenominator / d + rhs.n2 * newDenominator / rhs.d) > std::numeric_limits<N>::max() )
                throw std::bad_cast();

            n1 = (N)( n1 * newDenominator / d + rhs.n2 * newDenominator / rhs.d );
        } else if (!s2) {
            s2 = rhs.s2;
            n2 = rhs.n2;
        } else if (rhs.s2 == s2) {
            if (std::abs( n2 * newDenominator / d + rhs.n2 * newDenominator / rhs.d) > std::numeric_limits<N>::max())
                throw std::bad_cast();

            n2 = (N)( n2 * newDenominator / d + rhs.n2 * newDenominator / rhs.d );
        } else throw std::bad_cast();
    }

    d = newDenominator;

    // clean up
    SimplifyDenominator();

    return *this;

}
template<typename N, typename S, typename D>
SurdFrac<N,S,D> SurdFrac<N,S,D>::operator+(const SurdFrac<N,S,D> &rhs) {
    SurdFrac<N,S,D> lhs(*this);
    return lhs += rhs;
}

template<typename N, typename S, typename D>
SurdFrac<N,S,D> &SurdFrac<N,S,D>::operator-=(const SurdFrac<N,S,D> &rhs) {
    SurdFrac<N,S,D> rhsNeg(rhs);

    rhs.n1*=-1;
    rhs.n2*=-1;

    return *this += rhsNeg;
}

template<typename N, typename S, typename D>
SurdFrac<N,S,D> SurdFrac<N,S,D>::operator-(const SurdFrac<N,S,D> &rhs) {
    SurdFrac<N,S,D> lhs(*this);
    return lhs -= rhs;
}

template<typename N, typename S, typename D>
SurdFrac<N,S,D> &SurdFrac<N,S,D>::operator*=(const SurdFrac &rhs) {

    std::vector<std::tuple<unsigned long, long> > products{
            {(unsigned) s1 * rhs.s1, n1 * rhs.n1},
            {(unsigned) s1 * rhs.s2, n1 * rhs.n2},
            {(unsigned) s2 * rhs.s1, n2 * rhs.n1},
            {(unsigned) s2 * rhs.s2, n2 * rhs.n2}
    };

    std::sort(products.begin(), products.end(), MathFunc::ProductTupleSort);

    auto check(products.begin());
    auto i(check + 1);

    while (i != products.end()) {
        if (std::get<0>(*check) == std::get<0>(*i)) {
            std::get<1>(*check) += std::get<1>(*i);

            products.erase(i);
        } else {
            check = i;
            i++;
        }
    }
    // remove 0 surds
    if (std::get<0>(products[0]) == 0) products.erase(products.begin());

    // two many unique surds
    if (products.size() > 2) throw std::bad_cast();

    if (products.empty()) {
        s1 = s2 = 0;
        d = 1;
        return *this;
    }

    unsigned long commonFactor(d * rhs.d);

    for (auto prod : products) {
        auto devisor = MathFunc::DivideSurd(std::get<0>(prod));

        std::get<0>(prod) /= (devisor * devisor);
        std::get<1>(prod) *= devisor;

        commonFactor = MathFunc::GCD(commonFactor, std::abs( std::get<1>(prod) ) );
    }

    if ( ((d * rhs.d) / commonFactor) > std::numeric_limits<D>::max() ) throw std::bad_cast();

    d = (D) ((d * rhs.d) / commonFactor);

    for (auto prod : products) {
        if (std::abs(std::get<1>(prod) / commonFactor > std::numeric_limits<N>::max()) ) throw std::bad_cast();

        std::get<1>(prod) /= commonFactor;
    }

    if (products.size() == 1) {
        n1 = (N) std::get<1>(products[0]);
        s1 = (S) std::get<0>(products[0]);
    }
    else {
        n1 = (N) std::get<1>(products[0]);
        s1 = (S) std::get<0>(products[0]);

        n1 = (N) std::get<1>(products[1]);
        s1 = (S) std::get<0>(products[1]);
    }

    return *this;
}

template<typename N, typename S, typename D>
void SurdFrac<N,S,D>::SimplifyDenominator() {
    uint8_t devisor;

    if ((devisor = (uint8_t) MathFunc::GCD({n1, n2, d})) > 1) {
        n1 /= devisor;
        n2 /= devisor;
        d /= devisor;
    }
}


