//
//  comedy.cpp
//  movie Store
//
//  Created by Danny  and bardia borhaniLy on 3/5/17.
//  Copyright © 2017 Danny Ly. and Bardia Borhani All rights reserved.
//
/*
 
 COMEDYS IS KEY STROKE F
 */
#include "comedy.h"
/*==============================< FUNCTION NAME >==============================
||	Function description: This default constructor
||
||	Precondition:
||		- None
||
||	Postcondition:
||		-  Comedy object is constructed
||		-
||	Assumptions:
|| - None
++===========================================================================*/
Comedy::Comedy(){};
/*==============================< FUNCTION NAME >==============================
||	Function description: Operator overload of <, given the sorting attributes
||
||	Precondition:
||		- None
||
||	Postcondition:
||		- Returns true of this is less than RHS 
||		-
||	Assumptions:
|| - None
++===========================================================================*/
bool Comedy::operator<(const Movie &rhs) const{
    //std::cout << "< called from COmedy" << std::endl;
    if(this->getTitle() < rhs.getTitle()){
        return true;
    }else if (this->getTitle() == rhs.getTitle()){
        if(this->getYear() < rhs.getYear()){
            return true;
        }
    }else{
        return false;
    }
    //return ( this->getTitle() < rhs.getTitle()) && (this->getYear() < rhs.getYear());
    return true;
};
/*==============================< FUNCTION NAME >==============================
||	Function description: Operator > overload with the specifics
|| Given a title and year detingisuh which is greater
||	Precondition:
||		- None
||
||	Postcondition:
||		- return true of this is greater than rhs false otherwise
||		-
||	Assumptions:
|| - None
++===========================================================================*/
bool Comedy::operator>(const Movie &rhs) const{
    if(this->getTitle() > rhs.getTitle()){
        return true;
    }else if (this->getTitle() == rhs.getTitle()){
        if(this->getYear() > rhs.getYear()){
            return true;
        }
    }else{
        return false;
    }
    //return ( this->getTitle() < rhs.getTitle()) && (this->getYear() < rhs.getYear());
    return true;
    //return (this->getTitle() > rhs.getTitle()) && (this->getYear() > rhs.getYear());
};

/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - check weither this and rhs are equal
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns true if both objects are equal false otherwise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++============================================================================*/


bool Comedy::operator==(const Movie &rhs) const{
    return ( (this->getTitle() == rhs.getTitle() ) && (this->getYear() == rhs.getYear()) );
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - if objects are not the same, given title and released year
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - None
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++============================================================================*/

bool Comedy::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};
/*
 Given an vector/array of data, populate the current movie object with its respective elements
 
 */
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - This is a polymorphic method that is called to makes the object
 ||     given the string array of data, the data which contains data
 ||
 ||   Preconditions:
 ||      - the array given has already been split with title director
 ||     year and stock
 ||      -
 ||   Postconditions:
 ||      - this object is popualted correctly
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++============================================================================*/

void Comedy::makeMovie(std::vector<std::string> array){
   // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    //conver the string to int
    int year = atoi(array[4].c_str());
    //convert this string stock to int
    int stock = atoi(array[1].c_str());
    //set the data attributes of the comedy class
    this->setYear(year);
    this->setDirector(array[2].substr(1, array[3].size()));
    this->setTitle(array[3].substr(1,array[3].size()));
    this->setStock(stock);
    
};




