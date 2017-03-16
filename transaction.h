
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

#include "openhashtable.h"
#include <algorithm>
class OpenHashTable;
class Transaction {
    
    

public:

    // default constructor
    Transaction();

    // destructor
    virtual ~Transaction(){};
    //setters

    // sets the customer ID field to the value passed in the parameter
    void setCustomerID(std::string);
  
    // sets the movie title field to the value passed in the parameter
    void setMovieTitle(std::string movieTitle);
   
    //void setTransactionAmount(int);
    
    // set the transactionType field to the value passed in the parameter
    void setTransactionType(char transactionType);

    // set the media type field to the value passed in the parameter
    void setMediaType(char);
    
    //set the media type field to the value passed in the parameter
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
    virtual void makeTransaction(std::string, char)=0;
    
    
private:
    
    std::string customerID, movieTitle, movieDirector;
    
    char mediaType, transactionType, movieGenre;//typically D
    
    int movieReleasedMonth, movieYear;

    std::string firstName, lastName, actorName;

   
};
#endif /* TRANSACTION_H */
