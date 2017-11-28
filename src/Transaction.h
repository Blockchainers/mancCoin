#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
#include <string>

class Transaction {
    public:
        std::string sender;
        std::string recipient;
        double amount;
};

#endif