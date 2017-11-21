#include <vector>
#include <string>

class Transaction {
    double index;
    double timestamp;
    std::vector<Transaction> transactions;
    double proof;
    std::string previousHash;

    Transaction();
    ~Transaction();
};

