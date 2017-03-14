
#ifndef TRANSACTION_H
#define TRANSACTION_H


/*-------Class description------
A Transaction object is created for all the transactions in the
data4commands.txt file. Each line in the text file represents a transaction.

A ifstream variable in the main function intakes
the text file then passes it to the Store class. The Store class owns a
queue of transactions. The readTransactions function in the store class
works with the TransactionFactory to create a new Transaction object to be
stored in the Store class' "transactions" queue.

The Borrow, Return, and ViewInventory class all extend this class
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "hashTable.h"
#include "bintree.h"

#include "helper_functions.h"

#include "drama.h"
#include "comedy.h"
#include "classic.h"

#include "openhashtable.hpp"
class OpenHashTable;
class Transaction {
    
    

public:

    Transaction();

    virtual ~Transaction(){};
    //setters
    
    void setCustomerID(std::string);
  
    void setMovieTitle(std::string movieTitle);
    
    
    void setTransactionAmount(int);
    
    void setTransactionType(char transactionType);

    void setMediaType(char);
    
    void setMovieGenre(char);
    
    void setMovieDirector(std::string);
    
    void setMovieYear(std::string year);
    
    void setMovieReleasedMonth(std::string);
    
    void setFirstName(std::string);
    void setLastName(std::string);
    
    void setActorName(std::string, std::string);
    //getters
    
    std::string getActorName() const;
    char getMovieGenre() const;
    
    std::string getMovieTitle() const;

    std::string getCustomerID() const;
    
	char getTransactionType() const;

    int getTransactionAmount() const;
	
    char getMediaType() const;

    int getMovieYear() const;
    
    std::string getMovieDirector() const;
    
    int getMovieReleasedMonth() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    //methods
 
    virtual bool doTransaction(BinTree &, BinTree&, BinTree &, OpenHashTable &)=0;
    virtual void makeTransaction(std::string, char);
    virtual void print() const;
    
private:
    
    std::string movieDirector;
    
    std::string movieTitle;
    
    std::string customerID;
    
    int transactionAmount;
    
    char mediaType;//typically D
    
    // Indicates the type of transaction - Borrow, Return, or Inventory
    char transactionType;
    
    //movie Type AKA movie Genre
    char movieGenre;
    
    int movieReleasedMonth;

    int movieYear;

    std::string firstName;
    
    std::string lastName;
    
    std::string actorName;
};
#endif /* TRANSACTION_H */
