//
//  hashTable.cpp
//  movie Store
//
//  Created by Danny Ly on 3/3/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//
#include "hashTable.h"
#include <stdlib.h>
#include <stdio.h>

HashTable::HashTable(){
    length = 0;
    
    //array = nullptr;
    array = new Customer*[9999];
}

bool HashTable::retrieveCustomer(string customerID, Customer* cusPtr){
    
    int index = atoi(customerID.c_str());
    
    if(array[index] != nullptr){
        cusPtr = array[index];
        return true;
    } else{
        return false;
    }
    
}

/*
Pre-condition:
Post-condition:
*/
int HashTable::hash(Customer* customerObj){
    
    int index = 0;
    
    string custID = customerObj->getCustomerID();
    
    index = atoi(custID.c_str());
    
    array[index] = customerObj;
    
    length++;
    
    return index;
    
}

