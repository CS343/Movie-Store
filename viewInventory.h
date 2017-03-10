
#ifndef VIEWHISTORY_H
#define VIEWHISTORY_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to view the inventory of the store.
*/

#include "transaction.h"

class ViewInventory : public Transaction {


public:

    ViewInventory(){};
	bool doTransaction();
    
    void makeTransaction(std::string result, char command);
};

#endif /*   VIEWHISTORY_H   */
