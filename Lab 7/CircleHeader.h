/**********************************
* Title : Extended Circle 5
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/17/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 6 Circle class by adding a copy
* constructor and adds a “<” (less than) operator
* by overloading. There is also an added Painting
* class that is composed of a vector of Circle objects.
***********************************/
#include <math.h>
#include <iostream>
#include <iomanip>
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
    static int count;
    int radius;
    int x,y;
public:
    Circle();
    Circle(int xcoord,int ycoord, int r);
    Circle(const shared_ptr<Circle> &other);
    int getY();
    int getX();
    int getRadius();
    static int getCount();
    double getArea();
    double getCircumference();
    double getDistance(Circle other);
    bool intersects(Circle other);
    Circle resize(int scale);//to copy self to other;
    void resize(double scale);//for self
    void setX(int xcoord);
    void setY(int xcoord);
    void setRadius(int r);
    bool greaterThan(shared_ptr<Circle> other);
    bool operator<(shared_ptr<Circle> other);
    string toString();
    ~Circle();
};
