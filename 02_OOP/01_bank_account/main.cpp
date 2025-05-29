#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    BankAccount(string holder, string number, double initialBalance) {
        accountHolder = holder;
        accountNumber = number;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " BDT\n";
        } else {
            cout << "Invalid deposit amount\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " BDT\n";
        } else {
            cout << "Invalid or insufficient funds\n";
        }
    }

    void display() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << " BDT" << endl;
    }
};

int main() {
    BankAccount acc("Md. Rahim", "EBL123456789", 5000.0);

    acc.display();
    acc.deposit(1500.0);
    acc.withdraw(2000.0);
    acc.withdraw(6000.0);
    acc.display();

    return 0;
}
