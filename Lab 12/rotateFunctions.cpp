/**********************************
* Title : Lab 12
* Author : Esther Cheng
 Student ID : 1754368
* Date : 10/15/2021
* Version : Version 1.0
* Description : This is program
* creates four vectors of four different
* data types that will use the fuctions
* rotateLeft and output. rotateLeft
* takes in a vector of any type as input
* and rotates the vector by one position
* in a circular way. The methods
* implement generic data types.
***********************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Function to rotate data by one index
template <typename T>
void rotateLeft(std::vector<T> & v) {
  T temp = v[0];
  for (int i = 0; i < v.size() - 1; i++) {
    v[i] = v[i + 1];
  }
  v[v.size() - 1] = temp;
}

// Function to output data
template <typename T>
void output(std::vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
      cout << left << setprecision(2) << fixed << setw(7) << v[i] << " ";
    }
    cout << endl;
}
