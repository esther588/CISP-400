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
#include <vector>
#include <memory>
#include <string>
#include "UserAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;
class Bank {
public:
    class FileException {
    public:
        int value;
        FileException(int v)
        {
            value = v;
        }
        int getValue()
        {
            return value;
        }
};

public:
private:
    //static int dataSize;
    vector<shared_ptr<UserAccount>> accountsVector;
public:
    Bank(string filename);
    Bank(const Bank &other);
    void fillVector(ifstream &input, vector<shared_ptr<UserAccount>> &accountsVector);
    void addAccount(shared_ptr<UserAccount> a);//should sort vector
    bool removeAccount(shared_ptr<UserAccount> a);//vector remove method
    void sortAccounts();//use STL sort using Greater THan Function Object
    void displayAccounts();
    bool accountDeposit(shared_ptr<UserAccount> a, double amount);
    bool accountWithdraw(shared_ptr<UserAccount> a, double amount);
    //bool backupAccounts();
    bool checkSame(Bank &other);

};
