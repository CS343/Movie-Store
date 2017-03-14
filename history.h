#ifndef HISTORY_H
#define HISTORY_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to display the history of transactions of the store.
*/

#include "transaction.h"
class History : public Transaction {

    friend std::ostream& operator<<(std::ostream &, const History &);
public:
    History(){};

    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    
    //perform the transaction
	//bool doTransaction();
    bool doTransaction(BinTree &, BinTree &, BinTree &, OpenHashTable &);

    void print() const;
    void makeTransaction(std::string, char);
};

#endif /* HISTORY_H */
