#ifndef HISTORY_H
#define HISTORY_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to display the history of transactions of the store.
*/

#include "transaction.h"
class History : public Transaction {

public:
    //default constructor
    History(){};

    //perform the transaction
	//bool doTransaction();
    //a do transcation to perform what this class is suppused to do
    bool doTransaction(BinTree &, BinTree &, BinTree &, OpenHashTable &);
    //initalize the history transction
    void makeTransaction(std::string, char);
};

#endif /* HISTORY_H */
