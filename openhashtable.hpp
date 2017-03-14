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
#include "LinkedHashEntry.hpp"
#include "customer.h"
const int TABLE_SIZE = 128;
class LinkedHashEntry;
class OpenHashTable {
public:
    OpenHashTable();
    //given the customer ID as a int convert this this string
    //atoi(customID_Sring.c_str())
    Customer* get(int key);
    
    //given a int repersentation of a customer ID from a string
    //atoi(string_ID.c_str())
    void put(int, Customer *);
    void remove(int);
    
    ~OpenHashTable();
    
private:
    LinkedHashEntry **table;



};

#endif /* OPEN_HASH_TABLE_H */
