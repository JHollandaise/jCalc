//
// Created by Joseph Holland  on 10/04/2018.
//

#ifndef JCALC_BUTTONDEFS_H
#define JCALC_BUTTONDEFS_H

#include <map>

namespace ButtonMapMaths{
    static const std::map<char,short> Default {
            // numOne, numTwo, numThree, add, subtract, NULL, equals,
            {0,0x0001},{1,0x0002},{2,0x0003},{3,0x0200},{4,0x0201},{5,0xFF00},{6,0x1000},
            // numFour, numFive, numSix, multiply, divide, NULL15, prevAns,
            {10,0x0004},{11,0x0005},{12,0x0006},{13,0x0800},{14,0x0801},{15,0xFF00},{16,0x06FF},
            // numSeven, numEight, numNine, delChar, allClear, NULL25, timesTenPow,
            {20,0x0007},{21,0x0008},{22,0x0009},{23,0x1100},{24,0x1101},{25,0xFF00},{26,0x2000},
            // recall, eng, leftParen, rightParen, fractionDecimal, varMPlus, decimal,
            {30,0x1200},{31,0x1300},{32,0x0700},{33,0x0500},{34,0x1301},{35,0x1001},{36,0x0100},
            // unaryMinu, polarCoords, hyperbolicTrig, sine, cosine, tangent, numZero,
            {40,0x0300},{41,0x2100},{42,0x1400},{43,0x2200},{44,0x2201},{45,0x2202},{46,0x0000},
            // fraction, squareRoot, square, powerN, log, naturalLog, NULL56,
            {50,0x2300},{51,0x2301},{52,0x2400},{53,0x2401},{54,0x2203},{55,0x2204},{56,0xFF00},
            // calculate, integrate, left, down, xPowNegOne, logab, NULL66,
            {60,0x1002},{61,0x2302},{62,0x1500},{63,0x1501},{64,0x2402},{65,0x2303},{66,0xFF00},
            // shift, alpha, up, right, mode, NULL75, NULL76
            {70,0x1201},{71,0x1202},{72,0x1502},{73,0x1503},{74,0x1401},{75,0xFF00},{76,0xFF00}
    };

    static const std::map<char,short> Shift {
            {0,},{1,},{2,},{3,},{4,},{5,},{6,},

            {10,},{11,},{12,},{13,},{14,},{15,},{16,},

            {20,},{21,},{22,},{23,},{24,},{25,},{26,},

            {30,},{31,},{32,},{33,},{34,},{35,},{36,},

            {40,},{41,},{42,},{43,},{44,},{45,},{46,},

            {50,},{51,},{52,},{53,},{54,},{55,},{56,},

            {60,},{61,},{62,},{63,},{64,},{65,},{66,},

            {70,},{71,},{72,},{73,},{74,},{75,},{76,}
    };

}

#endif //JCALC_BUTTONDEFS_H
