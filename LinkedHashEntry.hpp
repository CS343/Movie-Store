//
//  LinkedHashEntry.hpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef LinkedHashEntry_hpp
#define LinkedHashEntry_hpp

#include <stdio.h>
#include "customer.h"
class Customer;
class LinkedHashEntry{
public:
    LinkedHashEntry(int , Customer *);
    
    int getKey() const;
    Customer* getValue() const;
    
    void setValue(Customer *);
    
    LinkedHashEntry* getNext();
    
    void setNext(LinkedHashEntry *next);
    
private:
    int key;
    Customer *value;
    LinkedHashEntry *next;
};
#endif /* LinkedHashEntry_hpp */
