/**********************************
* Title : Final Project
* Author : Esther Cheng
 Student ID : 1754368
* Date : 12/1/2021
* Version : Version 1.0
* Description : This is program
* creates and uses Bank objects.
* A Bank object is a vector containing
* UserAccount objects. UserAccounts
* can be of two types: Checking Account
* and Savings Account. They inherit from
* the UserAccount Class.
***********************************/
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"

void Bank::fillVector(ifstream &input, vector<shared_ptr<UserAccount>> &accountsVector) {
    string accountName, lastName, firstName, inputLine, type, str;
    int id, accountNumber;
    double accountBalance;
    //while not eof getline from file
    while(!input.eof()) {
        // parse the line and create shared pointer to BankAccount
        getline(input, str);
        // initalized with each string that is read from the data file through getline
        istringstream stream(str);
        stream >> firstName >> lastName >> id >> accountNumber >> accountBalance;
        // combines the firstName and lastName strings together to make the full name
        accountName = firstName + " " + lastName;
        // creates a BankAccount object with the variables read from the file
        shared_ptr<UserAccount> tempUser = make_shared<UserAccount>(accountName, id, accountNumber, accountBalance);
        // inserts the object into the vector
        accountsVector.push_back(tempUser);
    }
    //push the pointe onto the accounts vector
    input.close();
  
}

void Bank::displayAccounts() {
    for (int i = 0; i < accountsVector.size(); i++)
    {
        cout << accountsVector[i]->toString() << endl;
    }
}

Bank::Bank(const Bank &other) {
    cout << "In copy constructor" << endl;
    accountsVector.resize(other.accountsVector.size());
  
    cout << accountsVector.size() << endl;
    // create a copy constructor that copies the two vectors
    for (int i = 0; i < accountsVector.size(); i++)
    {
        string name = other.accountsVector[i]->getAccountName();
        int id = other.accountsVector[i]->getId();
        int accountNum = other.accountsVector[i]->getAccountNumber();
        int accountBalance = other.accountsVector[i]->getAccountBalance();
        shared_ptr<UserAccount> tempUser = make_shared<UserAccount>(name, id, accountNum, accountBalance);
        // inserts the object into the array
        accountsVector[i] = tempUser;
    }
 
}


Bank::Bank(string filename) {
    // throw File Open Error - File Exception -99 if file cannot be opened
    // use try catch statement
    try {
        std::ifstream input(filename);
        if (input) {
            fillVector(input, accountsVector);
        } else {
            FileException errorCode(-99);
            throw errorCode.getValue();
        }
    } catch (int exception) {
        cout << exception << endl;
        exit(0);
    }
}

void Bank::addAccount(shared_ptr<UserAccount> a) {
    // should sort vector
    // add an account
    // be sure to keep vector sorted
    // use STL sort using Greater THan Function Object
    sortAccounts();
    bool isEqual = false;
    for (auto iter = accountsVector.begin(); iter < accountsVector.end(); iter++)
    {
        isEqual = (*iter)->equalTo(a);
    }
    if (isEqual == false)
    {
        accountsVector.push_back(a);
    }
    sortAccounts();
}

void Bank::sortAccounts() {
    // use the STL sort by passing the beginning, end and Greater Than Function Object
    GreaterThan obj;
    sort(accountsVector.begin(), accountsVector.end(), obj);
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount) {
    // return false if amount is negative
    if(amount < 0)
    {
        return false;
    }
    // return true after depositing into account
    else {
        double balance = a->getAccountBalance();
        a->setAccountBalance(balance + amount);
        return true;
    }
}

bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount) {
    // if the withdraw amount is suitable then withdraw from account and return true
    // otherwise return false
    return a->withdraw(amount);
}

bool Bank::checkSame(Bank &other) {
    // check if this bank has the exact same accounts as the other bank
    // use equalTo method created in the UserAccount class (that implments Comparable)
    // return true if same, false otherwise
    // equalTo should check if each and every field matches
    bool isEqual = false;
    if (accountsVector.size() == other.accountsVector.size())
    {
        for (int i = 0; i < accountsVector.size(); i++)
        {
            isEqual = accountsVector[i]->equalTo(other.accountsVector[i]);
        }
    }
    return isEqual;
}

bool Bank::removeAccount(shared_ptr<UserAccount> a) {
    // search for the the given account a, if found
    // use vector.erase method to remove it and return true
    // otherwise return false
    bool isEqual = false;
    for (auto iter = accountsVector.begin(); iter < accountsVector.end(); iter++)
    {
        isEqual = (*iter)->equalTo(a);
        if(isEqual == true)
        {
            accountsVector.erase(iter);
            return isEqual;
        }
    }
    return isEqual;
}
