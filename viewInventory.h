/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to view the inventory of the store.
*/

#include "transaction.h"

#ifndef VIEWHISTORY_H
#define VIEWHISTORY_H
class ViewInventory : public Transaction {


public:

    //perform the transaction
	bool doTransaction();
    
    void makeTransaction();
};

#endif /*   VIEWHISTORY_H   */
