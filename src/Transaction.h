#include <vector>
#include <string>

class Transaction {
    double index;
    double timestamp;
    std::vector<Transaction> transactions;
    double proof;
    string previousHash;

    Transaction();
    ~Transaction();
};

