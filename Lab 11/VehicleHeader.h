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
    virtual void addSpeed(int s);
    virtual string toString();
    virtual string serveDrinks();
};
