//
// Created by Joseph Holland  on 10/04/2018.
//

#include "ErrorMgt/Error.h"
#include "GUI/tigr.h"
#include "core/Calculator.h"

#ifndef JCALC_TERMINIT_H
#define JCALC_TERMINIT_H


class TermInit {
public:
    TermInit(){Initialise();};

    ~TermInit() {DeInitialise();};

    // TODO: tigr screen init here

private:
    unsigned char Initialise();

    void DeInitialise();


};


#endif //JCALC_TERMINIT_H
