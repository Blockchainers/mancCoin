#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain {
    public:
        std::vector<Block> chain;
        
        Blockchain();
        ~Blockchain(); 

        void mine();   
};

#endif