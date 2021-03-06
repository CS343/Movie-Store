
#ifndef STORE_H
#define STORE_H
/*---------- Class Description -----------
This class represents the store itself. It has a Queue of the transactions,
just like a movie store would have receipts for everything that was
borrowed and
returned. The store also has a HashTable of all the customer accounts 
associated with the store. Lastly, the store has a BST to contain 
the inventory of the movies that the store has in stock.

The store class has four methods. The main function creates 
Finally, all transactions that were just read
in are performed via doTransactions.
*/


#include <queue>

#include <vector>
#include "bintree.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

#include "helper_functions.h"

#include "moviefactory.h"

#include "transactionfactory.h"

#include "transaction.h"

#include "openhashtable.h"


class Store {

public:
    
    // deletes the list of transactions that are made
    ~Store();
    Store();
    
  
    //read in the movies from the data file
    bool readMovies(std::ifstream& infile);
    
    //read in the customers from the data file
    bool readCustomers(std::ifstream& infile);
    
    //read in the transactions from the data file
    bool readTransactions(std::ifstream& infile);
   
    //carry out all the transactions in the transactions queue
    
    //bool doTransactions(BinTree &classicDB, BinTree &comedyDB,
    //BinTree &dramaDB, HashTable &customerDB);
    bool doTransactions();
    

    void showInventory() const;
    
    bool searchInventory(char);
	
private:
    
    //std::queue<Transaction *> transactionQueue;
    
    std::vector<std::string> string_split(std::string, const char);
    //queue of all transactions to perform
    //Queue transactions;
    
    //hashtable of all customer accounts
    //HashTable customerHashTable;
    
	// contains all the transactions that occur
    std::vector<Transaction *> transactionStorage;
	
    // Customer objects are stored in a hashtable
    OpenHashTable customerStorage;
    
    // stores all the classic movies in a BST
    BinTree _classicStorage;
	
	 // stores all the comedy movies in a BST
    BinTree _comedyStorage;
	
	 // stores all the drama movies in a BST
    BinTree _dramaStorage;
    
};

#endif /* STORE_H */
