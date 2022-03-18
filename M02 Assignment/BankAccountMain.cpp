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
void display(string information);
int main() {
    BankAccount accountZero;
    BankAccount accountOne("Matilda Patel", 1232, -4.00);
    BankAccount accountTwo("Fernando Diaz", 1234, 250.0);
    BankAccount accountThree("Howard Chen", 1236, 194.56);
    display(accountOne.toString()); // displays all accountOne's information (account name, number & balance)
    display(accountTwo.toString()); // displays all accountTwo's information (account name, number & balance)
    display(accountThree.toString()); // displays all accountThree's information (account name, number & balance)
    accountTwo.deposit(999); // adds 999 to accountTwo's account balance
    accountThree.deposit(1000.25); // adds 1000.25 to accountThree's account balance
    display(accountTwo.toString()); // displays all accountTwo's information (account name, number & balance)
    display(accountThree.toString()); // displays all accountThree's information (account name, number & balance)
    accountOne.withdraw(10000); // subtracts 10000 from accountOne's account balance
    accountTwo.withdraw(90); // subtracts 90 from accountTwo's account balance
    double total = accountZero.getAccountBalance() + accountOne.getAccountBalance() + accountTwo.getAccountBalance() + accountThree.getAccountBalance(); // adds all of the account balances together to get the total
    string totalStr = "Total Amounts: " + to_string(total) + "\n";
    display(totalStr); // displays the string passed in
    return 0;
}

// displays the given string to the console
void display(string information) {
    cout << information;
}
