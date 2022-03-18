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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cstdlib>//for exit
#include "BankAccountHeader.h"
using namespace std;
class Bank {
private:
  shared_ptr<BankAccount> bptr;
  vector<shared_ptr<BankAccount>> accountsVector;
public:
    Bank(std::string filename);//constructor that reads bank database from file
    string getAccountName() {
        string firstName, lastName;
        std::cout << "What is the Account First Name ? ";
        cin >> firstName;
        std::cout << "What is the Account Last Name ? ";
        cin >> lastName;
        return firstName + " " + lastName;
    }
    
    int getAccountNumber() {
        int number;
        std::cout << "What is the account Number ?";
        cin >> number;
        return number;
    }
    
    double getAmount() {
        double number;
        std::cout << "What is the dollar amount ?";
        cin>>number;
        return number;
    }
    //binary search
    int binarySearch(vector<shared_ptr<BankAccount>> &accountsVector, int accountNumber, string accountName){
        int first, middle, last;
        first = 0; last = accountsVector.size();
        middle = (first + last) / 2;
        while (first <= last) {
            if (accountsVector[middle]->getAccountName() == accountName &&   accountsVector[middle]->getAccountNumber() == accountNumber) {
                return middle;
            } else{
                if (accountsVector[middle]->getAccountNumber()<accountNumber) {
                    first = middle+1;
                } else {
                    last = middle - 1;
                }
           }
            middle = (first + last) / 2;
        }
        return -1;
}
    void withdraw();
    void viewBalance();
    void deposit();
    void fillVector (ifstream &input,vector<shared_ptr<BankAccount>> &accountsVector);
    void printVector(vector<shared_ptr<BankAccount>> &accountsVector);
    void sort(vector<shared_ptr<BankAccount>> &accountsVector);


};
