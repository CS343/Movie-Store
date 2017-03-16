#ifndef RETURN_H
#define RETURN_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to return a movie to the store
*/


#include "transaction.h"
class Return : public Transaction {

public:
    //perform the transaction

    // make the transaction accoridn the the string and char passed in the parameter
    void makeTransaction(std::string, char);
    
    // do the transactino after it has been created
    bool doTransaction(BinTree &, BinTree &, BinTree &, OpenHashTable &);
};

#endif /* RETURN_H */
