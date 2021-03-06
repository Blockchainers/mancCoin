#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include <string>

#include "Block.h"

class Blockchain {
public:
    std::vector<Block> chain;
    std::vector<Transaction> currentTransactions;

    Blockchain();

    /// Returns index of block this transaction will be mined into
    int pushTransaction(Transaction transaction);

    /// Adds a new block to the chain and returns it
    Block newBlock(unsigned int proof, std::string previousBlockHash);

    /// Returns the SHA256(SHA256()) of a block 
    std::string blockHash(Block block);

    MSGPACK_DEFINE_ARRAY(chain, currentTransactions);
};

#endif
