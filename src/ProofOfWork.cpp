#include "ProofOfWork.h"
#include "vendor/picosha2.h"
#include "Transaction.h"

#include <iostream>

bool ProofOfWork::verify(std::string previousHash, std::vector<Transaction> transactionData, int hashNonce) {
    std::vector<unsigned char> proofHash(32);
    std::string hashString = previousHash;

    // Concatenate transaction amounts
    for(std::vector<Transaction>::iterator it = transactionData.begin(); it != transactionData.end(); ++it) {
        previousHash += it->amount;
    }

    hashString += hashNonce;
    
    // Generate hash of hashString
    picosha2::hash256(hashString.begin(),
                    hashString.end(),
                    proofHash.begin(),
                    proofHash.end());

    // Check for any invalid characters in range (0,3)
    std::string hashHexString = picosha2::bytes_to_hex_string(proofHash.begin(), proofHash.end());
    return hashHexString.substr(0, 2) == "00";
}

int ProofOfWork::proof(std::string previousHash, std::vector<Transaction> transactionData) {
    int hashNonce = 0;

    // While not verified, increment nonce
    while(!verify(previousHash, transactionData, hashNonce)) {
        hashNonce++;

        if (hashNonce < 0) {
            std::cout << "NO!" << std::endl;
        } 
    }

    return hashNonce;
}
