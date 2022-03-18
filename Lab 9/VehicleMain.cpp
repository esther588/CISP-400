/**********************************
* Title : Lab 9
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/1/2021
* Version : Version 1.0
* Description : This is program consists
* of two classes, Car and Plane, that inherit
* from the Vehicle class and creates vehicles
* with specific models, years, speeds and
* wheelSize or altitude depending on if it's
* a car or plane.
***********************************/
#include <iostream>
#include "PlaneHeader.h"
#include "CarHeader.h"
#include <memory>
#include <vector>
#include <typeinfo>

int main() {
    shared_ptr<Car> car = make_shared<Car>(1992, 20, "Car", "Honda", 40);
    cout << "-----------------------------------" << endl;
    cout << "Making a Car " << endl;
    cout << "Model: " << car->getModel() << endl;
    cout << "Year: " << car->getYear() << endl;
    cout << "Speed: " << car->getSpeed() << endl;
    cout << "WheelSize: " << car->getWheelSize() << endl;
    
    shared_ptr<Plane> plane = make_shared<Plane>(2020, 200, "Plane", "Boeing", 3000);
 
    cout << "-----------------------------------" << endl;
    cout <<"Making a Plane "<< endl;
    cout <<"Model: " << plane->getModel()<<endl;
    cout <<"Year: " << plane->getYear()<<endl;
    cout <<"Speed: " << plane->getSpeed()<<endl;
    cout <<"Altitude: " << plane->getAltitude()<<endl;
    cout <<"-----------------------------------"<<endl;
  
    cout << "I am a car and my wheelSize is " << car->getWheelSize() << endl;
    cout << "Using the toString function: " << car->toString();
    cout << endl << endl;;
    
    cout << "I am a plane and my altitude is "<< plane->getAltitude() << endl;
    cout << "Using the toString function: " << plane->toString() << endl << endl;
    cout << "-----------------------------------" << endl;

    cout << "Creating a plane of Declared Type Plane and actual type Plane" << endl;
    cout << "Serve Drinks Function Overriden by Plane Class" << endl;
    shared_ptr<Plane> plane2 = make_shared<Plane>(2000, 100, "Plane", "Lockheed", 5000);
  
    cout <<"Plane says :"<<plane2->serveDrinks() << endl;
  
    cout << "-----------------------------------" << endl;
    cout << "Creating a plane of Declared Type Vehicle and actual type Plane" << endl;
    shared_ptr<Vehicle> plane3 = make_shared<Plane>(1000, 100, "Plane", "Hughes", 2000);
    cout << "Serve Drinks Function Not Overriden by Plane Class, Vehicle Class prevails " << endl;
    cout << "Vehicle Says: " << plane3->serveDrinks() << endl;
  }
