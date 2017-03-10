/*---------- Class Description -----------
This class extends the transaction class, and is specifically a transaction to
borrow a movie from the store.
*/

#ifndef BORROW_H
#define BORROW_H
#include <stdio.h>
#include "transaction.h"


class Borrow : public Transaction {


public:

  //perform the transaction
    ~Borrow();
	bool doTransaction();
private:
    int borrow_amount;
};


#endif /*   BORROW_H    */
