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
    virtual string talk();
    virtual string liveIn();
    string getName();
    void setName(string name);
    string getColor();
    void setColor(string color);
    int getAge();
    void setAge(int age);
    string getType();
    void setType(string type);
    virtual string toString();
};

#endif
