#include <vector>
#include <string>

class Block {
    public:
        int index;
        int proof;
        std::vector<Transaction> transaction;
        std::string previousHash;
        Block();
        ~Block();
};
