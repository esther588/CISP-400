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
#include "CircleHeader.h"
string displaysIntersect(bool isIntersect);
int main(){
    Circle circleOne;
    cout << "First Circle " << circleOne.toString();
    Circle circleTwo(0, 0, 4);
    cout << "Second Circle " << circleTwo.toString();
    cout << "The distance between the two circles is: " << circleOne.getDistanceCircle(circleTwo) << endl;
    cout << "The circles " << displaysIntersect(circleOne.intersects(circleTwo)) << endl;
    Circle circleThree = circleTwo.resize(10);
    cout << "Third Circle created " << circleThree.toString();
    circleThree.moveTo(4, 5);
    cout << "Moved circle Three - " << circleThree.toString();
    cout << "The circles Second and Third " << displaysIntersect(circleTwo.intersects(circleThree)) << endl;
    Circle circleFour(4, 5, 1);
    cout << "Fourth Circle created " << circleFour.toString();
    cout << "The circles First and Fourth " << displaysIntersect(circleOne.intersects(circleFour)) << endl;
    circleThree.resize(9.5);
    cout << "Resized cicle Three - " << circleThree.toString();
   
   return 0;
}

string displaysIntersect(bool isIntersect) {
    string display;
    if(isIntersect) {
        display = "do intersect";
    } else {
        display = "do not intersect";
    }
    return display;
}
