#include <iostream>
#include <string>
using namespace std;

class BankAccount {
//access specifier
private:
    string accountNum;
    string accountHolder;
    double balance;

//access specifier
public:
//parameterized constructor
    BankAccount(string accNum, string accHolder, double bal) {
        accountNum = accNum;
        accountHolder = accHolder;
        balance = bal;
    }

//display account details
    void showAccountDetails() {
        cout << "Account Number is: " << accountNum<< endl;
        cout << "Account Holder is: " << accountHolder<< endl;
        cout << "Balance: " << balance << endl;
    }
};