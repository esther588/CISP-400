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
//#include "UserAccount.h"
//#include "Helper.h"
#include <string>
#include <vector>
#include <fstream>
#include <memory>
using namespace std;

class UserAccount {
public:
    const static double MIN_BALANCE;
    const static double REWARD_RATE;
    const static double MIN_REWARD_AMOUNT;
    
private:
    int accountNumber, id;
    string accountName;
    double accountBalance;

public:
    UserAccount();
    UserAccount(string accountName, int id, int accountNumber, double accountBalance);
      
//getters
public:
    string getAccountName();
    int getId();
    int getAccountNumber();
    double getAccountBalance();
    void setAccountName(string name);
    void setId(int accountId);
    void setAccountNumber(int number);
    void setAccountBalance(double balance);
    
    //bool operator == (<shared_ptr<UserAccount> a, shared_ptr<UserAccount> b);
    //bool equals(shared_ptr<UserAccount> a);
    virtual std::string toString();
    virtual bool withdraw(double amount);
      
    string fixPoint(std::string number);
    //virtual
    void calculateBalance();
    virtual void deposit(double amount);
    bool equalTo(shared_ptr<UserAccount> a);
    void addReward(double amount);
};
