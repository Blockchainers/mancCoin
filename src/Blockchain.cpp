#include "Blockchain.h"

Blockchain::Blockchain() : chain() { 

    Block genisis = Block();

    genisis.index = 0;
    genisis.proof = 0;
    genisis.previousHash = "";

    chain.push_back(genisis);
};
