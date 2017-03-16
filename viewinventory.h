
#ifndef VIEWHISTORY_H
#define VIEWHISTORY_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to view the inventory of the store.
*/

#include "transaction.h"

class ViewInventory : public Transaction {


public:

    // when the store class calls the doTransactions function, this
    // function is called if the command stated is "I"
    // This function intakes the bintrees can the list of customers
    // and prints the inventory of all the items in the store
    bool doTransaction(BinTree &, BinTree&, BinTree &, OpenHashTable &);
	
    //ViewInventory(){};
    //bool doTransaction();
    
    // The transaction type is set according ot the second parameter
    void makeTransaction(std::string result, char command);
};

#endif /* VIEWHISTORY_H */
