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
#include "Goblin.h"
#include "MagicalCreatures.h"

// default constructor
Goblin::Goblin() {}

// constructor using member initializtion list
Goblin::Goblin(string name, string color, string type, int age) : MagicalCreatures(name, color, type, age) {}

string Goblin::talk() {
    return "I speak Gibberish";
}
