//
//  customer.cpp
//  movie Store
//
//  Created by Danny Ly on 3/3/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//
#include "customer.h"
#include <stdio.h>

Customer::Customer(){
    
}

Customer::Customer(string id, string firstName, string lastName){
    setCustomerID(id);
    setCustomerFirstName(firstName);
    setCustomerLastName(lastName);
}
void Customer::setCustomerID(string customerID){
    this->customerID = customerID;
}

void Customer::setCustomerFirstName(string firstName){
    this->firstName = firstName;
}

void Customer::setCustomerLastName(string lastName){
    this->lastName = lastName;
}

string Customer::getCustomerID() const{
    return this->customerID;
}

string Customer::getCustomerFirstName() const{
    return this->firstName;
}

string Customer::getCustomerLastName() const{
    return this->lastName;
}

ostream& operator<<(ostream& output, const Customer customerObj){
    output << customerObj.customerID << "\t" << customerObj.firstName << "\t" << customerObj.lastName;
    return output;
}
