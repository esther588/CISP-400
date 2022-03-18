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
#ifndef Goblin_h
#define Goblin_h

#include "MagicalCreatures.h"

//Goblin Class
class Goblin : public MagicalCreatures {
public:
    Goblin();
    Goblin(string name, string color, string type, int age);
    string talk();
    //void toString();
    
};

#endif
