//
// Created by Joseph Holland  on 22/01/2019.
//

#include "MenuPage.h"

MenuPage::MenuPage(std::vector<unsigned short>* _tokenSelections,
                  std::vector<std::string>* _selectionStrings,
                  std::string* _title = nullptr,
                  MenuPage *_parent = nullptr,
                  std::vector<const MenuPage*>* _childrenMenuPages = nullptr):

tokenSelections(_tokenSelections), selectionStrings(_selectionStrings),
title(_title),parent(_parent),childrenMenuPages(_childrenMenuPages)
{
    // if has children, assign as parent to each child
    if(childrenMenuPages) {
        for(auto child : *childrenMenuPages) {
            child->setParent(this);
        }
    }
}


unsigned short MenuPage::GetActionToken() {

    return 0;
}



// initialise extern MenuPages for all available menus
namespace MenuPages {

    using namespace std;

    /////// SINGLE PAGE MENUS ////////

        vector<unsigned short> hyperbolicTokens{0x220C,0x220D,0x220E,0x220F,0x2210,0x2211};
    vector<string> hyperbolicStrings{"sinh","cosh","tanh","sinh^{-1}","cosh^{-1}","tanh^{-1}"};

    // bottom and top level hyperbolic menu (no parents or children)
    const MenuPage hyperbolic(&hyperbolicTokens, &hyperbolicStrings);


    vector<unsigned short> modeTokens{0x5800,0x5801,0x5802,0x5803,0x5804,0x5805,0x5806,0x5807};
    vector<string> modeStrings{"comp","cmplx","stat","base-n","eqn","matrix","table","vector"};

    // mode selection
    const MenuPage mode{&modeTokens,&modeStrings};


    vector<unsigned short>drgTokens{0x2600,0x2601,0x2602};
    vector<string>drgStrings{"@degree@","@radian@","@gradian@"};
    // TODO: implement special strings for symbol reference

    const MenuPage drg{&drgTokens,&drgStrings};

    vector<unsigned short>clearTokens{0x5900,0x5901,0x5902};
    vector<string>clearStrings{"Setup Data","Memory","Initialise All"};
    string clearTitle("Reset:");

    const MenuPage clear{&clearTokens,&clearStrings,&clearTitle};

    vector<unsigned short>baseNTokens{0x1B00,0X1B01,0X1B02,0X1B03,0X1B04,0X1B05};
    vector<string>baseNStrings{"and","or","xor","xnor","not","neg"};

    const MenuPage baseN{&baseNTokens,&baseNStrings};

    //////////////////////////////////


    //////// MULTI-PAGE MENUS ////////

        // SETUP PAGES

            // note, childeren pages are assigned parent by parent page

            // Input/Output:
            vector<unsigned short>setupIOTokens{0x4000,0x4001,0x4002,0x4003};
            vector<string>setupIOStrings{"MathI/MathO","MathI/decimalO","LineI/LineO","LineI/DecimalO"};

            const MenuPage setupIO(&setupIOTokens,&setupIOStrings);

            // Angle Unit

            vector<unsigned short>setupAngleUnitTokens{0x4100,0x4101,0x4102};
            vector<string>setupAngleUnitStrings{"Degree","Radian","Gradian"};

            const MenuPage setupAngleUnit(&setupAngleUnitTokens,&setupAngleUnitStrings);

            // Number Format

            vector<unsigned short>setupNumberFormatTokens{0x4200,0x4201,0x4202};
            vector<string>setupNumberFormatStrings{"Fix","Sci","Norm"};

            const MenuPage setupNumberFormat(&setupNumberFormatTokens,&setupNumberFormatStrings);

            // Engineering Symbol

            vector<unsigned short>setupEngSymbolTokens{0x4300,0x4301};
            vector<string>setupEngSymbolStrings{"On","Off"};

            const MenuPage setupEngSymbol(&setupEngSymbolTokens,&setupEngSymbolStrings);

            // Fraction Result

            vector<unsigned short>setupFracResultTokens{0x4400,0x4401};
            vector<string>setupFracResultStrings{"ab/c","d/c"};

            const MenuPage setupFracResult(&setupFracResultTokens,&setupFracResultStrings);

            // Complex Result

            vector<unsigned short>setupComplexResultTokens{0x4500,0x4501};
            vector<string>setupComplexResultStrings{"a+bi","r@angle@@theta@"};

            const MenuPage setupComplexResult(&setupComplexResultTokens,&setupComplexResultStrings);


            // TODO: implement remaining setup MenuPages

            // parent (top-level) setup page

            vector<string>setupStrings{"Input/Output","Angle Unit", "Number Format",
                                       "Engineer Symbol", "Fraction Result", "Complex"};
            vector<const MenuPage*>setupChildren{&setupIO,&setupAngleUnit,
                                           &setupNumberFormat,&setupEngSymbol,&setupFracResult,
                                           &setupComplexResult};

            const MenuPage setup(nullptr, &setupStrings, nullptr ,nullptr ,&setupChildren);


    // TODO: implement remaining MenuPages








}