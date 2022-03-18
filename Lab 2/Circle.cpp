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
#include "CircleHeader.h"

// default constructor
Circle::Circle(){
    x=y=0;
    radius=1;  //creates unit circle with center at origin
}

// regular constructor
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
