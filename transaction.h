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

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
class Transaction {

public:

    Transaction();
    
    
    //setters
    
    void setCustomerID(std::string);
    //std::string print() const;
    void setMovieTitle(std::string movieTitle);
    
    void setTransactionAmount(int);
    
    
    void setTransactionType(char transactionType);

    void setMediaType(char);
    
    
    //getters
    std::string getMovieTitle() const;

    std::string getCustomerID() const;
    
	char getTransactionType() const;

    int getTransactionAmount() const;
	
    char getMediaType() const;

	int getYear();

	void setYear(int year);

	bool doTransaction();
    
    void print() const;
    
private:
    
    
    std::string movieTitle;
    
    std::string customerID;
    
    int transactionAmount;
    
    char mediaType;//typically D
    
    // Indicates the type of transaction - Borrow, Return, or Inventory
    char transactionType;

    
    // The year the movie was released
    int year;

    // the name of a major in the movie
    std::string actor;
};
#endif /* TRANSACTION_H */
