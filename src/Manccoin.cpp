#include "Manccoin.h"
#include "ProofOfWork.h"
#include "Blockchain.h"
#include "Transaction.h"
#include <iostream>
int Manccoin::start() {
    blockchain = new Blockchain();
    Block lastBlock = blockchain->chain.back();
    ProofOfWork *proof = new ProofOfWork();
    std::cout << "Finished " << proof->proof(lastBlock.hash, lastBlock.transactions);
    return 0;
}
