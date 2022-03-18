/**********************************
* Title : Lab 11
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/9/2021
* Version : Version 1.0
* Description : This is program is
* an exenstion of Lab 9. The only
* addition is implementing the addSpeed,
* toString, and serveDrinks methods to
* exhibit polymorphic behavior.
***********************************/
#include <iostream>
#include "PlaneHeader.h"
#include "CarHeader.h"
#include <memory>
#include <vector>
#include <typeinfo>

int main() {
    shared_ptr<Vehicle> car = make_shared<Car>(1992, 20, "Car", "Honda", 40);
    cout << "-----------------------------------" << endl;
    cout << "Making a Car " << endl;
    cout << "Model: " << car->getModel() << endl;
    cout << "Year: " << car->getYear() << endl;
    cout << "Speed: " << car->getSpeed() << endl;
    
    shared_ptr<Vehicle> plane = make_shared<Plane>(2020, 200, "Plane", "Boeing", 3000);
 
    cout << "-----------------------------------" << endl;
    cout <<"Making a Plane "<< endl;
    cout <<"Model: " << plane->getModel()<<endl;
    cout <<"Year: " << plane->getYear()<<endl;
    cout <<"Speed: " << plane->getSpeed()<<endl;
    cout <<"-----------------------------------"<<endl;
  
    cout << "Using the toString function: " << car->toString();
    cout << endl << endl;;
    
    cout << "Using the toString function: " << plane->toString() << endl << endl;
    cout << "-----------------------------------" << endl;

    cout <<"Serve Drinks: Plane Class "<<plane->serveDrinks()<<endl;
    cout <<"Serve Drinks: Car Class "<<car->serveDrinks()<<endl;
    
    cout << "-----------------------------------" << endl;
    cout << "Adding speed (20 mph) to car" << endl;
    car->addSpeed(20);
    cout << "Speed is now : " << car->getSpeed() << endl << endl;
    /* car->addSpeed(-1);
    cout<<"Speed is now : "<<car->getSpeed()<<endl<<endl;
    */
    cout << "-----------------------------------" << endl;
    cout << "Adding speed (700 mph) to plane " << endl;
    plane->addSpeed(700);
    cout << "Speed is now : "<<plane->getSpeed() << endl << endl;
    cout << "-----------------------------------" << endl;
    cout << "Adding speed (200) to plane " << endl;
    plane->addSpeed(200);
    cout << "Speed is now : "<<plane->getSpeed() << endl << endl;
    cout << "-----------------------------------" << endl;
  }
