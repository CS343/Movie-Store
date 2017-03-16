//
//  openhashtable.hpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef OPEN_HASH_TABLE_H
#define OPEN_HASH_TABLE_H

#include <stdio.h>
#include "LinkedHashEntry.h"
#include "customer.h"
const int TABLE_SIZE = 128;

// Forward Decleration
class LinkedHashEntry;
class Customer;
class OpenHashTable {
public:
    // news the hashtable
    OpenHashTable();
    //given the customer ID as a int convert this this string
    //atoi(customID_Sring.c_str())
    Customer* get(int key);
    
    //given a int repersentation of a customer ID from a string
    // create a new LinkedHashEntry and insert into hashtbale
    void put(int, Customer *);
    
    // removes a LinkedHashEntry from the table
    void remove(int);
    
    // deletes the hashtable
    ~OpenHashTable();
    
private:
    
    // the pointer tothe Hashtable
    LinkedHashEntry **table;



};

#endif /* OPEN_HASH_TABLE_H */
