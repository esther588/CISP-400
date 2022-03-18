/**********************************
* Title : Midterm
* Author : Esther Cheng
 Student ID : 1754368
* Date : 9/17/2021
* Version : Version 1.0
* Description : The client program will be a
* menu driven application to service viewing
* an account, depositing and withdrawing
* from an account (funds permitting).
***********************************/
#include <string>
#include <iostream>
#include "BankAccountHeader.h"

BankAccount::BankAccount(){
    this->id = 0;
    this->accountBalance = 0;
    this->accountBalance = 0;
    this->accountName = "";
    count++;
}

BankAccount::BankAccount(std::string accountName, int id, int accountNumber, double accountBalance) {        this->id = id;
    this->accountNumber = accountNumber;
    this->accountName = accountName;
    this->accountBalance = accountBalance;
    count++;
}

//getters

std::string BankAccount::getAccountName() {
    return accountName;
}

int BankAccount::getAccountNumber() {
    return accountNumber;
}

double BankAccount::getAccountBalance() {
    return accountBalance;
}

// setters : cannot change number and accountName
//setting balance may be needed by admin

void BankAccount::setAccountBalance(double accountBalance) {
    this->accountBalance=accountBalance;
}

//helper method
std::string fixPoint(std::string number) {
    int i = number.find('.');
    return number.substr(0,i+3);
}

std::string BankAccount::toString(){
    return "Account Name: "+accountName+"\n"+ "Account Number: "+std::to_string(accountNumber)+"\n"+ "Account Balance: " +fixPoint(std::to_string(accountBalance))+"\n";
}

bool BankAccount::withdraw(double amount) {
    if (accountBalance-amount>MIN_BALANCE){
        accountBalance-=amount;
        return true;
    } else {
        return false; // do nothing
    }
}

void BankAccount::deposit(double amount) {
    accountBalance+= amount;
    if (amount > MIN_REWARD_AMOUNT) {
        addReward(amount);
    }
}

int getCount() {
    return BankAccount::count;
}
     
void BankAccount::addReward(double amount) {
    accountBalance +=accountBalance+REWARD_RATE*amount;
}

int BankAccount::getId(){
    return id;
}

bool BankAccount::equals(BankAccount other){
    if (accountName==other.accountName &&id==other.id) {
        return true;
    } else {
          return false;
    }
}

const double BankAccount::MIN_BALANCE = 9.99;
const double BankAccount::MIN_REWARD_AMOUNT = 1000.0;
const double BankAccount::REWARD_RATE = 0.04;
int  BankAccount::count = 0;
