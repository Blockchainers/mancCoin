#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

#include "Transaction.h"

class Block {
public:
    int index;
    int proof;

    std::vector<Transaction> transactions;
    std::string previousHash;
    std::string hash;
};

#endif
