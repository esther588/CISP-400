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
// P8_17M.cpp
// member function definitions for p8_17.cpp
#include <cstdlib>
#include <iostream>
#include "OutOfRange.cpp"

using std::cout;
using std::endl;

#include "RationalNumberHeader.h"

RationalNumber::RationalNumber( int n, int d ) {
    numerator = n;
    denominator = d;
    reduction();
    try {
        OutOfRange d(denominator);
    } catch (OutOfRange::DivByZero ex) {
        exit(0);
    } catch (OutOfRange::NegativeDenom ex) {
        exit(0);
    }
}

RationalNumber RationalNumber::addition( const RationalNumber & a) {
    RationalNumber sum;
    sum.numerator = numerator + a.numerator;
    if(denominator != a.denominator) {
        sum.denominator = denominator + a.denominator;
    } else {
        sum.denominator = denominator;
    }
    sum.reduction();
    return sum;
}

RationalNumber RationalNumber::subtraction( const RationalNumber & s) {
    RationalNumber difference;
    difference.numerator = numerator - s.numerator;
    if(denominator != s.denominator) {
        difference.denominator = denominator - s.denominator;
    } else {
        difference.denominator = denominator;
    }
    difference.reduction();
    return difference;
}

RationalNumber RationalNumber::multiplication( const RationalNumber & m) {
    RationalNumber product;
    product.numerator = numerator * m.numerator;
    product.denominator = denominator * m.denominator;
    product.reduction();
    return product;
}

RationalNumber RationalNumber::division( RationalNumber & d) {
    RationalNumber quotient;
    quotient.numerator = numerator / d.numerator;
    quotient.denominator = denominator / d.denominator;
    quotient.reduction();
    return quotient;
}

string RationalNumber::toString() {
    return to_string(numerator) + "/" + to_string(denominator);
}

string RationalNumber::toStringRationalNumber() const {
    return to_string(numerator) + "/" + to_string(denominator);
}

string RationalNumber::toStringRationalNumberAsDouble() const {
    double doubleNumber = (double) numerator / (double) denominator;
    return to_string(doubleNumber);
}

RationalNumber RationalNumber::operator+( const RationalNumber &a ) {
    RationalNumber sum;
    sum.numerator = numerator * a.denominator + denominator * a.numerator;
    sum.denominator = denominator * a.denominator;
    sum.reduction();
    return sum;
}

RationalNumber RationalNumber::operator-( const RationalNumber &s ) {
    RationalNumber sub;
    sub.numerator = numerator * s.denominator - denominator * s.numerator;
    sub.denominator = denominator * s.denominator;
    sub.reduction();
    return sub;
}

RationalNumber RationalNumber::operator*( const RationalNumber &m ) {
    RationalNumber multiply;
    multiply.numerator = numerator * m.numerator;
    multiply.denominator = denominator * m.denominator;
    multiply.reduction();
    return multiply;
}

RationalNumber RationalNumber::operator/( RationalNumber &d ) {
    RationalNumber divide;
    if (d.numerator != 0) { // check for a zero in numerator
        divide.numerator = numerator * d.denominator;
        divide.denominator = denominator * d.numerator;
        divide.reduction();
    } else {
        cout << "Divide by zero error: terminating program" << endl;
        exit(1); // stdlib function
    }
    return divide;
}

bool RationalNumber::operator>( const RationalNumber &gr ) const {
    if ( static_cast<double>( numerator ) / denominator < static_cast<double>( gr.numerator ) / gr.denominator ) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator<(const RationalNumber &lr) const {
    if ( static_cast<double>( numerator ) / denominator < static_cast<double>( lr.numerator ) / lr.denominator ) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator>=( const RationalNumber &ger ) const {
    return *this == ger || *this > ger;
}

bool RationalNumber::operator<=( const RationalNumber &ler ) const {
    return *this == ler || *this < ler;
}

bool RationalNumber::operator==( const RationalNumber &er ) const {
    if ( numerator == er.numerator && denominator == er.denominator ) {
        return true;
    } else {
        return false;
    }
}

bool RationalNumber::operator!=( const RationalNumber &ner ) const {
    return !( *this == ner );
}

void RationalNumber::printRational( void ) const {
    if ( numerator == 0 ) { // print fraction as zero
        cout << numerator;
    } else if ( denominator == 1 ) { // print fraction as integer
        cout << numerator;
    } else {
        cout << numerator << '/' << denominator;
    }
}

void RationalNumber::reduction( void ) {
    int largest, gcd = 1; // greatest common divisor;
    largest = ( numerator > denominator ) ? numerator: denominator;
    for ( int loop = 2; loop <= largest; ++loop ) {
        if ( numerator % loop == 0 && denominator % loop == 0 ) {
            gcd = loop;
            numerator /= gcd;
            denominator /= gcd;
        }
    }
}
