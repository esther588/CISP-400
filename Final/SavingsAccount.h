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

class SavingsAccount: public UserAccount {
    //const static  double  MIN_BALANCE;
public:
    SavingsAccount();
    SavingsAccount(string accountName, int id, int accountNumber, double accountBalance);
    virtual string toString();
    virtual bool withdraw(double amount);
    virtual void deposit(double amount);
    //virtual bool operator == (shared_ptr<SavingsAccount> a);
};
