//
// Created by Joseph Holland  on 10/04/2018.
//

#ifndef JCALC_BUTTONDEFS_H
#define JCALC_BUTTONDEFS_H

#include <map>

namespace ButtonMapMaths{
    static std::map<unsigned char,unsigned short> Default {
            // numOne, numTwo, numThree, add, subtract, equals,
            {0,0x0A01},{1,0x0A02},{2,0x0A03},{3,0x0200},{4,0x0201},{6,0x1000},
            // numFour, numFive, numSix, multiply, divide, , prevAns,
            {10,0x0A04},{11,0x0A05},{12,0x0A06},{13,0x0800},{14,0x0801},{16,0x06FF},
            // numSeven, numEight, numNine, delChar, allClear, , timesTenPow,
            {20,0x0A07},{21,0x0A08},{22,0x0A09},{23,0x1100},{24,0x1101},{26,0x2000},
            // recall, eng, leftParen, rightParen, fractionDecimal, varMPlus, decimal,
            {30,0x1200},{31,0x1300},{32,0x0700},{33,0x0500},{34,0x1301},{35,0x1001},{36,0x0100},
            // unaryMinu, polarCoords, hyperbolicTrig, sine, cosine, tangent, numZero,
            {40,0x0300},{41,0x2100},{42,0x1400},{43,0x2200},{44,0x2201},{45,0x2202},{46,0x0A00},
            // fraction, squareRoot, square, powerN, log, naturalLog, ,
            {50,0x2300},{51,0x2301},{52,0x2400},{53,0x2401},{54,0x2203},{55,0x2204},
            // calculate, integrate, left, down, xPowNegOne, logab, ,
            {60,0x1002},{61,0x2302},{62,0x1500},{63,0x1501},{64,0x2402},{65,0x2303},
            // shift, alpha, up, right, mode, , 
            {70,0x1201},{71,0x1202},{72,0x1502},{73,0x1503},{74,0x1401}
    };

    static std::map<unsigned char,unsigned short> Shift {
//          , , , polar, rec, , aprrox,
            {3,0x2205},{4,0x2206},{6,0x1302},
//          permutate, combine, , angleSym,
            {13,0x2500},{14,0x2501},{16,0x1402},
//          Constant = 20 , convert, clear, insert, off, , pi,
            {20,0x1403},{21,0x1404},{22,0x1405},{23,0x1600},{24,0x1700},{26,0x0C00},
//          store = 30, , percent, comma, properImproper, varMMinus, ranNum,
            {30,0x1003},{32,0x2603},{33,0x0400},{34,0x1303},{35,0x1004},{36,0x2700},
//           = 40 ,, absolute, inverseSine, inverseCosine, inverseTangent, round,
            {42,0x2304},{43,0x2207},{44,0x2208},{45,0x2209},{46,0x220A},
//          improperFraction = 50, cubeRoot, cube, rootN, tenPower, ePower, ,
            {50,0x2305},{51,0x2306},{52,0x2403},{53,0x2307},{54,0x2308},{55,0x2309},
//          solve = 60, differentiate, , , factorial, sum, ,
            {60,0x1005},{61,0x230A},{64,0x2604},{65,0x230B},
//          setup
            {74,0x1406}
    };
    static std::map<unsigned char,unsigned short> Alpha {
                  
//          e
            {26,0x0C01},
            // VarX        VarY        VarM        randInt
            {33,0x0600},{34,0x0601},{35,0x0602},{36,0x220B},
//          VarA        VarB        VarC        VarD        VarE        VarF
            {40,0x0603},{41,0x0604},{42,0x0605},{43,0x0606},{44,0x0607},{45,0x0608},
//          '='         colon
            {60,0x0901},{61,0x0900}
    };

}
#endif //JCALC_BUTTONDEFS_H
