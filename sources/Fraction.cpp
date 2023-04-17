#include "Fraction.hpp"
#include "iostream"

using namespace std;

Fraction operator*(double num,Fraction &frac)
{
    int n = (int)num*1000;
    int d = 1000;
    Fraction f(n,d);
    return f*frac;
}
Fraction operator-(double num,Fraction &frac)
{
    int n = (int)num*1000;
    int d = 1000;
    Fraction f(n,d);
    return f-frac;
}
Fraction operator+(double num,Fraction &frac)
{
    int n = (int)num*1000;
    int d = 1000;
    Fraction f(n,d);
    return f+frac;
}
Fraction operator/(double num,Fraction &frac)
{
    int n = (int)num*1000;
    int d = 1000;
    Fraction f(n,d);
    return f/frac;
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


Fraction::Fraction():numerator(0),denominator(1) {
    reduce();
}

// constructor
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) throw std::invalid_argument("denominator cannot be zero");
    reduce(); // reduce the fraction to its lowest terms
}


// getters and setters
int Fraction::getNumerator() { return numerator; }

int Fraction::getDenominator() { return denominator; }

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
    int n = numerator * other.denominator + other.numerator * denominator;
    int d = denominator * other.denominator;
    return Fraction(n, d); // this will be reduced by the constructor
}
Fraction Fraction::operator+(double number) {
    // convert the float to a fraction with 1000 as the denominator
    int n = static_cast<int>(number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this + f; // use the previous overload to add the fractions
}
// overload the - operator to subtract two fractions and return their difference as another fraction in reduced form
Fraction Fraction::operator-(const Fraction& other) {
    int n = numerator * other.denominator - other.numerator * denominator;
    int d = denominator * other.denominator;
    return Fraction(n, d); // this will be reduced by the constructor
}

// overload the - operator to subtract a fraction and a float and return their difference as another fraction in reduced form
Fraction Fraction::operator-(double number) {
    // convert the float to a fraction with 1000 as the denominator
    int n = (int)(number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this - f; // use the previous overload to subtract the fractions
}
Fraction Fraction::operator*(const Fraction& other) {
    int n = numerator * other.numerator;
    int d = denominator * other.denominator;
    return Fraction(n, d); // this will be reduced by the constructor
}

Fraction Fraction::operator*(double number) {
    int n = (int)(number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this * f;
}




// overload the / operator to divide two fractions and return their quotient as another fraction in reduced form
Fraction Fraction::operator/(const Fraction& other)  {
    if (other.numerator == 0) throw std::invalid_argument("cannot divide by zero");
    int n = numerator * other.denominator;
    int d = denominator * other.numerator;
    return Fraction(n, d); // this will be reduced by the constructor
}




// overload the / operator to divide a fraction and a float and return their quotient as another fraction in reduced form
Fraction Fraction::operator/(double number)  {
    if (number == 0.0) throw std::invalid_argument("cannot divide by zero");
    // convert the float to a fraction with 1000 as the denominator
    int n = static_cast<int>(number * 1000);
    int d = 1000;
    Fraction f(n, d); // this will be reduced by the constructor
    return *this / f; // use the previous overload to divide the fractions
}

// overload the == operator to compare two fractions for equality and return true or false
bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}
bool Fraction::operator==(double number) const
{
    return (double)this->numerator/this->denominator == number;
}

bool Fraction::operator<(const Fraction& other)  const{
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator<(double number)  const{
    int n = static_cast<int>(number * 1000);
    int d = 1000;
    Fraction f(n, d);
    return *this < f;
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this == other || *this < other);
}

bool Fraction::operator>(double x) const{
    return !(*this == x || *this < x);
}

bool Fraction::operator<=(const Fraction& other)const {
    return *this == other || *this < other;
}

bool Fraction::operator<=(double x) const{
    return *this == x || *this < x;
}

bool Fraction::operator>=(const Fraction& other) const{
    return *this == other || *this > other;
}

bool Fraction::operator>=(double x) const{
    return *this == x || *this > x;
}

// overload the ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix
Fraction& Fraction::operator++() { // pre-increment
    numerator += denominator; // add 1 to the fraction
    reduce(); // reduce the fraction to its lowest terms
    return *this; // return the modified fraction
}

Fraction Fraction::operator++(int) { // post-increment
    Fraction temp = *this; // save a copy of the current fraction
    ++(*this); // use the pre-increment overload to modify the fraction
    return temp; // return the original fraction
}

Fraction& Fraction::operator--() { // pre-decrement
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
ostream& operator<<(ostream& os, Fraction frac) {
    os << frac.getNumerator() << "/" << frac.getDenominator();
    return os;
}

istream& operator>>(istream& is, Fraction& frac) {
    int num, den;
    char slash;
    is >> num >> slash >> den;
    if (is && slash == '/' && den != 0) {
        frac.setNumerator(num);
        frac.setDenominator(den);
    }
    else {
        is.setstate(std::ios::failbit);
    }
    return is;
}
