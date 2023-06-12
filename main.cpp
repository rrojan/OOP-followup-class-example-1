#include <iostream>
#include "Bank.h"
#include "Customer.h"

using namespace std;

int main() {
    // Create a bank
    Bank globalImeBank("Global IME Bank", "Gwarko");

    // Create bank customers
    Customer sumit("Sumit Pandey", "9841-456-333", "Bafal", "2057-05-05");
    Customer ronij("Ronij Joshi", "9833-456-333", "Old Thimi", "2057-05-06");

    // Create an account for Sumit
    Account sumitsAccount = globalImeBank.openAccount(sumit.getName());
    Account ronijAccount = globalImeBank.openAccount(ronij.getName());

    // Check balance
    int amount, pin;

    // Add balance to Sumit's account
    cout << "Enter the amount to load to Sumit's bank: ";
    cin >> amount;
    sumitsAccount.addBalance(amount);

    // Check balance
    cout << "Enter your pin, Mr. Sumit: ";
    cin >> pin;
    cout << sumitsAccount.getBalance(pin) << endl;

    // Transfer 500 to Ronij
    cout << "Enter the amount to send to Ronij: ";
    cin >> amount;
    sumitsAccount.reduceBalance(amount);
    ronijAccount.addBalance(amount);

    // Check Ronij's balance
    cout << "Enter your pin, Mr. Ronij: ";
    cin >> pin;
    cout << ronijAccount.getBalance(pin) << endl;

    // Check new balance for Sumit
    cout << "Enter your pin, Mr. Sumit: ";
    cin >> pin;
    cout << sumitsAccount.getBalance(pin) << endl;
}
