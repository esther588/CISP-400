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
#include "Dragon.h"
#include "MagicalCreatures.h"

// default constructor that sets name, type, color to null and age to 0
Dragon::Dragon() {
    size = 0;
    hasSpike = true;
}

// regular constructor
Dragon::Dragon(string name, string color, string type, int age, int size, bool hasSpike) {
    setName(name);
    setColor(color);
    setType(type);
    setAge(age);
    this->size = size;
    this->hasSpike = hasSpike;
}

// returns size
int Dragon::getSize() {
    return size;
}

// sets size to value passed in
void Dragon::changeSize(int newSize) {
    size = newSize;
}

// returns hasSpike
bool Dragon::getHasSpike() {
    return hasSpike;
}

// sets hasSpike to value passed in
void Dragon::setHasSpike(bool hasSpike) {
    this->hasSpike = hasSpike;
}

string Dragon::toString() {
    return "I am a Dragon, I breathe fire!";
}
