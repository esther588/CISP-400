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
#include "SavingsAccount.h"
#include <iostream>
//#include "Helper.h"

SavingsAccount::SavingsAccount(){
    setAccountName("");
    setId(0);
    setAccountNumber(0);
    setAccountBalance(0.0);
}
     
SavingsAccount::SavingsAccount(string accountName, int id, int accountNumber, double accountBalance){
    //regular constructor
    setAccountName(accountName);
    setId(id);
    setAccountNumber(accountNumber);
    setAccountBalance(accountBalance);
}

string SavingsAccount::toString(){
    return "Account Name: " + getAccountName() + "\n" + "Account Number: " + std::to_string(getAccountNumber()) + "\n" + "Account Balance: " + fixPoint(std::to_string(getAccountBalance())) + "\n" + "Account Type: Savings \n";
}

bool SavingsAccount::withdraw(double amount) {
    return false;
}

void SavingsAccount::deposit(double amount) {
    // deposit and
    if (amount > 0)
    {
        setAccountBalance(getAccountBalance() + amount);
        //check if eligible for reward
        if(amount > MIN_REWARD_AMOUNT)
        {
            addReward(amount);
        }
    }
}
