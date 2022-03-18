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
#include "RationalNumberHeader.h"
#include <iostream>
#include "OutOfRange.cpp"
#include "Integer.cpp"
using std::cout;
using std::endl;

template <class T>
void print(T obj){
   cout<< obj.toString() << endl;
}

int main() {
    int num, denom;
    //RationalNumber z1(1,0);
    //RationalNumber n(1,-1);
    Integer n(77);
    RationalNumber c( 7, 3 ), d( 3, 9 ), x;
    print(n);
    print(c);
    cout << "Please enter a numerator";
    cin >> num;
    cout << "Please enter a denominator";
    cin >> denom;
    
    try {
        OutOfRange d(denom);
        RationalNumber test(num,denom);
    } catch (OutOfRange::DivByZero ex) {
        cout << "Division by Zero Error " << ex.exNum << endl;
        exit(0);
    } catch (OutOfRange::NegativeDenom ex) {
        cout << "Negative Denominator Error " << ex.exNum <<endl;
        exit(0);
    }
    
    cout << "The numbers are "<<c.toStringRationalNumber() << " and " << d.toStringRationalNumber() << endl;
    cout << "Operations using methods " << endl;
    cout << c.toStringRationalNumber();
    cout << " + " ;
    cout << d.toStringRationalNumber();
    cout << " = ";
    x = c.addition(d);
    cout << x.toStringRationalNumber();
    cout << '\n';
    cout<<c.toStringRationalNumber();
    cout << " - " ;
    cout << d.toStringRationalNumber();
    cout << " = ";
    x = c.subtraction(d);
    cout << x.toStringRationalNumber();

    cout << '\n';
    cout << c.toStringRationalNumber();
    cout << " * " ;
    cout << d.toStringRationalNumber();
    cout << " = ";
    x = c.multiplication(d);
    cout << x.toStringRationalNumber();

    cout << '\n';
    cout << c.toStringRationalNumber();
    cout << " / " ;
    cout << d.toStringRationalNumber();
    cout << " = ";
    x = c.division(d);
    cout << x.toStringRationalNumber() << endl;

    cout << "Operations using overloaded operators " << endl;
    cout << c.toStringRationalNumber();
    cout << " + " ;
    cout << d.toStringRationalNumber();
    cout << " = ";
    x = c + d;
    cout << x.toStringRationalNumber();

    cout << '\n';
    cout << c.toStringRationalNumber();
    cout << " - ";
    cout << d.toStringRationalNumber();
    cout << " = ";
    x = c - d;
    cout << x.toStringRationalNumber();

    cout << '\n';
    cout<< c.toStringRationalNumber();
    cout << " * " ;
    cout<<d.toStringRationalNumber();
    cout << " = ";
    x = c * d;
    cout<<x.toStringRationalNumber();

    cout << '\n';
    cout<<c.toStringRationalNumber();
    cout << " / " ;
    cout<<d.toStringRationalNumber();
    cout << " = ";
    x = c / d;
    cout << x.toStringRationalNumber();

    cout << '\n';
    cout<<c.toStringRationalNumber();
    cout << " is:\n";

    cout << ( ( c > d ) ? " > " : " <= " );
    cout << d.toStringRationalNumber();
    cout << " according to the overloaded > operator\n";

    cout << ( ( c < d ) ? " < " : " >= " );
    cout << d.toStringRationalNumber();
    cout << " according to the overloaded < operator\n";

    // cout << ( ( c >= d ) ? " >= " : " < " );
    cout << "In decimal form is " << c.toStringRationalNumberAsDouble() << endl;
    cout << "Trying with negative numbers " << endl;
    RationalNumber e( -7, 3 ), f( 3, 9 ), y;
    cout << "The numbers are " << e.toStringRationalNumber() << " and " << f.toStringRationalNumber() << endl;

    cout << "Operations using methods " << endl;
    cout << e.toStringRationalNumber();
    cout << " + " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e.addition(f);
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " - " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e.subtraction(f);
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " * " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e.multiplication(f);
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " / " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e.division(f);
    cout << y.toStringRationalNumber()<<endl;

    cout << "Operations using overloaded operators " << endl;
    cout << e.toStringRationalNumber();
    cout << " + " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e + f;
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " - " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e - f;
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " * " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e * f;
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " / " ;
    cout << f.toStringRationalNumber();
    cout << " = ";
    y = e / f;
    cout << y.toStringRationalNumber();

    cout << '\n';
    cout << e.toStringRationalNumber();
    cout << " is:\n";

    cout << ( ( e > f ) ? " > " : " <= " );
    cout << f.toStringRationalNumber();
    cout << " according to the overloaded > operator\n";

    cout << ( ( e < f ) ? " < " : " >= " );
    cout << f.toStringRationalNumber();
    cout << " according to the overloaded < operator\n";

    cout << ( ( c >= d ) ? " >= " : " < " );

    cout << "In decimal form is "<<e.toStringRationalNumberAsDouble()<<endl;

    cout << "Trying 0 denominator - with number 1/0" << endl;
    RationalNumber z(1,0);
    cout << "Trying negative  denominator - with number 1/-1" << endl;
    RationalNumber k(1,-1);
  
 }
