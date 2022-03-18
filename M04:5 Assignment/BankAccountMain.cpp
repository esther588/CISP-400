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
void fillArray(std::ifstream &input, std::vector<BankAccount> &bankAccVector);
int largest(std::vector<BankAccount> bankAccVector);
int smallest(std::vector<BankAccount> bankAccVector);
void printArray(std::vector<BankAccount> bankAccVector);
void findDuplicates(std::vector<BankAccount> &bankAccVector);
void displayCount(int bankAccCount, int vectorCount);
void insertNewItems(std::vector<BankAccount> &bankAccVector);
const int SIZE = 8;
int main() {
    std::vector<BankAccount> bankAccVector; // creates an array of BankAccount objects with size SIZE
    std::ifstream inFile;
    fillArray(inFile, bankAccVector); // fills array from file, details of input and output values and purpose of function
    printArray(bankAccVector); // displays all elements of the accounts array
    int largestIndex = largest(bankAccVector); // finds the index of smallest account in the array
    cout << "Largest Balance:" << endl << bankAccVector[largestIndex].toString();
    int smallestIndex = smallest(bankAccVector); // finds the index of smallest account in the array
    cout << "Smallest Balance:" << endl << bankAccVector[smallestIndex].toString();
    displayCount(bankAccVector[0].getCount(), bankAccVector.size());
    findDuplicates(bankAccVector); // finds any duplicates in the array
    displayCount(bankAccVector[0].getCount(), bankAccVector.size()); // displays the count of objects
    insertNewItems(bankAccVector); // inserts the new bank account objects into the vector
    displayCount(bankAccVector[0].getCount(), bankAccVector.size()); // displays the count of objects
    return 0;
}

// method to fill array from file, details of input and output values and purpose of function
void fillArray(std::ifstream &input, std::vector<BankAccount> &bankAccVector) {
    input.open("/Users/esthercheng/Downloads/BankData.txt");
    try {
        if (!input) {
            throw 505;
        }
    } catch(...) {
        cout << "File Open Error" << endl;
        exit(1); // terminate with error
    }
    std::string fullName, firstName, lastName;
    int accountId = 0, accountNumber = 0;
    double accountBalance = 0.0;
    while(!input.eof()) {
        input >> firstName >> lastName >> accountId >> accountNumber >> accountBalance;
        // combines the firstName and lastName strings together to make the full name
        fullName = firstName + " " + lastName;
        // creates a BankAccount object with the variables read from the file
        BankAccount bankAcc(fullName, accountId, accountNumber, accountBalance);
        // inserts the object into the array
        bankAccVector.push_back(bankAcc);
    }
    input.close();
}

// method to find the largest account using balance as key
int largest(std::vector<BankAccount> bankAccVector) {
    double tempVal = bankAccVector[0].getAccountBalance();
    int largestIndex = 0, index = 0;
    for (auto iter = bankAccVector.begin(); iter < bankAccVector.end(); iter++) {
        if(tempVal < iter->getAccountBalance()) {
            tempVal = iter->getAccountBalance();
            largestIndex = index;
        }
        index++;
    }
    return largestIndex;
}

// method to find the smallest account using balance as key
int smallest(std::vector<BankAccount> bankAccVector) {
    double tempVal = bankAccVector[0].getAccountBalance();
    int smallestIndex = 0, index = 0;
    for (auto iter = bankAccVector.begin(); iter < bankAccVector.end(); iter++) {
        if(tempVal > iter->getAccountBalance()) {
            tempVal = iter->getAccountBalance();
            smallestIndex = index;
        }
        index++;
    }
    return smallestIndex;
}

// method to display all elements of the accounts vector
void printArray(std::vector<BankAccount> bankAccVector) {
    cout << "FAVORITE BANK - CUSTOMER DETAILS" << endl;
    cout << "--------------------------------" << endl;
    for (auto iter = bankAccVector.begin(); iter < bankAccVector.end(); iter++) {
        cout << iter->toString();
    }
}

// finds any duplicate accounts from the given vector
void findDuplicates(std::vector<BankAccount> &bankAccVector) {
    bool isDuplicate = false;
    for(int i = 0; i < bankAccVector.size(); i++) {
        for(int j = i + 1; j < bankAccVector.size(); j++) {
            // calls the equals method and returns a BankAccount object
            bool isEqual = bankAccVector[i].equals(bankAccVector[j]);
            // check if the object returned is a dummy object
            if(isEqual) {
                // switches the duplicate account with the dummy account
                bankAccVector.erase(bankAccVector.begin()+j);
                // flag to keep track if a duplicate acccount has been found
                isDuplicate = true;
                break;
            }
        }
    }
    // if there's been any duplicate account found
    if(isDuplicate) {
        cout << "Duplicate Accounts Found : Reprinting List" << endl << endl;
        printArray(bankAccVector);
    }
}

// method to display the count of objects using static count variable and vector size method
void displayCount(int bankAccCount, int vectorCount) {
    cout << "Using the static count, there are " << bankAccCount << " accounts" << endl;
    cout << "Using vector size, there are " << vectorCount << " accounts" << endl << endl;
}

// method to insert new bank account objects into vector at certain positions
void insertNewItems(std::vector<BankAccount> &bankAccVector) {
    BankAccount amyBankAcc("Amy Machado", 387623, 1244, 1023.67);
    BankAccount takBankAcc("Tak Phen", 981243, 1262, 6423.03);
    BankAccount celiaBankAcc("Celia Beatle", 465281, 1276, 3.56);
    auto iter1 = bankAccVector.insert(bankAccVector.begin() + 2, amyBankAcc);
    auto iter2 = bankAccVector.insert(bankAccVector.begin() + 4, takBankAcc);
    auto iter3 = bankAccVector.insert(bankAccVector.begin() + 6, celiaBankAcc);
    cout << "Inserted Three New Accounts: Reprinting List" << endl;
    printArray(bankAccVector);
}
