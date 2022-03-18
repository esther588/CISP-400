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
    //string toString();
};
