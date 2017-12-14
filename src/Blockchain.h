#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>

#include "Block.h"

class Blockchain {
public:
    std::vector<Block> chain;
        
    Blockchain();
    ~Blockchain();

    // TODO: Make this a transaction generator method
    int newTransaction(Transaction transaction);
    Block newBlock(unsigned int proof, std::string previousBlockHash);

    // Returns the SHA256(SHA256()) of a block 
    std::string blockHash(Block block);

private:
    std::vector<Transaction> currentTransactions;
};

#endif
