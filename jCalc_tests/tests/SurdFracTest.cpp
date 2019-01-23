#include "../catch.h"
#include "core/SurdFrac.h"
#include <limits>


TEST_CASE( "SurdFrac Addition", "[SurdFrac]") {
    SurdFrac<short, unsigned short, unsigned short> surdFrac1(-1,3,2,5,2);
    SurdFrac<short, unsigned short, unsigned short> surdFrac2(6,-8,5,2,11);
    SurdFrac<short, unsigned short, unsigned short> surdFrac3(-27,45,2,5,22);

    // simple summation
    CHECK((surdFrac1+surdFrac2 == surdFrac3));
    surdFrac1+=surdFrac2;
    CHECK((surdFrac1==surdFrac3));

    SurdFrac<short, unsigned short, unsigned short> surdFrac4(-1,3,2,3,2);
    SurdFrac<short, unsigned short, unsigned short> surdFrac5(6,-8,5,7,11);

    // too many unique surds
    CHECK_THROWS_AS(surdFrac4+surdFrac5, std::bad_cast);

    SurdFrac<short, unsigned short, unsigned short> surdFrac6(1,1,1,1,std::numeric_limits<uint8_t>::max()-1);
    SurdFrac<short, unsigned short, unsigned short> surdFrac7(1,1,1,1,std::numeric_limits<uint8_t>::max()-2);

    // new denominator too large
    CHECK_THROWS_AS(surdFrac6+surdFrac7, std::bad_cast);

    SurdFrac<short, unsigned short, unsigned short> surdFrac8(0,0,0,0,1);
    SurdFrac<short, unsigned short, unsigned short> surdFrac9(6,-8,5,2,11);
    SurdFrac<short, unsigned short, unsigned short> surdFrac10(-8,6,2,5,11);

    // simple summation
    CHECK((surdFrac8+surdFrac9 == surdFrac10));
    surdFrac8+=surdFrac9;
    CHECK((surdFrac8==surdFrac10));

}

TEST_CASE( "SurdFrac Subtraction" , "[SurdFrac]") {

    SurdFrac<short, unsigned short, unsigned short> surdFrac1(-1,3,2,5,2);
    SurdFrac<short, unsigned short, unsigned short> surdFrac2(6,-8,5,2,11);
    SurdFrac<short, unsigned short, unsigned short> surdFrac3(5,21,2,5,22);

    CHECK((surdFrac1-surdFrac2 == surdFrac3));
    surdFrac1-=surdFrac2;
    CHECK((surdFrac1==surdFrac3));

    SurdFrac<short, unsigned short, unsigned short> surdFrac4(51,0,5,0,16);
    SurdFrac<short, unsigned short, unsigned short> surdFrac5(3,8,7,5,2);
    SurdFrac<short, unsigned short, unsigned short> surdFrac6(-13,-24,5,7,16);

    CHECK((surdFrac4-surdFrac5 == surdFrac6));
    surdFrac4-=surdFrac5;
    CHECK((surdFrac4==surdFrac6));
}

TEST_CASE( "SurdFrac Unary Minus", "[SurdFrac]") {
    SurdFrac<short, unsigned short, unsigned short> surdFrac1(3,5,5,3,12);
    SurdFrac<short, unsigned short, unsigned short> surdFrac2(-3,-5,5,3,12);

    CHECK((-surdFrac1 == surdFrac2));
}

TEST_CASE( "SurdFrac Multiplication", "[SurdFrac]" ) {
    SurdFrac<short, unsigned short, unsigned short> surdFrac1(3,5,5,3,12);
    SurdFrac<short, unsigned short, unsigned short> surdFrac2(18,0,7,0,15);
    SurdFrac<short, unsigned short, unsigned short> surdFrac3(5,3,21,35,10);

    // simple multiplication with reduction
    CHECK((surdFrac1 * surdFrac2 == surdFrac3));
    surdFrac1*=surdFrac2;
    CHECK((surdFrac1==surdFrac3));

    SurdFrac<short, unsigned short, unsigned short> surdFrac4(6,4,7,3,5);
    SurdFrac<short, unsigned short, unsigned short> surdFrac5(8,-9,7,3,4);
    SurdFrac<short, unsigned short, unsigned short> surdFrac6(114,-11,1,21,10);

    // regroup surd multiples
    CHECK( (surdFrac4*surdFrac5==surdFrac6));

    SurdFrac<short, unsigned short, unsigned short> surdFrac7(-1,3,2,5,2);
    SurdFrac<short, unsigned short, unsigned short> surdFrac8(6,-8,5,2,11);
    SurdFrac<short, unsigned short, unsigned short> surdFrac9(53,-15,1,10,11);

    // negatives etc
    CHECK( (surdFrac7*surdFrac8==surdFrac9));

    SurdFrac<short, unsigned short, unsigned short> surdFrac10(std::numeric_limits<short>::max() -1,1,1,1,1);
    SurdFrac<short, unsigned short, unsigned short> surdFrac11(std::numeric_limits<short>::max() -1,1,1,1,1);
    // numerator overflow
    CHECK_THROWS_AS(surdFrac10*surdFrac11, std::bad_cast);

    SurdFrac<short, unsigned short, unsigned short> surdFrac12(1,2,3,5,1);
    SurdFrac<short, unsigned short, unsigned short> surdFrac13(1,7,11,3,5);
    // overflow in number of unique surds
    CHECK_THROWS_AS(surdFrac12 * surdFrac13, std::bad_cast);
}

TEST_CASE( "SurdFrac Division" , "[SurdFrac]") {
    SurdFrac<short, unsigned short, unsigned short> surdFrac1(-1,3,2,5,2);
    SurdFrac<short, unsigned short, unsigned short> surdFrac2(6,0,5,0,11);
    SurdFrac<short, unsigned short, unsigned short> surdFrac3(165,-11,1,10,60);

    CHECK((surdFrac1/surdFrac2 == surdFrac3));
    surdFrac1/=surdFrac2;
    CHECK((surdFrac1==surdFrac3));
}