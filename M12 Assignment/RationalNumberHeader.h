/**********************************
* Title : Assignment 12
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/15/2021
* Version : Version 1.0
* Description : This program creates
* a class called RationalNumber
* to perform arithmetic with fractions.
* Constructors throw exception if
* the denominator is 0 or less than 0.
* There's an Exception Class inside the
* RationalNumber class called OutOfRange
* that contains an integer value to exhibit
* the exception number.
***********************************/
// P8_17.H
#ifndef P8_17_H
#define P8_17_H
#include <string>
using namespace std;

class RationalNumber {
public:
    RationalNumber( int = 0, int = 1 ); // default constructor
    RationalNumber addition( const RationalNumber & a);
    RationalNumber subtraction( const RationalNumber & s);
    RationalNumber multiplication( const RationalNumber & m);
    RationalNumber division( RationalNumber & d);
    string toString();
    string toStringRationalNumber() const;
    string toStringRationalNumberAsDouble() const;
    RationalNumber operator+( const RationalNumber& a);
    RationalNumber operator-( const RationalNumber& s);
    RationalNumber operator*( const RationalNumber& m);
    RationalNumber operator/( RationalNumber& d);
    bool operator>( const RationalNumber& gr) const;
    bool operator<( const RationalNumber& lr) const;
    bool operator>=( const RationalNumber& ger) const;
    bool operator<=( const RationalNumber& ler) const;
    bool operator==( const RationalNumber& er) const;
    bool operator!=( const RationalNumber& ner) const;
private:
    int numerator;
    int denominator;
    void printRational( void ) const;
    void reduction( void );
};

 #endif
