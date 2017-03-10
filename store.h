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

#ifndef STORE_H
#define STORE_H

#include <queue>
#include "hashtable.h"
#include "bst.h"
#include <vector>
#include "bintree.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "helper_functions.h"
#include "moviefactory.h"
#include "transactionfactory.h"
class Store {


public:
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
	Store();
    
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    //read in the movies from the data file
    bool readMovies(std::ifstream& infile);
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    //read in the customers from the data file
    bool readCustomers(std::ifstream& infile);
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    //read in the transactions from the data file
    bool readTransactions(std::ifstream& infile);
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    //carry out all the transactions in the transactions queue
	bool doTransactions();
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    void showInventory() const;
private:
    
    std::queue<Transaction> transactionQueue;
    
    std::vector<std::string> string_split(std::string, const char);
    //queue of all transactions to perform
    //Queue transactions;
    
    //hashtable of all customer accounts
    HashTable customerHashTable;
    
    
    BinTree _classicStorage;
    BinTree _comedyStorage;
    BinTree _dramaStorage;
    
};

#endif /*    STORE_H   */
