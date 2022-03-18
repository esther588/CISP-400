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
#include<iostream>
#include<iomanip>
#include <fstream>
#include <sstream>
using std::string;
using std::to_string;
using std::cout;
using std::endl;
class BankAccount {
private:
    
    constexpr static const double MIN_BALANCE = 9.99;
    constexpr static const double REWARDS_AMOUNT = 1000.00;
    constexpr static const double REWARDS_RATE = 0.04;
    string accountName; // First and Last name of Account Holder
    int accountId; // secret social security number
    int accountNumber;
    double accountBalance; // current balance amount
    int getId(); //returns the accountID – this is not a public function, its used only inside the class
    
// all the method headers for this class
public:
    
    BankAccount();
    BankAccount(string accountName, int accountId, int accountNumber, double accountBalance);
    double getAccountBalance();
    string getAccountName();
    BankAccount equals(BankAccount other);
    int getAccountNumber();
    void setAccountBalance(double balance);
    bool withdraw(double amount);
    void deposit(double amount);
    void addReward(double amount);
    string toString();
};
