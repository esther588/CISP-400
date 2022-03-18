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
