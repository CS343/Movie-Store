//
//  return.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "return.h"
void Return::print() const{
    std::cout << "returned Item: " << std::endl;
}

bool Return::doTransaction(BinTree &classicDB, BinTree &comedyDB, BinTree &dramaDB, OpenHashTable &customerDB){
    //borrowing, 1 each time
    
    //std::cout << "We are in here" << std::endl;
    
    //Make this into a class that is inherited, into anothe rlayer //repeated code
    
    
    Customer *returnCustomer = nullptr;
     //std::cout << "return" << std::endl;
    
    returnCustomer = customerDB.get(std::atoi(this->getCustomerID().c_str()));
    if(returnCustomer == nullptr){
        //first retrieve the customer
        //we are to check the ttrancsation type and make stock changes
        std::cout << "ERROR customer does not exist: " << this->getCustomerID() << std::endl;
        return false;
    }else{
        Movie *moviePtr = nullptr;
        switch (this->getMovieGenre()) {
            
            case 'D':
            {
                Drama temp_movie;
                
                temp_movie.setDirector(this->getMovieDirector());
                temp_movie.setTitle(this->getMovieTitle());
                
                
                //temp_movie.setTitle(this->getMovieTitle());
              
                if(!(dramaDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does not exist in Drama Database " <<this->getMovieTitle()<< std::endl;
                    
                    //std::cout <<this->getMovieTitle() << " " << this->getMovieDirector() <<" Item is not in the drama database " << std::endl;
                    
                }else{
                    moviePtr->addStock();
                }
                break;
                
            }
            case 'C':
            {
                Classic temp_movie;
                temp_movie.setReleaseMonth(this->getMovieReleasedMonth());
                temp_movie.setMajorActor(this->getFirstName(), this->getLastName());

                temp_movie.setYear(this->getMovieYear());
                if(!(classicDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does not exist in Classic Database " <<this->getMovieTitle()<< std::endl;
                    
                    //std::cout <<this->getMovieTitle()<<" " <<this->getMovieReleasedMonth() << " " <<this->getActorName()<< this->getMovieYear() << "Item is not in the Classic database " << std::endl;
                    
                }else{
                    this->setMovieTitle(moviePtr->getTitle());
                    moviePtr->addStock();
                }
                break;
                
            }
            case 'F':
            {
                Comedy temp_movie;
                
                temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setYear(this->getMovieYear());
                /*
                temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setYear(this->getMovieYear());
                 */
                
                if(!(comedyDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does not exist in Comedy Database " <<this->getMovieTitle()<< std::endl;
                    
                    //std::cout << this->getMovieTitle()  << " " << this->getMovieYear()<<"Item is not in the Comedy  database " << std::endl;
                    
                }else{
                    moviePtr->addStock();
                }
                break;
                
            }
            default:
                std::cout <<"ERROR Invalid Data ERROR(Genere Code): " << this-getMovieGenre()<< std::endl;
                //std::cout << "InCorrect Genere return: " << this->getMovieGenre() << this->getMovieTitle() << std::endl;
                break;
        }
        if(moviePtr != nullptr){
            returnCustomer->addTransaction(this);
        }
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
    
    // remove the carriage return /r
    result.erase( std::remove(result.begin(), result.end(), '\r'));
    
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

std::ostream& operator<<(std::ostream &output, const Return &rhs){
    output << "hellow from return";
    
    return output;
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
