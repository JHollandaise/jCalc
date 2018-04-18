//
// Created by Joseph Holland  on 16/04/2018.
//

#ifndef JCALC_BASEN_H
#define JCALC_BASEN_H

#include <map>

namespace ButtonMapsBaseN {

    static std::map<unsigned char,unsigned short> Default {
        //  1               2               3               +               -               =(EXE)
            {0,0x1001},     {1,0x1002},     {2,0x1003},     {3,0x1200},     {4,0x1201},     {6,0x5000},
        //  4               5               6               *               /               Ans
            {10,0x1004},    {11,0x1005},    {12,0x1006},    {13,0x1800},    {14,0x1801},    {16,0x16FF},
        //  7               8               9               DEL             AC
            {20,0x1007},    {21,0x1008},    {22,0x1009},    {23,0x5100},    {24,0x5101},
        //  RCL             ENG             (               )               M+
            {30,0x5200},    {31,0x5300},    {32,0x1700},    {33,0x1500},    {35,0x5001},
        //  HexA            HexB            HexC            HexD            HexE            HexF            0
            {40,0x100A},    {41,0x100B},    {42,0x100C},    {43,0x100D},    {44,0x100E},    {45,0x100F},    {46,0x1000},
        //  DEC             HEX             BIN             OCT
            {52,0x5B00},    {53,0x5B01},    {54,0x5B02},    {55,0x5B03},
        //  left
            {62,0x5500},
        //  shift           alpha           up              right           mode
            {70,0x5203},    {71,0x5204},    {72,0x5502},    {73,0x5503},    {74,0x5401}
    };

    static std::map<unsigned char,unsigned short> Shift {
        //  Base Menu
            {2,0x5407},
        //  clear           insert          off
            {22,0x5405},    {23,0x5600},    {24,0x5700},
        //  store           M-
            {30,0x5003},    {35,0x5004},
        //  HexA            HexB            HexC            HexD            HexE            HexF
            {40,0x1B00},    {41,0x1B01},    {42,0x1B02},    {43,0x1B03},    {44,0x1B04},    {45,0x1B05},
        //  DEC             HEX             BIN             OCT
            {52,0x5B00},    {53,0x5B01},    {54,0x5B02},    {55,0x5B03},
        //  setup
            {74,0x5406}
    };

    static std::map<unsigned char,unsigned short> Alpha {

        //  VarX            VarY            VarM
            {33,0x1600},    {34,0x1601},    {35,0x1602},
        //  VarA            VarB            VarC            VarD            VarE            VarF
            {40,0x1603},    {41,0x1604},    {42,0x1605},    {43,0x1606},    {44,0x1607},    {45,0x1608},
        //  :
            {61,0x1900}
    };
}

#endif //JCALC_BASEN_H
