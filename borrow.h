#ifndef BORROW_H
#define BORROW_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a transaction to
borrow a movie from the store.
*/
//if you do not declare a method virtual in parent you CANNOT OVERRIDE IT, but can hide it.

#include "transaction.h"


class Borrow : public Transaction {

public:
    Borrow(){};

    bool doTransaction();
    void makeTransaction(std::string, char transactionType);
    bool doTransaction(BinTree &, BinTree&, BinTree &, HashTable &);


};


#endif /* BORROW_H */
