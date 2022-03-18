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
#include "BankAccountHeader.h"

//default constructor that sets name to “”, account number to 0 and balance to 0
BankAccount::BankAccount() {
    accountName = "";
    accountNumber = 0;
    accountBalance = 0.0;
}

// regular constructor
BankAccount::BankAccount(std::string name, int number, double balance) {
    accountName = name;
    accountNumber = number;
    accountBalance = balance;
}

// returns the balance
double BankAccount::getAccountBalance() {
    return accountBalance;
}

// returns name
std::string BankAccount::getAccountName() {
    return accountName;
}

// returns account number
int BankAccount::getAccountNumber() {
    return accountNumber;
}

// sets the balance
void BankAccount::setAccountBalance(double amount) {
    accountBalance = amount;
}

//deducts from balance and returns true if resulting balance is less than minimum balance
bool BankAccount::withdraw(double amount) {
    bool isLessThanMin = false;
    accountBalance -= amount;
    if(accountBalance < MIN_BALANCE) {
        isLessThanMin = true;
        // reverses back to original balance since withdrawal was not possible
        accountBalance += amount;
        cout << "Insufficient Funds" << endl;
    } else {
        cout << "Remaining Balance: " << getAccountBalance() << endl;
    }
    return isLessThanMin;
}

//adds amount to balance. If amount is greater than rewards amount, calls addReward method
void BankAccount::deposit(double amount) {
    accountBalance += amount;
    if(amount > REWARDS_AMOUNT) {
        addReward(amount);
    }
}

// adds rewards rate * amount to balance
void BankAccount::addReward(double amount) {
    accountBalance += REWARDS_RATE * amount;
}

// return the account information as a string with three lines.
// “Account Name: “ name
// “Account Number:” number
// “Account Balance:” balance
string BankAccount::toString() {
    return "Account Name: " + getAccountName() + "\n" + "Account Number: " + to_string(getAccountNumber()) + "\n" + "Account Balance: " + to_string(getAccountBalance()) + "\n\n";
}
