
//  openhashtable.cpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "openhashtable.hpp"


OpenHashTable::OpenHashTable(){
    table = new LinkedHashEntry *[TABLE_SIZE];
    for(int i =0; i < TABLE_SIZE; i++){
        table[i] = NULL;
    }
};


Customer* OpenHashTable::get(int key){
    
    //returns nullptr if not found
    int hash = (key % TABLE_SIZE);
    if (table[hash] == NULL)
        return nullptr;
    else {
        LinkedHashEntry *entry = table[hash];
        while (entry != NULL && entry->getKey() != key)
            entry = entry->getNext();
        if (entry == NULL)
            return nullptr;
        else
            return entry->getValue();
    }
};
void OpenHashTable::put(int key, Customer *customerPtr){
    int hash = (key % TABLE_SIZE);
    if (table[hash] == NULL)
        table[hash] = new LinkedHashEntry(key, customerPtr);
    else {
        LinkedHashEntry *entry = table[hash];
        while (entry->getNext() != NULL)
            entry = entry->getNext();
        if (entry->getKey() == key)
            entry->setValue(customerPtr);
        else
            entry->setNext(new LinkedHashEntry(key, customerPtr));
    }
};
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
OpenHashTable::~OpenHashTable(){
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL) {
            LinkedHashEntry *prevEntry = NULL;
            LinkedHashEntry *entry = table[i];
            while (entry != NULL) {
                prevEntry = entry;
                entry = entry->getNext();
                delete prevEntry;
            }
        }
    delete[] table;
};
