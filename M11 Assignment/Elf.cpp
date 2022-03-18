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
#include "Elf.h"
#include "MagicalCreatures.h"

Elf::Elf() {}

//constructor using member initializtion list
Elf::Elf(string name, string color, string type, int age) : MagicalCreatures(name, color, type, age) {}

string Elf::toString() {
    return "I am an Elf..I can spell";
}
