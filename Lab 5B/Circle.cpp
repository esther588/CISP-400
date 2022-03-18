/**********************************
* Title : Extended Circle 3 Pt 2
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/4/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 4 Circle class by storing data into
* a pointer array instead of a vector. In addition,
* the radius of circles can be compared to each
* other to determine which circle is larger.
* Positions of the pointer array can be switched,
* too, due to the fact that pointers are being used.
***********************************/
#include <math.h>
#include "CircleHeader.h"
int Circle::count = 0;

// default constructor
Circle::Circle(){
    x=y=0;
    radius=1;  //creates unit circle with center at origin
    count++;
}

// regular constructor
Circle::Circle(int xcoord,int ycoord, int r):x(xcoord),y(ycoord),radius(r){
    x=xcoord;
    y=ycoord;
    radius=r;
    count++;
}

void Circle::setX(int newX) {
    x = newX;
}
void Circle::setY(int newY) {
    y = newY;
}
void Circle::setRadius(int newRadius) {
    radius = newRadius;
}
int Circle::getX(){
    return x;
}
int Circle::getY(){
    return y;
}
int Circle::getRadius(){
    return radius;
}

// returns the area using formula pi*r^2
double Circle::getArea(){
    return M_PI*radius*radius;
}

// returns the circumference using the formula 2*pi*r
double Circle::getCircumference(){
    return 2*M_PI*radius;
}

// return the circle as a string in the form (x,y) : radius
string Circle::toString() {
    return "(" + to_string(getX()) + "," + to_string(getY()) + ")" + ":" + to_string(getRadius()) + "\n";
}

// returns the distance between the center of this circle and the other circle
double Circle::getDistanceCircle(Circle other) {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

// move the center of the circle to the new coordinates
void Circle::moveTo(int newX, int newY) {
    x = newX;
    y = newY;
}

// returns true if the center of the other circle lies inside this circle else returns false
bool Circle::intersects(Circle other) {
    bool isIntersect = false;
    if ((other.x - x) * (other.x - x) +
        (other.y - y) * (other.y - y) <= other.radius * other.radius) {
        isIntersect = true;
    }
    return isIntersect;
}

// multiply the radius by the scale
void Circle::resize(double scale) {
    radius = radius * scale;
}

// returns a new Circle with the same center as this circle but radius multiplied by scale
Circle Circle::resize(int scale) {
    Circle newCircle(x, y, scale * radius);
    return newCircle;
}

//returns the number of circles created
int Circle::getCount() {
    return count;
}

// method that compares two circles using radius as key
bool Circle::greaterThan(Circle * other){
    return this->radius > other->getRadius(); // checks if "this circle" is greater than the "other circle"
}
