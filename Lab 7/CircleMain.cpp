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
#include "CircleHeader.h"
#include "PaintingHeader.h"

int main() {
    // create a new shared pointer to a Circle Object
    std::shared_ptr<Circle> circleOnePtr = std::make_shared<Circle>(0,0,15);
    Circle circleTwo(-2, -2, 10);
   //*************** create another shared pointer called circleTwoPtr
    std::shared_ptr<Circle> circleTwoPtr = std::make_shared<Circle>(0,0,7);
   
    // check which circle has a larger radius
    if (!(circleOnePtr->operator<(circleTwoPtr))) {
       cout << "Circle One is bigger" << endl;
    } else {
       cout<< "Circle Two is bigger" << endl;
    }

    Painting p("/Users/esthercheng/Downloads/dataLab7.txt");
    cout << "Printing Painting p" << endl;
    cout << p.toString() << endl;
    Painting q = p;
    cout << "Printing Painting q" << endl;
    cout << q.toString() << endl;
    cout<<"Changing Painting q"<<endl;
    q.setRadius(0,99);
    cout << "Printing Painting p" << endl;
    cout<<p.toString()<<endl;
    cout << "Printing Painting q" << endl;
    cout << q.toString() << endl;
    return 0;
   
}
