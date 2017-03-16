
//  openhashtable.cpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "openhashtable.h"


/*============================< DEFAULT CONSTRUCTOR >===========================
||	Description:
||		- Sets up the Open Hash Object, initalizes a empty Array of 128 spaces
||		full of NULL for each index
||
||	Precondition:
||		- None
||		
||	Postcondition:
||		- Object has been initalized with an array
||		
||	Assumption(s):
||		- None
||		-
++============================================================================*/
OpenHashTable::OpenHashTable(){
    table = new LinkedHashEntry *[TABLE_SIZE];
    for(int i =0; i < TABLE_SIZE; i++){
	// elements have been set to NULL to avoid garbage data
        table[i] = NULL;
    }
};


/*=========================< FUNCTION NAME >================================
||	Description:
||		- This function retrieves a customer given a customer ID from the hash
||		structure.
||
||	Precondition:
||		- key is of type integer
||		-
||
||	Postcondition:
||		- Return nullptr if the item is not found with in the structure.
||		- Return the customer lesh(pointer) to the customer to the caller.
||
||	Assumption(s):
||		- None	
++============================================================================*/
Customer* OpenHashTable::get(int key){
    
    // finds the hash value
    int hash = (key % TABLE_SIZE);
	
    // returns nullptr if not found
    if (table[hash] == NULL)
        return nullptr;
    else {
	// create the pointer to a linked list node that points to the position
	// that the customer we want to get is in
        LinkedHashEntry *entry = table[hash];
	    
	// continue through linked list to see if can find customer
        while (entry != NULL && entry->getKey() != key){
			//move the entry cursor forward 
            entry = entry->getNext();
	}
	//check if an item exist at the current hash location
        if (entry == NULL){
            return nullptr;
       	}else{
	    //if something exist then return it.
            return entry->getValue();
    	}
     }
};

/*================================< PUT/INSERT >================================
||	Description:
||		- Inserts a customer Object, pointer to the structure, given an
||		Customer Integer as a hash key value
||
||	Precondition:
||		- Int is a 4 digit customer ID of type INt
||		
||	Postcondition:
||		- Customer has been inserted into the Hash Table
||		
||	Assumption(s):
||		- None
||		-
++============================================================================*/
void OpenHashTable::put(int key, Customer *customerPtr){
    // calculate the has value for the key
    int hash = (key % TABLE_SIZE);
	
    // if there isnt alredy a cusomter at the position of the hashtable then insert
    // the customer object there
    if (table[hash] == NULL){
        table[hash] = new LinkedHashEntry(key, customerPtr);
    } else { // either wise insert at the end of the linked list at the position
	LinkedHashEntry *entry = table[hash];
	// iterate through until end of linked list
	while (entry->getNext() != NULL){
	    entry = entry->getNext();
	}
	if (entry->getKey() == key){
	    entry->setValue(customerPtr);
	} else{
	    entry->setNext(new LinkedHashEntry(key, customerPtr));
	}
    }
};

/*==============================================================================
||	Description:
||		- Remove a Customer object from the hashtable. Use hash value to
||		- find where the object should be  - find then delete
||
||	Precondition:
||		-key must be passed in the parameter indicating the key
||		-
||
||	Postcondition:
||		- delete the node from the hashtable
||		-
||
||	Assumption(s):
||		-
||		-
++============================================================================*/
void OpenHashTable::remove(int key){
    // calculate has value
    int hash = (key % TABLE_SIZE);
	
    // there must be a customer object at the place we want to delete	
    if (table[hash] != NULL) {
        LinkedHashEntry *prevEntry = NULL;
        LinkedHashEntry *entry = table[hash];
	    
	// iterate until the Customer object is found    
        while (entry->getNext() != NULL && entry->getKey() != key) {
            prevEntry = entry;
            entry = entry->getNext();
        }
	// if the key values of a Cusomter object in the hashtable match
	// the key value in he parameter than that customer is found
	// delete the Customer object
        if (entry->getKey() == key) {
            if (prevEntry == NULL) {
                LinkedHashEntry *nextEntry = entry->getNext();
                delete entry;
                table[hash] = nextEntry;
            } else {
                LinkedHashEntry *next = entry->getNext();
                delete entry;
                prevEntry->setNext(next);
            }
        }
    }
};

/*==============================================================================
||	Description:
||		- Destructor only deletes the Linked nodes not the Linked nodes
||		Data contained
||	Precondition:
||		- None
||		
||	Postcondition:
||		- No memory leaks cleans up all data, by removing linked Node ann
||		deallocates the nodes to prevent memory leaks
||
||	Assumption(s):
||		- linked hash Entry Destructor is implmented and deletes its contained
||		data pointer that it holds else it will leak
++============================================================================*/

OpenHashTable::~OpenHashTable(){
    // go through the hashtable and delete all of the Customer objects
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL) {	// delete only places that have Customer objects
            LinkedHashEntry *prevEntry = NULL;
            LinkedHashEntry *entry = table[i];
            while (entry != NULL) {
                prevEntry = entry;
                entry = entry->getNext();
				//this just delete the Linked hashEntry, but the hashEntry
				//also contains or holds  a customer Value/item 
				//which needs to be deleted
                delete prevEntry;
            }
        }
    delete[] table; // delete the hashtable itself
};
