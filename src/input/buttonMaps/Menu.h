//
// Created by Joseph Holland  on 12/04/2018.
//

#ifndef JCALC_MENU_H
#define JCALC_MENU_H

#include <map>
#include <vector>

namespace ButtonMapMenu {









    static std::map<unsigned char, unsigned short> ConstantCategory {
        //  1: Universal    2: Electromagnetic  3: Atomic & nuclear
            {0,0x3000},     {1,0x3001},         {2,0x3002},
        //  4: Pysico-chem
            {10,0x3003},

        //  1: Adopted values   2: other
            {0,0x3004},         {1,0x3005}
    };

    static std::map<unsigned char, unsigned short> ConvertCategory {
        //  1: Length   2: Area     3: Volume
            {0,0x3100}, {1,0x3101}, {2,0x3102},
        //  4: Mass
            {10,0x3103},

        //  1: Velocity 2: Pressure 3: Energy
            {0,0x3104}, {1,0x3105}, {2,0x3106},
        //  4: Power
            {10,0x3107},

        //  1: Temperature
            {0,0x3108}
    };


    static std::vector<unsigned short> ConstantValue {
            // Universal
                //  1:Plank Constant            2: Reduced Plank Constant   3: Vaccuum Speed of Light
                    0x1A02,                     0x1A03,                     0x1A04,
                //  4: Vacuum Permittivity      5: Vacuum Permeability      6: Vacuum Characteristic Impedance
                    0x1A05,                     0x1A06,                     0x1A07,
                //  7: Constant of Gravitation  8: Plank Length             9: Plank time
                    0x1A08,                     0x1A09,                     0x1A0A,

            // Electromagnetic
                //  1: Nuclear Magneton         2: Bohr Magneton            3: Elementary Charge
                    0x1A0B,                     0x1A0C,                     0x1A0D,
                //  4: Magnetic Flux Quantum    5: Conductance Quantum  6: Josephson Constant
                    0x1A0E,                     0x1A0F,                 0x1A10,
                //  7: Von Klitzing Constant
                    0x1A11,

            // Atomic & Nuclear
                //  1: Proton Mass                  2: Neutron Mass                 3: Electron Mass
                    0x1A12,                         0x1A13,                         0x1A14,
                //  4: Muon Mass                    5: Bohr Radius                  6: Fine Structure Constant
                    0x1A15,                         0x1A16,                         0x1A17,
                //  7: Classical Electron Radius    8: Electron Compton Wavelength  9: Proton Gyromagnetic Ratio
                    0x1A18,                         0x1A19,                         0x1A1A,
                //  A: Proton Compton Wavelength    B: Neutron Compton Wavelength   C: Rydberg Constant
                    0x1A1B,                         0x1A1C,                         0x1A1D,
                //  D: Proton Magnetic Moment       E: Electron Magnetic Moment     F: Neutron Magnetic Moment
                    0x1A1E,                         0x1A1F,                         0x1A20,
                //  M: Muon Magnetic Moment         x: Tau Lepton Mass
                    0x1A21,                         0x1A22,

            // Physico-Chemical
                //  1: Atomic Mass Constant     2: Faraday Constant             3: Avagadro Constant
                    0x1A23,                     0x1A24,                         0x1A25,
                //  4: Boltzmann Constant       5: Molar Volume of an Ideal Gas 6: Gas Constant
                    0x1A26,                     0x1A27,                         0x1A28,
                //  7: First Radiation Constant 8: Second Radiation Constant    9: Stefan-Boltzmann Constant
                    0x1A29,                     0x1A2A,                         0x1A2B,

            // Adopted Values
                //  1: Accn of Gravity      2: Standard Atmosphere  3: Von Klitzing Constant
                    0x1A2C,                 0x1A2D,                 0x1A2E,
                //  4: Josephson Constant
                    0x1A2F,

            // Other
                //  1: Freezing point of water
                    0x1A30
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
