#include <vector>
#include "Block.h"

class Blockchain {
    public:
        std::vector<Block> chain;
        
        Blockchain();
        ~Blockchain(); 

        void mine();   
};
