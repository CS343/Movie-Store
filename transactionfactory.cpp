//
//  transactionfactory.cpp
//  movie Store
//
//  Created by Danny Ly and Bardia Borhani on 3/9/17.
//  Copyright © 2017 Danny Ly and Bardia Borhani. All rights reserved.
//


#include "transactionfactory.h"




/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- this method takes an input stream reference, and a command char,
||      - given the command char, makes a specific Transaction subclass,
||      - given the input stream it pulls data directly from the input stream  
||      - line by line - one line is pulled from it and it is passed
||      - to a makeTransaction functino depending on the trasaction object
||      - that is created
||      - the readTransaction function in Store calls this function
||      -
||	Precondition:
||		- Intakes two parameters - ifstream and char
||		-
||
||	Postcondition:
||		- returns a pointer to a newly created transaction type object
||		-
||	Assumptions:
||		- NONE
++===========================================================================*/
Transaction* TransactionFactory::makeTransaction(std::ifstream &input, 
                                                 char command){
    
    // create a pointer to a transaction object to be later point to a type
    // of transaction object
    Transaction *transactionPtr;
    
    // to store the line
    std::string result;
    
    
    // gets one line from the command file read by the ifstream and inputs it 
    // into the variable "result"
    std::getline(input, result);
    
    //get the first half, if the last
    //index contains a number good we have quantity, if not, bad we have default
    //to borrowing 1 quntity.
    std::string ayyo1 = result.substr(1,10);
    
    // splits the line by white spaces so that every token can be put
    //into variable
std::vector<std::string> first_half=Helper_Functions::string_split(ayyo1, ' ');
    
    switch (command) {
            
        case 'B':
        {
            // a new borrow object is created because the command
            //  is a "borrow" command transactino Ptr points to this new object
            transactionPtr = new Borrow();
            /* new */
            
            //give it the resulting string, and teh genre
            //within the method it will do all the splitting depedent on
            //what genere is specified.
            //transactionPtr->makeTransaction(result, command);
            break;
        }
            
        case 'R':
        {
            // a new Return object is created because the command
            //  is a "Return" command transactino Ptr points to this new object
            transactionPtr = new Return();
            break;
        }
        case 'H':
        {
            // a new History object is created because 
            // the command is a "History" command
            // transactino Ptr points to this new object
            transactionPtr = new History();
            break;
        }
        case 'I':
        {
            // a new inventory object is created because the
            // command is a "inventory" command
            // transactino Ptr points to this new object
            transactionPtr = new ViewInventory();
            break;
        }
        default:
            break;
    }
    
    // once the new object is created and transactionPtr 
    //points to a new Transactino subclass,
    // the subclass's makeTransaction function is called  
    //intaking the result and the command
    // The function sets the newly created object's 
    //variabls passed on the values in "result"
    transactionPtr->makeTransaction(result, command);
    
    // return the transactionPtr to be used be in the Store
    // class's readTransctino function
    return transactionPtr;
    
    //return NULL;
    
};

