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
#include "Dragon.h"
#include "MagicalCreatures.h"

// default constructor that sets name, type, color to null and age to 0
Dragon::Dragon() {
    size = 0;
    hasSpike = true;
}

// regular constructor
Dragon::Dragon(string name, string color, string type, int age, int size, bool hasSpike) : MagicalCreatures(name, color, type, age) {
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
