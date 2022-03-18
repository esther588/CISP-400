/**********************************
* Title : Extend Bank Account 3
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/21/2021
* Version : Version 1.0
* Description : This is program that reads
* data from a file and fills a vector with
* Bank Account objects, then displays all
* elements from the array. Then, it finds and
* displays the largest and smallest accounts
* and also any duplicate accounts. If there
* are duplicates, erase them from the vector.
* Then insert three new bank account objects.
***********************************/
#include "BankAccountHeader.h"
int BankAccount::count = 0;
//default constructor that sets name to “”, account number to 0 and balance to 0
BankAccount::BankAccount() {
    accountName = "";
    accountNumber = 0;
    accountBalance = 0.0;
    count++;
}

// regular constructor
BankAccount::BankAccount(std::string name, int id, int number, double balance) {
    accountName = name;
    accountId = id;
    accountNumber = number;
    accountBalance = balance;
    count++;
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

// returns true if this equals other. False otherwise
bool BankAccount::equals(BankAccount other) {
    bool isEqual = false;
    // checks if the "this" account object's name and number are the same as that of the other account
    if(accountName.compare(other.accountName) == 0 && accountNumber == other.accountNumber) {
        // instantiates to true
        isEqual = true;
    }
    // returns the boolean variable
    return isEqual;
}

int BankAccount::getCount() {
    return count;
}

// returns the id
int BankAccount::getId() {
    return accountId;
}

// sets the balance
void BankAccount::setAccountBalance(double balance) {
    accountBalance = balance;
}

//deducts from balance and returns true if resulting balance is less than minimum balance
bool BankAccount::withdraw(double amount) {
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

//adds amount to balance. If amount is greater than rewards amount, calls
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
    return "Account Name: " + getAccountName() + "\n" + "Account Number: " + to_string(getAccountNumber()) + "\n" + "Account Balance: " + std::to_string(getAccountBalance()).substr(0, std::to_string(getAccountBalance()).find(".") + 3) + "\n\n";
}
