/**********************************
* Title : Extend Bank Account
* Author : Esther Cheng
 Student ID : 1754368
* Date : 8/18/2021
* Version : Version 1.0
* Description : This is program that reads
* data from a file and fills an array with
* Bank Account objects, then displays all
* elements from the array. Then, it finds and
* displays the largest and smallest accounts
* and also any duplicate accounts.
***********************************/
#include "BankAccountHeader.h"
const int SIZE = 8;
void fillArray(std::ifstream &input, std::vector<shared_ptr<BankAccount>> &accountsVector);
int largest(std::vector<shared_ptr<BankAccount>> &accountsVector);
int smallest(std::vector<shared_ptr<BankAccount>> &accountsVector);
void printArray(std::vector<shared_ptr<BankAccount>> &accountsVector);
void checkDuplicates(std::vector<shared_ptr<BankAccount>> &accountsVector);
bool removeDuplicate(shared_ptr<BankAccount> account1, shared_ptr<BankAccount> account2);
void displayCount(int bankAccCount, int vectorCount);
void insertNewItems(std::vector<shared_ptr<BankAccount>> &accountsVector);
int main() {
    std::vector<shared_ptr<BankAccount>> bankAccVector; // creates an array of BankAccount objects with size SIZE
    try {
        std::ifstream input("/Users/esthercheng/Downloads/BankData.txt");
    if (input) {
      cout << "File Open " << endl;
        fillArray(input, bankAccVector); // fills array from file, details of input and output values and purpose of function
        printArray(bankAccVector); // displays all elements of the accounts array
        int largestIndex = largest(bankAccVector); // finds the index of smallest account in the array
        cout << "Largest Balance:" << endl << bankAccVector[largestIndex]->toString();
        int smallestIndex = smallest(bankAccVector); // finds the index of smallest account in the array
        cout << "Smallest Balance:" << endl << bankAccVector[smallestIndex]->toString();
        displayCount(bankAccVector[0]->getCount(), bankAccVector.size());
        checkDuplicates(bankAccVector); // finds any duplicates in the array
        displayCount(bankAccVector[0]->getCount(), bankAccVector.size()); // displays the count of objects
        insertNewItems(bankAccVector); // inserts the new bank account objects into the vector
        displayCount(bankAccVector[0]->getCount(), bankAccVector.size()); // displays the count of objects
    } else
        throw string("File Open Error");
    } catch (string message){
        cout << message << endl;
        exit(0);
    }
}

// method to fill array from file, details of input and output values and purpose of function
void fillArray(std::ifstream &input, std::vector<shared_ptr<BankAccount>> &accountsVector) {
    string accountName, lastName, firstName, fullName, str;
    int accountId = 0,accountNumber = 0;
    double accountBalance = 0.0;
    while(!input.eof()) {
        // reads one line from the file
        getline(input, str);
        // initalized with each string that is read from the data file through getline
        std::istringstream stream(str);
        stream >> firstName >> lastName >> accountId >> accountNumber >> accountBalance;
        // combines the firstName and lastName strings together to make the full name
        fullName = firstName + " " + lastName;
        // creates a BankAccount object with the variables read from the file
        std::shared_ptr<BankAccount> bankAcc = std::make_shared<BankAccount>(fullName, accountId, accountNumber, accountBalance);
        // inserts the object into the array
        accountsVector.push_back(bankAcc);
    }
    input.close();
}

// method to find the largest account using balance as key
int largest(std::vector<shared_ptr<BankAccount>> &accountsVector) {
    double tempVal = accountsVector[0]->getAccountBalance();
    int largestIndex = 0, index = 0;
    for (auto iter = accountsVector.begin(); iter < accountsVector.end(); iter++) {
        if(tempVal < (*iter)->getAccountBalance()) {
            tempVal = (*iter)->getAccountBalance();
            largestIndex = index;
        }
        index++;
    }
    return largestIndex;
}

// method to find the smallest account using balance as key
int smallest(std::vector<shared_ptr<BankAccount>> &accountsVector) {
    double tempVal = accountsVector[0]->getAccountBalance();
    int smallestIndex = 0, index = 0;
    for (auto iter = accountsVector.begin(); iter < accountsVector.end(); iter++) {
        if(tempVal > (*iter)->getAccountBalance()) {
            tempVal = (*iter)->getAccountBalance();
            smallestIndex = index;
        }
        index++;
    }
    return smallestIndex;
}

// method to display all elements of the accounts array
void printArray(std::vector<shared_ptr<BankAccount>> &accountsVector) {
    cout << "FAVORITE BANK - CUSTOMER DETAILS" << endl;
    cout << "--------------------------------" << endl;
    for (auto iter = accountsVector.begin(); iter < accountsVector.end(); iter++) {
        cout << (*iter)->toString();
    }
}

// finds any duplicate accounts from the given array
void checkDuplicates(std::vector<shared_ptr<BankAccount>> &accountsVector) {
    bool isDuplicate = false;
    for(int i = 0; i < accountsVector.size(); i++) {
        for(int j = i + 1; j < accountsVector.size(); j++) {
            // calls the equals method and returns a BankAccount object
            shared_ptr<BankAccount> bankAcc0 = accountsVector[i];
            shared_ptr<BankAccount> bankAcc1 = accountsVector[j];
            bool canRemove = removeDuplicate(bankAcc0, bankAcc1);
            // check if the object returned is a dummy object
            if(canRemove) {
                // switches the duplicate account with the dummy account
                accountsVector.erase(accountsVector.begin()+j);
                // flag to keep track if a duplicate acccount has been found
                isDuplicate = true;
                break;
            }
        }
    }
    // if there's been any duplicate account found
    if(isDuplicate) {
        cout << "Duplicate Accounts Found : Reprinting List" << endl << endl;
        printArray(accountsVector);
    }
}

// checks if the two accounts are duplicates and can be removed
bool removeDuplicate(shared_ptr<BankAccount> account1, shared_ptr<BankAccount> account2) {
    bool canRemove = account1->equals(*account2);
    return canRemove;
}
// method to display the count of objects using static count variable and vector size method
void displayCount(int bankAccCount, int vectorCount) {
    cout << "Using the static count, there are " << bankAccCount << " accounts" << endl;
    cout << "Using vector size, there are " << vectorCount << " accounts" << endl << endl;
}

// method to insert new bank account objects into vector at certain positions
void insertNewItems(std::vector<shared_ptr<BankAccount>> &accountsVector) {
    std::shared_ptr<BankAccount> amyBankAcc = std::make_shared<BankAccount>("Amy Machado", 387623, 1244, 1023.67);
    std::shared_ptr<BankAccount> takBankAcc = std::make_shared<BankAccount>("Tak Phen", 981243, 1262, 6423.03);
    std::shared_ptr<BankAccount> celiaBankAcc = std::make_shared<BankAccount>("Celia Beatle", 465281, 1276, 3.56);
    auto iter1 = accountsVector.insert(accountsVector.begin() + 2, amyBankAcc);
    auto iter2 = accountsVector.insert(accountsVector.begin() + 4, takBankAcc);
    auto iter3 = accountsVector.insert(accountsVector.begin() + 6, celiaBankAcc);
    cout << "Inserted Three New Accounts: Reprinting List" << endl;
    printArray(accountsVector);
}
