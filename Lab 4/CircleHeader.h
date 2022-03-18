/**********************************
* Title : Extended Circle 2
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/19/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 3 Circle class by creating a vector
* of circles, reads from a text file and inserts
* data into the vector. Then displays the circles
* and their counts, afterwards clearing the vector.
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

};
