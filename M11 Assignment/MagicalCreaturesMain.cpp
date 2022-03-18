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
#include <memory>
#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"
void displayCreatures(vector<shared_ptr<MagicalCreatures>> creaturesVector) {
    for(auto iter = creaturesVector.begin(); iter < creaturesVector.end(); iter++) {
        cout << "I am a : " << (*iter)->getType() << endl;
        cout << "My name is : " << (*iter)->getName() << endl;
        cout << "My color is : " << (*iter)->getColor() << endl;
        cout << "My speech is : " << (*iter)->talk() << endl;
        cout << "My habitat : " << (*iter)->liveIn() << endl;
        cout << "I am " << (*iter)->getAge() << " years of age" << endl << endl;
        cout << "Displaying the " << (*iter)->getType() << " object" << endl;
        cout << (*iter)->toString() << endl << endl;
    }
}

int main() {
    
    //create a vector of pointer to MagicalCreatures
    vector<shared_ptr<MagicalCreatures>> creatures;

    //create the individual creatures of type pointer of MagicalCreatures
    shared_ptr<Dragon> dragon = make_shared< Dragon>("Jack","black","Dragon", 200, 500, true);
    shared_ptr<Elf> elf = make_shared<Elf>("Doug", "green", "Elf", 80);
    shared_ptr<Genie> genie = make_shared< Genie>("Cosmo", "blue", "Genie", 1000, 40, true);
    shared_ptr<Goblin> goblin = make_shared<Goblin>("Harry", "red", "Goblin", 150);
  
    //push back each specific creature to the vector of MagicalCreatures
 
    creatures.push_back(dragon);
    creatures.push_back(elf);
    creatures.push_back(genie);
    creatures.push_back(goblin);
    displayCreatures(creatures);
   
}
