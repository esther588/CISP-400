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
#include <memory>
#include "Dragon.h"
#include "Elf.h"
#include "Genie.h"
#include "Goblin.h"

void displayCreatures(vector<shared_ptr<MagicalCreatures>> m){
    for (auto iter = m.begin(); iter < m.end(); iter++) {
        cout << endl;
        cout << "I am a : " << (*iter)->getType() << endl;
        cout << "My name is : " << (*iter)->getName() << endl;
        cout << "My color is : " << (*iter)->getColor() << endl;
        cout <<"My speech :" << (*iter)->talk()<<endl;
        cout <<"My habitat: " << (*iter)->liveIn()<<endl;
        cout << "I am " << (*iter)->getAge() <<" years of age." << endl << endl;
        cout << "Displaying the " << (*iter)->getType() << " Object" << endl;
        cout << (*iter)->toString() << endl;
    }
}

void swap(vector<shared_ptr<MagicalCreatures>> &m, int source, int destination) {
    // use to swap creatures in partition method
    shared_ptr<MagicalCreatures> sourcePtr = m[source];
    m[source] = m[destination];
    m[destination] = sourcePtr;
}

int partition(vector<shared_ptr<MagicalCreatures>> &m, int start, int end) {
    // implement partition search space
    int pivot = m[end]->getAge();    // pivot
        int i = (start - 1);
       
        for (int j = start; j <= end - 1; j++) {
            //if current element is smaller than pivot, increment the low element
            //swap elements at i and j
            if (m[j]->getAge() <= pivot) {
                // increment index of smaller element
                i++;
                swap(m, i, j);
            }
        }
        swap(m, i + 1, end);
        return (i + 1);
}
  
void recursiveQuickSort(vector<shared_ptr<MagicalCreatures>> &m, int start, int end) {
    //implement recursive Quick sort by calling partition method
    if (start < end) {
        //partition the array
        int pivot = partition(m, start, end);
        //sort the sub arrays independently
        recursiveQuickSort(m, start, pivot - 1);
        recursiveQuickSort(m, pivot + 1, end);
    }
}

bool recursiveBinarySearch(vector<shared_ptr<MagicalCreatures>> m, int first, int last, string name) {
    //implement binary search method
    if(first <= last) {
        int mid = first + (last - first) / 2;
        if (m[mid]->getName() == name) {
            return true;
        } else if (m[mid]->getName() > name) {
            return recursiveBinarySearch(m, mid + 1, last, name);
        } else {
            return recursiveBinarySearch(m, first, mid - 1, name);
        }
    }
    return false;
}

void searchCreature(vector<shared_ptr<MagicalCreatures>> m) {
    string name;
    while(name.compare("N") != 0) {
        cout << "Please enter the name of the Creature" << endl;
        cin >> name;
        int index= recursiveBinarySearch(m, 0, m.size() - 1, name);
        if (index < 0) {
            cout << "Creature Not Found " << endl;
        } else {
            cout<<"Creature found at index "<<index <<endl;
            cout<<"Here it is " << m[index]->toString() << endl;
        }
    }
}

int main() {
    //create a vector of pointer to MagicalCreatures
    vector<shared_ptr<MagicalCreatures>> creatures;

    //create the individual creatures of type pointer of MagicalCreatures
    shared_ptr<Dragon> dragon = make_shared< Dragon>("Jack", "black", "Dragon", 200, 500, true);
    shared_ptr<Elf> elf = make_shared<Elf>("Doug", "green", "Elf", 80);
    shared_ptr<Genie> genie = make_shared< Genie>("Cosmo", "blue", "Genie", 1000, 40, true);
    shared_ptr<Goblin> goblin = make_shared<Goblin>("Harry", "red", "Goblin", 150);

    //push back each specific creature to the vector of MagicalCreatures
    creatures.push_back(dragon);
    creatures.push_back(elf);
    creatures.push_back(genie);
    creatures.push_back(goblin);
    
    displayCreatures(creatures);
    std::cout << "*****AFTER SORTING *******" << std::endl;
    bool isExist = recursiveBinarySearch(creatures, 0, creatures.size() - 1, "Cosmo");
    cout << isExist << endl;
    //recursiveQuickSort(creatures, 0, creatures.size() - 1);
    displayCreatures(creatures);
    searchCreature(creatures);
}
