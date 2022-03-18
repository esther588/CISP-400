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
#include <cstdlib>
#include "BankHeader.h"

char printMenu(Bank myBank){
    char menuOp;
    string toFind;
    int number;
   
    std::cout <<endl<< "MENU" << endl;
    std::cout << "v - View Account Balance" << endl;
    std::cout << "w - Withdraw from Account" << endl;
    std::cout << "d - Deposit into Account" << endl;
    std::cout << "a - Add an Account" << endl;
    std::cout << "r - Remove an Account" << endl;
   
    std::cout << "q - Quit" << endl << endl;
   
    menuOp = ' ';
   
    while (menuOp != 'd' && menuOp != 'a' && menuOp != 'v' && menuOp != 'r' && menuOp != 'w'&& menuOp != 'q') {
        std::cout << "Choose an option: ";
        string s;
        getline(cin,s,'\n');
        cin.clear();
        menuOp = s[0];
        menuOp = tolower(menuOp);
    }
   
    if (menuOp == 'r') {
        std::cout << "Remove Account: Coming Soon" << endl;
        menuOp = ' ';
        cin.clear();
    } else if (menuOp == 'd') {
        myBank.deposit();
        menuOp = ' ';
        cin.ignore(9999,'\n');
    } else if (menuOp == 'v') {
        myBank.viewBalance();
        menuOp = ' ';
        cin.ignore(9999,'\n');
   } else if (menuOp == 'w') {
       //withdraw if funds are sufficient
       myBank.withdraw();
       menuOp = ' ';
       cin.ignore(9999,'\n');
   } else if (menuOp == ' ') {
       menuOp = ' ';
       cin.ignore(9999,'\n');
   } else if (menuOp == 'a') {
       std::cout << "Add Account: Coming Soon" << endl;
       menuOp = ' ';
       cin.clear();
   } else if (menuOp =='q'){
       std::cout << "Good Bye!" << endl;
   }
    return menuOp;
}

int main() {
    Bank myBank("/Users/esthercheng/Downloads/BankData.txt");
    char option  = printMenu(myBank);
    while (option != 'q') {
        option = printMenu(myBank);
    }
}
