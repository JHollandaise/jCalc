//
// Created by Joseph Holland  on 12/04/2018.
//

#ifndef JCALC_MENU_H
#define JCALC_MENU_H

#include <map>
#include <vector>

namespace ButtonMapMenu {
    static std::vector<std::map<unsigned char, unsigned short> >Hyperbolic {
        {
            //  1: sinh         2: cosh         3: tanh
                {0, 0x220C},    {1, 0x220D},    {2, 0x220E},
            //  4: sinh^-1      5: cos^-1       6: tanh^-1
                {10, 0x220F},   {11, 0x2210},   {12, 0x2211},

            //  AC: Escape
                {24,0x5A00}
        }
    };

    static std::vector<std::map<unsigned char, unsigned short> > Mode {
            {
                //  1: comp         2: cmplx        3: stat
                    {0, 0x5800},    {1, 0x5801},    {2, 0x5802},
                //  4: base-n       5: eqn          6: matrix
                    {10, 0x5803},   {11, 0x5804},   {12, 0x5805},
                //  7: table        8: vector
                    {20, 0x5806},   {21, 0x5807},

                //  AC: Escape
                    {24,0x5A00}
            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > DRG {
            {
                //  1: degree       2: radian       3: gradian
                    {0, 0x2600},    {1, 0x2601},    {2, 0x2602},

                //  AC: Escape
                    {24,0x5A00}
            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > Clear {
            {
                //  1: Setup Data   2: Memory       3: Initialise All
                    {0,0x5900},     {1,0x5901},     {2,0x5902},

                //  AC: Escape
                    {24,0x5A00}

            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > BaseN {
            {
                //  1: and          2: or           3: xor
                    {0, 0x1B00},    {1, 0x1B01},    {2, 0x1B02},
                //  4: xnor         5: not          6: neg
                    {10, 0x1B03},   {11, 0x1B04},   {12, 0x1B05},

                    //  AC: Escape
                    {24,0x5A00}
            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > ConstantCategory {
            // Page 1:
            {
                //  1: Universal    2: Electromagnetic  3: Atomic & nuclear
                    {0,0x3000},     {1,0x3001},         {2,0x3002},
                //  4: Pysico-chem
                    {10,0x3003},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Page 2:
            {
                //  1: Adopted values   2: other
                    {0,0x3004},         {1,0x3005},


                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > ConvertCategory {
            // Page 1:
            {
                //  1: Length   2: Area     3: Volume
                    {0,0x3100}, {1,0x3101}, {2,0x3102},
                //  4: Mass
                    {10,0x3103},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Page 2:
            {
                //  1: Velocity 2: Pressure 3: Energy
                    {0,0x3104}, {1,0x3105}, {2,0x3106},
                //  4: Power
                    {10,0x3107},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Page 3:
            {
                //  1: Temperature
                    {0,0x3108},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > SetupCategory {
            // Page 1:
            {
                //  1: Input/Output     2: Angle Unit   3: Number Format
                    {0,0x3200},         {1,0x3201},     {2,0x3202},
                //  4: Engineer Symbol
                    {10,0x3203},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Page 2:
            {
                //  1: Fraction Result  2: Complex  3: Statistics
                    {0,0x3204},         {1,0x3205}, {2,0x3206},
                //  4: Spreadsheet
                    {10,0x3207},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Page 3:
            {
                //  1: Equation/Func    2: Table    3: Decimal Mark
                    {0,0x3208},         {1,0x3209}, {2,0x320A},
                //  4: Digit Separator
                    {10,0x320B},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Page 4:
            {
                //  1: Multiline Font   2: QR Code  3: Input Method
                    {0,0x320C},         {1,0x320D}, {2,0x320E},
                //  4: Contrast
                    {10,0x320F},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            }
    };

    static std::vector<std::map<unsigned char, unsigned short> > ConstantValue {
            // Universal
            {
                //  1:Plank Constant            2: Reduced Plank Constant   3: Vaccuum Speed of Light
                    {0,0x1A02},                 {1,0x1A03},                 {2,0x1A04},
                //  4: Vacuum Permittivity      5: Vacuum Permeability      6: Vacuum Characteristic Impedance
                    {10, 0x1A05},               {11, 0x1A06},               {12, 0x1A07},
                //  7: Constant of Gravitation  8: Plank Length             9: Plank time
                    {20, 0x1A08},               {21, 0x1A09},               {22, 0x1A0A},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Electromagnetic
            {
                //  1: Nuclear Magneton         2: Bohr Magneton            3: Elementary Charge
                    {0,0x1A0B},                 {1,0x1A0C},                 {2,0x1A0D},
                //  4: Magnetic Flux Quantum     5: Conductance Quantum  6: Josephson Constant
                    {10, 0x1A0E},               {11, 0x1A0F},               {12, 0x1A10},
                //  7: Von Klitzing Constant
                    {20, 0x1A11},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Atomic & Nuclear
            {
                //  1: Proton Mass                  2: Neutron Mass                 3: Electron Mass
                    {0,0x1A12},                     {1,0x1A13},                     {2,0x1A14},
                //  4: Muon Mass                    5: Bohr Radius                  6: Fine Structure Constant
                    {10, 0x1A15},                   {11, 0x1A16},                   {12, 0x1A17},
                //  7: Classical Electron Radius    8: Electron Compton Wavelength  9: Proton Gyromagnetic Ratio
                    {20, 0x1A18},                   {21, 0x1A19},                   {22, 0x1A1A},
                //  A: Proton Compton Wavelength    B: Neutron Compton Wavelength   C: Rydberg Constant
                    {40, 0x1A1B},                   {41, 0x1A1C},                   {42, 0x1A1D},
                //  D: Proton Magnetic Moment       E: Electron Magnetic Moment     F: Neutron Magnetic Moment
                    {43, 0x1A1E},                   {44, 0x1A1F},                   {45, 0x1A20},
                //  M: Muon Magnetic Moment         x: Tau Lepton Mass
                    {35, 0x1A21},                   {33, 0x1A22},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Physico-Chemical
            {
                //  1: Atomic Mass Constant     2: Faraday Constant             3: Avagadro Constant
                    {0,0x1A23},                 {1,0x1A24},                     {2,0x1A25},
                //  4: Boltzmann Constant       5: Molar Volume of an Ideal Gas 6: Gas Constant
                    {10, 0x1A26},               {11, 0x1A27},                   {12, 0x1A28},
                //  7: First Radiation Constant 8: Second Radiation Constant    9: Stefan-Boltzmann Constant
                    {20, 0x1A29},               {21, 0x1A2A},                   {22, 0x1A2B},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },
            // Adopted Values
            {
                //  1: Accn of Gravity      2: Standard Atmosphere  3: Von Klitzing Constant
                    {0,0x1A2C},             {1,0x1A2D},             {2,0x1A2E},
                //  4: Josephson Constant
                    {10, 0x1A2F},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Other
            {
                //  1: Freezing point of water
                    {0,0x1A30},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            }
    };

    // TODO: implement remaining converts
    static std::vector<std::map<unsigned char, unsigned short> > ConvertValue {
            // Length
            {
                //  1: Inches -> Centimemters   2: Centimemters -> Inches   3: Feet -> Meters
                    {0,0x2605},                 {1,0x2606},                 {2,0x2607},
                //  4: Meters -> Feet           5: Yards -> Meters          6: Meters -> Yards
                    {10, 0x2608},               {11, 0x2609},               {12, 0x260A},
                //  7: Miles -> Kilometers      8: Kilometers -> Miles      9: Nautical Miles -> Meters
                    {20, 0x260B},               {21, 0x260C},               {22, 0x2610D},
                //  A: Meters -> Nautical Miles B: Parsecs -> Kilometers    C: Kilometers -> Parsecs
                    {40, 0x260E},               {41, 0x260F},               {42, 0x2610},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Area
            {
                //  1: Acres -> Meters^2    2: Meters^2 -> Acres
                    {0,0x2611},             {1,0x2612},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Volume
            {
                //  1: Galons (US) -> Galons (UK)   2: Galons (US) -> Galons (UK)
                    {0,0x2613},                     {1,0x2614},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Mass
            {
                //  1: Ounces -> Grams      2: Grams -> Ounces  3: Pounds -> Kilograms
                    {0,0x2615},             {1,0x2616},         {2,0x2617},
                //  4: Kilograms -> Pounds
                    {10, 0x2618},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Velocity
            {
                //  1: Kilometers/Hour -> Meters/Second 2: Meters/Second -> Kilometers/Hour
                    {0,0x2619},                         {1,0x261A},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Pressure
            {
                //  1: Atmospheres -> Pascals           2: Pascals -> Atmospheres           3: Milimeters Mercury -> Pascals
                    {0,0x261B},                         {1,0x261C},                         {2,0x261D},
                //  4: Pascals -> Milimeters Mercury    5: Kilogram Force/Cm^2 -> Pascals   6: Pascals -> Kilogram Force/Cm^2
                    {10,0x261E},                        {11,0x261F},                        {12,0x2620},
                //  7: Pound Force/Inch^2 -> kilopascal 8: kilopascal -> Pound Force/Inch^2
                    {20, 0x2621},                       {21, 0x2622},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Energy
            {
                //  1: Kilogram Force Meters -> Joules  2: Joules -> Kilogram Force Meters  3: Joules -> Calories
                    {0,0x2623},                         {1,0x2624},                         {2,0x2625},
                //  4: Calories -> Joules
                    {10,0x2626},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},
                //  AC: Escape
                    {24,0x5A00}
            },

            // Power
            {
                //  1: HorsePower -> Kilowatts  2: Kilowatts -> HorsePower
                    {0,0x2627},                 {1,0x2628},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Temperature
            {
                //  1: Fahrenheit -> Celsius    2: Celsius -> Fahrenheit
                    {0,0x26A9},                 {1,0x262A},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            }

    };

    static std::vector<std::map<unsigned char, unsigned short> > SetupValue {
            // Input/Output:
            {
                //  1: MathI/MathO      2: MathI/decimalO   3: LineI/LinO
                    {0,0x4000},         {1,0x4001},         {2,0x4002},
                //  4: LineI/DecimalO
                    {10,0x4003},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Angle Unit:
            {
                //  1: Degree   2: Radian   3: Gradian
                    {0,0x4100}, {1,0x4101}, {2,0x4102},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Number Format:
            {
                //  1: Fix      2: Sci      3: Norm
                    {0,0x4200}, {1,0x4201}, {2,0x4202},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Engineering Symbol:
            {
                //  1: On       2: Off
                    {0,0x4300}, {1,0x4301},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Fraction Result:
            {
                //  1: ab/b     2: d/c
                    {0,0x4400}, {1,0x4401},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Complex:
            {
                //  1: a+bi     2: r<theta
                    {0,0x4500}, {1,0x4501},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Statistics - Frequency:
            {
                //  1: On       2: Off
                    {0,0x4600}, {1,0x4601},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Spreadsheet:
            {
                //  1: Auto Calculate   2: Show Cell
                    {0,0x4700},         {1,0x4701},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Equation/Func - Complex Result:
            {
                //  1: On       2: Off
                    {0,0x4800}, {1,0x4801},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Table:
            {
                //  1: f(x)     2: f(x), g(x)
                    {0,0x4900}, {1,0x4901},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Decimal Mark:
            {
                //  1: Dot      2: Comma
                    {0,0x4A00}, {1,0x4A01},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Digit Separator:
            {
                //  1: On       2: Off
                    {0,0x4B00}, {1,0x4B01},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Multiline Font:
            {
                //  1: Normal Font  2: Small Font
                    {0,0x4C00},     {1,0x4C01},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // QR Code:
            {
                //  1: Version 3    2: Version 11
                    {0,0x4D00},     {1,0x4D01},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Input Method:
            {
                //  1: Insert   2: Replace
                    {0,0x4E00}, {1,0x4E01},

                //  Down: NextPage
                    {63,0x5501},
                //  Up: PrevPage
                    {72,0x5502},

                //  AC: Escape
                    {24,0x5A00}
            },

            // Change Contrast
            {{0,0x4F00}}

    };
}

#endif //JCALC_MENU_H
