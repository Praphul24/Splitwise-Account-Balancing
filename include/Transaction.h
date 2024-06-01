#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public:
    string from; // Debtor
    string to;   // Creditor
    int amount;  // Amount of the transaction

    Transaction() = default;
    
};

#endif // TRANSACTION_H
