
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
    
    // sets the movie director to the string passed in the parameter
    void setMovieDirector(std::string);
    
     // sets the movie year to the string passed in the parameter
    void setMovieYear(std::string year);
    
    // sets the movieReleasedMonth field to the string passed in the parameter	
    void setMovieReleasedMonth(std::string);
    
    // set the first name field to the value in the parameter
    void setFirstName(std::string);
    
    // set the last name field to the value in the parameter
    void setLastName(std::string);
    
    // set the actor's name to the value of the two parameters
    void setActorName(std::string, std::string);
   
	
	
     //getters
	
    // returns actor's name
    std::string getActorName() const;
	
    // returns movie genre
    char getMovieGenre() const;
    
    // returns the title of the movie
    std::string getMovieTitle() const;

   // returns the customer's id
    std::string getCustomerID() const;
    
    // return the transaction type
    char getTransactionType() const;

    //int getTransactionAmount() const;
	
    // return the media type
    char getMediaType() const;

    // return the movie's year
    int getMovieYear() const;
    
    // return the name of the movie director
    std::string getMovieDirector() const;
    
    // return the release month of the movie
    int getMovieReleasedMonth() const;
	
    // get actpr's first name
    std::string getFirstName() const;
	
    // get actor's last name
    std::string getLastName() const;
    //methods
 
    // pure virtual functinos for the subclasses
    // does the transaction
virtual bool doTransaction(BinTree &, BinTree&, BinTree &, OpenHashTable &)=0;
	
    // makes the transaction object- sets variables depending on string paramter
    virtual void makeTransaction(std::string, char)=0;
    
    
private:
    
    std::string customerID, movieTitle, movieDirector;
    
    char mediaType, transactionType, movieGenre;//typically D
    
    int movieReleasedMonth, movieYear;

    std::string firstName, lastName, actorName;

   
};
#endif /* TRANSACTION_H */
