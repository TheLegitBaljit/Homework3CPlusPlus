#ifndef FRACTIONS_FRACTION_HPP
#define FRACTIONS_FRACTION_HPP

#include "iostream"

namespace ariel{}


class Fraction {
private:
    int numerator; // the numerator of the fraction
    int denominator; // the denominator of the fraction

    // a helper function that returns the greatest common divisor of two integers
    int gcd(int num1, int num2);

    // a helper function that reduces the fraction to its lowest terms
    void reduce();

public:
    // constructor
    Fraction();
    Fraction(int num, int den);

    // getters and setters
    int getNumerator();

    int getDenominator() ;

    void setNumerator(int num) ;

    void setDenominator(int den) ;

    Fraction operator+(const Fraction &other);
    Fraction operator+(double number)  ;
    Fraction operator-(const Fraction& other)  ;
    Fraction operator-(double number)  ;
    Fraction operator*(const Fraction& other) ;
    Fraction operator*(double number)  ;
    Fraction operator/(const Fraction& other)  ;
    Fraction operator/(double number)  ;
    bool operator==(const Fraction& other)  const;
    bool operator==(double number) const;
    bool operator<(const Fraction& other) const ;
    bool operator<(double number) const ;
    bool operator>(const Fraction& other) const ;
    bool operator>(double number) const ;
    bool operator<=(const Fraction& other) const;
    bool operator<=(double number) const ;
    bool operator>=(const Fraction& other) const;
    bool operator>=(double number) const ;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);


};
std::ostream& operator<<(std::ostream& os, Fraction frac) ;
std::istream& operator>>(std::istream& is, Fraction& frac) ;
Fraction operator*(double num,Fraction &frac);
Fraction operator-(double num,Fraction &frac);
Fraction operator+(double num,Fraction &frac);
Fraction operator/(double num,Fraction &frac);


#endif //FRACTIONS_FRACTION_HPP
