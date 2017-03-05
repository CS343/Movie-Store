/*---------- Class Description -----------
This class represents a hash table of the customers that the store has on
record. The hashtable is implemented using an array of linked lists -- i.e.
an open hashtable.
*/

#include "customer.h"


class HashTable {

private:
    
    //array to hold the linked lists which we hash customers into
	Customer** array;
	
	//length of the array
	int length;

public:
    
    HashTable();
    //retrieves a customer from the table
	bool retrieveCustomer(string customerID, Customer* cusObj);
    
    int hash(Customer* customerObj);

private:

    //hashes a customer based on their ID
	//int hash(Customer customerObj);
};
