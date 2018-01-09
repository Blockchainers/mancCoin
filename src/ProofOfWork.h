#ifndef PROOFOFWORK_H
#define PROOFOFWORK_H

#include <string>
#include <vector>

#include "Transaction.h"

class ProofOfWork {
public:
    bool verify(unsigned int previousProof, unsigned int proof);
    int proof(unsigned int previousProof);

private:
    bool validateConstraints(std::string hash);
};

#endif