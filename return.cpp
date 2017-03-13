//
//  return.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "return.h"


bool Return::doTransaction(BinTree &classicDB, BinTree &comedyDB, BinTree &dramaDB, OpenHashTable &customerDB){
    //borrowing, 1 each time
    
    std::cout << "We are in here" << std::endl;
    
    //Make this into a class that is inherited, into anothe rlayer //repeated code
    
    
    Customer *returnCustomer = nullptr;
    
    returnCustomer = customerDB.get(std::atoi(this->getCustomerID().c_str()));
    if(returnCustomer == nullptr){
        //first retrieve the customer
        //we are to check the ttrancsation type and make stock changes
        std::cout << "customer does not exist" << std::endl;
        return false;
    }else{
        switch (this->getMovieGenre()) {
                
                Movie *moviePtr;
            case 'D':
            {
                Drama temp_movie;
                temp_movie.setDirector(this->getMovieDirector());
                temp_movie.setTitle(this->getMovieDirector());
                if(!(dramaDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout << "Item is not in the drama database " << std::endl;
                    
                }else{
                    moviePtr->addStock();
                }
                break;
                
            }
            case 'C':
            {
                Classic temp_movie;
                temp_movie.setReleaseMonth(this->getMovieReleasedMonth());
                temp_movie.setYear(this->getMovieYear());
                temp_movie.setMajorActor(this->getFirstName(), this->getLastName());
                
                if(!(classicDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout << "Item is not in the Classic database " << std::endl;
                    
                }else{
                    moviePtr->addStock();
                }
                break;
                
            }
            case 'F':
            {
                Drama temp_movie;
                temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setYear(this->getMovieYear());
                if(!(comedyDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout << "Item is not in the Comedy  database " << std::endl;
                    
                }else{
                    moviePtr->addStock();
                }
                break;
                
            }
            default:
                std::cout << "WE always here" << std::endl;
                break;
        }
        
        returnCustomer->addTransaction(this);
        
        return true;
    }
    
    
};


void Return::makeTransaction(std::string result, char transactionType){
    //std::cout << "making command" << std::endl;
    
    /*
     
     IDEA since this method is copied for all three sub classes i can inherit one more layer and have this method be in the parent of these classes
     
     
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
    std::string second_half_string = result.substr(10, result.length());
    
    
    this->setCustomerID(first_half_vector[0]);
    this->setMovieGenre(first_half_vector[2][0]);
    this->setMediaType(first_half_vector[1][0]);
    this->setTransactionType(transactionType);
    
    switch (this->getMovieGenre()) {
        case 'F':
        {
            //title then year
            
            std::vector<std::string> second_half_vector = Helper_Functions:: string_split(second_half_string,',');
            this->setMovieTitle(second_half_vector[0]);
            this->setMovieYear(second_half_vector[1]);
           // std::cout << "funny Movie" << std::endl;
            break;
        }
        case 'D':
        {
            //delimited by comas
            //director, title
            std::vector<std::string> second_half_vector = Helper_Functions:: string_split(second_half_string,',');
            
            this->setMovieTitle(second_half_vector[1]);
            this->setMovieDirector(second_half_vector[0]);
            
            break;
        }
            
        case 'C':
        {
            std::vector<std::string> second_half_vector = Helper_Functions:: string_split(second_half_string,' ');
            //classics re split by white space with month, year, firstname, lastname
            this->setMovieReleasedMonth(second_half_vector[0]);
            this->setMovieYear(second_half_vector[1]);
            this->setFirstName(second_half_vector[2]);
            this->setLastName(second_half_vector[3]);
            
            break;
        }
        default:
            break;
    }
    
};

/*
bool Return::doTransaction() {
    
    //query the movie database by looking at this movie title,
    //then increment the quntity of the stores amount by 1
    std::ostringstream ss;
 
    ss << "\nTransaction Type: " << this->getTransactionType();
    ss << "\nMovie Title: " << this->getMovieTitle();
    ss << "\nCustomer ID: " << this->getCustomerID();
    ss << "\nMedia Type: "  << this->getMediaType();
    ss << "\nMovie Genre: " << this->getMovieGenre();
    ss << "\nTransaction Amount: " << this->getTransactionAmount();
    std::cout << ss.str() << std::endl;
    return true;
};
*/
