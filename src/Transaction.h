#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

#include "rpc/server.h"

class Transaction {
public:
    std::string sender;
    std::string recipient;
    double amount;

    MSGPACK_DEFINE_ARRAY(sender, recipient, amount);
};

#endif
