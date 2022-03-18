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
#include "Goblin.h"
#include "MagicalCreatures.h"

// default constructor that sets name, type, color to null and age to 0
Goblin::Goblin() {}

// regular constructor
Goblin::Goblin(string name, string color, string type, int age) : MagicalCreatures(name, color, type, age) {}

string Goblin::talk() {
    return "I speak Gibberish";
}
