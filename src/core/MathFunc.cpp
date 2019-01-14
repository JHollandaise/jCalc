//
// Created by Joseph Holland  on 09/11/2018.
//
#include "MathFunc.h"

unsigned long MathFunc::GCD(unsigned long u, unsigned long v) {
    while ( v != 0) {
        unsigned long r = u % v;
        u = v;
        v = r;
    }
    return u;
}

unsigned long MathFunc::GCD(std::vector<unsigned long> numArray) {
    std::vector<unsigned long> devisors(numArray);

    for(auto i : numArray){
        *devisors.begin() = GCD(*devisors.begin(),i);
    }
    return *devisors.begin();
}


unsigned long MathFunc::LCM(unsigned long u, unsigned long v) {
    return (u*v)/GCD(u,v);
}

unsigned long MathFunc::DivideSurd(unsigned long surd) {
    // reduce surd and return devisor

    unsigned long devisor(1);

    for(auto i = 2; (i*i) <= surd ;i++){
        if( !(surd % (i*i)) ){
            surd /= (i*i);
            devisor *= i;
        }
    }

    return devisor;
}

bool MathFunc::ProductTupleSort(std::tuple<unsigned long, long> u,
        std::tuple<unsigned long, long> v) {
    return ( std::get<0>(u) < std::get<0>(v) );
}
