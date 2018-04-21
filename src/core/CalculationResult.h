//
// Created by Joseph Holland  on 19/04/2018.
//

#ifndef JCALC_CALCULATIONRESULT_H
#define JCALC_CALCULATIONRESULT_H


struct CalculationResult {

    // TODO: add initialisation
    CalculationResult(const CalculationResult& _calculationResult) {numerator = _calculationResult.numerator;};
    CalculationResult() : numerator(0){};

    long numerator;

    CalculationResult& operator=(const CalculationResult&);

    CalculationResult& operator+=(const CalculationResult&);
    CalculationResult& operator-=(const CalculationResult&);

    CalculationResult& operator*=(const CalculationResult&);
    CalculationResult& operator/=(const CalculationResult&);

    CalculationResult operator-();
};


#endif //JCALC_CALCULATIONRESULT_H
