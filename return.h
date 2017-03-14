#ifndef RETURN_H
#define RETURN_H

/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to return a movie to the store
*/


#include "transaction.h"
class Return : public Transaction {

    friend std::ostream& operator<<(std::ostream &, const Return &);
public:
    //perform the transaction
	//bool doTransaction();

    void print() const;
    void makeTransaction(std::string, char);
    bool doTransaction(BinTree &, BinTree &, BinTree &, OpenHashTable &);
};

#endif /* RETURN_H */
