//
//  customer.cpp
//  movie Store
//
//  Created by Danny Ly on 3/3/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "customer.h"
#include <stdio.h>

/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
Customer::Customer(){
    
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */

Customer::Customer(string id, string firstName, string lastName){
    setCustomerID(id);
    setCustomerFirstName(firstName);
    setCustomerLastName(lastName);
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
void Customer::setCustomerID(string customerID){
    this->customerID = customerID;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
void Customer::setCustomerFirstName(string firstName){
    this->firstName = firstName;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
void Customer::setCustomerLastName(string lastName){
    this->lastName = lastName;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
string Customer::getCustomerID() const{
    return this->customerID;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */

string Customer::getCustomerFirstName() const{
    return this->firstName;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
string Customer::getCustomerLastName() const{
    return this->lastName;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
ostream& operator<<(ostream& output, const Customer customerObj){
    output << customerObj.customerID << "\t" << customerObj.firstName << "\t" << customerObj.lastName;
    return output;
}

void Customer::printHistory() const{
    std::string format =
    "|--------------------------------------------------|\n";
    format+="|INVENTORY                                         |\n";
    format+="|--------------------------------------------------|\n";
    
    cout << format << endl;
    /*
    while(!(this->history.empty())){
        //output the transaction print function string returned
        //cout << this->history.front().print() << endl;
    
    }
     */
}
