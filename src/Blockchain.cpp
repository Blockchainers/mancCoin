#include "Blockchain.h"

Blockchain::Blockchain() : chain(), currentTransactions() { 
    Block genisis = Block();

    genisis.index = 0;
    genisis.proof = 0;
    genisis.previousHash = "";

    chain.push_back(genisis);
}

int Blockchain::newTransaction(Transaction transaction) {
    currentTransactions.push_back(transaction);
    
    if (chain.empty()) {
        return 0;
    }
    
    Block lastBlock = chain.back();
    
    return lastBlock.index + 1;
}
