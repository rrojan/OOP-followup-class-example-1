#include <iostream>
#include "Bank.h"
#include "Customer.h"

using namespace std;

// In this file I have refactored to use functions to load balance, transfer balance, etc
// The "Account&" <- "&" refers to pass by reference instead of pass by value

// In a nutshell, you need to use "ClassName&" instead of "ClassName" for params
// whenever a function takes in an object and modifies the object in some way

// Function to load balance to an account
void loadBalance(Account& account) {
    int amount;
    cout << "Enter the amount to load: ";
    cin >> amount;
    account.addBalance(amount);
}

// Function to transfer balance between accounts
void transferBalance(Account& sourceAccount, int sourceAccPin, Account& destinationAccount) {
    int amount;
    cout << "Enter the amount to transfer: ";
    cin >> amount;

    if (sourceAccount.getBalance(sourceAccPin) < amount) {
        cout << "Insufficient balance in the source account." << endl;
        return;
    }

    sourceAccount.reduceBalance(amount);
    destinationAccount.addBalance(amount);
}

// Function to check account balance
void checkBalance(Account& account) {
    int pin;
    cout << "Enter your pin: ";
    cin >> pin;

    float balance = account.getBalance(pin);
    if (balance == -1.0) {
        cout << "Invalid pin. Access denied." << endl;
    } else {
        cout << "Current balance: " << balance << endl;
    }
}

int main() {
    // Create a bank
    Bank globalImeBank("Global IME Bank", "Gwarko");

    // Create bank customers
    Customer sumit("Sumit Pandey", "9841-456-333", "Bafal", "2057-05-05");
    Customer ronij("Ronij Joshi", "9833-456-333", "Old Thimi", "2057-05-06");

    // Create an account for Sumit
    Account sumitsAccount = globalImeBank.openAccount(sumit.getName());
    Account ronijAccount = globalImeBank.openAccount(ronij.getName());

    // Load balance to Sumit's account
    loadBalance(sumitsAccount);

    // Check Sumit's balance
    checkBalance(sumitsAccount);

    // Transfer balance from Sumit to Ronij
    transferBalance(sumitsAccount, 123, ronijAccount);

    // Check Ronij's balance
    checkBalance(ronijAccount);

    // Check new balance for Sumit
    checkBalance(sumitsAccount);

    return 0;
}
