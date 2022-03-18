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
#include "UserAccount.h"

class GreaterThan {
public:
    bool operator()(shared_ptr<UserAccount> a, shared_ptr<UserAccount>b);
};
