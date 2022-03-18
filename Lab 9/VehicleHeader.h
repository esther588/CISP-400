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
#include <string>
#include <iostream>
using namespace std;
class Vehicle {
private:
  int year;
  int speed;
  string type;
  string model;
public:
    Vehicle();
    Vehicle(int year, int speed, string type, string model);
    void setSpeed(int speed);
    void setYear(int year);
    void setModel(string model);
    void setType(string type);
    int getSpeed()const;
    int getYear();
    string getType();
    string getModel();
    void addSpeed(int s) ;
    string toString();
    string serveDrinks();
};
