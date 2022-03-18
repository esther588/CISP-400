/**********************************
* Title : Assignment 11
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/9/2021
* Version : Version 1.0
* Description : This is program is
* an exenstion of Assignment 9. The only
* addition is implementing the talk,
* liveIn, and toString methods to
* exhibit polymorphic behavior and
* adding a helper function to display
* every creature of the vector of pointer
* to Magical Creatures.
***********************************/
#ifndef Genie_h
#define Genie_h
#include "MagicalCreatures.h"
//Genie Class
class Genie : public MagicalCreatures {
private:
    int size;
    bool hasWand;

public:
    Genie();
    Genie(string name, string color, string type, int age, int size, bool hasWand);
    int getSize();
    void changeSize(int newSize);
    bool getHasWand();
    void setHasWand(bool hasWand);
    string liveIn();
    //void toString();
};

#endif
