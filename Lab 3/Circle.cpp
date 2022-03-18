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
#include "CircleHeader.h"

// default constructor
Circle::Circle(){
    x=y=0;
    radius=1;  //creates unit circle with center at origin
}

  // regular constructor
//Circle(int xcoord,int ycoord, int r):x(xcoord),y(ycoord),radius(r);
Circle::Circle(int xcoord,int ycoord, int r):x(xcoord),y(ycoord),radius(r){
    x=xcoord;
    y=ycoord;
    radius=r;
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
