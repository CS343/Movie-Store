//
//  transaction.cpp
//  movie Store
//
//  Created by Danny Ly and Bardia Borhani on 3/9/17.
//  Copyright © 2017 Danny Ly and Bardia Borhani. All rights reserved.
//


#include "transaction.h"


Transaction::Transaction(){

}


// returns the actor's full name
// only used for classic movies
std::string Transaction::getActorName() const{
    return this->actorName;
}

// returns the movie's title
std::string Transaction::getMovieTitle() const{
    return this->movieTitle;
}

// returns the customer's ID
std::string Transaction::getCustomerID() const{
    return this->customerID;
}

// returns the trasaction type
char Transaction::getTransactionType() const{
    return this->transactionType;
}

// returns the media type
char Transaction::getMediaType() const{
    return this->mediaType;
}

// returns the movie genre
// All going to be "D" for DVDs for this project
char Transaction::getMovieGenre() const{
    return this->movieGenre;
}

// returns movie year
int Transaction::getMovieYear() const{
    return this->movieYear;
}

// returns the movie director
std::string Transaction::getMovieDirector() const{
    return this->movieDirector;
}

int Transaction::getMovieReleasedMonth() const{
    return this->movieReleasedMonth;
}

// returns the actors first name
// only used for classic movies
std::string Transaction::getFirstName() const{
    return this->firstName;
}

// reutrns the actor's last name
// only used for classic movies
std::string Transaction::getLastName() const{
    return this->lastName;
}



//setters

// sets the actors full name
// only used for classic movies
void Transaction::setActorName(std::string firstName, std::string lastName ){
    this->actorName = firstName + " " + lastName;
}

// sets the actors first name
// only used for classic movies
void Transaction::setFirstName(std::string first){
    this->firstName = first;
}

// sets the actors last name
// only used for classic movies
void Transaction::setLastName(std::string last){
    this->lastName = last;
}

// sets the release month of the movie
void Transaction::setMovieReleasedMonth(std::string month){
    int value  = std::atoi(month.c_str());
    this->movieReleasedMonth = value;
}

// sets the name of the movie director
void Transaction::setMovieDirector(std::string director){
    this->movieDirector = director;
}

// sets the media type
// All going to be "D" for DVDs for this project
void Transaction::setMediaType(char mediaType){
    this->mediaType = mediaType;
}

// sets the Transaction type
void Transaction::setTransactionType(char type){
    this->transactionType = type;
}

// sets the movie title
void Transaction::setMovieTitle(std::string movieTitle){
    this->movieTitle = movieTitle;
}

// sets the customer's ID number
void Transaction::setCustomerID(std::string customerID){
    this->customerID = customerID;
}

// sets the movie genre
void Transaction::setMovieGenre(char genre) {
    this->movieGenre = genre;
}

// sets the year the movie was released
// converted from string to int. It was read as a string
// when the ifstream variable was reading the lines in 
// the movie file in Store's readMovies function
void Transaction::setMovieYear(std::string year){
    
    int value = std::atoi(year.c_str());
    this->movieYear = value;
}




 
