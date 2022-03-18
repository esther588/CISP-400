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
#pragma once
#include "UserAccount.h"
//#include "Helper.h"
#include <cstdlib>
#include <memory>
#include <vector>
#include <iostream>

UserAccount::UserAccount() {
    this->id = 0;
    this->accountBalance = 0;
    this->accountBalance = 0;
    this->accountName = "";
}

UserAccount::UserAccount(string accountName, int id, int accountNumber, double accountBalance) {
    // regular constructor
    this->accountName = accountName;
    this->id = id;
    this->accountNumber = accountNumber;
    this->accountBalance = accountBalance;
}

//getters

string UserAccount::getAccountName() {
    return accountName;
}

int UserAccount::getId() {
    return id;
}

int UserAccount::getAccountNumber() {
    return accountNumber;
}

double UserAccount::getAccountBalance() {
    return accountBalance;
}

void UserAccount::setAccountName(string name) {
    accountName = name;
}

void UserAccount::setId(int accountId) {
    id = accountId;
}

void UserAccount::setAccountNumber(int number) {
    accountNumber = number;
}

void UserAccount::setAccountBalance(double balance){
    accountBalance = balance;
}

//helper method
std::string UserAccount::fixPoint(std::string number){
    int i = number.find('.');
    return number.substr(0,i + 3);
}

// compare all fields of this user account with a
bool UserAccount::equalTo(shared_ptr<UserAccount> a){
    bool isEqual = false;
    // checks if the "this" account object's name and number are the same as that of the other account
    if(accountName.compare(a->accountName) == 0 && accountNumber == a->accountNumber) {
        // instantiates to true
        isEqual = true;
    }
    // returns the boolean variable
    return isEqual;
}
      
std::string UserAccount::toString(){
    //std::cout<<fixPoint(std::to_string(accountBalance));
    return "Account Name: " + accountName + "\n" + "Account Number: " + std::to_string(accountNumber) + "\n" + "Account Balance: " + fixPoint(std::to_string(accountBalance)) + "\n";
                
}

bool UserAccount::withdraw(double amount) {
    bool isLessThanMin = false;
    accountBalance -= amount;
    if(accountBalance < MIN_BALANCE) {
        isLessThanMin = true;
        accountBalance += amount;
        cout << "Insufficient Funds" << endl;
    } else {
        cout << "Remaining Balance: " << getAccountBalance() << endl;
    }
    return isLessThanMin;
}

void UserAccount::deposit(double amount) {
    // deposit
    accountBalance += amount;
}

void  UserAccount::addReward(double amount) {
    accountBalance += accountBalance + REWARD_RATE * amount;
}
     
const double UserAccount::MIN_BALANCE = 9.99;
const double UserAccount::MIN_REWARD_AMOUNT = 1000.0;
const double UserAccount::REWARD_RATE = 0.04;
