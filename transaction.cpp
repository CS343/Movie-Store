//
//  transaction.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


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

char Transaction::getMovieGenre() const{
    return this->movieGenre;
}

std::string Transaction::getMovieYear() const{
    return this->movieYear;
}

std::string Transaction::getMovieDirector() const{
    return this->movieDirector;
}

char Transaction::getMovieReleasedMonth() const{
    return this->movieReleasedMonth;
}

std::string Transaction::getFirstName() const{
    return this->firstName;
}
std::string Transaction::getLastName() const{
    return this->lastName;
}

//setters

void Transaction::setFirstName(std::string first){
    this->firstName = first;
}
void Transaction::setLastName(std::string last){
    this->lastName = last;
}
void Transaction::setMovieReleasedMonth(char month){
    this->movieReleasedMonth = month;
}
void Transaction::setMovieDirector(std::string director){
    this->movieDirector = director;
}
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
void Transaction::setCustomerID(std::string customerID){
    this->customerID = customerID;
}
void Transaction::setMovieGenre(char genre) {
    this->movieGenre = genre;
}

void Transaction::setMovieYear(std::string year){
    this->movieYear = year;
}




void Transaction::makeTransaction(std::string result, char transactionType){
    //IM TRYING TO MAKE THIS METHOD A PURE VIRTUAL METHOD SUCH THAT
    //THIS METHOS NEEDS TO BE DEFINED WITHIN THE
    //SUBCLASSES
     //NOT SURE WHY XCODE C++ DOES NOT ALLOW ME TO DO THIS
    
    std::cout << "studpid called" << std::endl;
}

bool Transaction::doTransaction(){
    return true;
}


//print
void Transaction::print() const{
    std::ostringstream ss;

    ss << "Transaction";
    ss << "\nTransaction Type: " << this->getTransactionType();
    ss << "\nMovie Title: " << this->getMovieTitle();
    ss << "\nCustomer ID: " << this->getCustomerID();
    ss << "\nMedia Type: "  << this->getMediaType();
    ss << "\nMovie Genre: " << this->getMovieGenre();
    ss << "\nTransaction Amount: " << this->getTransactionAmount();
    std::cout << ss.str() << std::endl;
}
