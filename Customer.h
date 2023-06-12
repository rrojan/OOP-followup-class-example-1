#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

class Customer {
private:
    std::string name, contactNumber, address, dateOfBirth;

public:
    std::string getName() {
        return name;
    }

    Customer(
        std::string _name,
        std::string _contactNumber,
        std::string _address,
        std::string _dateOfBirth
    ) {
        name = _name;
        contactNumber = _contactNumber;
        address = _address;
        dateOfBirth = _dateOfBirth;
    }
};

#endif
