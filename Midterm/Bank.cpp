/**********************************
* Title : Midterm
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/17/2021
* Version : Version 1.0
* Description : The client program will be a
* menu driven application to service viewing
* an account, depositing and withdrawing
* from an account (funds permitting).
***********************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cstdlib>//for exit
#include "BankHeader.h"
Bank::Bank (std::string filename){
    //constructor
    ifstream inputFile(filename);
    fillVector(inputFile, accountsVector);
    printVector(accountsVector);
}


void Bank::withdraw() {
    //search for account, if found
    // display details
    // else say account not found
    bool canWithdraw = false;
    string accName = getAccountName();
    int accNumber = getAccountNumber();
    double amount = getAmount();
    int index = binarySearch(accountsVector, accNumber, accName);
    if(index >= 0) {
        bptr = accountsVector[index];
        canWithdraw = bptr->withdraw(amount);
        if(canWithdraw == false) {
            cout << endl << "Insufficient Funds" << endl;
        } else {
            cout << endl << "Amount withdrawn from account" << endl;
        }
    } else {
        cout << endl << "Account not found" << endl;
    }
}

void Bank::viewBalance() {
    //search for account, if found
    // display details
    // else say account not found
    string accName = getAccountName();
    int accNumber = getAccountNumber();
    int index = binarySearch(accountsVector, accNumber, accName);
    if(index >= 0) {
        bptr = accountsVector[index];
        cout << bptr->toString();
    } else {
        cout << endl << "Account not found" << endl;
    }
}


void Bank::deposit() {
    //search for account, if found
    // display details
    // else say account not found
    string accName = getAccountName();
    int accNumber = getAccountNumber();
    double amount = getAmount();
    int index = binarySearch(accountsVector, accNumber, accName);
    if(index >= 0) {
        bptr = accountsVector[index];
        bptr->deposit(amount);
        cout << endl << "Amount deposited into account" << endl;
    } else {
        cout << endl << "Account not found" << endl;
    }
}

//populate the vector of BankAccounts database
void Bank::fillVector(ifstream &input,vector<std::shared_ptr<BankAccount>> &accountsVector){
    try {
        if (input){
            string accountName, lastName, firstName, fullName, str;
            int accountId = 0, accountNumber = 0;
            double accountBalance = 0.0;
                while (!input.eof()) {
                    // reads one line from the file
                    getline(input, str);
                    // initalized with each string that is read from the data file through getline
                    istringstream stream(str);
                    stream >> firstName >> lastName >> accountId >> accountNumber >> accountBalance;
                    // combines the firstName and lastName strings together to make the full name
                    fullName = firstName + " " + lastName;
                    // creates a BankAccount object with the variables read from the file
                    bptr = std::make_shared<BankAccount>(fullName, accountId, accountNumber, accountBalance);
                    // inserts the object into the array
                    accountsVector.push_back(bptr);
                }
            
        } else throw string("File Not Found");
        
    }
    catch (string message){
        cout << message << endl;
        exit(0);
    }
}


void Bank::printVector(vector<std::shared_ptr<BankAccount>> &accountsVector){
  //display all the accounts. This is only done at the beginning for privacy reasons
    for (auto iter = accountsVector.begin(); iter < accountsVector.end(); iter++) {
        cout << (*iter)->toString() << endl;
    }
}

//bubble sort of the vector..given to you.
void Bank::sort(vector<std::shared_ptr<BankAccount>> &accountsVector){
  if (accountsVector.size() > 1) {
      shared_ptr<BankAccount> temp;
      for (int i = 0; i < accountsVector.size()-1; i++) {
          for (int j = 0;j < accountsVector.size()-i-1; j++) {
              if (accountsVector[j]->getAccountNumber() > accountsVector[j+1]->getAccountNumber()) {
                  temp = accountsVector[j];
                  accountsVector[j] = accountsVector[j+1];
                  accountsVector[j+1] = temp;
              }
          }
      }
  }
}
