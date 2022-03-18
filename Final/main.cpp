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
#include <iostream>
#include "Bank.h"
int main() {
  
    shared_ptr<UserAccount> newAcc = make_shared<CheckingAccount>("John Smith", 9999, 1120, 154.67);
    shared_ptr<UserAccount> temp = make_shared<SavingsAccount>("Lily Zhaou", 786534, 1242, 001.98);
    //temp->withdraw(100);

    shared_ptr<UserAccount> temp2 = make_shared<CheckingAccount>("Vai vu", 432657, 1240, 987.56);
    string filename;
    int action;
    cout << "What is the file name?" << endl;
    cin >> filename;
    Bank WellsFargo(filename); // test action 1 : incorrect file name
    WellsFargo.sortAccounts();
    WellsFargo.displayAccounts();
    for (int i = 0; i < 9; i++)
    {
        cout << "Which action would you like to test? ";
        cin >> action;
        Bank WellsFargo(filename);
        WellsFargo.sortAccounts();
        WellsFargo.displayAccounts();
        if (action == 2)
        {
            // add a new account
            WellsFargo.addAccount(newAcc);
            cout << "Adding New Account" << endl;
            WellsFargo.displayAccounts();
        }
        else if (action == 4)
        {
            // backing up accounts
            Bank Backup(WellsFargo);
            if (Backup.checkSame(WellsFargo))
            {
                cout << "Verified Backup" << endl; // verifying that they are same;
            }
            else
            {
                cout << "Backup Error " << endl;
            }
        }
        else if (action == 3)
        {
            //remove and display
            cout << "Removing Account" << endl;
            WellsFargo.removeAccount(temp);
            WellsFargo.displayAccounts();
        }
        else if (action == 5)
        {
            // back up and remove account from original
            Bank Backup(WellsFargo);
  
            WellsFargo.removeAccount(temp);
            WellsFargo.displayAccounts();
            if (Backup.checkSame(WellsFargo))
            {
                cout << "Verified Backup" << endl; // verifying that they are same;
            }
            else
            {
                cout << "Backup Error Databases do not match" << endl;
            }
        }
        else if (action == 6)
        { // withdraw money from CheckingAccount
     
            WellsFargo.addAccount(newAcc);
            cout << " Adding New Account " << endl;
            if(WellsFargo.accountWithdraw(newAcc, 20))
            {
                cout << "Withdraw Successful for this amount 20$" << endl;
            }
            else
            {
                cout << "Withdraw Unsuccessful for this amount 20$" << endl;
            }
        }
        else if (action == 7)
        {
            WellsFargo.addAccount(newAcc);
            cout << " Adding New Account " << endl;
            if(WellsFargo.accountWithdraw(newAcc, 100))
            {
                cout << "Withdraw Successful for this amount -20$" << endl;
            }
            else
            {
                cout << "Withdraw Unsuccessful for this amount - Minimum funds 99.99" << endl;
            }
            if(WellsFargo.accountWithdraw(newAcc, 5000))
            {
                cout << "Withdraw Successful for this amount 5000$" << endl;
            }
            else
            {
                cout << "Withdraw Unsuccessful - Insufficient funds for this amount 5000$" << endl;
            }
            WellsFargo.displayAccounts();
            //cout<<"After Withdrawing Backup"<<endl;
            //Backup.displayAccounts();
        }
        else if (action == 8)
        { //withdraw money from savings account
            if(WellsFargo.accountWithdraw(temp,20))
            {
                cout << "Withdraw Successful" << endl;
            }
            else
            {
                cout << "Withdraw Unsuccessful" << endl;
            }
        }
        else if (action == 9)
        { //deposit money into savings
            if(WellsFargo.accountDeposit(temp, 1400))
            {
                cout <<"Deposit Successful rewards added" << endl;
            }
            WellsFargo.displayAccounts();
            if(WellsFargo.accountDeposit(temp, 20))
            {
                cout << "Deposit Successful rewards added" << endl;
            }
            WellsFargo.displayAccounts();
        }
        else if (action == 10)
        { //deposit money into checking
            if(WellsFargo.accountDeposit(temp, -20))
            {
                cout << "Deposit Successful" << endl;
            }
            else
            {
                cout << "Deposit Unsuccessful - Negative Amount" << endl;
            }
            if(WellsFargo.accountDeposit(temp, 20))
            {
                cout << "Deposit Successful" << endl;
            }
            else
            {
                cout << "Deposit Unsuccessful" << endl;
            }
        }
        else
        {
            cout << "Testing Ends" << endl;
        }
    }
}
