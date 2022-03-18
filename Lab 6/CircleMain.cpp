/**********************************
* Title : Extended Circle 4
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/10/2021
* Version : Version 1.0
* Description : This is program that extends
* the Lab 5B Circle class by storing data into
* a vector of pointers to circles. In addition,
* the radius of circles can be compared to each
* other to determine which circle is larger.
* Positions of the pointer vector can be switched,
* too, due to the fact that pointers are being used.
***********************************/
#include "CircleHeader.h"
const int SIZE = 6;
// pay attention to this parameter list
int inputData(vector<shared_ptr<Circle>> &circlePointerArray, string filename);
void displayVector(vector<shared_ptr<Circle>> &circlePointerArray);
void displaySumOfAreas(vector<shared_ptr<Circle>> &circlePointerArray);
void swapArrPos(vector<shared_ptr<Circle>> &circlePointerArray);

int main() {
    Circle circleOne(0,0,5);
    Circle *circleOnePtr = &circleOne;
   // create a new shared pointer to a Circle Object
    Circle circleTwo(-2, -2, 10);
   //*************** create another shared pointer called circleTwoPtr
    Circle *circleTwoPtr = &circleTwo;
   
    // check which circle has a larger radius
    if (circleOnePtr->greaterThan(circleTwoPtr)) {
      cout << "Circle One is bigger " << endl;
    } else {
      cout << "Circle Two is bigger " << endl;
    }

// declare a vector of shared pointers to Circle objects

    vector<shared_ptr<Circle>>circlePointerVector;
    int count = inputData(circlePointerVector, "/Users/esthercheng/Downloads/dataLab6.txt");
    cout<<"The total number of circles is " << count << endl;
    displayVector(circlePointerVector);
    displaySumOfAreas(circlePointerVector);
    swapArrPos(circlePointerVector);
    cout << "The modified array is " << endl;
    displayVector(circlePointerVector);
    return 0;
   
}

// reads data from a file into a vector of pointers to circles
int inputData(vector<shared_ptr<Circle>> &circlePointerArray, string filename) {
    std::ifstream inputFile(filename);
    std::istringstream instream;
    string data;
    int count = 0;
    int x, y, radius;
    try{
        if (inputFile){
            while (!inputFile.eof() && count < SIZE){
                getline(inputFile,data);
                std::istringstream instream(data);
                instream>>x;
                instream>>y;
                instream>>radius;
                //create a new Circle object and push it into
                //the vector
                std::shared_ptr<Circle> newCircle = std::make_shared<Circle>(x, y, radius);
                circlePointerArray.push_back(newCircle);
                count++;
            }
            
        } else throw string("File Not Found");
        
    }
    catch (string message){
        cout << message << endl;
        exit(0);
    }
    return count;
}

// displays all the circles in the vector
void displayVector(vector<shared_ptr<Circle>> &circlePointerArray) {
    cout << "They are :" << endl;
    for (auto iter = circlePointerArray.begin(); iter < circlePointerArray.end(); iter++) {
        cout << (*iter)->toString();
    }
}

// displays the sum of the areas of all the circles in the vector
void displaySumOfAreas(vector<shared_ptr<Circle>> &circlePointerArray) {
    double sum = 0.0;
    for (auto iter = circlePointerArray.begin(); iter < circlePointerArray.end(); iter++) {
        sum += (*iter)->getArea();
    }
    cout << "The total sum of the areas is " << sum << endl;
}

// swaps the pointers of the first and third index
void swapArrPos(vector<shared_ptr<Circle>> &circlePointerArray) {
    std::shared_ptr<Circle> posCircle1 = circlePointerArray[1];
    std::shared_ptr<Circle> posCircle2 = circlePointerArray[3];
    circlePointerArray[1] = posCircle2;
    circlePointerArray[3] = posCircle1;
}
