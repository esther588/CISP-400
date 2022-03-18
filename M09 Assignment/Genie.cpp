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
#include "Genie.h"
#include "MagicalCreatures.h"

// default constructor that sets name, type, color to null and age to 0
Genie::Genie() {
    size = 0;
    hasWand = true;
}

// regular constructor
Genie::Genie(string name, string color, string type, int age, int size, bool hasWand) : MagicalCreatures(name, color, type, age) {
    this->size = size;
    this->hasWand = hasWand;
}

// returns size
int Genie::getSize() {
    return size;
}

// sets size to value passed in
void Genie::changeSize(int newSize) {
    size = newSize;
}

// return hasWand
bool Genie::getHasWand() {
    return hasWand;
}

// sets hasWand to value passed in
void Genie::setHasWand(bool hasWand) {
    this->hasWand = hasWand;
}

string Genie::liveIn() {
    return "I live in a bottle";
}
