//
//  classic.cpp
//  movie Store
//NOTE SOMETHING WRONG WITH Comparsion for Classics, we do not compare
//by actor just date
//and confused about actor how do we get an actor
//  Created by Danny Ly Bardia BorHani on 3/5/17.
//  Copyright © 2017 Danny and Bardia Borhani Ly. All rights reserved.
//

#include "classic.h"
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      -default constructor
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - object is instantiated
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



Classic::Classic(){
    
    // std::cout << "Classic constr called" << std::endl;
}

/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - operator << overloader to check weither this is smaller than RHS
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns true if this is smaller than rhs false otherwise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



bool Classic::operator<(const Movie &rhs) const{
    //  std::cout << "< called from Classic" << std::endl;
    //-	Classics (‘D’) are sorted by Director, then Title
    
    if(this->getYear() < rhs.getYear()){
        return true;
    }else if(this->getYear() == rhs.getYear()){
        if(this->getReleaseMonth() < rhs.getReleaseMonth()){
            return true;
        }
    }else{
        return false;
    }

    return false;
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - operator overload of > to check if this is larger than rhs
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - return true if this is bigger than rhs
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/


bool Classic::operator>(const Movie &rhs) const{
 
    if(this->getYear() > rhs.getYear()){
        return true;
    }else if(this->getYear() == rhs.getYear()){
        if(this->getReleaseMonth() > rhs.getReleaseMonth()){
            return true;
        }
    }else{
        return false;
    }

    return false;
    

    
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - equals operator if the released date and major actors are the same
 ||
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - return true if objecsts are the same false otherwise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



bool Classic::operator==(const Movie &rhs) const{

    
    
    return (this->getYear() == rhs.getYear()) && ( this->getReleaseMonth()
                                                  == rhs.getReleaseMonth() )
    && (this->hasMajorActor(rhs.getMajorActor()));
    
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      -if the objects are not the same
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns true if objects are not the same fase otherwise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/


bool Classic::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};


/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - set the major actor of the current object first name
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - object has first name set
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



void Classic::setMajorActorFirst(std::string firstName){
    this->major_actor_firstName = firstName;
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      -gets the first of the objects major actor
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - major actor first is got
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/


std::string Classic::getMajorActorFirst() const{
    return this->major_actor_firstName;
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      -sets the major actors lastname
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - sets teh major actors lastname
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/


void Classic::setMajorActorLast(std::string lastName){
    this->major_actor_lastName = lastName;
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - get the major actors lastname
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - type string of major actors lastname is returned
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



std::string Classic::getMajorActorLast() const{
    return this->major_actor_lastName;
};
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - set the released month for the object
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



void Classic::setReleaseMonth(int month){
    this->release_month =month;
}
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      -gets the released month of the object
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns an INT
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



int Classic::getReleaseMonth() const{
    return this->release_month;
}
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - get major actor of the object
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - return string of the major actor lastname and first name combined
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/



std::string Classic::getMajorActor() const{
    
    return getMajorActorFirst() + " " + getMajorActorLast();
}
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - add a major actor to the current movie object, given a name check
 ||     wether it already exist, if not push it into the major actor list
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



void Classic::addMajorActorToList(std::string majorActorName){
    if(!(std::find(list_major_actors.begin(), list_major_actors.end(),
                   majorActorName) != list_major_actors.end())) {
        /* actor not contain inside x */
        list_major_actors.push_back(majorActorName);
    }
}


/*
 Given an vector/array of data, populate the current movie object with 
 its respective elements
 
 */

/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - sets the major actor give first and last name
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


void Classic::setMajorActor(std::string firstName, std::string lastName){
    this->major_actor_firstName = firstName;
    this->major_actor_lastName = lastName;
}
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      -Make movie is a polymophism method, that populates the current 
 ||classic
 ||     Movie, because classic movie genere have different ways to distingish
 ||     the movie, it is split differently and the data is distributed to its
 |\     Respective attributes
 ||
 ||   Preconditions:
 ||      - a string that contains the various attributes with white space
 ||     delimited
 ||      -
 ||   Postconditions:
 ||      - this current classic movie object is populated
 ||      -
 ||
 ||   Assumptions:
 ||      - None
++============================================================================*/


void Classic::makeMovie(std::vector<std::string> array){
    
    std::vector<std::string> extra_classic_data =
    Helper_Functions::string_split(array[4], ' ');
    
    // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    //convert the string repersentation of year to int
    int year = atoi(extra_classic_data[4].c_str());
    //convert the stock string repersentation to int
    int stock = atoi(array[1].c_str());
    //convert the string repersentation of month to int
    int releaseMonth = atoi(extra_classic_data[3].c_str());
    //set the released year
    this->setYear(year);
    //set the director
    this->setDirector(array[2].substr(1,array[2].size()));
    //set the title
    this->setTitle(array[3].substr(1,array[3].size()));
    //set the stock
    this->setStock(stock);
    //set the major actor
    this->setMajorActorFirst(extra_classic_data[1]);
    this->setMajorActorLast(extra_classic_data[2]);
    //set the released month
    this->setReleaseMonth(releaseMonth);
    //add a major actor to the actors list
    addMajorActorToList(extra_classic_data[1] + " " +extra_classic_data[2]);
}
/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - A Helper method to check if a actor already exist in the actors
 ||     list
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



bool Classic::hasMajorActor(std::string actor) const{
    
    for(int i = 0; i < list_major_actors.size(); i++){
        if(list_major_actors[i] == actor){
            return true;
        }
    }
    return false;
}



