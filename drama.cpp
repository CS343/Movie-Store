//
//  drama.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "drama.h"

/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - Default constructor
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - Initalizes the object
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/


Drama::Drama(){};



/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - Operator < to tell if this drama is less than RHS, given the 
 ||     director and title
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - Return true if this is less than RHS object
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Drama::operator<(const Movie &rhs) const{
   // std::cout << "< called from Drama" << std::endl;
    //-	dramas (‘D’) are sorted by Director, then Title
    
    if(getDirector() != rhs.getDirector()){
        return getDirector() < rhs.getDirector();
    }else{
        return getTitle() < rhs.getTitle();
    }

};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - Operator > overload to see if this is greater than RHS, given
 ||     the director and title
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - Returns true if this is greater than RHS
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Drama::operator>(const Movie &rhs) const{
    // std::cout << "< called from Drama" << std::endl;
    //-	dramas (‘D’) are sorted by Director, then Title
    if(getDirector() != rhs.getDirector()){
        return getDirector() > rhs.getDirector();
    }else{
        return getTitle() > rhs.getTitle();
    }

};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - checks wether two drama objects are the same,
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - Returns true if the two ovjects are the same false otherwise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Drama::operator==(const Movie &rhs) const{
    return (this->getDirector() == rhs.getDirector()) && (this->getTitle()
                                                          == rhs.getTitle());
    /* && (this->getYear() == rhs.getYear()*/
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - check wether two objects are not the same
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - If the objects are different returns true false other wise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Drama::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};
/*
 Given an vector/array of data, populate the current movie object with i
 ts respective elements
 
 */
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - polymophic method that is called to populate the current object
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - The current movie is drama is constructed, because the objects are 
 ||     different attributes, they will split differently
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

void Drama::makeMovie(std::vector<std::string> array){
   // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    int year = atoi(array[4].c_str());
    int stock = atoi(array[1].c_str());
    this->setYear(year);
    this->setDirector(array[2].substr(1,array[2].size()));
    this->setTitle(array[3].substr(1,array[3].size()));
    this->setStock(stock);
    
};



