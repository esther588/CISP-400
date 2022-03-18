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
#include "CircleHeader.h"
const int SIZE = 6;
int inputData(Circle **circlePointerArray, string filename);
void displayVector(Circle **circlePointerArray);
void displaySumOfAreas(Circle **circlePointerArray);
void swapArrPos(Circle **circlePointerArray);
int main() {
    Circle *circleOne = new Circle(0, 0, 5);
    Circle *circleTwo = new Circle(-2, -2, 10);
    // checks which circle has the larger radius
    if(circleOne->greaterThan(circleTwo)) {
        cout << "Circle One is bigger" << endl;
    } else {
        cout << "Circle Two is bigger" << endl;
    }
    // create an array of pointers to circles
    Circle *circlePointerArray[SIZE];
    //populate the pointer array with circles from the data file and return the number of circles created
    int count = inputData(circlePointerArray, "/Users/esthercheng/Downloads/dataLab5B.txt");
    cout << "The total number of circles is " << count << endl;
    cout << "They are :" << endl;
    displayVector(circlePointerArray);
    displaySumOfAreas(circlePointerArray);
    swapArrPos(circlePointerArray);
    cout << "The modified array is :" << endl;
    displayVector(circlePointerArray);
    return 0;
}

// reads data from a file into a Circle array
int inputData(Circle **circlePointerArray, string filename) {
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
    int xCoord = 0, yCoord = 0, radius = 0, index = 0;
    while(!input.eof()) {
        getline(input, str);
        std::istringstream stream(str);
        stream >> xCoordStr >> yCoordStr >> radiusStr;
        xCoord = std::stoi(xCoordStr);
        yCoord = std::stoi(yCoordStr);
        radius = std::stoi(radiusStr);
        Circle *newCircle = new Circle (xCoord, yCoord, radius);
        circlePointerArray[index] = newCircle;
        index++;
    }
    input.close();
    return index;
}

// displays all the circles in the array
void displayVector(Circle **circlePointerArray) {
    for (int i = 0; i < SIZE; i++) {
        Circle *tempCircle = circlePointerArray[i];
        cout << tempCircle->toString();
    }
}

// displays the sum of the areas of all the circles in the array
void displaySumOfAreas(Circle **circlePointerArray) {
    double sum = 0.0;
    for (int i = 0; i < SIZE; i++) {
        Circle *tempCircle = circlePointerArray[i];
        sum += tempCircle->getArea();
    }
    cout << "The total sum of the areas is " << sum << endl;
}

// swaps the pointers of the first and third index
void swapArrPos(Circle **circlePointerArray) {
    for (int i = 0; i < SIZE; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            if(i == 1 && j == 3) {
                Circle *posCircle1 = circlePointerArray[i];
                Circle *posCircle2 = circlePointerArray[j];
                circlePointerArray[i] = posCircle2;
                circlePointerArray[j] = posCircle1;
            }
        }
    }
}
