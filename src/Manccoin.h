#ifndef MANCCOIN_H
#define MANCCOIN_H

#include "Blockchain.h"

class Manccoin {
public:
    Blockchain blockchain;

    int start();

private:
    void bindRPC();
};

namespace rpcinterface {
    static const auto pushTransaction = "pushTransaction";   // Push transaction to the blockchain currentTransactions
    static const auto highestBlock = "highestBlock";
    static const auto blockAtIndex = "blockAtIndex";
    static const auto chain = "chain";
}

#endif
