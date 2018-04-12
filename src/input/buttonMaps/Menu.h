//
// Created by Joseph Holland  on 12/04/2018.
//

#ifndef JCALC_MENU_H
#define JCALC_MENU_H

#include <map>

namespace ButtonMapMenu {
    static std::vector<std::map<unsigned char, unsigned short> >Hyperbolic {
        {
//          1: sinh    2: cosh    3: tanh
            {0, 0x220C}, {1, 0x220D}, {2, 0x220E},
//          4: sinh^-1  5: cos^-1   6: tanh^-1
            {10, 0x220F}, {11, 0x2210}, {12, 0x2211}
        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > Mode {
        {
    //      1: comp    2: cmplx   3: stat
            {0, 0x1800}, {1, 0x1801}, {2, 0x1802},
    //      4: base-n  5: eqn       6: matrix
            {10, 0x1803}, {11, 0x1804}, {12, 0x1805},
    //      7: table      8: vector
            {20, 0x1806}, {21, 0x1807}
        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > DRG {
        {
//          1: degree  2: radian  3: gradian
            {0, 0x0B00}, {1, 0x0B01}, {2, 0x0B02}
        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > Clear {
        {
//          1: Setup Data 2: Memory   3: Initialise All
            {0,0x1900},   {1,0x1901}, {2,0x1902},

        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > ConstantCategory {
//      Page 1:
        {
//          1: Universal 2: Electromagnetic 3: Atomic & nuclear
            {0,0x3000},  {1,0x3001},        {2,0x3002},
//          4: Pysico-chem
            {10,0x3003},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Page 2:
        {
//          1: Adopted values 2: other
            {0,0x3004},       {1,0x3005},


//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > ConvertCategory {
//      Page 1:
        {
//          1: Length    2: Area    3: Volume
            {0,0x3100}, {1,0x3101}, {2,0x3102},
//          4: Mass
            {10,0x3103},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Page 2:
        {
//          1: Velocity 2: Pressure 3: Energy
            {0,0x3104}, {1,0x3105}, {2,0x3106},
//          4: Power
            {10,0x3107},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Page 3:
        {
//          1: Temperature
            {0,0x3108},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502},


        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > SetupCategory {
//      Page 1:
        {
//          1: Input/Output 2: Angle Unit   3: Number Format
            {0,0x3200},     {1,0x3201},     {2,0x3202},
//          4: Engineer Symbol
            {10,0x3203},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Page 2:
        {
//          1: Fraction Result  2: Complex  3: Statistics
            {0,0x3204},         {1,0x3205}, {2,0x3206},
//          4: Spreadsheet
            {10,0x3207},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Page 3:
        {
//          1: Equation/Func 2: Table    3: Decimal Mark
            {0,0x3208},      {1,0x3209}, {2,0x320A},
//          4: Digit Separator
            {10,0x320B},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Page 4:
        {
//          1: Multiline Font   2: QR Code  3: Contrast
            {0,0x320C},         {1,0x320D}, {2,0x320E},


//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        }
    };

    // TODO: implement remaining constants
    static std::vector<std::map<unsigned char, unsigned short> > ConstantValue {
        // universal
        {
//          1: h
            {0,0x0C02}
        }
    };

    // TODO: implement remaining converts
    static std::vector<std::map<unsigned char, unsigned short> > ConvertValue {
        // length
        {
//          1: in->cm
            {0,0x0C02}
        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > SetupValue {
//      Input/Output:
        {
//          1: MathI/MathO  2: Angle Unit   3: Number Format
            {0,0x4000},     {1,0x4001},     {2,0x4002},
//          4: Engineer Symbol
            {10,0x4003},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        },

//      Angle Unit:
        {
//          1: MathI/MathO  2: Angle Unit   3: Number Format
            {0,0x4000},     {1,0x4001},     {2,0x4002},
//          4: Engineer Symbol
            {10,0x4003},

//          down: NextPage
            {63,0x1501},
//          up: PrevPage
            {72,0x1502}
        }
    };
}

#endif //JCALC_MENU_H
