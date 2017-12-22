#include <iostream>

#include "Manccoin.h"
#include "ProofOfWork.h"
#include "Transaction.h"
#include "Block.h"
#include "rpc/rpc.h"

#include "rpc/client.h"

rpc::client client("localhost", network::serverPort);

int Manccoin::start() {
    static const std::string MyAddress = "TheAddressOfThisNode";
    blockchain = Blockchain();

    network::start();
    bindRPC();

    // Mine lots of blocks
    for (;;) {
        Block lastBlock = blockchain.chain.back();
        ProofOfWork *proof = new ProofOfWork();

        // Do mining
        int proofResult = proof->proof(lastBlock.proof);
        delete proof;

        // Add coinbase
        Transaction coinbase = Transaction();
        coinbase.sender = "0";
        coinbase.recipient = MyAddress;
        coinbase.amount = 1; // Send the miner 1manc

        blockchain.pushTransaction(coinbase);

        // Create our new block
        std::string previousBlockHash = blockchain.blockHash(lastBlock);
        std::cout << "Previous block hash: " << previousBlockHash << std::endl;

        Block newBlock = blockchain.newBlock(proofResult, previousBlockHash);

        std::cout << "Mined block " << std::to_string(newBlock.index)
                  << " with proof: " << proofResult
                  << " and hash: " << blockchain.blockHash(newBlock)
                  << std::endl;
    }

    return 0;
}

void Manccoin::bindRPC() {
    // Push a transaction into the currentTransactions of the blockchain
    network::srv.bind(rpcinterface::pushTransaction, [=](Transaction t) {
        blockchain.pushTransaction(t);
    });

    // Return highest block index
    network::srv.bind(rpcinterface::highestBlock, [=]() {
        Block b = blockchain.chain.back();
        return b.index;
    });

    // Return block object at index
    network::srv.bind(rpcinterface::blockAtIndex, [=](int index) -> Block {
        return blockchain.chain.at(index);
    });

    // Return entire blockchain
    network::srv.bind(rpcinterface::chain, [=]() -> Blockchain {
        return blockchain;
    });
}