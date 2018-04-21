//
// Created by Joseph Holland  on 19/04/2018.
//

#include "Evaluator.h"

CalculationResult Evaluator::Expr(bool get) {
    CalculationResult result(Term(get));

    for (;;) {
        switch (**evalCursor) {
            case 0x1200 :
                result += Term(true);
                break;
            case 0x1201 :
                result -= Term(true);
                break;
            default:
                return result;
        }
    }
}

CalculationResult Evaluator::Term(bool get) {
    CalculationResult result(IPrimary(get));

    for(;;) {
        switch (**evalCursor) {
            case 0x1800 :
                result *= IPrimary(true);
                break;
            case 0x1801 :
                result /= IPrimary(true);
            default:
                return result;
        }
    }
}

CalculationResult Evaluator::IPrimary(bool get) {
    if (get) (*evalCursor)++;

    switch (**evalCursor) {
        case 0x1200 :
            return -IPrimary(true);
        case 0x1201 :
            return IPrimary(true);
        default:
            if( ((**evalCursor) & 0xFF00U) == 0x1000) {
                CalculationResult result(Number(false));
                if(
                        ( ((**evalCursor) & 0xFF00U ) == 0x2400) ||
                        ( ((**evalCursor) & 0xFF00U ) == 0x2500) ||
                        ( ((**evalCursor) & 0xFF00U ) == 0x2600)
                    ) {
                    FuncPost(&result);
                }
                return result*=Primary(false,true);
            }
            else return Primary(false,false);
    }
}

CalculationResult Evaluator::Primary(bool get, bool fallthrough) {
    if (get) (*evalCursor)++;

    CalculationResult result;

    switch ((**evalCursor) & 0xFF00U) {
        case 0x1700 :
            result=Expr(true);
            if (
                        (*evalCursor==tokenStreamEnd) ||
                        (**evalCursor == 0x1900) ||
                        (**evalCursor == 0x1901)
                    )
                return result;
            else if (**evalCursor!=0x1500)
                // TODO: syntax error
                return Error(0x0000);
            break;
        case 0x1A00 :
            result = Constant(**evalCursor);
            break;
        // TODO: implement other options here (variables etc...)
        default:
            // TODO: implement 1 multiplier
            if(fallthrough) return CalculationResult();
            return Error(0x0000);
    }
    if(
            ( ((**evalCursor) & 0xFF00U ) == 0x2400) ||
            ( ((**evalCursor) & 0xFF00U ) == 0x2500) ||
            ( ((**evalCursor) & 0xFF00U ) == 0x2600)
            ) {
        FuncPost(&result);
    }
    return result*=Primary(false, true);


}

void Evaluator::FuncPost(CalculationResult *result) {
    switch(**evalCursor) {
        // TODO: Implement all type 4 functions
        case 0x2400 :
            Square(result);
            break;
        case 0x2401 :
            XPowY(result);
            break;
        case 0x2402 :
            XPowNegOne(result);
            break;
        case 0x2403 :
            XPowThree(result);
            break;
        case 0x2500 :
            Permute(result);
            break;
        case 0x2501 :
            Combine(result);
            break;
        case 0x2600 :
            Degree(result);
            break;
        case 0x2601 :
            Radian(result);
            break;
        case 0x2602 :
            Gradian(result);
            break;
        case 0x2603 :
            Percent(result);
            break;
        case 0x2604 :
            Factorial(result);
            break;
        default:
            // TODO: implement 4th func fallthrough
            *result = Error(0x0000);
    }
}


