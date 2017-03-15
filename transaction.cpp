//
//  transaction.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "transaction.h"

Transaction::Transaction(){

}


//getters
std::string Transaction::getActorName() const{
    return this->actorName;
}
std::string Transaction::getMovieTitle() const{
    return this->movieTitle;
}
std::string Transaction::getCustomerID() const{
    return this->customerID;
}

char Transaction::getTransactionType() const{
    return this->transactionType;
}


char Transaction::getMediaType() const{
    return this->mediaType;
}

char Transaction::getMovieGenre() const{
    return this->movieGenre;
}

int Transaction::getMovieYear() const{
    return this->movieYear;
}

std::string Transaction::getMovieDirector() const{
    return this->movieDirector;
}

int Transaction::getMovieReleasedMonth() const{
    return this->movieReleasedMonth;
}

std::string Transaction::getFirstName() const{
    return this->firstName;
}
std::string Transaction::getLastName() const{
    return this->lastName;
}

//setters

void Transaction::setActorName(std::string firstName, std::string lastName ){
    this->actorName = firstName + " " + lastName;
}
void Transaction::setFirstName(std::string first){
    this->firstName = first;
}
void Transaction::setLastName(std::string last){
    this->lastName = last;
}
void Transaction::setMovieReleasedMonth(std::string month){
    int value  = std::atoi(month.c_str());
    this->movieReleasedMonth = value;
}
void Transaction::setMovieDirector(std::string director){
    this->movieDirector = director;
}
void Transaction::setMediaType(char mediaType){
    this->mediaType = mediaType;
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
    
    int value = std::atoi(year.c_str());
    this->movieYear = value;
}


/*

void Transaction::makeTransaction(std::string result, char transactionType){
    //IM TRYING TO MAKE THIS METHOD A PURE VIRTUAL METHOD SUCH THAT
    //THIS METHOS NEEDS TO BE DEFINED WITHIN THE
    //SUBCLASSES
     //NOT SURE WHY XCODE C++ DOES NOT ALLOW ME TO DO THIS
    
    std::cout << "stupid called" << std::endl;
}
 */


 
