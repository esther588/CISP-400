/**********************************
* Title : Circle
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/18/2021
* Version : Version 1.0
* Description : This is program that creates
* a circle with the specified x and y
* coordinates and radius. Then computes
* the area and circumferences of the circle.
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

};
