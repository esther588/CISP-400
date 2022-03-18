#ifndef Dragon_h
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
#define Dragon_h

#include "MagicalCreatures.h"

class Dragon : public MagicalCreatures {
private:
    int size;
    bool hasSpike;

public:
    Dragon();
    Dragon(string name,string color,string type, int age, int size, bool hasSpike);
    
    int getSize();
    void changeSize(int newSize);
    bool getHasSpike();
    void setHasSpike(bool hasSpike);
    string toString();

};

#endif
