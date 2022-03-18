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
#include "MagicalCreatures.h"

// default constructor that sets name, type, color to null and age to 0
MagicalCreatures::MagicalCreatures() {
    name = "null";
    color = "null";
    type = "null";
    age = 0;
}

// regular constructor
MagicalCreatures::MagicalCreatures(string name, string color, string type, int age) {
    this->name = name;
    this->color = color;
    this->type = type;
    this->age = age;
}

// returns creature speak
string MagicalCreatures::talk() {
    return  "Magical Creature is talking.";
}

// return its natural habitat
string MagicalCreatures::liveIn() {
    return  "Magical Creature lives anywhere.";
}

// returns the name
string MagicalCreatures::getName() {
    return name;
}

// set name to value passed in
void MagicalCreatures::setName(string name) {
    this->name = name;
}

// returns color
string MagicalCreatures::getColor() {
    return color;
}

// set color to value passed in
void MagicalCreatures::setColor(string color) {
    this->color = color;
}

// returns age
int MagicalCreatures::getAge() {
    return age;
}

// set age to value passed in
void MagicalCreatures::setAge(int age) {
    this->age = age;
}

// returns type
string MagicalCreatures::getType() {
    return type;
}

// set type to value passed in
void MagicalCreatures::setType(string type) {
    this->type = type;
}

string MagicalCreatures::toString() {
    string value = "I am a Magical creature ";
    value = value.append("\nName    : ");
    value = value.append(name);
    value = value.append("\nType    : ");
    value = value.append(type);
    value = value.append("\nColor   : ");
    value = value.append(color);
    value = value.append("\nAge     : ");
    value = value.append(to_string(age));
    return value;
}
