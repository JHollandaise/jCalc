//
// Created by Joseph Holland  on 14/01/2019.
//

#include "../catch.h"
#include "core/CalculationResult.h"

TEST_CASE("CalculationResult Addition", "[CalculationResult]") {
    CalculationResult calculationResult1(3.5,3.8);
    CalculationResult calculationResult2(3.785,3.8);
    CalculationResult calculationResult3(7.285,7.6);


    CHECK((calculationResult1+calculationResult2==calculationResult3));
    calculationResult1+=calculationResult2;
    CHECK((calculationResult1==calculationResult3));

    CalculationResult calculationResult4(3.541,0);
    CalculationResult calculationResult5(SurdFrac<short,unsigned short,unsigned short >(4937,0,1,0,500),0);
    CalculationResult calculationResult6(SurdFrac<short,unsigned short,unsigned short >(2683,0,1,0,200),0);


    CHECK((calculationResult4+calculationResult5==calculationResult6));
    calculationResult4+=calculationResult5;
    CHECK((calculationResult4==calculationResult6));

    CalculationResult calculationResult7(SurdFrac<short,unsigned short,unsigned short >(21,0,5,0,16),
                                         SurdFrac<short,unsigned short,unsigned short >(3,0,7,0,14));
    CalculationResult calculationResult8(SurdFrac<short,unsigned short,unsigned short >(85,0,5,0,19),
                                         SurdFrac<short,unsigned short,unsigned short >(9,0,7,0,17));
    CalculationResult calculationResult9(SurdFrac<short,unsigned short,unsigned short >(1759,0,5,0,304),
                                         SurdFrac<short,unsigned short,unsigned short >(177,0,7,0,238));


    CHECK((calculationResult7+calculationResult8==calculationResult9));
    calculationResult7+=calculationResult8;
    CHECK((calculationResult7==calculationResult9));

}

TEST_CASE("CalculationResult Unary Minus", "[CalculationResult]") {
    CalculationResult calculationResult1(3.5,3.8);
    CalculationResult calculationResult2(-3.5,-3.8);

    CalculationResult calculationResult3(SurdFrac<short,unsigned short,unsigned short >(21,-7,5,0,16),
                                         SurdFrac<short,unsigned short,unsigned short >(3,-12,7,0,14));
    CalculationResult calculationResult4(SurdFrac<short,unsigned short,unsigned short >(-21,7,5,0,16),
                                         SurdFrac<short,unsigned short,unsigned short >(-3,12,7,0,14));

    CHECK((-calculationResult1 == calculationResult2 ));
    CHECK((-calculationResult3 == calculationResult4 ));



}

TEST_CASE("CalculationResult Subtraction", "[CalculationResult]") {
    CalculationResult calculationResult1(3.5,3.8);
    CalculationResult calculationResult2(3.785,3.8);
    CalculationResult calculationResult3(-0.28500000000000014,0);

    CHECK((calculationResult1-calculationResult2==calculationResult3));
    calculationResult1-=calculationResult2;
    CHECK((calculationResult1==calculationResult3));

    CalculationResult calculationResult7(SurdFrac<short,unsigned short,unsigned short >(51,0,5,0,16),
                                         SurdFrac<short,unsigned short,unsigned short >(51,0,5,0,16));
    CalculationResult calculationResult8(SurdFrac<short,unsigned short,unsigned short >(3,8,7,5,2),
                                         SurdFrac<short,unsigned short,unsigned short >(3,8,7,5,2));
    CalculationResult calculationResult9(SurdFrac<short,unsigned short,unsigned short >(-13,-24,5,7,16),
                                         SurdFrac<short,unsigned short,unsigned short >(-13,-24,5,7,16));


    CHECK((calculationResult7-calculationResult8==calculationResult9));
    calculationResult7-=calculationResult8;
    CHECK((calculationResult7==calculationResult9));

    CalculationResult calculationResult10(5.94658048,-5.94658048);
    CalculationResult calculationResult11(1.234668,-1.234668);
    CalculationResult calculationResult12(4.71191248,-4.71191248);


    CHECK((calculationResult10-calculationResult11==calculationResult12));
    calculationResult10-=calculationResult11;
    CHECK((calculationResult10==calculationResult12));

    CalculationResult calculationResult13(SurdFrac<short,unsigned short,unsigned short >(7,0,1,0,2),3.8);
    CalculationResult calculationResult14(3.785,3.8);
    CalculationResult calculationResult15(SurdFrac<short,unsigned short,unsigned short >(-57,0,1,0,200),0);

    CHECK((calculationResult13-calculationResult14==calculationResult15));
    calculationResult13-=calculationResult14;
    CHECK((calculationResult13==calculationResult15));

}

TEST_CASE("CalculationResult Multiplication", "[CalculationResult]") {
    CalculationResult calculationResult1(SurdFrac<short,unsigned short,unsigned short >(3,9,2,1,12),0);
    CalculationResult calculationResult2(0,SurdFrac<short,unsigned short,unsigned short >(2,2,2,1,3));
    CalculationResult calculationResult3(0,SurdFrac<short,unsigned short,unsigned short >(5,4,1,2,6));


    CHECK((calculationResult1*calculationResult2==calculationResult3));
    calculationResult1*=calculationResult2;
    CHECK((calculationResult1==calculationResult3));

    CalculationResult calculationResult4(SurdFrac<short,unsigned short,unsigned short >(1,0,2,0,1),
                                         SurdFrac<short,unsigned short,unsigned short >(3,0,1,0,1));
    CalculationResult calculationResult5(SurdFrac<short,unsigned short,unsigned short >(6,0,1,0,1),
                                         SurdFrac<short,unsigned short,unsigned short >(1,0,5,0,1));
    CalculationResult calculationResult6(SurdFrac<short,unsigned short,unsigned short >(6,-3,2,5,1),
                                         SurdFrac<short,unsigned short,unsigned short >(18,1,1,10,1));


    CHECK((calculationResult4*calculationResult5==calculationResult6));
    calculationResult4*=calculationResult5;
    CHECK((calculationResult4==calculationResult6));

    CalculationResult calculationResult7(3.28594,SurdFrac<short,unsigned short,unsigned short >(1,0,6,0,1));
    CalculationResult calculationResult8(SurdFrac<short,unsigned short,unsigned short >(5,0,1,0,1),0);
    CalculationResult calculationResult9(16.4297,SurdFrac<short,unsigned short,unsigned short >(5,0,6,0,1));


    CHECK((calculationResult7*calculationResult8==calculationResult9));
    calculationResult7*=calculationResult8;
    CHECK((calculationResult7==calculationResult9));

    CalculationResult calculationResult10(SurdFrac<short,unsigned short,unsigned short >(-3,0,2,0,1),
                                         SurdFrac<short,unsigned short,unsigned short >(12,0,1,0,1));
    CalculationResult calculationResult11(SurdFrac<short,unsigned short,unsigned short >(4,0,6,0,1),
                                         SurdFrac<short,unsigned short,unsigned short >(-9,0,5,0,3));
    CalculationResult calculationResult12(SurdFrac<short,unsigned short,unsigned short >(-24,36,3,5,1),
                                         SurdFrac<short,unsigned short,unsigned short >(48,9,6,10,1));


    CHECK((calculationResult10*calculationResult11==calculationResult12));
    calculationResult10*=calculationResult11;
    CHECK((calculationResult10==calculationResult12));


}


