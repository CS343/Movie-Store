//
//  customer.cpp
//  movie Store
//
//  Created by Danny Ly on 3/3/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "customer.h"
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
void Customer::displayHistory() const {
    std::string format =
    "\n|--------------------------------------------------|\n";
    format+="|HISTORY                   Customer ID: " + getCustomerID() + "       |\n";
    format+="|--------------------------------------------------|\n";
    format+="|Status | Title                                    |\n";
    format+="|--------------------------------------------------|";
    
    std::cout << format << std::endl;
    for(int i = history.size() - 1; i >= 0; i--){
        if(history[i]->getTransactionType() == 'B'){
            std::cout << " Borrowed " << history[i]->getMovieTitle() << std::endl;
        }else if(history[i]->getTransactionType() == 'R'){
            std::cout << " Returned " << history[i]->getMovieTitle() << std::endl;
        }
        //history[i]->print();
        //std::cout << history[i]->print() << std::endl;
    }
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
void Customer::addTransaction(Transaction *transaction){
    history.push_back(transaction);
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
Customer::Customer(){};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */

Customer::Customer(std::string id, std::string firstName, std::string lastName){
    setCustomerID(id);
    setCustomerFirstName(firstName);
    setCustomerLastName(lastName);
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
void Customer::setCustomerID(std::string customerID){
    this->customerID = customerID;
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
void Customer::setCustomerFirstName(std::string firstName){
    this->firstName = firstName;
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
void Customer::setCustomerLastName(std::string lastName){
    this->lastName = lastName;
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
std::string Customer::getCustomerID() const{
    return this->customerID;
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
std::string Customer::getCustomerFirstName() const{
    return this->firstName;
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
std::string Customer::getCustomerLastName() const{
    return this->lastName;
};
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */



