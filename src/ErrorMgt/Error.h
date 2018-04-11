//
// Created by Joseph Holland  on 09/04/2018.
//

#ifndef JCALC_ERROR_H
#define JCALC_ERROR_H


#include <string>

class Error {
public:
    Error(): value((char)255), message("no error"){};

    char GetValue(){return value;}

private:
    char value;
    std::string message;
};


#endif //JCALC_ERROR_H
