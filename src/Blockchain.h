#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
public:
    std::vector<Block> chain;
        
    Blockchain();
    ~Blockchain();

    int newTransaction(Transaction transaction);
private:
    std::vector<Transaction> currentTransactions;
};

#endif
