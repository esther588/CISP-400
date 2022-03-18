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
#include "CheckingAccount.h"
//#include "Helper.h"
#include<iostream>

CheckingAccount::CheckingAccount() {
    setAccountName("");
    setId(0);
    setAccountNumber(0);
    setAccountBalance(0.0);
}

CheckingAccount::CheckingAccount(string accountName, int id, int accountNumber, double accountBalance) {
    setAccountName(accountName);
    setId(id);
    setAccountNumber(accountNumber);
    setAccountBalance(accountBalance);
};

string CheckingAccount::toString(){
    return  "Account Name: " + getAccountName() + "\n" + "Account Number: " + std::to_string(getAccountNumber()) + "\n" + "Account Balance: " + fixPoint(std::to_string(getAccountBalance())) + "\n" + "Account Type: Checking \n";
}

bool CheckingAccount::withdraw(double amount) {
    bool canWithdraw = false;
    double accountBalance = getAccountBalance();
    accountBalance -= amount;
    if (accountBalance >= MIN_BALANCE_CHECKING)
    {
        setAccountBalance(accountBalance);
        canWithdraw = true;
    }
    else
    {
        accountBalance += amount;
    }
    return canWithdraw;
}
 
void CheckingAccount::deposit(double amount) {
    if (amount > 0)
    {
        double accountBalance = getAccountBalance();
        accountBalance += amount;
        setAccountBalance(accountBalance);
    }
}

const double CheckingAccount::MIN_BALANCE_CHECKING = 99.99;
