/**********************************
* Title : Extended Circle
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/19/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 2 Circle class by calculating the distance
* between two circles, resizing the circle, checking
* if the original circle's center is inside a passed in circle,
* and adjusting the center of a circle.
***********************************/
#include <math.h>
#include<iostream>
#include<iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
class Circle{
private:
    int x,y;
    int radius;

   // all the method headers for the class
public:
    Circle();
    Circle(int xcoord,int ycoord, int r);
    void setX(int newX);
    void setY(int newY);
    void setRadius(int newRadius);
    int getX();
    int getY();
    int getRadius();
    double getArea();
    double getCircumference();
    string toString();
    double getDistanceCircle(Circle other);
    void moveTo(int newX, int newY);
    bool intersects(Circle other);
    void resize(double scale);
    Circle resize(int scale);

};
