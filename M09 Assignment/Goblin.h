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
