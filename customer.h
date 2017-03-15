/*---------- Class Description -----------
This class represents a customer of the store. 
Each customer has two pieces of information.
The object contains two fields. One is "customerID" which represents
the customers ID number. The other is "name" which represnts the name 
of the customer. The Store class has a BST which contains Customer objects.
The BST reads the data4customers.txt file, extracts information about each
customer and creates an Customer object for each customer. 
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H 

#include <iostream>
#include <stdio.h>
#include "transaction.h"
#include <vector>
//this is called forward declaration, to avoid circular dependancy,
//circlular dependancy is defined as
//A <-- includes B --> B includes A
//both classes are included within each other, so they are collided against.
class Transaction;

class Customer {

public:
    /*_________________________________________
     #description:
     #Assumption:
     #Parameters:
     ----------------------------------------*/
    Customer();
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    Customer(std::string, std::string, std::string);
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    // returns the customerID - used to find a customer in the hash table
    //this is a unique ID assumed
    std::string getCustomerID() const;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    // passes in a parameter and sets the customerID field according to the
    // value of the parameter
    void setCustomerID(std::string customerID);
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    
    void addTransaction(Transaction *);
    
    // returns the name of the customer
    std::string getCustomerFirstName() const;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    std::string getCustomerLastName() const;

    // sets the name of the customer according to the value of the parameter.
    void setCustomerFirstName(std::string name);
    void setCustomerLastName(std::string name);
    
 
    
    void displayHistory() const;
    
 
    
private:
    std::string customerID;
    std::string firstName;
    std::string lastName;
    std::vector<Transaction *> history;

	
};

#endif /* CUSTOMER_H */
