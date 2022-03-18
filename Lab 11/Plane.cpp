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
    cout << "In Plane's add Speed : Trying to add speed : " << s << endl;
    int speed = getSpeed() + s;
    try{
        if(speed > 0 && speed < 1000) {
            setSpeed(speed);
        } else {
            throw string("Over speed limit of 1000");
        }
        
    }
    catch (string message){
        cout << message << endl;
        exit(0);
    }
}

string Plane::serveDrinks() {
    return "Water and Apple Juice Available";
}

string Plane::toString() {
    return getType() + " " + getModel() + " " + to_string(getYear()) + " Speed " + to_string(getSpeed());
}
