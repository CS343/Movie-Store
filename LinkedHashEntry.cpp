//
//  LinkedHashEntry.cpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "LinkedHashEntry.hpp"
LinkedHashEntry::LinkedHashEntry(int key, Customer *value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
};

int LinkedHashEntry::getKey() const {
    return key;
};
Customer* LinkedHashEntry::getValue() const{
    return value;
};
void LinkedHashEntry::setValue(Customer *value) {
    this->value = value;
};
LinkedHashEntry* LinkedHashEntry::getNext() {
    return next;
};

void LinkedHashEntry::setNext(LinkedHashEntry *next){
    this->next = next;
};

