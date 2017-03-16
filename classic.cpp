//
//  classic.cpp
//  movie Store
//NOTE SOMETHING WRONG WITH Comparsion for Classics, we do not compare by actor just date
//and confused about actor how do we get an actor
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "classic.h"
/*==============================< Function NAME >==========================
||	Function Desction:
||		-  Default constructor
||
||	Precondition:
||		- None
||		-
||
||	PostCondition:
||		- Classic Movie is instantiated
||		-
||	Assumptions:
||		-
++===========================================================================*/


Classic::Classic(){
    
   // std::cout << "Classic constr called" << std::endl;
}


/*==============================< Function NAME >==========================
||	Function Desction:
||		-  Opoerator < overloader using the required sorting attributes 
||
||	Precondition:
||		- The movie class has to have exposure to the specific operator over
||   loaded method.
||	PostCondition:
||		- returns true regarding wether this is less than RHS
||		-
||	Assumptions:
||		- NONE
++===========================================================================*/
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
    //return (this->getYear() < rhs.getYear()) && ( this->getReleaseMonth() < rhs.getReleaseMonth() ) && (this->getMajorActor() < rhs.getMajorActor());
    return false;
};
/*==============================< Function NAME >==========================
||	Function Desction:
||		-  Operator > check if this is greater than rhs
||
||	Precondition:
||		- None
||
||	PostCondition:
||		- Returns true of this is greater than rhs
||		-
||	Assumptions:
||		- None
++===========================================================================*/
bool Classic::operator>(const Movie &rhs) const{
   // std::cout << "get release month is : " << getReleaseMonth() << " VS " << rhs.getReleaseMonth() << std::endl;
    //  std::cout << "< called from Classic" << std::endl;
    //-	Classics (‘D’) are sorted by Director, then Title
    if(this->getYear() > rhs.getYear()){
        return true;
    }else if(this->getYear() == rhs.getYear()){
     //checks of the relkeased months are the same 
        if(this->getReleaseMonth() > rhs.getReleaseMonth()){
            return true;
        }
    }else{
        return false;
    }
    //return (this->getYear() < rhs.getYear()) && ( this->getReleaseMonth() < rhs.getReleaseMonth() ) && (this->getMajorActor() < rhs.getMajorActor());
    return false;
    
   // return (this->getYear() > rhs.getYear()) && ( this->getReleaseMonth() > rhs.getReleaseMonth() ) && (this->getMajorActor() > rhs.getMajorActor());
    
};
/*==============================< Function NAME >==========================
||	Function Desction:
||		-  Operator == to tell wether two objecsta are the same
||
||	Precondition:
||		-
||		-
||
||	PostCondition:
||		-
||		-
||	Assumptions:
||		-
++===========================================================================*/
bool Classic::operator==(const Movie &rhs) const{
    //released date then major actor
   // std::cout << "comparing : " << getMajorActor() << "with other major actor: " << rhs.getMajorActor() << std::endl;
    //since this is calssic i need some way to ask Movie RHS if one of these major actors are what you seek.
    
    
    
    return (this->getYear() == rhs.getYear()) && ( this->getReleaseMonth() == rhs.getReleaseMonth() )  && (this->hasMajorActor(rhs.getMajorActor()));
    
};
/*==============================< makeTransaction >==========================
||	Function Desction:
||		- This function intakes a string and a character type
||
||	Precondition:
||		-
||		-
||
||	PostCondition:
||		-
||		-
||	Assumptions:
||		-
++===========================================================================*/

bool Classic::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};




void Classic::setMajorActorFirst(std::string firstName){
    this->major_actor_firstName = firstName;
};
std::string Classic::getMajorActorFirst() const{
    return this->major_actor_firstName;
};
void Classic::setMajorActorLast(std::string lastName){
    this->major_actor_lastName = lastName;
};
/*==============================< makeTransaction >==========================
||	Function Desction:
||		- This function intakes a string and a character type
||
||	Precondition:
||		-
||		-
||
||	PostCondition:
||		-
||		-
||	Assumptions:
||		-
++===========================================================================*/

std::string Classic::getMajorActorLast() const{
    return this->major_actor_lastName;
};

void Classic::setReleaseMonth(int month){
    this->release_month =month;
}

int Classic::getReleaseMonth() const{
    return this->release_month;
}

std::string Classic::getMajorActor() const{
    
    return getMajorActorFirst() + " " + getMajorActorLast();
}


void Classic::addMajorActorToList(std::string majorActorName){
    if(!(std::find(list_major_actors.begin(), list_major_actors.end(), majorActorName) != list_major_actors.end())) {
        /* actor not contain inside x */
        list_major_actors.push_back(majorActorName);
    }
}
  

/*
 Given an vector/array of data, populate the current movie object with its respective elements
 
 */

/*==============================< makeTransaction >==========================
||	Function Desction:
||		- This function intakes a string and a character type
||
||	Precondition:
||		-
||		-
||
||	PostCondition:
||		-
||		-
||	Assumptions:
||		-
++===========================================================================*/
void Classic::setMajorActor(std::string firstName, std::string lastName){
    this->major_actor_firstName = firstName;
    this->major_actor_lastName = lastName;
}

void Classic::makeMovie(std::vector<std::string> array){
    
    std::vector<std::string> extra_classic_data = Helper_Functions::string_split(array[4], ' ');
    
   // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    int year = atoi(extra_classic_data[4].c_str());
    int stock = atoi(array[1].c_str());
    int releaseMonth = atoi(extra_classic_data[3].c_str());
    this->setYear(year);
    this->setDirector(array[2].substr(1,array[2].size()));
    this->setTitle(array[3].substr(1,array[3].size()));
    this->setStock(stock);
    this->setMajorActorFirst(extra_classic_data[1]);
    this->setMajorActorLast(extra_classic_data[2]);
    this->setReleaseMonth(releaseMonth);
    addMajorActorToList(extra_classic_data[1] + " " +extra_classic_data[2]);
}

bool Classic::hasMajorActor(std::string actor) const{
    
    for(int i = 0; i < list_major_actors.size(); i++){
        if(list_major_actors[i] == actor){
            return true;
        }
    }
    return false;
}


/*==============================< makeTransaction >==========================
||	Function Desction:
||		- This function intakes a string and a character type
||
||	Precondition:
||		-
||		-
||
||	PostCondition:
||		-
||		-
||	Assumptions:
||		-
++===========================================================================*/

//output operator work around, flow transition.
void Classic::print(std::ostream& output) const{
        output << getYear() << " " << getTitle() << " " << getDirector() << " " << getStock();
    //output <<"Year: " << " " << getYear() << "  Title: " << getTitle() << "   " << "Director: " << getDirector() << "   " <<"STOCK: " << getStock() <<  "   Major Actor: " << getMajorActor() << "   Get month: " << getReleaseMonth();
    
}
