/*---------- Class Description -----------
This class represents a hash table of the customers that the store has on
record. The hashtable is implemented using an array of linked lists -- i.e.
an open hashtable.
*/
#ifndef HASHTABLE_h
#define HASHTABLE_h

#include "customer.h"


class HashTable {

public:
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    struct HashEntry {
        //int key;
        //int value;
        std::string key;
        Customer *value;
        /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
         #description:
         #Assumption:
         #Parameters:
         $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
        HashEntry(std::string key, Customer *value){
            this->key = key;
            this->value = value;
        }
    };
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    HashTable();
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    ~HashTable();
 
    
    //This takes a string as a unique key Identifier, and stores a pointer to a customer object
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    void insert(std::string key, Customer *);

    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    bool retrieveCustomer(std::string customerID, Customer *&returnPtr);
    //retrieves a customer from the table
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    void showAllItems()const;
private:
    //private hashFunction
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    int _hashFunction(int key);

    //this is to signify a pointer to a array that contains/holds pointers of HashEntry objects.
    HashEntry **table;
    
    
    //array to hold the linked lists which we hash customers into

    //hashes a customer based on their ID
	//int hash(Customer customerObj);
};
#endif /* HASHTABLE_H */
