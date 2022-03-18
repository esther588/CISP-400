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
