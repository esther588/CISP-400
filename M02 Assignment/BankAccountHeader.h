/**********************************
* Title : Bank Account
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/18/2021
* Version : Version 1.0
* Description : This is program that creates
* a bank account with a name, an account
* number and an account balance.
* A certain amount of money can be
* withdrawn from or deposited into the account.
***********************************/
#include<iostream>
#include<iomanip>
using std::string;
using std::to_string;
using std::cout;
using std::endl;
class BankAccount {
private:
    
    double MIN_BALANCE = 9.99;
    double REWARDS_AMOUNT = 1000.00;
    double REWARDS_RATE = 0.04;
    string accountName; // First and Last name of Account Holder
    int accountNumber;
    double accountBalance; // current balance amount
    
    // all the method headers for this class
public:
    
    BankAccount();
    BankAccount(string accountName, int accountNumber, double accountBalance);
    double getAccountBalance();
    string getAccountName();
    int getAccountNumber();
    void setAccountBalance(double amount);
    bool withdraw(double amount);
    void deposit(double amount);
    void addReward(double amount);
    string toString();
};
