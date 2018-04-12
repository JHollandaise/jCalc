//
// Created by Joseph Holland  on 09/04/2018.
//

#ifndef JCALC_ERROR_H
#define JCALC_ERROR_H


#include <string>

class Error {
public:
    Error(): value((unsigned char)255), message("no error"){};

    unsigned char GetValue(){return value;}

private:
    unsigned char value;
    std::string message;
};


#endif //JCALC_ERROR_H
