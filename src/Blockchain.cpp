#include "Blockchain.h"

#include "vendor/picosha2.h"

Blockchain::Blockchain() : chain(), currentTransactions() { 
    Block genesis = Block();

    genesis.index = 0;
    genesis.proof = 0;
    genesis.previousHash = "0";

    chain.push_back(genesis);
}

int Blockchain::newTransaction(Transaction transaction) {
    currentTransactions.push_back(transaction);
    
    if (chain.empty()) {
        return 0;
    }
    
    Block lastBlock = chain.back();
    
    return lastBlock.index + 1;
}

Block Blockchain::newBlock(unsigned int proof, std::string previousBlockHash) {
    Block block = Block();
    block.index = chain.back().index + 1;
    block.previousHash = previousBlockHash;
    block.proof = proof;

    chain.push_back(block);
    return block;
}

std::string Blockchain::blockHash(Block block) {
    std::vector<unsigned char> hash(32);
    std::string hashableString("");

    hashableString += block.previousHash;
    hashableString += std::to_string(block.index);
    hashableString += std::to_string(block.proof);
    
    for (std::vector<Transaction>::iterator i = block.transactions.begin(); i != block.transactions.end(); i++) {
        Transaction t = *i;
        hashableString += std::to_string(t.amount);
        hashableString += t.recipient;
        hashableString += t.sender;
    }

    picosha2::hash256(hashableString.begin(), hashableString.end(), hash.begin(), hash.end());
    picosha2::hash256(hash.begin(), hash.end(), hash.begin(), hash.end());

    return picosha2::hash256_hex_string(hash.begin(), hash.end());
}
