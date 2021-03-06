//
//  LinkedHashEntry.cpp
//  movie Store
//
//  Created by Danny Ly on 3/13/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//
/*==============================< Default Constructor >=====================
||	Function Desction:Consutructor for Linked Hash Entry
||
||	Precondition:
||		- Key is of type int with 4 characters
||		- Customer has been intalitated
||
||	Precondition:
||		- popualtes a Hash Node to be inserted into hash table
||		-
||	Assumptions:
||		- Customer is populated correctly and key is value 4 digit 
||		cust ID.
++===========================================================================*/
#include "LinkedHashEntry.h"
LinkedHashEntry::LinkedHashEntry(int key, Customer *value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
};
/*==============================< GET Key>==============================
||	Function Desction:
||		- Gets the ket of this current Hash Node
||	Precondition:
||		-None
||	Precondition:
||		- returns Int of current hash Key
||	Assumptions:
||		- None
++===========================================================================*/
int LinkedHashEntry::getKey() const {
    return key;
};
/*==============================< getValue>=============================
||	Function Desction:
||		- Returns the value of the stored Customer Object
||	Precondition:
||		- None
||	Precondition:
||		- Returns the data within this node as a customer pointer
||	Assumptions:
||		- None
++===========================================================================*/
Customer* LinkedHashEntry::getValue() const{
    return value;
};
/*==============================< setValue >===========================
||	Function Desction:
||		- Sets the data object, Customer Object of the current Node
||	Precondition:
||		-  Set the key customer object of the current Node.
||	Post Condition
||		- None
||	Assumptions:
||		- Customer Object is instatiated correctly
++===========================================================================*/
void LinkedHashEntry::setValue(Customer *value) {
    this->value = value;
};
/*==============================< getNext >=============================
||	Function Desction:
||		- get Next the next precedding Entry Node
||	Precondition:
||		- None
||	Precondition:
||		- Returns the Linked Hash Node next in line
||	Assumptions:
||		- None
++===========================================================================*/
LinkedHashEntry* LinkedHashEntry::getNext() {
    return next;
};
/*==============================< setNext >==============================
||	Function Desction:
||		- Sets the next link to the next preceeding hash Entry Node
||	Precondition:
||		- None
||	Precondition:
||		- puts a object into the linked hash entry
||	Assumptions:
||		- None
++===========================================================================*/
void LinkedHashEntry::setNext(LinkedHashEntry *next){
    this->next = next;
};
/*==============================< DECONSTRUCTOR>==============================
||	Function Desction:
||		- deallocates teh Customer object taht is current held
||		weithin the Node
||	Precondition:
||		- None
||	Precondition:
||		- Deallocation of customer object 
||	Assumptions:
||		- None
++===========================================================================*/
LinkedHashEntry::~LinkedHashEntry(){
	delete this->value;
};

