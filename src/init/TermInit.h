//
// Created by Joseph Holland  on 10/04/2018.
//

#include "../ErrorMgt/Error.h"

#ifndef JCALC_TERMINIT_H
#define JCALC_TERMINIT_H


class TermInit {
public:
    TermInit(){Initialise();};

    ~TermInit() {DeInitialise();};

private:
    unsigned char Initialise();

    void DeInitialise();

};


#endif //JCALC_TERMINIT_H
