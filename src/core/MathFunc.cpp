//
// Created by Joseph Holland  on 09/11/2018.
//
#include "MathFunc.h"

unsigned MathFunc::GCD(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

unsigned MathFunc::GCD(std::vector<unsigned int> numArray) {
    std::vector<unsigned int> devisors(numArray);

    for(auto i : numArray){
        *devisors.begin() = GCD(*devisors.begin(),i);
    }
    return *devisors.begin();
}


unsigned MathFunc::LCM(unsigned u, unsigned v) {
    return (u*v)/GCD(u,v);
}

