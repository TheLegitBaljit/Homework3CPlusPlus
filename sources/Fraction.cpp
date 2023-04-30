#include "Fraction.hpp"
#include "iostream"
#include <cmath>
#include "limits"

using namespace std;

double rounded(const double num)
{
    double rounded = std::round(num * 1000.0) / 1000.0;
    return rounded;
}

Fraction operator*(double num, const Fraction &frac) {
    return Fraction(rounded(num * (double)frac.getNumerator()/frac.getDenominator()));
}

Fraction operator-(double num, const Fraction &frac) {
    return Fraction(rounded(num - (double)frac.getNumerator()/frac.getDenominator()));
}

Fraction operator+(double num, const Fraction &frac) {
    return Fraction(rounded(num + (double)frac.getNumerator()/frac.getDenominator()));
}

Fraction operator/(double num, const Fraction &frac) {
    double rep = (double)frac.getNumerator()/frac.getDenominator();
    return Fraction(rounded(num / rep));
}

bool operator==(double num, const Fraction &frac) {
    double num_rounded = rounded(num);
    double this_rounded = rounded((double)frac.getNumerator()/frac.getDenominator());
    return num_rounded == this_rounded;
}

bool operator>(double num, const Fraction &frac) {
    return frac < num;
}

bool operator<(double num, const Fraction &frac) {
    return frac > num;
}

bool operator>=(double num,const  Fraction &frac) {
    return (num > frac) || (frac == num);
}

bool operator<=(double num,const  Fraction &frac) {
    return num < frac || frac == num;
}


int Fraction::gcd(int num1, int num2) {
    if (num2 == 0) return num1;
    return gcd(num2, num1 % num2);
}

// a helper function that reduces the fraction to its lowest terms
void Fraction::reduce() {
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}


Fraction::Fraction() : numerator(0), denominator(1) {
    reduce();
}


Fraction::Fraction(double num) : numerator((int) (num * 1000)), denominator(1000) {
    reduce();
}


// constructor
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) throw std::invalid_argument("denominator cannot be zero");
    reduce(); // reduce the fraction to its lowest terms
}


// getters and setters
int Fraction::getNumerator() const { return numerator; }

int Fraction::getDenominator() const { return denominator; }

void Fraction::setNumerator(int num) {
    numerator = num;
    reduce();
}

void Fraction::setDenominator(int den) {
    if (den == 0) throw std::invalid_argument("denominator cannot be zero");
    denominator = den;
    reduce();
}

// overload the + operator to add two fractions and return their sum as another fraction in reduced form
Fraction Fraction::operator+(const Fraction &other) {
    int n1 = numerator * other.denominator;
    int n2 = other.numerator * denominator;
    int n;
    if (__builtin_add_overflow(n1, n2, &n)) {
        throw std::overflow_error("Overflow error: result of addition is too large");
    }
    int d = denominator * other.denominator;
    return Fraction(n, d); // this will be reduced by the constructor
}
Fraction Fraction::operator+(double number) {
    // convert the float to a fraction with 1000 as the denominator
    int n = (number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this + f; // use the previous overload to add the fractions
}

// overload the - operator to subtract two fractions and return their difference as another fraction in reduced form
Fraction Fraction::operator-(const Fraction &other) {
    int n1 = numerator * other.denominator;
    int n2 = other.numerator * denominator;
    int n;
    if (__builtin_sub_overflow(n1, n2, &n)) {
        throw std::overflow_error("Overflow error: result of subtraction is too large");
    }
    int d = denominator * other.denominator;
    return Fraction(n, d); // this will be reduced by the constructor
}

// overload the - operator to subtract a fraction and a float and return their difference as another fraction in reduced form
Fraction Fraction::operator-(double number) {
    // convert the float to a fraction with 1000 as the denominator
    int n = (int) (number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this - f; // use the previous overload to subtract the fractions
}

Fraction Fraction::operator*(const Fraction &other) {
    int n;
    if (__builtin_mul_overflow(numerator, other.numerator, &n)) {
        throw std::overflow_error("Overflow error");
    }
    int d;
    if (__builtin_mul_overflow(denominator, other.denominator, &d)) {
        throw std::overflow_error("Overflow error");
    }
    return Fraction(n, d);
}

Fraction Fraction::operator*(double number) {
    int n = (int) (number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this * f;
}


// overload the / operator to divide two fractions and return their quotient as another fraction in reduced form
Fraction Fraction::operator/(const Fraction &other) {
    if (other.numerator == 0) {
        throw std::runtime_error("Division by zero error: cannot divide by zero");
    }
    int n;
    if (__builtin_mul_overflow(numerator, other.denominator, &n)) {
        throw std::overflow_error("Overflow error: result of multiplication is too large");
    }
    int d;
    if (__builtin_mul_overflow(denominator, other.numerator, &d)) {
        throw std::overflow_error("Overflow error: result of multiplication is too large");
    }
    return Fraction(n, d); // this will be reduced by the constructor
}


// overload the / operator to divide a fraction and a float and return their quotient as another fraction in reduced form
Fraction Fraction::operator/(double number) {
    if (number == 0.0) throw std::runtime_error("cannot divide by zero");
    // convert the float to a fraction with 1000 as the denominator
    int n = static_cast<int>(number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this / f; // use the previous overload to divide the fractions
}

// overload the == operator to compare two fractions for equality and return true or false
bool Fraction::operator==(const Fraction &other) const {
    double double1 = rounded((double)numerator/denominator);
    double double2 = rounded((double)other.numerator/other.denominator);
    return double1 == double2;
}

bool Fraction::operator==(double number) const {
    return number == *this;
}

bool Fraction::operator<(const Fraction &other) const {
    double double1 = (double)numerator/denominator;
    double double2 = (double)other.numerator/other.denominator;
    return double1 < double2;;
}

bool Fraction::operator<(double number) const {
    int n = static_cast<int>(number * 1000);
    int d = 1000;
    Fraction f(n, d);
    return *this < f;
}

bool Fraction::operator>(const Fraction &other) const {
    return !(*this == other || *this < other);
}

bool Fraction::operator>(double x) const {
    return !(*this == x || *this < x);
}

bool Fraction::operator<=(const Fraction &other) const {
    return *this == other || *this < other;
}

bool Fraction::operator<=(double x) const {
    return *this == x || *this < x;
}

bool Fraction::operator>=(const Fraction &other) const {
    return *this == other || *this > other;
}

bool Fraction::operator>=(double x) const {
    return *this == x || *this > x;
}

// overload the ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix
Fraction &Fraction::operator++() { // pre-increment
    numerator += denominator; // add 1 to the fraction
    reduce(); // reduce the fraction to its lowest terms
    return *this; // return the modified fraction
}

Fraction Fraction::operator++(int) { // post-increment
    Fraction temp = *this; // save a copy of the current fraction
    ++(*this); // use the pre-increment overload to modify the fraction
    return temp; // return the original fraction
}

Fraction &Fraction::operator--() { // pre-decrement
    numerator -= denominator; // subtract 1 from the fraction
    reduce(); // reduce the fraction to its lowest terms
    return *this; // return the modified fraction
}

Fraction Fraction::operator--(int) { // post-decrement
    Fraction temp = *this; // save a copy of the current fraction
    --(*this); // use the pre-decrement overload to modify the fraction
    return temp; // return the original fraction
}

// overload the << operator to print a fraction to an output stream in the format “numerator/denominator”
ostream &operator<<(ostream &ost, Fraction frac) {
    int n = frac.getNumerator();
    int d = frac.getDenominator();
    if(n < 0 || d < 0) // check if either n or d is negative
    {
        n = abs(n); // use absolute value of n
        d = abs(d); // use absolute value of d
        ost << "-"; // print a minus sign
    }
    ost << n << "/" << d;
    return ost;
}

istream &operator>>(istream &ist, Fraction &frac) {
    int num, den;
    ist >> num >> den;
    if (ist && den != 0) {
        frac.setNumerator(num);
        frac.setDenominator(den);
    } else {
        throw runtime_error("Bad input");
    }
    return ist;
}
