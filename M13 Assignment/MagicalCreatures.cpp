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
#include "MagicalCreatures.h"

MagicalCreatures::MagicalCreatures() {
    name = "null";
    color = "null";
    type = "null";
    age = 0;
}

MagicalCreatures::MagicalCreatures(string name, string color, string type, int age) {
    this->name = name;
    this->color = color;
    this->type = type;
    this->age = age;
}

string MagicalCreatures::talk() {
    return  "Magical Creature is talking.";
}

string  MagicalCreatures::liveIn() {
    return  "Magical Creature lives anywhere.";
}

string MagicalCreatures::getName() {
    return name;
}

void MagicalCreatures::setName(string name) {
    this->name = name;
}

string MagicalCreatures::getColor() {
    return color;
}

void MagicalCreatures::setColor(string color) {
    this->color = color;
}

int MagicalCreatures::getAge() {
    return age;
}

void MagicalCreatures::setAge(int age) {
    this->age = age;
}

string MagicalCreatures::getType() {
    return type;
}

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

bool MagicalCreatures::operator<(shared_ptr<MagicalCreatures> other) {
  return this->age < other->getAge();
}
