/**********************************
* Title : Extended Circle 3
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/4/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 4 Circle class by erasing circles
* with radii larger than 8. A simple destructor
* is also created in the Circle class.
***********************************/
#include <math.h>
#include<iostream>
#include<iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::to_string;
class Circle{
private:
    int x,y;
    int radius;
    static int count;

   // all the method headers for the class
public:
    Circle();
    Circle(int xcoord, int ycoord, int r);
    ~Circle();
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
    int getCount();
    void setCount(int newCount);

};
