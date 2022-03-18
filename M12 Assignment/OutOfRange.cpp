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
#include <cstdlib>
#include <iostream>

class OutOfRange {
private:
    int denominator;
public:
    OutOfRange(int newDenom) {
        denominator = newDenom;
        try {
            if (denominator == 0) {
                throw 99;
            }
        } catch (int exception) {
            std::cout << "Error " << exception << " Denominator is zero" << std::endl;
        }
        try {
            if(denominator < 0) {
                throw 100;
            }
        } catch (int exception) {
            std::cout << "Error " << exception << " Negative denominator" << std::endl;
        }
    }
    class DivByZero {
    public:
        int exNum;
        DivByZero(int newExNum) {
            exNum = newExNum;
        }
    };
    class NegativeDenom {
    public:
        int exNum;
        NegativeDenom(int newExNum) {
            exNum = newExNum;
        }
    };
};
