//
//  history.cpp
//  movie Store
//
//  Created by Danny Ly and Bardia Borhani on 3/9/17.
//  Copyright © 2017 Danny Ly and Bardia Borhani. All rights reserved.
//

#include "history.h"
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - Do transaction will call the view history method of the current 
 ||     storedd customer , , by query the customer database,
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - the customers history is viewed,
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/


bool History::doTransaction(BinTree &classicDB, BinTree &comedyDB,
                            BinTree &dramaDB, OpenHashTable &customerDB){
    //borrowing, 1 each time
    
    //Make this into a class that is inherited, into anothe rlayer //repeated code
    
    
    Customer *returnCustomer;
    returnCustomer = customerDB.get(std::atoi(this->getCustomerID().c_str()));
    if(returnCustomer == nullptr){
        //first retrieve the customer
        //we are to check the ttrancsation type and make stock changes
        std::cout << "ERROR customer does not exist: " << getCustomerID()<< std::endl;
        return false;
    }else{
        //std::cout << "Printing History for customer ID: " << this->getCustomerID() << std::endl;
        //call the current customers displayHistory.
        returnCustomer->displayHistory();
   
        return true;
    }
    
    
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - make this transaction, given the data string and a trancastion 
 ||     populates an transctions
 ||
 ||   Preconditions:
 ||      - two parameters need to be passed in - one string and one char
 ||      - the char represents the transaction tpye and the other one is
 ||      - the command that has been taken from the command txt file
 ||   Postconditions:
 ||      - a history object will be able to be completed when calling this
 ||      - function - the fields of the class are filled
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/


void History::makeTransaction(std::string result, char transactionType){
   // std::cout << "making command" << std::endl;
    
    /*
     
     IDEA since this method is copied for all three sub classes
     i can inherit one more layer and have this method be in the parent of these classes
     
     
     if(isdigit(first_half[3][0])){
     int amt = std::atoi(first_half[3].c_str());
     // std::cout << "we have a digit: " << amt<< std::endl;
     transactionPtr->setTransactionAmount(amt);
     }else{
     transactionPtr->setTransactionAmount(1);
     //std::cout << "we have a alpha: " << first_half[3][0] << std::endl;
     }
     std::cout <<  "SECOND HALF : " << ayoo2.substr(10, ayoo2.length() - 10) << std::endl;
     std::cout <<  "SECOND HALF : " << ayoo2 << std::endl;
     //make the rest of the transaction
     std::vector<std::string> second_half = Helper_Functions::string_split(ayoo2, ',');
     
     
     */
    
    
    
    //classica re split by white space with month, year, firstname, lastname
    //Funny are split(dimilted by coma), title,  year
    
    //Drams are delimited by comas Director, title
    
    //this will get the Customer Customer ID, MediaType, Genre
    std::string first_half_string = result.substr(1,9);
    std::vector<std::string> first_half_vector = Helper_Functions::string_split(first_half_string, ' ');
    
    // set customer ID field to the part of the string that comes after the transaction type
    this->setCustomerID(first_half_vector[0]);
 
    this->setTransactionType(transactionType);
    
    
};

