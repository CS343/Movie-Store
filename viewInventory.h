/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to view the inventory of the store.
*/

#include "transaction.h"

#ifndef TRANSACTION_H
#define TRANSACTION_H
class ViewInventory : Transaction {


public:

    //perform the transaction
	bool doTransaction();
};

#endif /*   VIEWTRANSACTION_H   */
