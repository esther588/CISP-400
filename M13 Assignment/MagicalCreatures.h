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
#ifndef MagicalCreatures_h
#define MagicalCreatures_h

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//MagicalCreatures Class
class MagicalCreatures {
private:
    string name, color, type;
    int age;

public:
    MagicalCreatures();
    MagicalCreatures(string name, string color, string type, int age);
    virtual string  talk();
    virtual string liveIn();
    virtual string getName();
    virtual void setName(string name);
    virtual string getColor();
    virtual void setColor(string color);
    virtual int getAge();
    virtual void setAge(int age);
    virtual string getType();
    virtual void setType(string type);
    virtual string toString();
    virtual bool operator<(shared_ptr<MagicalCreatures> other);
};

#endif
