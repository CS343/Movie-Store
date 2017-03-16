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
    // Borrow(){};
    //makes the current transaction given a char tarnsaction type
    //and a string which is the resulting string of text
    void makeTransaction(std::string, char transactionType);
    
    
    //does a borrrow transaction
    //given the database reference to customers and movie databases
    bool doTransaction(BinTree &, BinTree&, BinTree &, OpenHashTable &);
   

};


#endif /* BORROW_H */
