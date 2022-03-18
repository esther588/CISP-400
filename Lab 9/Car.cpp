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
#include "CarHeader.h"

Car::Car() {
    wheelSize = 0;
    setYear(0);
    setSpeed(0);
    setType("");
    setModel("");
}

int Car::getWheelSize() {
    return wheelSize;
}

string Car::toString() {
    return getType() + " " + getModel() + " " + to_string(getYear()) + " Speed " + to_string(getSpeed()) + " wheelSize " + to_string(getWheelSize());
}
