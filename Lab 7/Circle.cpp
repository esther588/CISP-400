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

// copy constructor
Circle::Circle( const shared_ptr<Circle> &other) {
    shared_ptr<Circle> temp = std::make_shared<Circle>();
    temp->setX(other->getX());
    temp->setY(other->getY());
    temp->setRadius(other->getRadius());
    x=temp->getX();
    y=temp->getY();
    radius=temp->getRadius();
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
    return "(" + to_string(getX()) + "," + to_string(getY()) + ")" + ":" + to_string(getRadius());
}

// returns the distance between the center of this circle and the other circle
double Circle::getDistance(Circle other) {
    return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
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
bool Circle::greaterThan(std::shared_ptr<Circle> other){
    return this->radius > other->getRadius(); // checks if "this circle" is greater than the "other circle"
}

bool Circle::operator<(shared_ptr<Circle> other){
  return this->radius < other->getRadius();
}

Circle::~Circle() {

}
