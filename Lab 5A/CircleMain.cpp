/**********************************
* Title : Extended Circle 3
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/4/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 4 Circle class by erasing circles
* with radii larger than 8. A simple destructor
* is also created in the Circle class.
***********************************/
#include "CircleHeader.h"
void inputData(std::vector<Circle> &circleVector, string filename);
void displayVector(std::vector<Circle> circleVector);
void displayCount(std::vector<Circle> circleVector, int count);
void checkToErase(std::vector<Circle> &circleVector);
int main(){
    std::vector<Circle> circleVector; // creates a vector of circles
    inputData(circleVector, "/Users/esthercheng/Downloads/dataLab5B.txt");
    displayVector(circleVector);
    checkToErase(circleVector);
    cout << "The number of circles remaining is " << circleVector.size() << endl;
    Circle circle1(3, 4, 7);
    Circle circle2(-2, -4, 4);
    auto insert1 = circleVector.insert(circleVector.begin()+2, circle1);
    auto insert2 = circleVector.insert(circleVector.begin()+3, circle2);
    displayVector(circleVector);
    return 0;
}

// reads data from a file into a vector of circles
void inputData(std::vector<Circle> &circleVector, string filename) {
    std::ifstream input;
    input.open(filename);
    try {
        if (!input) {
            throw 505;
        }
    } catch(...) {
        cout << "File Open Error" << endl;
        exit(1); // terminate with error
    }
    string str, xCoordStr, yCoordStr, radiusStr;
    int xCoord = 0, yCoord = 0, radius = 0;
    while(!input.eof()) {
        getline(input, str);
        std::istringstream stream(str);
        stream >> xCoordStr >> yCoordStr >> radiusStr;
        xCoord = std::stoi(xCoordStr);
        yCoord = std::stoi(yCoordStr);
        radius = std::stoi(radiusStr);
        Circle newCircle(xCoord, yCoord, radius);
        circleVector.push_back(newCircle);
    }
    input.close();
}

// method to display all the circles in the vector
void displayVector(std::vector<Circle> circleVector) {
    int finalCount = 0;
    cout << "The circles created are :" << endl;
    for (auto iter = circleVector.begin(); iter<circleVector.end(); iter++) {
        std::cout<< iter->toString();
        finalCount = iter->getCount();
    }
    displayCount(circleVector, finalCount);
}

// method to check if each circle's radius is larger than 8. if it is, erase it from the vector
void checkToErase(std::vector<Circle> &circleVector) {
    int finalCount = 0, count = 0;
    for (auto iter = circleVector.begin(); iter<circleVector.end(); iter++) {
        if(iter->getRadius() > 8) {
            circleVector.erase(circleVector.begin()+count);
            iter--;
            finalCount = iter->getCount();
            finalCount--;
            iter->setCount(finalCount);
        } else {
            count++;
        }
    }
}

// method to display the current count of all the circles using result from the getCount method and the vector size method
void displayCount(std::vector<Circle> circleVector, int count) {
    cout << "The number of circles using getCount method is " << count << endl;
    cout << "The number of circles remaining is " << circleVector.size() << endl;
}
