/**********************************
* Title : Assignment 13
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/22/2021
* Version : Version 1.0
* Description : This is program is
* implements quick sort, to sort the
* creatures according to age, and binary
* search methods, which searches the
* vector with the creature's name as
* a key, both using recursion. Partition
* and swap methods are implemented too.
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
