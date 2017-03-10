#ifndef HISTORY_H
#define HISTORY_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to display the history of transactions of the store.
*/

#include "transaction.h"
class History : public Transaction {


public:
    History(){};

    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    
    //perform the transaction
	bool doTransaction();
    
    void makeTransaction(std::string, char);
};

#endif /*  HISTORY_H */
