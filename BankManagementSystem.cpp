/*
    PROJECT: BANK MANAGEMENT SYSTEM
    LANGUAGE: C++
    OOP: Encapsulation, Inheritance, Polymorphism, Abstraction
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
protected:
    string accountHolder;

private:
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }

    virtual ~BankAccount() = default;

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Rs. " << fixed << setprecision(2)
                 << amount << " deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0)
            cout << "Invalid withdrawal amount.\n";
        else if (amount > balance)
            cout << "Insufficient balance.\n";
        else {
            balance -= amount;
            cout << "Rs. " << fixed << setprecision(2)
                 << amount << " withdrawn successfully.\n";
        }
    }

    void displayDetails() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Type: " << getAccountType() << endl;
        cout << "Balance: Rs. " << fixed << setprecision(2)
             << balance << endl;
    }

    virtual string getAccountType() const = 0;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string name, double balance)
        : BankAccount(name, balance) {}

    string getAccountType() const override {
        return "Savings Account";
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string name, double balance)
        : BankAccount(name, balance) {}

    string getAccountType() const override {
        return "Current Account";
    }
};

int main() {
    cout << "====================================\n";
    cout << "      BANK MANAGEMENT SYSTEM\n";
    cout << "====================================\n\n";

    SavingsAccount account1("Parnika", 5000);
    CurrentAccount account2("Rahul", 10000);

    cout << "--- SAVINGS ACCOUNT ---\n";
    account1.displayDetails();

    cout << "\nDepositing Rs. 2000...\n";
    account1.deposit(2000);

    cout << "\nWithdrawing Rs. 1000...\n";
    account1.withdraw(1000);

    cout << "\nUpdated Savings Account Details:\n";
    account1.displayDetails();

    cout << "\n--- CURRENT ACCOUNT ---\n";
    account2.displayDetails();

    cout << "\nDepositing Rs. 500...\n";
    account2.deposit(500);

    cout << "\nUpdated Current Account Details:\n";
    account2.displayDetails();

    cout << "\nThank you for using the system!\n";
    return 0;
}
