//
//  LinkedHashEntry.hpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef LinkedHashEntry_h
#define LinkedHashEntry_h
#include <stdio.h>
#include "customer.h"



class Customer;
class LinkedHashEntry{
public:
	//Default consturctor
	//takes a Csutomer object to initalize
    	LinkedHashEntry(int , Customer *);
	//default destructor to deallocate the Stored Customer Object 
	~LinkedHashEntry();    
	//get the stored key
    	int getKey() const;
	//get the customer object currently stored
    	Customer* getValue() const;
    
	//set the customer object to contain within this node
    	void setValue(Customer *);
    	//get the next Node Object 
    	LinkedHashEntry* getNext();
    	//set the next Node Object
    	void setNext(LinkedHashEntry *next);
    
private:
	//int is a key for the hash
    	int key;
	//customer Holding pointer
    	Customer *value;
	//the current nodes next value
    	LinkedHashEntry *next;
};
#endif /* LinkedHashEntry_h */
