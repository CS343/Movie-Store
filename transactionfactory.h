/*---------- Class Description -----------
This class is a factory for creating transactions. Since transactions
are an action, this is a proper use of the factory design pattern.
*/

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

// The TransactionFactory needs to know about all types of transactions
// so it can create an object based on a Transaction Type
#include "transaction.h"
#include "borrow.h"
#include "history.h"
#include "return.h"
#include "viewinventory.h"


#include <stdio.h>
#include <iostream>
#include <fstream>
#include "helper_functions.h"


//#include "drama.h"
//#include "classic.h"
//#include "comedy.h"
//#include "viewinventory.h"

class TransactionFactory {
    
public:
    
    //this method takes an input stream reference, and a command char,
    //given the command char, makes a specific Transaction subclass,
    //given the input stream it pulls data directly from the input stream line 
    // by line
    static Transaction* makeTransaction(std::ifstream &input, char command);
};

#endif /* TRANSACTIONFACTORY_H */
