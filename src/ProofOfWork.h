#ifndef PROOFOFWORK_H
#define PROOFOFWORK_H

#include <string>
#include <vector>
#include "Transaction.h"

class ProofOfWork {
    public:
        bool verify(std::string, std::vector<Transaction>, int);
        int proof(std::string, std::vector<Transaction>);
};

#endif