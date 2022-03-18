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
// Header files
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include "rotateFunctions.cpp"

using namespace std;

// Main
int main() {

    // Define variables and open file
    ifstream inFile;
    inFile.open("/Users/esthercheng/Downloads/text.txt");

    // creates four vectors of four different datatypes: Integer, Double, Char, and String
    vector <int> data1;
    vector <char> data2;
    vector <double> data3;
    vector <string> data4;
    string input;

    // Generate data for the four vectors
    for (int i = 0; i < 10; i++) {
        data1.push_back(i);
        data2.push_back(i + 'A');
        data3.push_back(i / 0.35);
        getline(inFile, input, ' ');
        data4.push_back(input);
    }

    // Close file
    inFile.close();

    // Display rotating integer data
    for (int i = 0; i < data1.size(); i++) {
        output(data1);
        rotateLeft(data1);
    }

    std::cout << std::endl << std::endl;

    // Display rotating char data
    for (int i = 0; i < data2.size(); i++) {
        output(data2);
        rotateLeft(data2);
    }

    std::cout << std::endl << std::endl;

    // Display rotating floating point number data
    for (int i = 0; i < data3.size(); i++) {
        output(data3);
        rotateLeft(data3);
    }

    std::cout << std::endl << std::endl;

    // Display rotating string data
    for (int i = 0; i < data4.size(); i++) {
        output(data4);
        rotateLeft(data4);
    }
    return 0;
}
