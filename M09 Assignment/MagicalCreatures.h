/**********************************
* Title : Assignment 9
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/1/2021
* Version : Version 1.0
* Description : This is program consists
* of multiple classes, such as Dragons and
* Goblins, that inherit from the Magical Creatues
* class and creates all sorts of creatures with
* names, types, colors, ages and how they may talk
* and what they live in. Some creatures have methods
* that override the original methods in the Magical
* Creatures class.
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
    string talk();
    string liveIn();
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
