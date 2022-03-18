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
#include "CarHeader.h"

Car::Car() {
    wheelSize = 0;
    setYear(0);
    setSpeed(0);
    setType("");
    setModel("");
}

void Car::addSpeed(int s) {
    cout << "In Car's add Speed : Trying to add speed : " << s << endl;
    int speed = getSpeed() + s;
    try{
        if(speed > 0 && speed < 100) {
            setSpeed(speed);
        } else {
            throw string("Over speed limit of 100");
        }
        
    }
    catch (string message){
        cout << message << endl;
        exit(0);
    }
}

int Car::getWheelSize() {
    return wheelSize;
}

string Car::serveDrinks() {
    return "Food and Drinks are not permitted in a Car";
}

string Car::toString() {
    return getType() + " " + getModel() + " " + to_string(getYear()) + " Speed " + to_string(getSpeed()) + " wheelSize " + to_string(getWheelSize());
}
