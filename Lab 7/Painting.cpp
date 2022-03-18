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
#include <fstream>
#include <sstream>
#include "PaintingHeader.h"

Painting::Painting(){
    
}
 
//regular constructor
Painting::Painting(string filename) {
    std::ifstream inputFile(filename);
    std::istringstream instream;
    string data;
    int count = 0;
    int x, y, radius;
    try {
        if (inputFile) {
            while (!inputFile.eof()) {
                getline(inputFile,data);
                std::istringstream instream(data);
                instream >> x;
                instream >> y;
                instream>>radius;
                std::shared_ptr<Circle> circle = std::make_shared<Circle>(x,y,radius);
                paintingVector.push_back(circle);
                count++;
            }
        } else throw string("File Not Found");
    }
    catch (string message){
        cout << message << endl;
        exit(0);
    }
}
 

//returns a circle at the given index in the std::shared_ptrector
std::shared_ptr<Circle> Painting::getCircle(int index) const {
    return paintingVector[index];
}

//gets the size of the painting vector
int Painting::getSize()const {
    return paintingVector.size();
}

//copy constructor for the Painting Class
Painting::Painting(const Painting &other) {
   
   // copy individual circles from other to this painting
   // note that deep copy for these circles will need to be done since
   // the painting vector contains pointers to circles

   //this code will involves a for loop to traverse "other"
   // make temporary pointer to circle which contains a copy of the current "other" circle
   //push this pointer onto the "this" painting vector
    
    for (auto iter = other.paintingVector.begin(); iter < other.paintingVector.end(); iter++) {
        shared_ptr<Circle> temp = std::make_shared<Circle>((*iter)->getX(), (*iter)->getY(), (*iter)->getRadius());
        paintingVector.push_back(temp);
    }

}
 

  
//returns a string containing the painting vector
string Painting::toString(){
    string fullVector = "[";
    //concatenate the strings of individual circle objects of the painting Vector
    for (auto iter = paintingVector.begin(); iter < paintingVector.end(); iter++) {
        fullVector+= " " + (*iter)->toString();
    }
    fullVector += " ]";
    return fullVector;
}


void Painting::setRadius(int index,int radius) {
    paintingVector[index]->setRadius(radius);
}

Painting::~Painting() {
    //delete paintingVector;
    paintingVector.clear();
}
