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
//          NULL0, NULL1, NULL2, polar, rec, NULL5, aprrox,
            {0,0xFF00},{1,0xFF00},{2,0xFF00},{3,0x2205},{4,0x2206},{5,0xFF00},{6,0x1302},
//          NULL10 = 10, NULL11, NULL12, permutate, combine, NULL15, angleSym,
            {10,0xFF00},{11,0xFF00},{12,0xFF00},{13,0x2500},{14,0x2501},{15,0xFF00},{16,0x1402},
//          Constant = 20 , convert, clear, insert, off, NULL25, pi,
            {20,0x1403},{21,0x1404},{22,0x1405},{23,0x1600},{24,0x1700},{25,0xFF00},{26,0x06##}, // TODO: implement const storage
//          store = 30, NULL31, percent, comma, properImproper, varMMinus, ranNum,
            {30,0x1003},{31,0xFF00},{32,0x2603},{33,0x0400},{34,0x1303},{35,0x1004},{36,0x2700},
//          NULL40 = 40 ,NULL41, absolute, inverseSine, inverseCosine, inverseTangent, round,
            {40,0xFF00},{41,0xFF00},{42,0x2304},{43,0x2207},{44,0x2208},{45,0x2209},{46,0x220A},
//          improperFraction = 50, cubeRoot, cube, rootN, tenPower, ePower, NULL56,
            {50,0x2305},{51,0x2306},{52,0x2403},{53,0x2307},{54,0x2308},{55,0x2309},{56,0xFF00},
//          solve = 60, differentiate, NULL62, NULL63, factorial, sum, NULL66,
            {60,0x1005},{61,0x230A},{62,0xFF00},{63,0xFF00},{64,0x2604},{65,0x230B},{66,0xFF00},
//          NULL70 = 70, NULL71, NULL72, NULL73, NULL74, NULL75, NULL76,
            {70,0xFF00},{71,0xFF00},{72,0xFF00},{73,0xFF00},{74,0xFF00},{75,0xFF00},{76,0xFF00}
    };
    static const std::map<char,char> Alpha {
            {0,0xFF00}, {1,0xFF00}, {2,0xFF00}, {3,0xFF00}, {4,0xFF00}, {5,0xFF00}, {6,0xFF00},
            {10,0xFF00},{11,0xFF00},{12,0xFF00},{13,0xFF00},{14,0xFF00},{15,0xFF00},{16,0xFF00},
            {20,0xFF00},{21,0xFF00},{22,0xFF00},{23,0xFF00},{24,0xFF00},{25,0xFF00},{26,0xFF00},
                                             // VarX        VarY        VarM        randInt
            {30,0xFF00},{31,0xFF00},{32,0xFF00},{33,0x0600},{34,0x0601},{35,0x0602},{36,0x220B},
//          VarA        VarB        VarC        VarD        VarE        VarF
            {40,0x0603},{41,0x0604},{42,0x0605},{43,0x0606},{44,0x0607},{45,0x0608},{46,0xFF00},
            {50,0xFF00},{51,0xFF00},{52,0xFF00},{53,0xFF00},{54,0xFF00},{55,0xFF00},{56,0xFF00},
//          '='         colon
            {60,0x0901},{61,0x0900},{62,0xFF00},{63,0xFF00},{64,0xFF00},{65,0xFF00},{66,0xFF00},
            {70,0xFF00},{71,0xFF00},{72,0xFF00},{73,0xFF00},{74,0xFF00},{75,0xFF00},{76,0xFF00}
    };

}
#endif //JCALC_BUTTONDEFS_H
