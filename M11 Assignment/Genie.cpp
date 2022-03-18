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
#include "Genie.h"
#include "MagicalCreatures.h"

// default constuctor
Genie::Genie() {
    size = 0;
    hasWand = true;
}

// constructor using member initializtion list
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
