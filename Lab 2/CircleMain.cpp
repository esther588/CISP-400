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
#include "CircleHeader.h"

int main(){
    Circle circleOne;
    cout << "Created circleOne" << circleOne.toString();
    Circle circleTwo(0,0,4);
    cout << "Created circleTwo" << circleTwo.toString();
    Circle circleThree(-2,-9,6);
    cout << "Created circleThree" << circleThree.toString();
   //use the above starter to create circleThree and complete the rest of the lab to print the circle, circumference and area
    cout << std::fixed << std::setprecision(2);
    cout << "The area of circleOne is " << circleOne.getArea() << " Its circumference is " << circleOne.getCircumference() << endl;
    cout << "The area of circleTwo is " << circleTwo.getArea() << " Its circumference is " << circleTwo.getCircumference() << endl;
    cout << "The area of circleThree is " << circleThree.getArea() << " Its circumference is " << circleThree.getCircumference() << endl;
   
   return 0;
}
