/**********************************
* Title : Extended Circle 4
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/10/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 5B Circle class by storing data into
* a vector of pointers to circles. In addition,
* the radius of circles can be compared to each
* other to determine which circle is larger.
* Positions of the pointer vector can be switched,
* too, due to the fact that pointers are being used.
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
using std::vector;
using std::shared_ptr;
class Circle {
private:
    int x,y;
    int radius;
    static int count;

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
    int getCount();
    bool greaterThan(Circle * other);
};
