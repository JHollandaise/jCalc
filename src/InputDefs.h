//
// Created by Joseph Holland  on 08/04/2018.
//

// DEBUG: remove before compile
#define TERMINAL_EMULATE

#ifndef JCALC_INPUT_DEFS_H
#define JCALC_INPUT_DEFS_H

#ifdef TERMINAL_EMULATE
#include <map>
#endif //TERMINAL_EMULATE

namespace InputDefs {


#ifdef TERMINAL_EMULATE
    static std::map<int,unsigned char> KeypressMap{
        //  1               2               3               +               -               =(EXE)
            {'1',0},        {'2',1},        {'3',2},        {'+',3},        {'-',4},        {075,6},
        //  4               5               6               *               /               Ans
            {'4',10},       {'5',11},       {'6',12},       {'*',13},       {'/',14},       {'~',16},
        //  7               8               9               DEL             AC              *10^x
            {'7',20},       {'8',21},       {'9',22},       {0177,23},      {033,24},      {'c',26},
        //  RCL             ENG             (               )               S-D             M+              .
            {'z',30},       {'x',31},       {'(',32},       {')',33},       {'b',34},       {'n',35},       {'.',36},
        //  (-)             •'"             hyp             sin             cos             tan             0
            {'a',40},       {'s',41},       {'d',42},       {'f',43},       {'g',44},       {'h',45},       {'0',46},
        //  (a/b)           sqrt            square          PowerN          log             ln
            {'q',50},       {'w',51},       {'e',52},       {'r',53},       {'t',54},       {'y',55},
        //  calc            integrate       left            down            x^-1            logab
            {'u',60},       {'i',61},       {0404,62},      {0402,63},      {'o',64},       {'p',65},
        //  shift           alpha           up              right           mode
            {0x09,70},      {0541,71},      {0403,72},      {0405,73},      {'j',74}
        };
#endif
    enum class CalcMode {
        maths, vector, matrix, stat, baseN, complex
    };

    enum class CalculatorBase {
        decimal, hexedecimal, Binary, Octal
    };

    enum class ButtonType {
        ignore, fallthrough, noAction, menu,
    };

    enum class ButtonDefsNULL {
        NULL0, NULL1, NULL2, NULL3, NULL4, NULL5, NULL6,
        NULL10 = 10, NULL11, NULL12, NULL13, NULL14, NULL15, NULL16,
        NULL20 = 20, NULL21, NULL22, NULL23, NULL24, NULL25, NULL26,
        NULL30 = 30, NULL31, NULL32, NULL33, NULL34, NULL35, NULL36,
        NULL40 = 40, NULL41, NULL42, NULL43, NULL44, NULL45, NULL46,
        NULL50 = 50, NULL51, NULL52, NULL53, NULL54, NULL55, NULL56,
        NULL60 = 60, NULL61, NULL62, NULL63, NULL64, NULL65, NULL66,
        NULL70 = 70, NULL71, NULL72, NULL73, NULL74, NULL75, NULL76,
    };

    enum class ButtonDefsIGNORE {
        IGNORE0, IGNORE1, IGNORE2, IGNORE3, IGNORE4, IGNORE5, IGNORE6,
        IGNORE10 = 10, IGNORE11, IGNORE12, IGNORE13, IGNORE14, IGNORE15, IGNORE16,
        IGNORE20 = 20, IGNORE21, IGNORE22, IGNORE23, IGNORE24, IGNORE25, IGNORE26,
        IGNORE30 = 30, IGNORE31, IGNORE32, IGNORE33, IGNORE34, IGNORE35, IGNORE36,
        IGNORE40 = 40, IGNORE41, IGNORE42, IGNORE43, IGNORE44, IGNORE45, IGNORE46,
        IGNORE50 = 50, IGNORE51, IGNORE52, IGNORE53, IGNORE54, IGNORE55, IGNORE56,
        IGNORE60 = 60, IGNORE61, IGNORE62, IGNORE63, IGNORE64, IGNORE65, IGNORE66,
        IGNORE70 = 70, IGNORE71, IGNORE72, IGNORE73, IGNORE74, IGNORE75, IGNORE76,
    };

    enum class ButtonDefs {
        numOne = 0, numTwo, numThree, add, subtract, NULL5, equals,
        numFour = 10, numFive, numSix, multiply, divide, NULL15, prevAns,
        numSeven = 20 , numEight, numNine, delChar, allClear, NULL25, timesTenPow,
        recall = 30, eng, leftParen, rightParen, fractionDecimal, varMPlus, decimal,
        unaryMinus= 40, polarCoords, hyperbolicTrig, sine, cosine, tangent, numZero,
        fraction = 50, squareRoot, square, powerN, logBaseTen, naturalLog, NULL56,
        calculate = 60, integrate, left, down, xPowNegOne, logab, NULL66,
        shift = 70, alpha, up, right, mode_Setup, NULL75, NULL76
    };
    enum class ButtonDefsShift {
        NULL0, NULL1, NULL2, polar, rec, NULL5, aprrox,
        NULL10 = 10, NULL11, NULL12, permutate, combine, NULL15, angleSym,
        Constant = 20 , convert, clear, insert, off, NULL25, pi,
        store = 30, NULL31, percent, comma, properImproper, varMMinus, ranNum,
        NULL40 = 40 ,NULL41, absolute, inverseSine, inverseCosine, inverseTangent, round,
        improperFraction = 50, cubeRoot, cube, rootN, tenPower, ePower, NULL56,
        solve = 60, differentiate, NULL62, NULL63, factorial, sum, NULL66,
        NULL70 = 70, NULL71, NULL72, NULL73, NULL74, NULL75, NULL76,
    };

    enum class ButtonDefsAlpha {
        NULL0, NULL1, NULL2, NULL3, NULL4, NULL5, NULL6,
        NULL10 = 10, NULL11, NULL12, NULL13, NULL14, NULL15, NULL16,
        NULL20 = 20, NULL21, NULL22, NULL23, NULL24, NULL25, E,
        NULL30 = 30, NULL31, NULL32, varX, varY, varM, randInt,
        varA = 40 ,varB, varC, varD, varE, varF, NULL46,
        NULL50 = 50, NULL51, NULL52, NULL53, NULL54, NULL55, NULL56,
        equals = 60, colon, NULL62, NULL63 , NULL64, NULL65, NULL66,
        NULL70 = 70, NULL71, NULL72, NULL73, NULL74, NULL75, NULL76,
    };

    enum class ButtonDefsComplex {
        NULL0, NULL1, NULL2, NULL3, NULL4, IGNORE5, NULL6,
        NULL10 = 10, NULL11, NULL12, NULL13, NULL14, IGNORE15, NULL16,
        NULL20 = 20, NULL21, NULL22, NULL23, NULL24, IGNORE25, NULL26,
        NULL30 = 30, NULL31, NULL32, NULL33, NULL34, NULL35, NULL36,
        NULL40 = 40, NULL41, NULL42, NULL43, NULL44, NULL45, NULL46,
        NULL50 = 50, NULL51, NULL52, NULL53, NULL54, NULL55, IGNORE56,
        IGNORE60 = 60, IGNORE61, NULL62, NULL63, NULL64, NULL65, IGNORE66,
        NULL70 = 70, NULL71, NULL72, NULL73, NULL74, IGNORE75, IGNORE76,
    };

    enum class ButtonDefsComplexShift {
        IGNORE0, complexMenu, IGNORE2, IGNORE3, IGNORE4, IGNORE5, NULL6,
        IGNORE10 = 10, IGNORE11, IGNORE12, NULL13, NULL14, IGNORE15, NULL16,
        NULL20 = 20, NULL21, NULL22, NULL23, NULL24, IGNORE25, NULL26,
        NULL30 = 30, imaginary, IGNORE32, NULL33, NULL34, NULL35, NULL36,
        arguement = 40, IGNORE41, NULL42, NULL43, NULL44, NULL45, NULL46,
        NULL50 = 50, NULL51, NULL52, NULL53, NULL54, NULL55, IGNORE56,
        IGNORE60 = 60, IGNORE61, IGNORE62, IGNORE63, NULL64, IGNORE65, IGNORE66,
        IGNORE70 = 70, IGNORE71, IGNORE72, IGNORE73, IGNORE74, IGNORE75, IGNORE76,
    };

    enum class ButtonDefsBaseN {
        NULL0, NULL1, NULL2, NULL3, NULL4, IGNORE5, NULL6,
        NULL10 = 10, NULL11, NULL12, NULL13, NULL14, IGNORE15, NULL16,
        NULL20 = 20, NULL21, NULL22, NULL23, NULL24, IGNORE25, IGNORE26,
        NULL30 = 30, IGNORE31, NULL32, NULL33, IGNORE34, NULL35, IGNORE36,
        hexA = 40, hexB, hexC, hexD, hexE, hexF, NULL46,
        IGNORE50 = 50, IGNORE51, decimal, hexedecimal, binary, octal, IGNORE56,
        IGNORE60 = 60, IGNORE61, NULL62, NULL63, IGNORE64, IGNORE65, IGNORE66,
        NULL70 = 70, NULL71, NULL72, NULL73, NULL74, IGNORE75, IGNORE76,
    };

    enum class ButtonDefsBaseNShift {
        IGNORE0, IGNORE1, baseNMenu, IGNORE3, IGNORE4, IGNORE5, IGNORE6,
        IGNORE10 = 10, IGNORE11, IGNORE12, IGNORE13, IGNORE14, IGNORE15, IGNORE16,
        IGNORE20 = 20, IGNORE21, clear, insert, off, IGNORE25, IGNORE26,
        NULL30 = 30, IGNORE31, IGNORE32, IGNORE33, IGNORE34, IGNORE35, IGNORE36,
        hexA = 40, hexB, hexC, hexD, hexE, hexF, IGNORE46,
        IGNORE50 = 50, IGNORE51, decimal, hexedecimal, binary, octal, IGNORE56,
        IGNORE60 = 60, IGNORE61, IGNORE62, IGNORE63, IGNORE64, IGNORE65, IGNORE66,
        IGNORE70 = 70, IGNORE71, IGNORE72, IGNORE73, IGNORE74, IGNORE75, IGNORE76,
    };

    enum class ButtonDefsBaseNAlpha {
        IGNORE0, IGNORE1, IGNORE2, IGNORE3, IGNORE4, IGNORE5, IGNORE6,
        IGNORE10 = 10, IGNORE11, IGNORE12, IGNORE13, IGNORE14, IGNORE15, IGNORE16,
        IGNORE20 = 20, IGNORE21, IGNORE22, IGNORE23, IGNORE24, IGNORE25, IGNORE26,
        IGNORE30 = 30, IGNORE31, IGNORE32, varX, varY, varM, IGNORE36,
        varA = 40 ,varB, varC, varD, varE, varF, IGNORE46,
        IGNORE50 = 50, IGNORE51, IGNORE52, IGNORE53, IGNORE54, IGNORE55, IGNORE56,
        IGNORE60 = 60, IGNORE61, IGNORE62, IGNORE63, IGNORE64, IGNORE65, IGNORE66,
        IGNORE70 = 70, IGNORE71, IGNORE72, IGNORE73, IGNORE74, IGNORE75, IGNORE76,
    };
}

#endif //JCALC_INPUT_DEFS_NAMEME_H

