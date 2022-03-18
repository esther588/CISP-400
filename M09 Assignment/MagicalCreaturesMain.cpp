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
#include <memory>
#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"
void displayDragons(shared_ptr<Dragon> d){
    cout << "In display Dragons" << endl;
    cout << "I am " << d->getName() << ": " << d->toString() << endl;
}
int main() {

    //create a vector of shared pointer to Dragons
    vector<shared_ptr<Dragon>> dragonVector;

    //create the individual creatures of type pointer of MagicalCreatures
    shared_ptr<Dragon> dragon = make_shared<Dragon>("Jack","black","Dragon", 200, 500, true);
    shared_ptr<Dragon> dragoness = make_shared<Dragon>("Jill","white","Dragon", 100, 500, true);
    shared_ptr<Elf> elf =  make_shared<Elf>("Doug", "green", "Elf", 80);
    shared_ptr<Genie> genie = make_shared<Genie>("Cosmo", "blue", "Genie", 1000, 40, true);
    shared_ptr<Goblin>  goblin = make_shared<Goblin>("Harry", "red", "Goblin", 150);

    //print the traits of each creature
    cout << "Printing Traits of Each Magical Creature" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << dragon->getName() << endl;
    cout << "Type: " << dragon->getType() << endl;
    cout << "Color: " << dragon->getColor() << endl;
    cout << "Age: " << dragon->getAge() << endl;
    cout << "Talk: " << dragon->talk() << endl;
    cout << "Live: " << dragon->liveIn() << endl;
    cout << "To String: " << dragon->toString() << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << dragoness->getName() << endl;
    cout << "Type: " << dragoness->getType() << endl;
    cout << "Color: " << dragoness->getColor() << endl;
    cout << "Age: " << dragoness->getAge() << endl;
    cout << "Talk: " << dragoness->talk() << endl;
    cout << "Live: " << dragoness->liveIn() << endl;
    cout << "To String: " << dragoness->toString() << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << elf->getName() << endl;
    cout << "Type: " << elf->getType() << endl;
    cout << "Color: " << elf->getColor() << endl;
    cout << "Age: " << elf->getAge() << endl;
    cout << "Talk: " << elf->talk() << endl;
    cout << "Live: " << elf->liveIn() << endl;
    cout << "To String: " << elf->toString() << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << genie->getName() << endl;
    cout << "Type: " << genie->getType() << endl;
    cout << "Color: " << genie->getColor() << endl;
    cout << "Age: " << genie->getAge() << endl;
    cout << "Talk: " << genie->talk() << endl;
    cout << "Live: " << genie->liveIn() << endl;
    cout << "To String: " << genie->toString() << endl;
    cout << "-----------------------------------" << endl;
    cout << "Name: " << goblin->getName() << endl;
    cout << "Type: " << goblin->getType() << endl;
    cout << "Color: " << goblin->getColor() << endl;
    cout << "Age: " << goblin->getAge() << endl;
    cout << "Talk: " << goblin->talk() << endl;
    cout << "Live: " << goblin->liveIn() << endl;
    cout << "To String: " << goblin->toString() << endl;
  
    //push back dragons to the vector of Dragons
    dragonVector.push_back(dragon);
    dragonVector.push_back(dragoness);

    //loop through the dragon vector using iterators and print the relevant data for each dragon by calling dragonDisplay
    for(auto iter = dragonVector.begin(); iter < dragonVector.end(); iter++) {
        shared_ptr<Dragon> tempDragon = make_shared<Dragon>((*iter)->getName(), (*iter)->getColor(), (*iter)->getType(), (*iter)->getAge(), (*iter)->getSize(), (*iter)->getHasSpike());
        displayDragons(tempDragon);
    }
   
}
