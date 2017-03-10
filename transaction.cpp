//
//  transaction.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include <stdio.h>

#include "transaction.h"

Transaction::Transaction(){
    this->setTransactionAmount(0);
}

//getters

std::string Transaction::getMovieTitle() const{
    return this->movieTitle;
}
std::string Transaction::getCustomerID() const{
    return this->customerID;
}

char Transaction::getTransactionType() const{
    return this->transactionType;
}

int Transaction::getTransactionAmount() const{
    return this->transactionAmount;
}

char Transaction::getMediaType() const{
    return this->mediaType;
}
//setters
void Transaction::setMediaType(char mediaType){
    this->mediaType = mediaType;
}

void Transaction::setTransactionAmount(int amount){
    this->transactionAmount = amount;
}
void Transaction::setTransactionType(char type){
    this->transactionType = type;
}
void Transaction::setMovieTitle(std::string movieTitle){
    this->movieTitle = movieTitle;
}
void Transaction::setCustomerID(std::string customrID){
    this->customerID = customerID;
}

//print
void Transaction::print() const{
    std::ostringstream ss;

    ss << "Transaction";
    ss << "\nMovie Title: " << this->getMovieTitle();
    ss << "\nCustomer ID: " << this->getCustomerID();
    ss << "\nMedia Type: "  << this->getMediaType();
    ss << "\nTransaction Amount: " << this->getTransactionAmount();
    std::cout << ss.str() << std::endl;
}
