//
//  borrow.cpp
//  movie Store
//
//  Created by Danny Ly  and Bardia Borhani on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//
#include "borrow.h"
/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- Do transaction, of the current Borrow object, this class
||		Is in charnge of removing a stock from the given databaese
||		of either one of the movie storages
||		- this class also check wether a customer doesnt exist in the
|\		system
||	Precondition:
||		- All bintree and Hash tables need to be intalizated prior to
||		call.
||		-
||
||	Postcondition:
||		- Customer object will get an update of this transaction to 
||		its history
||		- stock is removed if found
||	Assumptions:
||		- Item are all initalized correctly.
++===========================================================================*/
bool Borrow::doTransaction(BinTree &classicDB, BinTree &comedyDB, BinTree &dramaDB, OpenHashTable &customerDB){
    //borrowing, 1 each time
    
     //Make this into a class that is inherited, into anothe rlayer //repeated code
    
    
    Customer *returnCustomer = nullptr;
    //std::cout << "borrow " << std::endl;
    //get the customer from the customer Database ,
	//given a customer INT so we MUST convert thstring to an INT
    returnCustomer = customerDB.get(std::atoi(this->getCustomerID().c_str()));
    	//if the customer doesn't exist then rprint out an error
	if(returnCustomer == nullptr){
  //first retrieve the customer
        //we are to check the ttrancsation type and make stock changes
        std::cout << "ERROR customer does not exist: " << this->getCustomerID() << std::endl;
        return false;
	//checker to check of 
    }else if(getMediaType() != 'D'){
        std::cout << "ERROR invalid Media Type: " << getMediaType() << std::endl;
        return false;
    
    }else{
		//all checks are find then procedded to process teh transaction
        Movie *moviePtr = nullptr;
		//switch case for the movie genre
        switch (this->getMovieGenre()) {
            
            //Movie *moviePtr;
            case 'D':
            {
                Drama temp_movie;
                
           
		    //make a temp movie to query for the movie
                 
                temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setDirector(this->getMovieDirector());
                if(!(dramaDB.retrieveMovie(temp_movie, moviePtr))){
			//and return a leash to the movie
                    std::cout <<"ERROR Incorrect Data, This Item does not exist in Drama Database " <<this->getMovieTitle()<< std::endl;
                    
                }else{
			//remove the stock of thje movie is found
                    moviePtr->removeStock();
                }
                break;
                
            }
            case 'C':
            {
                Classic temp_movie;
                
                temp_movie.setReleaseMonth(this->getMovieReleasedMonth());
                temp_movie.setYear(this->getMovieYear());
                //temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setMajorActor(this->getFirstName(), this->getLastName());
                /*
                temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setYear(this->getMovieYear());
                */
                 if( !(classicDB.retrieveMovie(temp_movie, moviePtr) ) ){
                    std::cout <<"ERROR Incorrect Data, This Item does not exist in Classic Database "<< this->getMovieTitle() << getCustomerID()<< std::endl;
                     /*
                     std::cout <<this->getMovieTitle()<<" " <<this->getMovieReleasedMonth() << " " <<this->getFirstName() << " " << this->getLastName() << this->getMovieYear() << "Item is not in the Classic database " << std::endl;
                      */
                     
                }else{
                    this->setMovieTitle(moviePtr->getTitle());
                    moviePtr->removeStock();
                }
                break;
                
            }
            case 'F':
            {
                Comedy temp_movie;
                temp_movie.setTitle(this->getMovieTitle());
                temp_movie.setYear(this->getMovieYear());
                if(!(comedyDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does not exist in Comedy Database " << this->getMovieTitle()<< std::endl;
                    /*
                    std::cout << this->getMovieTitle()  << " " << this->getMovieYear()<<"Item is not in the Comedy  database " << std::endl;
                     */
                    
                }else{
                    moviePtr->removeStock();
                }
                break;
                
            }
            default:
                std::cout <<"ERROR Invalid Data ERROR(Genere Code): " << this-getMovieGenre()<< std::endl;
                //std::cout << "Incorrect Genre Type: " << this->getMovieGenre() << this->getMovieTitle() << std::endl;
                //std::cout<< this->getMovieTitle() << "WE always HERE: " << this->getTransactionType() <<"hello" << std::endl;
                break;
        }
        if(moviePtr != nullptr){
            returnCustomer->addTransaction(this);
        }
        return true;
    }
    
    
}



/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- Make transction is called to make itself, and initalize all
||		The correct attributes because all transactions are different
||		We needed a way for transactions to parse differently
||	Precondition:
||		- the Result and char are valid types
||		-
||
||	Postcondition:
||		- this borrow transaction is properly set up
||		-
||	Assumptions:
||		- None
++===========================================================================*/

void Borrow::makeTransaction(std::string result, char transactionType){
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
    
    // removes the carriage return /r form the string
    
	
	//remove the escape line character
	result.erase( std::remove(result.begin(), result.end(), '\r'), result.end() );

	
    
    //this will get the Customer Customer ID, MediaType, Genre
    std::string first_half_string = result.substr(1,9);
    std::vector<std::string> first_half_vector = Helper_Functions::string_split(first_half_string, ' ');
    std::string second_half_string = result.substr(10, result.length());
    
    
//set up the normal data fiels taht are of transactions from the split transaction string
    this->setCustomerID(first_half_vector[0]);
    this->setMovieGenre(first_half_vector[2][0]);
    this->setMediaType(first_half_vector[1][0]);
    this->setTransactionType(transactionType);
    
    switch (this->getMovieGenre()) {
        case 'F':
        {
            //title then year
            
            std::vector<std::string> second_half_vector = Helper_Functions::string_split(second_half_string,',');
            this->setMovieTitle(second_half_vector[0]);
            this->setMovieYear(second_half_vector[1]);
            //std::cout << "funny Movie" << std::endl;
            break;
        }
        case 'D':
        {
            //delimited by comas
            //director, title
            std::vector<std::string> second_half_vector = Helper_Functions:: string_split(second_half_string,',');
            //Dramas do not contain a movie year,
            this->setMovieTitle(second_half_vector[1].substr(1,second_half_string[1]));
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

