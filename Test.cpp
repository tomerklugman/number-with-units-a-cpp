#include "doctest.h"
#include "NumberWithUnits.hpp"

#include <sstream>

using namespace std;
using namespace ariel;

// unit class for test
NumberWithUnits km{2, "km"};
NumberWithUnits m{2, "m"};
NumberWithUnits cm{2, "cm"};
NumberWithUnits ton{2, "ton"};
NumberWithUnits kg{2, "kg"};
NumberWithUnits g{2, "g"};
NumberWithUnits hour{2, "hour"};
NumberWithUnits minu{2, "min"};
NumberWithUnits sec{2, "sec"};
NumberWithUnits usd{2, "usd"};
NumberWithUnits ils{2, "ils"};

TEST_CASE("bad input")
{                                               // NumberWithUnits(has to be int from signature, "check if there number and unit")
    CHECK_THROWS(NumberWithUnits(2, ""));       // empty
    CHECK_THROWS(NumberWithUnits(2, "123"));    //num
    CHECK_THROWS(NumberWithUnits(2, "123 km")); //theres already num
    CHECK_THROWS(NumberWithUnits(2, "inch"));   // not viable unit

    NumberWithUnits a; // check bad input from string
    istringstream sample_input{"700 [ inch ]"};
    CHECK_THROWS(sample_input >> a);
}

TEST_CASE("check operators")
{
    //+
    CHECK((km + km) == NumberWithUnits(4, "km"));
    CHECK((km + m) == NumberWithUnits(2002, "m"));
    CHECK((m + cm) == NumberWithUnits(102, "cm"));
    //-
    CHECK((kg - kg) == NumberWithUnits(0, "kg"));
    CHECK((kg - g) == NumberWithUnits(998, "kg"));
    CHECK((ton - kg) == NumberWithUnits(1998, "kg"));
    //*
    CHECK((2 * hour) == NumberWithUnits(4, "hour"));
    CHECK((2 * minu) == NumberWithUnits(4, "min"));
    CHECK((2 * sec) == NumberWithUnits(4, "sec"));
    //+=
    CHECK((usd += ils) == NumberWithUnits(8.66, "ils"));
    //>
    CHECK(km > m);
    CHECK_FALSE(m > km);
    CHECK(m > cm);
    CHECK_FALSE(cm > m);
    CHECK(ton > kg);
    CHECK_FALSE(kg > ton);
    CHECK(kg > g);
    CHECK_FALSE(g > kg);
    CHECK(hour > minu);
    CHECK_FALSE(minu > hour);
    CHECK(minu > sec);
    CHECK_FALSE(sec > minu);
    CHECK(usd > ils);
    CHECK_FALSE(ils > usd);
    //>=
    CHECK((km + m) >= NumberWithUnits(2, "km"));
    CHECK((km + m) >= NumberWithUnits(1.002, "km"));
    //<
    CHECK_FALSE(km < m);
    CHECK(m < km);
    CHECK_FALSE(m < cm);
    CHECK(cm < m);
    CHECK_FALSE(ton < kg);
    CHECK(kg < ton);
    CHECK_FALSE(kg < g);
    CHECK(g < kg);
    CHECK_FALSE(hour < minu);
    CHECK(minu < hour);
    CHECK_FALSE(minu < sec);
    CHECK(sec < minu);
    CHECK_FALSE(usd < ils);
    CHECK(ils < usd);
    //<=
    CHECK((km + m) <= NumberWithUnits(3, "km"));
    CHECK((km + m) <= NumberWithUnits(2.002, "km"));
    //==
    CHECK((km + km) <= NumberWithUnits(4, "km"));
    CHECK((km + m) <= NumberWithUnits(2, "km"));
    CHECK((km + m) <= NumberWithUnits(2.002, "km"));
}
TEST_CASE("check bad unit convert")
{
    CHECK_THROWS(km + kg);
    CHECK_THROWS(km + hour);
    CHECK_THROWS(km + sec);
    CHECK_THROWS(km + usd);
}