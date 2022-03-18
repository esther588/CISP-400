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
class BankAccount {
private:
    const static  double  MIN_BALANCE;
    const static double REWARD_RATE;
    const static double MIN_REWARD_AMOUNT;
    public: static int count;
private:
    int accountNumber,id;
    std::string accountName;
    double accountBalance;

public:
    BankAccount();
    BankAccount(std::string accountName, int id,int accountNumber, double accountBalance);
    //getters
public:
    std::string getAccountName();
    int getAccountNumber();
    double getAccountBalance();
    // setters : cannot change number and accountName
    //setting balance may be needed by admin
    
    void setAccountBalance(double accountBalance);
    std::string toString();
    bool withdraw(double amount);
    int getCount();
    void deposit(double amount);
    bool equals(BankAccount other);
    private: void addReward(double amount);
    private: int getId();
    
};
