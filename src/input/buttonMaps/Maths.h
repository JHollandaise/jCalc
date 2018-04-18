//
// Created by Joseph Holland  on 10/04/2018.
//

#ifndef JCALC_BUTTONDEFS_H
#define JCALC_BUTTONDEFS_H

#include <map>

namespace ButtonMapMaths{
    static std::map<unsigned char,unsigned short> Default {
        //  1               2               3               +               -               =(EXE)
            {0,0x1001},     {1,0x1002},     {2,0x1003},     {3,0x1200},     {4,0x1201},     {6,0x5000},
        //  4               5               6               *               /               Ans
            {10,0x1004},    {11,0x1005},    {12,0x1006},    {13,0x1800},    {14,0x1801},    {16,0x16FF},
        //  7               8               9               DEL             AC              *10^x
            {20,0x1007},    {21,0x1008},    {22,0x1009},    {23,0x5100},    {24,0x5101},    {26,0x2000},
        //  RCL             ENG             (               )               S-D             M+              .
            {30,0x5200},    {31,0x5300},    {32,0x1700},    {33,0x1500},    {34,0x5301},    {35,0x5001},    {36,0x1100},
        //  (-)             •'"             hyp             sin             cos             tan             0
            {40,0x1300},    {41,0x2100},    {42,0x5400},    {43,0x2200},    {44,0x2201},    {45,0x2202},    {46,0x1000},
        //  (a/b)           sqrt            square          PowerN          log             ln
            {50,0x2300},    {51,0x2301},    {52,0x2400},    {53,0x2401},    {54,0x2203},    {55,0x2204},
        //  calc            integrate       left            down            x^-1            logab
            {60,0x5002},    {61,0x2302},    {62,0x5500},    {63,0x5501},    {64,0x2402},    {65,0x2303},
        //  shift           alpha           up              right           mode
            {70,0x5201},    {71,0x5202},    {72,0x5502},    {73,0x5503},    {74,0x5401}
    };

    static std::map<unsigned char,unsigned short> Shift {
        //  pol             rec             aprrox
            {3,0x2205},     {4,0x2206},     {6,0x5302},
        //  permutate       combine         DRG
            {13,0x2500},    {14,0x2501},    {16,0x5402},
        //  constant        convert         clear           insert          off             pi,
            {20,0x5403},    {21,0x5404},    {22,0x5405},    {23,0x5600},    {24,0x5700},    {26,0x1A00},
        //  store           percent         comma           properImproper  M-              ran#
            {30,0x5003},    {32,0x2603},    {33,0x1400},    {34,0x5303},    {35,0x5004},    {36,0x5700},
        //  abs             sin^-1          cos^-1          tan^-1          round
            {42,0x2304},    {43,0x2207},    {44,0x2208},    {45,0x2209},    {46,0x220A},
        //  a(b/c)          cubeRoot        x^3             rootN           10^x            e^x
            {50,0x2305},    {51,0x2306},    {52,0x2403},    {53,0x2307},    {54,0x2308},    {55,0x2309},
        //  solve           differentiate   factorial       summation
            {60,0x5005},    {61,0x230A},    {64,0x2604},    {65,0x230B},
        //  setup
            {74,0x5406}
    };

    static std::map<unsigned char,unsigned short> Alpha {

        //  e
            {26,0x1A01},
        //  VarX            VarY            VarM            randInt
            {33,0x1600},    {34,0x1601},    {35,0x1602},    {36,0x220B},
        //  VarA            VarB            VarC            VarD            VarE            VarF
            {40,0x1603},    {41,0x1604},    {42,0x1605},    {43,0x1606},    {44,0x1607},    {45,0x1608},
        //  '='             :
            {60,0x1901},    {61,0x1900}
    };

    static std::map<unsigned char, unsigned short> RCL {
            //  VarX            VarY            VarM
            {33,0x1600},    {34,0x1601},    {35,0x1602},
            //  VarA            VarB            VarC            VarD            VarE            VarF
            {40,0x1603},    {41,0x1604},    {42,0x1605},    {43,0x1606},    {44,0x1607},    {45,0x1608},
    };

}
#endif //JCALC_BUTTONDEFS_H
