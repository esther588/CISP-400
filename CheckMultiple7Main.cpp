/**********************************
* Title : Check Multiple 7
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/16/2021
* Version : Version 1.0
* Description : This is program that prompts
* the user for an integer. It then checks if that
* integer is a multiple of 7 and prints a message
* with the answer.
***********************************/
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int inputNumber();
bool checkMultiple7(int number);
void displayResults(string message);
void runNumberCheck();
int main() {
    //single call to runNumberCheck
    runNumberCheck();
}

// this function inputs an integer from the console and returns this number to the main program
// no input validation required
void runNumberCheck(){
    //declare integer variable
    int number = 0;
    string message = "";
    // get the input number by calling function inputNumber
    number = inputNumber();
    //pass this number to checkMultiple7 method
    bool result = checkMultiple7(number);
    cout << number;
    // if checkMultiple7 method returns true, call
    //displayResults method and pass print message that it is a multiple of 7
    // if false call
    //displayResults method and pass print message that it is Not  a multiple of 7
    if(result == true) {
        message = " is a multiple of 7";
        displayResults(message);
    } else {
        message = " is not a multiple of 7";
        displayResults(message);
    }


    // this function inputs an integer from the console and returns this number to the main program
    // no input validation required
}
int inputNumber(){
    //declare an integer variable
    int number = 0;
    // prompt user for integer input
    cout << "Please enter an integer ";
    // read the input into the integer variable
    cin >> number;
    // return the value
    return number;
    
}
bool checkMultiple7(int number){
    // check if number is a multiple of 7 by using formula (number %7 == 0)
    bool isMultiple = false;
    if(number % 7 == 0) {
        isMultiple = true;
    }
    //return true or false accordingly
    return isMultiple;
}
void displayResults(string message){
    //output the message
    cout << message << endl;
}
