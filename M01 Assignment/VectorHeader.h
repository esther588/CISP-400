/**********************************
 * Title : Vector
 * Author : Esther Cheng
 * Student ID : 1754368
 * Date : 8/17/2021
 * Version : Version 1.0
 * Description : This is program that populates
 * a vector with randomized integers,
 * removes the smallest value, and calculates
 * the average of the remaining vector values.
***********************************/
#include <vector>
#include <cstdlib>   // for random number
#include <ctime>     // for seeding random number
#include<algorithm>  // for vector libraries
#include<iostream>   // for console output
#include<iomanip>    // for formatting output

const int MAX_VALUE = 100;     // The contents of the vector can have values from 1 to MAX_VALUE.
//Use random number with this constant to generate values

const int VECTOR_SIZE = 10;    // size - ie number of vector elements

void initializeVector(std::vector<int> &numbers); // populate the vector with VECTOR_SIZE number of random integers of value between 1 and 100
 // pass by ref ensures vector is returned with values to calling program
void sortVector(std::vector<int> &numbers);       // use the vector and algorithm library to sort this vector database
void reverseVector(std::vector<int> &numbers);    // use the vector and algorithm library to reverse this vector database
void displayVector(std::vector<int>numbers);      // display the vector contents by iterating through the vector
void removeLowest(std::vector<int> &numbers);     // remove the number with the least value
void displayResults(double value);                // display the calculated average of the values
double calculateAverage(std::vector<int>numbers); // calculate the average of the vector contents
