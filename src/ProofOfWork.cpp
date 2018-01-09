#include <iostream>

#include "vendor/picosha2.h"

#include "ProofOfWork.h"
#include "Transaction.h"

/// Number of leading zeros to find
static const int POWZeroCount = 5;

bool ProofOfWork::validateConstraints(std::string hash) {
    std::string zeroString = std::string("").append(POWZeroCount, '0');
    return hash.substr(0, POWZeroCount) == zeroString;
}

bool ProofOfWork::verify(unsigned int previousProof, unsigned int proof) {
    std::vector<unsigned char> proofHash(32);
    std::string hashString = std::to_string(previousProof) + std::to_string(proof);
    
    // Generate initial hash
    picosha2::hash256(hashString, proofHash);

    // Generate second hash
    picosha2::hash256(proofHash, proofHash);

    // Check for prefix hash requirements
    std::string hashHexString = picosha2::bytes_to_hex_string(proofHash);
    return validateConstraints(hashHexString);
}

int ProofOfWork::proof(unsigned int previousProof) {
    unsigned int nonce = 0;

    // While not verified, increment nonce
    while(!verify(previousProof, nonce)) {
        nonce++;
    }

    return nonce;
}
