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
    string serveDrinks();
    string toString();
  
};
