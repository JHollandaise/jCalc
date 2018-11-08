//
// Created by Joseph Holland  on 19/04/2018.
//

#ifndef JCALC_EVALUATOR_H
#define JCALC_EVALUATOR_H


#include <vector>
#include "CalculationResult.h"


class Evaluator {

public:

    explicit Evaluator(std::vector<unsigned short>::iterator* evalCursor) : evalCursor(evalCursor) {};
    // TODO: set at init
    unsigned char returnError{0};

    CalculationResult Expr(bool get);

    std::vector<unsigned short>::iterator* tokenStreamEnd;
    std::vector<unsigned short>::iterator* evalCursor;

private:

    CalculationResult Term(bool get);

    CalculationResult IPrimary(bool get);

    CalculationResult Primary(bool get, bool fallthrough);

    CalculationResult Number(bool get);

    CalculationResult Digits(bool get);

    CalculationResult Error(unsigned char);

    void FuncPost(CalculationResult& result);

    void Square(CalculationResult& result);

    void XPowY(CalculationResult& result);

    void XPowNegOne(CalculationResult& result);

    void XPowThree(CalculationResult& result);

    void Permute(CalculationResult& result);

    void Combine(CalculationResult& result);

    void Degree(CalculationResult& result);

    void Radian(CalculationResult& result);

    void Gradian(CalculationResult& result);

    void Percent(CalculationResult& result);

    void Factorial(CalculationResult& result);

    CalculationResult Constant(std::vector<unsigned short>::iterator* token);


};


#endif //JCALC_EVALUATOR_H
