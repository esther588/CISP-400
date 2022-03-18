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
#include <fstream>
#include <sstream>

class Painting {
   vector<shared_ptr<Circle>> paintingVector;
   
 public:
   Painting();
   //regular constructor
   Painting(string filename);
   //ifstream inputFile(filename);
  
public:
    //try to remove const and see what happens
    std::shared_ptr<Circle> getCircle(int index) const;
    //try to remove const and see what happens
    int getSize()const;
    
    //copy constructor for the Painting class
    Painting(const Painting &other);
  
    //-----------------------> } extra } here
    //return a string of the painting
    string toString();
    
    void setRadius(int index, int radius);
    //destructor
    ~Painting();

};
