//
// Created by Joseph Holland  on 08/11/2018.
//

#ifndef JCALC_SURDFRAC_H
#define JCALC_SURDFRAC_H


#include <cstdint>
#include <tuple>
#include "MathFunc.h"
#include <cmath>
#include <cstdlib>
#include <limits>



// ( ± n1*sqrt(s1) ± n2*sqrt(s2) ) / d

// ensure S and D are unsigned
template<typename N, typename S, typename D>
struct SurdFrac{
    SurdFrac<N,S,D>():n1(0),n2(0),s1(0),s2(0),d(1){};
    SurdFrac<N,S,D>(N _n1, N _n2, S _s1, S _s2, D _d):
            n1(_n1),n2(_n2),s1(_s1),s2(_s2),d(_d){SimplifyDenominator();
                                                  if(d==0) throw std::bad_cast();};
    // init with FractionalApproximation
    explicit SurdFrac(std::tuple<long, unsigned long, double> fractionalApprox) :
            n1((N) std::get<0>(fractionalApprox)), n2(0), s1(1), s2(0),
            d((D) std::get<1>(fractionalApprox)) {
        const long &numerator(std::get<0>(fractionalApprox));
        const unsigned long &denominator(std::get<1>(fractionalApprox));
        const double &error(std::get<2>(fractionalApprox));

        if (std::abs(numerator) > std::numeric_limits<N>::max() || denominator > std::numeric_limits<D>::max() || error > 0)
            throw std::bad_cast();
        SimplifyDenominator();

    }

    N n1;
    N n2;
    S s1;
    S s2;
    D d;

    SurdFrac<N,S,D>& operator+=(const SurdFrac<N,S,D> &rhs) {
        // set new denominator
        if (MathFunc::LCM(d, rhs.d) > std::numeric_limits<D>::max() ) throw std::bad_cast();

        auto newDenominator((D) MathFunc::LCM(d, rhs.d));

        if(rhs.s1) {
            // no first surd
            if (!s1) {
                s1 = rhs.s1;
                n1 = rhs.n1 * newDenominator / rhs.d;
            }
                // first surds same
            else if (rhs.s1 == s1) {
                if (std::abs(n1 * newDenominator / d + rhs.n1 * newDenominator / rhs.d) > std::numeric_limits<N>::max())
                    throw std::bad_cast();

                // sum first surd
                n1 = (N) (n1 * newDenominator / d + rhs.n1 * newDenominator / rhs.d);

            }
                // otherwise is second spot open
            else if (!s2) {
                // move rhs.s1 into s2 spot
                s2 = rhs.s1;
                n2 = rhs.n1 * newDenominator / rhs.d;
            }
                // otherwise is same as s2
            else if (rhs.s1 == s2) {
                if (std::abs(n2 * newDenominator / d + rhs.n1 * newDenominator / rhs.d) > std::numeric_limits<N>::max())
                    throw std::bad_cast();

                // sum into second surd
                n2 = (N) (n2 * newDenominator / d + rhs.n1 * newDenominator / rhs.d);

            }
                // otherwise no room at the inn
            else throw std::bad_cast();
        }

        // is there a rhs.s2 we need to jam in
        if (rhs.s2) {
            // same as s1
            if (rhs.s2 == s1) {
                if (std::abs( n1 * newDenominator / d + rhs.n2 * newDenominator / rhs.d) > std::numeric_limits<N>::max() )
                    throw std::bad_cast();

                // sum into s1 spot
                n1 = (N)( n1 * newDenominator / d + rhs.n2 * newDenominator / rhs.d );
            }
            // otherwise is s2 empty
            else if (!s2) {
                // move there
                s2 = rhs.s2;
                n2 = rhs.n2 * newDenominator / rhs.d;
            }
            // otherwise is same as s2
            else if (rhs.s2 == s2) {
                if (std::abs( n2 * newDenominator / d + rhs.n2 * newDenominator / rhs.d) > std::numeric_limits<N>::max())
                    throw std::bad_cast();

                // sum in
                n2 = (N)( n2 * newDenominator / d + rhs.n2 * newDenominator / rhs.d );
            }
            // otherwise no room at the inn
            else throw std::bad_cast();
        }

        d = newDenominator;

        // clean up
        SimplifyDenominator();
        TidySurd();

        return *this;

    }

    SurdFrac<N,S,D> operator+(const SurdFrac<N,S,D>& rhs) {
        SurdFrac<N,S,D> lhs(*this);
        return lhs += rhs;
    }

    SurdFrac<N,S,D>& operator-=(const SurdFrac<N,S,D> &rhs) {
        SurdFrac<N, S, D> rhsNeg(rhs);

        rhsNeg.n1 = (-rhs.n1);
        rhsNeg.n2 = (-rhs.n2);

        return *this += rhsNeg;
    }

    SurdFrac<N,S,D> operator-(const SurdFrac<N,S,D> &rhs) {
        SurdFrac<N,S,D> lhs(*this);
        return lhs -= rhs;
    }

    SurdFrac<N,S,D>& operator*=(const SurdFrac<N,S,D> &rhs) {

        // get top products
        std::vector<std::tuple<unsigned long, long> > products{
                {s1 * rhs.s1, n1 * rhs.n1},
                {s1 * rhs.s2, n1 * rhs.n2},
                {s2 * rhs.s1, n2 * rhs.n1},
                {s2 * rhs.s2, n2 * rhs.n2}
        };

        // reduce surd products
        for (auto &prod : products) {
            auto devisor = MathFunc::DivideSurd(std::get<0>(prod));

            std::get<0>(prod) /= (devisor * devisor);
            std::get<1>(prod) *= devisor;
        }


        // organise surd products in ascending order
        std::sort(products.begin(), products.end(), MathFunc::ProductTupleSort);

        auto check(products.begin());
        auto i(check + 1);


        // sum non-unique products
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

        // too many unique surds
        if (products.size() > 2) throw std::bad_cast();

        if (products.empty()) {
            s1 = s2 = 0;
            d = 1;
            return *this;
        }


        unsigned long commonFactor(d * rhs.d);

        // divide out numerators
        for (auto &prod : products) {

            commonFactor = MathFunc::GCD(commonFactor, (unsigned long)std::abs( std::get<1>(prod) ) );
        }

        if ( ((d * rhs.d) / commonFactor) > std::numeric_limits<D>::max() ) throw std::bad_cast();

        // reduce devisor
        d = (D) ((d * rhs.d) / commonFactor);

        // reduce numerators
        for (auto &prod : products) {
            if ( std::abs(std::get<1>(prod)) / commonFactor > std::numeric_limits<N>::max() ) throw std::bad_cast();

            // dividing the negative value gives overflow (for some reason)
            if(std::get<1>(prod) < 0) {
                std::get<1>(prod) = -1 * (std::abs(std::get<1>(prod)) / commonFactor);
            } else std::get<1>(prod)/=commonFactor;
        }

        // replace values
        if (products.size() == 1) {
            n1 = (N) std::get<1>(products[0]);
            s1 = (S) std::get<0>(products[0]);
        }
        else {
            n1 = (N) std::get<1>(products[0]);
            s1 = (S) std::get<0>(products[0]);

            n2 = (N) std::get<1>(products[1]);
            s2 = (S) std::get<0>(products[1]);
        }

        TidySurd();
        return *this;
    }
    SurdFrac<N,S,D> operator*(const SurdFrac &rhs) {
        SurdFrac<N,S,D> lhs(*this);
        return lhs *= rhs;
    }

    SurdFrac<N,S,D>& operator/=(const SurdFrac<N,S,D> &rhs) {
        // invert surd

        long newDenominator(rhs.n1*rhs.n1*rhs.s1 - rhs.n2*rhs.n2*rhs.s2);
        long newN1(rhs.d*rhs.n1);
        long newN2(-rhs.d*rhs.n2);

        if(newDenominator < 0){
            newN1 = (-newN1);
            newN2 = (-newN2);
            newDenominator = -newDenominator;
        }

        if(newDenominator > std::numeric_limits<D>::max() ||
           newN1 > std::numeric_limits<N>::max() ||
           newN2 > std::numeric_limits<N>::max() ) throw std::bad_cast();

        SurdFrac inverseSurd((N)newN1, (N)newN2, rhs.s1, rhs.s2, (D)newDenominator);

        // ensure surd is minimised
        inverseSurd.SimplifyDenominator();
        return *this *= inverseSurd;
    }

    SurdFrac<N,S,D> operator/(const SurdFrac<N,S,D> &rhs) {
        SurdFrac<N,S,D> lhs(*this);
        return lhs /= rhs;
    }

    SurdFrac<N,S,D> operator-() const{
        SurdFrac<N,S,D> negSurd(-n1,-n2,s1,s2,d);
        return negSurd;
    }

    bool operator==(const SurdFrac<N,S,D> &rhs) {
        return this->n1 == rhs.n1 && this->n2 == rhs.n2 && this->s1 == rhs.s1 && this->s2 == rhs.s2
               && this->d == rhs.d;
    }

    void SimplifyDenominator(){
        D devisor;

        if ((devisor = (D) MathFunc::GCD({(unsigned) std::abs(n1) , (unsigned) std::abs(n2), d})) > 1) {
            n1 /= devisor;
            n2 /= devisor;
            d /= devisor;
        }
    }
    void TidySurd() {
        if((s1 > s2) && s2 != 0){
            S newS1 = s2;
            s2 = s1;
            s1 = newS1;

            N newN1 = n2;
            n2 = n1;
            n1 = newN1;
        }
    }

private:

};

#endif //JCALC_SURDFRAC_H
