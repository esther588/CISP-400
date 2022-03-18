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
#include "VehicleHeader.h"

Vehicle::Vehicle() {
    year = 0;
    speed = 0;
    model = "";
    type = "";
}

Vehicle::Vehicle(int year, int speed, string type, string model){
    this->year = year;
    this->speed = speed;
    this->type = type;
    this->model = model;
}

void Vehicle::setSpeed(int speed){
     this->speed=speed;
}

void Vehicle::setYear(int year){
    this->year=year;
}

void Vehicle::setType(string type){
    this->type=type;
}

void Vehicle::setModel(string model){
    this->model=model;
}

int Vehicle::getSpeed()const{
    return speed;
}

int Vehicle::getYear(){
    return year;
}

string Vehicle::getType(){
    return type;
}

string Vehicle::getModel(){
    return model;
}

void Vehicle::addSpeed(int s){
    return;
}

string Vehicle::toString(){
    return "I am a Vehicle";
}

string Vehicle::serveDrinks(){
    return "Drinks are only served in Planes";
}
