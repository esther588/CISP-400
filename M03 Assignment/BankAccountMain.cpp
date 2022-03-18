/**********************************
* Title : Extend Bank Account
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/18/2021
* Version : Version 1.0
* Description : This is program that reads
* data from a file and fills an array with
* Bank Account objects, then displays all
* elements from the array. Then, it finds and
* displays the largest and smallest accounts
* and also any duplicate accounts.
***********************************/
#include "BankAccountHeader.h"
void display(string information);
void fillArray(std::ifstream &input, BankAccount accountsArray[]);
int largest(BankAccount accountsArray[]);
int smallest(BankAccount accountsArray[]);
void printArray(BankAccount accountsArray[]);
void findDuplicates(BankAccount accountsArray[]);
const int SIZE = 8;
int main() {
    BankAccount bankAccArr[SIZE]; // creates an array of BankAccount objects with size SIZE
    std::ifstream inFile;
    fillArray(inFile, bankAccArr); // fills array from file, details of input and output values and purpose of function
    printArray(bankAccArr); // displays all elements of the accounts array
    int largestIndex = largest(bankAccArr); // finds the index of largest account in the array
    BankAccount largestBankAcc = bankAccArr[largestIndex]; // obtains the largest account using the index
    string largestOutput = "Largest Balance: \n" + largestBankAcc.toString();
    display(largestOutput);
    int smallestIndex = smallest(bankAccArr); // finds the index of smallest account in the array
    BankAccount smallestBankAcc = bankAccArr[smallestIndex]; // obtains the largest account using the index
    string smallestOutput = "Smallest Balance: \n" + smallestBankAcc.toString();
    display(smallestOutput);
    findDuplicates(bankAccArr); // finds any duplicates in the array
    return 0;
}

// displays the given string to the console
void display(string information) {
    cout << information;
}

// method to fill array from file, details of input and output values and purpose of function
void fillArray(std::ifstream &input, BankAccount accountsArray[]) {
    input.open("/Users/esthercheng/Downloads/BankData.txt");
    if (!input) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int index = 0;
    std::string fullName, firstName, lastName;
    int accountId = 0, accountNumber = 0;
    double accountBalance = 0.0;
    while(index < SIZE) {
        input >> firstName >> lastName >> accountId >> accountNumber >> accountBalance;
        // combines the firstName and lastName strings together to make the full name
        fullName = firstName + " " + lastName;
        // creates a BankAccount object with the variables read from the file
        BankAccount bankAcc(fullName, accountId, accountNumber, accountBalance);
        // inserts the object into the array
        accountsArray[index] = bankAcc;
        index++;
    }
    input.close();
}

// method to find the largest account using balance as key
int largest(BankAccount accountsArray[]) {
    double tempVal = accountsArray[0].getAccountBalance();
    int largestIndex = 0;
    for(int index = 0; index < 8; index++) {
        if(tempVal < accountsArray[index].getAccountBalance()) {
            tempVal = accountsArray[index].getAccountBalance();
            largestIndex = index;
        }
    }
    return largestIndex;
}

// method to find the smallest account using balance as key
int smallest(BankAccount accountsArray[]) {
    double tempVal = accountsArray[0].getAccountBalance();
    int smallestIndex = 0;
    for(int index = 0; index < 8; index++) {
        if(tempVal > accountsArray[index].getAccountBalance()) {
            tempVal = accountsArray[index].getAccountBalance();
            smallestIndex = index;
        }
    }
    return smallestIndex;
}

// method to display all elements of the accounts array
void printArray(BankAccount accountsArray[]) {
    cout << "FAVORITE BANK - CUSTOMER DETAILS" << endl;
    cout << "--------------------------------" << endl;
    for(int index = 0; index < SIZE; index++) {
        BankAccount bankAcc = accountsArray[index];
        cout << bankAcc.toString();
    }
}

// finds any duplicate accounts from the given array
void findDuplicates(BankAccount accountsArray[]) {
    bool isDuplicate = false;
    for(int i = 0; i < SIZE; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            // calls the equals method and returns a BankAccount object
            BankAccount returnAcc = accountsArray[i].equals(accountsArray[j]);
            // check if the object returned is a dummy object
            if(returnAcc.getAccountName().compare("XXXX XXXX") == 0) {
                // switches the duplicate account with the dummy account
                accountsArray[j] = returnAcc;
                // flag to keep track if a duplicate acccount has been found
                isDuplicate = true;
                break;
            }
        }
    }
    // if there's been any duplicate account found
    if(isDuplicate) {
        cout << "Duplicate Accounts Found : Reprinting List" << endl << endl;
        printArray(accountsArray);
    }
}
