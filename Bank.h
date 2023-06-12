#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include "Account.h"

class Bank {
private:
    std::string name, branch;

public:
    Bank(std::string _name, std::string _branch) {
        name = _name;
        branch = _branch;
    }

    Account openAccount(std::string accHoldersName) {
        Account newAccount(accHoldersName, name);
        return newAccount;
    }
};

#endif
