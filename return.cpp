//
//  return.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "return.h"


/*==========================< FUNCTION NAME >=============================
||
||   Function_Description:
||      - completes the transaction based on the values of the fields in the 
||	- return object
||   Preconditions:
||      - Take in 4 parameters - three are the 3 bintree of movies
||      - the other one is the customer hashtable
||   Postconditions:
||      - The actions stated by the Return object are done
||      - 
||
||   Assumptions:
||      - None
++============================================================================*/
bool Return::doTransaction(BinTree &classicDB, BinTree &comedyDB,
			   BinTree &dramaDB, OpenHashTable &customerDB){
    //borrowing, 1 each time
    
    //std::cout << "We are in here" << std::endl;
    
    //Make this into a class that is inherited, into anothe rlayer 
	//repeated code
    
    
    Customer *returnCustomer = nullptr;
     //std::cout << "return" << std::endl;
    
    // points at the customer in the customer hashtable that this
    //reutnr is dealing with
    returnCustomer = customerDB.get(std::atoi(this->getCustomerID().
                                              c_str()));
	
    // if the customer was not found then show error
    if(returnCustomer == nullptr){
        //first retrieve the customer
        //we are to check the ttrancsation type and make stock changes
        std::cout << "ERROR customer does not exist: " <<
		this->getCustomerID() << std::endl;
		
        return false;
    }else if(getMediaType() != 'D'){	// if media type is not 'D'
        //for DVD then show an error
        std::cout << "ERROR invalid Media Type: " << getMediaType()
        << std::endl;
        return false;	// return false as the transactino cannot
        //be completed due to error
    }else{
        Movie *moviePtr = nullptr;
	// differemt cases for reuturning different types of movies
        switch (this->getMovieGenre()) {
            
	    // if drama
            case 'D':
            {
                Drama temp_movie;
                
                temp_movie.setDirector(this->getMovieDirector());
                temp_movie.setTitle(this->getMovieTitle());
                
		// check to see if the drama movie is in the drama BST
                if(!(dramaDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does \
                    not exist in Drama Database " <<
                    this->getMovieTitle()<<
                    std::endl;
             
                    
                }else{
		    // if movie was found in the store then add a stock to that movie
                    moviePtr->addStock();
                }
                break;
                
            }
            case 'C':
            {
                Classic temp_movie;
                temp_movie.setReleaseMonth(this->getMovieReleasedMonth());
                temp_movie.setMajorActor(this->getFirstName(),
                                         this->getLastName());
                temp_movie.setYear(this->getMovieYear());
		    
		// check to see if the classic movie is in the classic BST
                if(!(classicDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does\
                    not exist in Classic Database "
                    <<this->getMovieTitle()<< std::endl;
                
                }else{
		    // if it is then add to the movie's stock
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
                
		// check to see if the comedy movie is in the comedy BST
                if(!(comedyDB.retrieveMovie(temp_movie, moviePtr))){
                    std::cout <<"ERROR Incorrect Data, This Item does not\
                    exist in Comedy Database " <<this->getMovieTitle()<<
                    std::endl;
                    
             
                    
                }else{
		    // if it is there then add to the movie's stock
                    moviePtr->addStock();
                }
                break;
                
            }
            default:
                std::cout <<"ERROR Invalid Data ERROR(Genere Code): " <<
                this-getMovieGenre()<< std::endl;
           
                break;
        }
	    
	// add the movie to the customer's list of transactions
        //so we can keep track
	// of what the customer has borrowed and returned
        if(moviePtr != nullptr){
            returnCustomer->addTransaction(this);
        }
        return true;
    }
    
    
};

/*==========================< FUNCTION NAME >=============================
||
||   Function_Description:
||      - Create the Return transaction object based on the string and char
||	- passed in the parameter. 
||	- the first parameter contains a string representing a line from the 
||	- command txt file that represents a return command
||	- The string is cut up and the pieces are set as this objects fields
||	-
||   Preconditions:
||      - Two parameters must be passed in. The first one must contain a line 
||      - from the command txt file where the transactionType is R
||   Postconditions:
||      - The fields of the Return object will be filled
||      - 
||
||   Assumptions:
||      - None
++============================================================================*/
void Return::makeTransaction(std::string result, char transactionType){
    //std::cout << "making command" << std::endl;
    
    /*
     
     IDEA since this method is copied for all three sub classes i can 
     inherit one more layer and have this method be in the parent of 
     these classes
     
     
     if(isdigit(first_half[3][0])){
     int amt = std::atoi(first_half[3].c_str());
     // std::cout << "we have a digit: " << amt<< std::endl;
     transactionPtr->setTransactionAmount(amt);
     }else{
     transactionPtr->setTransactionAmount(1);
     //std::cout << "we have a alpha: " << first_half[3][0] <<
     std::endl;
     }
     std::cout <<  "SECOND HALF : " << ayoo2.substr(10,
     ayoo2.length() - 10) << std::endl;
     std::cout <<  "SECOND HALF : " << ayoo2 << std::endl;
     //make the rest of the transaction
     std::vector<std::string> second_half 
     = Helper_Functions::string_split(ayoo2, ',');
     
     
     */
    
    
    
    //classica re split by white space with month, year,
    //firstname, lastname
    //Funny are split(dimilted by coma), title,  year
    
    //Drams are delimited by comas Director, title
    
    // remove the carriage return /r
    result.erase( std::remove(result.begin(), result.end(), '\r'),
                 result.end() );
    
    //this will get the Customer Customer ID, MediaType, Genre
    std::string first_half_string = result.substr(1,9);
    std::vector<std::string> first_half_vector =
    Helper_Functions::string_split(first_half_string, ' ');
    std::string second_half_string = result.substr(10, result.length());
    
    // set the fields of the object based on the split of the vector
    this->setCustomerID(first_half_vector[0]);
    this->setMovieGenre(first_half_vector[2][0]);
    this->setMediaType(first_half_vector[1][0]);
    this->setTransactionType(transactionType);
    
    switch (this->getMovieGenre()) {
        case 'F':
        {
            //title then year
            
	    // split the vector based on commas because we dont want t
            //o add the commas to the fields
            std::vector<std::string> second_half_vector =
            Helper_Functions:: string_split(second_half_string,',');
		
	    // in the data4movies.txt file, comedy movies end
            //with the name of the title and year released
            this->setMovieTitle(second_half_vector[0]);
            this->setMovieYear(second_half_vector[1]);
           // std::cout << "funny Movie" << std::endl;
            break;
        }
        case 'D':
        {
            //delimited by comas
            //director, title
            // split the vector based on commas because we
            //dont want to add the commas to the fields
            std::vector<std::string> second_half_vector =
            Helper_Functions:: string_split(second_half_string,',');
		
             // in the data4movies.txt file, comedy movies
            //end with the name of the title and director
            this->setMovieTitle(second_half_vector[1].
                                substr(1,second_half_string[1]));
            this->setMovieDirector(second_half_vector[0]);
            
            break;
        }
            
        case 'C':
        {
	    // split the vector based on commas because we dont
            //want to add the commas to the fields
            std::vector<std::string> second_half_vector =
            Helper_Functions:: string_split(second_half_string,' ');
            //classics re split by white space with month,
            //year, firstname, lastname
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

