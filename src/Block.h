#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

#include "Transaction.h"

class Block {
public:
    unsigned int index;
    unsigned int proof;

    std::vector<Transaction> transactions;
    std::string previousHash;
};

#endif
