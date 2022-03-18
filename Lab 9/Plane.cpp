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
#include "PlaneHeader.h"

Plane::Plane() {
    setAltitude(0);
    setYear(0);
    setSpeed(0);
    setType("");
    setModel("");
}

int Plane::getAltitude() {
    return altitude;
}

void Plane::setAltitude(int height) {
    if(altitude >= 0 && altitude < 300000) {
        altitude = height;
    }
}

void Plane::addSpeed(int s) {
    return;
}

string Plane::serveDrinks() {
    return "Water and Apple Juice Available";
}
