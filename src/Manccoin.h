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
    /// Push transaction to the blockchain currentTransactions
    static const auto pushTransaction = "pushTransaction";
}

#endif
