#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
private:
    std::string accountHoldersName;
    float balance;
    int accNumber;
    std::string bankName;
    int pin;

public:
    float getBalance(int _pin) {
        if (_pin == pin) {
            return balance;
        }
        return -1.0;
    }

    void reduceBalance(int amount) {
        balance = balance - amount;
    }

    void addBalance(int amount) {
        balance = balance + amount;
    }

    Account(std::string _name, std::string _bankName) {
        accountHoldersName = _name;
        accNumber = 1234;
        balance = 0.0;
        pin = 123;
    }
};

#endif
