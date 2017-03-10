/*---------- Class Description -----------
This class is a factory for creating transactions. Since transactions
are an action, this is a proper use of the factory design pattern.
*/

#include "transaction.h"
#include "borrow.h"
#include "history.h"
#include "return.h"
#include "viewinventory.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "helper_functions.h"
class TransactionFactory {

private:
	
	// holds the type of transaction to be performed
	char transactionType;

public:
    //this method takes an input stream reference, and a command char,
    //gien the command char, makes a specific Transaction subclass,
    //givne the input stream it pulls data directly from the input stream line by line
    
    static Transaction* makeTransaction(std::ifstream &input, char command);
	// transactionType setter and getter
	char getTransactionType();
	
	void setTransactionType(char transactionType);

	// creates a transaction object of the requested type
	Transaction* createTransaction();
};
