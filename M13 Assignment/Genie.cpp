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
#include "Genie.h"
#include "MagicalCreatures.h"

Genie::Genie() {
    size = 0;
    hasWand = true;
}

//constructor using member initializtion list
Genie::Genie(string name, string color, string type, int age, int size, bool hasWand) : MagicalCreatures(name, color, type, age) {
    this->size = size;
    this->hasWand = hasWand;
}

string Genie::liveIn() {
  return "I live in a bottle ";
}

int Genie::getSize() {
    return size;
}

void Genie::changeSize(int newSize) {
    this->size = newSize;
}

bool Genie::getHasWand() {
    return hasWand;
}

void Genie::setHasWand(bool hasWand) {
    this->hasWand = hasWand;
}
