#include "Manccoin.h"

#include "Blockchain.h"
#include "Transaction.h"

int Manccoin::start() {
    blockchain = new Blockchain();

    return 0;
}
