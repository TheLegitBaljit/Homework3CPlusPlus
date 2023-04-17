#include <iostream>
#include "sources/Fraction.hpp"
#include "doctest.h"
#include <sstream>


TEST_CASE("Test + operator") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 6);
    Fraction f4(7, 8);

    CHECK(((f1 + f2) == Fraction(5, 4)));
    CHECK(((f3 + f4) == Fraction(41, 24)));
}
TEST_CASE("Test - operator") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 6);
    Fraction f4(7, 8);

    CHECK((f1 - f2 == Fraction(-1, 4)));
    CHECK((f3 - f4 == Fraction(-1, 24)));
}
TEST_CASE("Test * operator") {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(5, 6);
    Fraction f4(7, 8);

    CHECK((f1 * f2 == Fraction(3, 8)));
    CHECK((f3 * f4 == Fraction(35, 48)));
}
TEST_CASE("testing the / operator") {
    CHECK((Fraction(1,2) / Fraction(3,4) == Fraction(2,3)));
    CHECK((Fraction(1,2) / 0.5 == Fraction(1,1)));
}
TEST_CASE("testing the == operator") {
    CHECK((Fraction(1,2) == Fraction(2,4)));
    CHECK((Fraction(1,2) == 0.5));
    CHECK_FALSE((Fraction(1,2) == Fraction(3,4)));
    CHECK_FALSE((Fraction(1,2) == 0.75));
}

TEST_CASE("testing the comparison (<,>,<=,>=) operators") {
    CHECK((Fraction(1,2) < Fraction(3,4)));
    CHECK((Fraction(1,2) < 0.75));
    CHECK_FALSE((Fraction(1,2) < Fraction(1,4)));
    CHECK_FALSE((Fraction(1,2) < 0.25));

    CHECK((Fraction(1,2) > Fraction(1,4)));
    CHECK((Fraction(1,2) > 0.25));
    CHECK_FALSE((Fraction(1,2) > Fraction(3,4)));
    CHECK_FALSE((Fraction(1,2) > 0.75));

    CHECK((Fraction(1,2) <= Fraction(3,4)));
    CHECK((Fraction(1,2) <= 0.75));
    CHECK((Fraction(1,2) <= Fraction(1,2)));
    CHECK((Fraction(1,2) <= 0.5));
    CHECK_FALSE((Fraction(1,2) <= Fraction(1,4)));
    CHECK_FALSE((Fraction(1,2) <= 0.25));

    CHECK((Fraction(1,2) >= Fraction(1,4)));
    CHECK((Fraction(1,2) >= 0.25));
    CHECK((Fraction(1,2) >= Fraction(1,2)));
    CHECK((Fraction(1,2) >= 0.5));
    CHECK_FALSE((Fraction(1,2) >= Fraction(3,4)));
    CHECK_FALSE((Fraction(1,2) >= 0.75));
}
TEST_CASE("testing the ++ and -- operators") {
    Fraction f = Fraction(1,2);
    CHECK((++f == Fraction(3,2)));
    CHECK((f++ == Fraction(3,2)));
    CHECK((f == Fraction(5,2)));
    CHECK((--f == Fraction(3,2)));
    CHECK((f-- == Fraction(3,2)));
    CHECK((f == Fraction(1,2)));
}


TEST_CASE("testing the reduction of fractions") {
    Fraction f1(2,4);
    Fraction f2(6,9);
    Fraction f3(15,5);

    CHECK((f1 == Fraction(1,2)));
    CHECK((f2 == Fraction(2,3)));
    CHECK((f3 == Fraction(3,1)));
}

TEST_CASE("Check if a Fraction throws exception when denominator is 0 or when a fraction is divided by 0")
{
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(1,2) / 0);
    CHECK_THROWS(Fraction(3,4)/Fraction(0,1));
}

TEST_CASE("operator<<") {
    Fraction f1(1, 4);
    std::ostringstream oss1;
    oss1 << f1;
    CHECK(oss1.str() == "1/4");

    Fraction f2(-3, 7);
    std::ostringstream oss2;
    oss2 << f2;
    CHECK(oss2.str() == "-3/7");

    Fraction f3(0, 9);
    std::ostringstream oss3;
    oss3 << f3;
    CHECK(oss3.str() == "0/1");
}

TEST_CASE("operator>>") {
    Fraction f1;
    std::istringstream iss1("4/5");
    iss1 >> f1;
    CHECK((f1 == Fraction(4,5)));

    Fraction f3(1, 2);
    std::istringstream iss3("not a fraction");
    iss3 >> f3;
    CHECK(iss3.fail());
}