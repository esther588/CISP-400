/**********************************
* Title : Extended Circle 2
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/19/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 3 Circle class by adding a count
*  for how many circles created.
***********************************/
#include "CircleHeader.h"
void inputData(std::vector<Circle> &circleVector, string filename);
void displayVector(std::vector<Circle> circleVector);
void displayCount(std::vector<Circle> circleVector, int count);
int main(){
    std::vector<Circle> circleVector; // creates a vector of circles
    inputData(circleVector, "/Users/esthercheng/Downloads/dataLab4.txt");
    displayVector(circleVector);
    cout << "Erasing the Vector of Circles" << endl;
    circleVector.clear(); // clears the vector
    cout << "Creating a new Circle" << endl;
    Circle c; // creates a default circle
    displayCount(circleVector, c.getCount());
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

// method to display the current count of all the circles using result from the getCount method and the vector size method
void displayCount(std::vector<Circle> circleVector, int count) {
    cout << "The number of circles using getCount method is " << count << endl;
    cout << "The number of circles remaining is " << circleVector.size() << endl;
}
