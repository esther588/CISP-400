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
#include "Dragon.h"
#include "MagicalCreatures.h"

Dragon::Dragon() {
    size = 0;
    hasSpike = true;
}

//constructor using member initializtion list
Dragon::Dragon(string name, string color, string type, int age, int size, bool hasSpike) : MagicalCreatures(name, color, type, age) {
    this->size = size;
    this->hasSpike = hasSpike;
}

int Dragon::getSize() {
    return size;
}

void Dragon::changeSize(int newSize) {
    this->size = newSize;
}

bool Dragon::getHasSpike() {
    return hasSpike;
}

void Dragon::setHasSpike(bool hasSpike) {
    this->hasSpike = hasSpike;
}

string Dragon::toString() {
    return "I am a Dragon! I breathe fire";
}

