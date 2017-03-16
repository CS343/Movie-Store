
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
        table[i] = NULL;
    }
};


/*=========================< RETRIEVE CUSTOMER >================================
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
    
    //returns nullptr if not found
    int hash = (key % TABLE_SIZE);
    if (table[hash] == NULL)
        return nullptr;
    else {
        LinkedHashEntry *entry = table[hash];
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
    int hash = (key % TABLE_SIZE);
    if (table[hash] == NULL){
        table[hash] = new LinkedHashEntry(key, customerPtr);
   	} else {
        LinkedHashEntry *entry = table[hash];
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
||		-
||		-
||
||	Precondition:
||		-
||		-
||
||	Postcondition:
||		-
||		-
||
||	Assumption(s):
||		-
||		-
++============================================================================*/
void OpenHashTable::remove(int key){
    int hash = (key % TABLE_SIZE);
    if (table[hash] != NULL) {
        LinkedHashEntry *prevEntry = NULL;
        LinkedHashEntry *entry = table[hash];
        while (entry->getNext() != NULL && entry->getKey() != key) {
            prevEntry = entry;
            entry = entry->getNext();
        }
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
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL) {
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
    delete[] table;
};
