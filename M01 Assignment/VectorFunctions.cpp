#include "VectorHeader.h"
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
void initializeVector(std::vector<int> &numbers){ // populate the vector with VECTOR_SIZE number of random integers of value between 1 and 100
 // pass by ref ensures vector is returned with values to calling program
    srand(time(0)); // seed the random number
// put this in a loop to populate the vector with VECTOR_SIZE (ie 10) number of values
    for (int i = 0; i < VECTOR_SIZE; i++){
        int randomNumber = rand() % MAX_VALUE + 1;//returns random numbers between 1 and 100;
        numbers.push_back(randomNumber);
    }
}

void sortVector(std::vector<int> &numbers){    // use  sort on this  vector database from the begining to the end. Use iterators
    sort(numbers.begin(), numbers.end());
}

void reverseVector(std::vector<int> &numbers){   //  reverse this vector database
    std::reverse(numbers.begin(), numbers.end());
}

void displayVector(std::vector<int>numbers){     // display the vector contents by iterating through the vector
    for (auto iter = numbers.begin(); iter<numbers.end(); iter++) {
        std::cout<<*iter<<" ";
    }
    std::cout << std::endl;
}

void removeLowest(std::vector<int> &numbers){    // remove the number with the least value
    auto minElement = std::min_element(numbers.begin(), numbers.end());
    numbers.erase(minElement);
}

void displayResults(double value){       // display the calculated average of the values
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "The average is " << value << std::endl;
}

double calculateAverage(std::vector<int>numbers){ // calculate the average of the vector contents
    double avg = 0.0;
    // iterates through the vector and adds all integers together
    for(auto integer : numbers) {
        avg += integer;
    }
    // divides total of integers in vector by size of vector
    avg = avg / numbers.size();
    // return the value
    return avg;
}

