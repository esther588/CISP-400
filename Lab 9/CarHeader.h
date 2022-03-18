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
#pragma once
#include "VehicleHeader.h"

class Car : public Vehicle {

private:
  int wheelSize;
public:
    Car();
    Car(int year, int speed, string type, string model, int wheelSize) : Vehicle(year, speed, type, model), wheelSize(wheelSize){};
    void addSpeed(int s);
    int getWheelSize();
    string toString();
  
};
