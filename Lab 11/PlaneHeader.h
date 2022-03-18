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
class Plane : public Vehicle {
private:
    int altitude;
public:
    Plane();
    Plane(int year, int speed, string type, string model, int altitude) : Vehicle(year,speed, type,model), altitude(altitude){};
    void addSpeed(int speed);
    int getAltitude();
    void setAltitude(int height);
    string serveDrinks();
    string toString();
};
