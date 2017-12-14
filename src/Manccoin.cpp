#include <iostream>

#include "Manccoin.h"
#include "ProofOfWork.h"
#include "Blockchain.h"
#include "Transaction.h"
#include "Block.h"

int Manccoin::start() {
    blockchain = new Blockchain();

    // Mine lots of blocks
    for (;;) {
        Block lastBlock = blockchain->chain.back();
        ProofOfWork *proof = new ProofOfWork();

        // Do mining
        int proofResult = proof->proof(lastBlock.proof);

        // Add coinbase

        // Create our new block
        std::string previousBlockHash = blockchain->blockHash(lastBlock);
        std::cout << "Previous block hash: " << previousBlockHash << std::endl;

        Block newBlock = blockchain->newBlock(proofResult, previousBlockHash);

        std::cout << "Mined block " << std::to_string(newBlock.index)
                  << " with proof: " << proofResult
                  << " and hash: " << blockchain->blockHash(newBlock)
                  << std::endl;
    }

    return 0;
}
