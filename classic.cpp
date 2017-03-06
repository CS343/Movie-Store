//
//  classic.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "classic.h"
Classic::Classic(){
    
   // std::cout << "Classic constr called" << std::endl;
}



bool Classic::operator<(const Movie &rhs) const{
  //  std::cout << "< called from Classic" << std::endl;
    //-	Classics (‘D’) are sorted by Director, then Title
    
    return (this->getYear() < rhs.getYear()) && ( this->getReleaseMonth() < rhs.getReleaseMonth() ) && (this->getMajorActor() < rhs.getMajorActor());
    
};

bool Classic::operator>(const Movie &rhs) const{
    return (this->getYear() > rhs.getYear()) && ( this->getReleaseMonth() > rhs.getReleaseMonth() ) && (this->getMajorActor() > rhs.getMajorActor());
    
};

bool Classic::operator>=(const Movie &rhs) const{
    return (this->getYear() >= rhs.getYear()) && ( this->getReleaseMonth() >= rhs.getReleaseMonth() ) && (this->getMajorActor() >= rhs.getMajorActor());
    
};

bool Classic::operator<=(const Movie &rhs) const{
    return (this->getYear() <= rhs.getYear()) && ( this->getReleaseMonth() <= rhs.getReleaseMonth() ) && (this->getMajorActor() <= rhs.getMajorActor());
    
};

bool Classic::operator==(const Movie &rhs) const{
    return (this->getYear() == rhs.getYear()) && ( this->getReleaseMonth() == rhs.getReleaseMonth() ) && (this->getMajorActor() == rhs.getMajorActor());
    
};

bool Classic::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};


/*
 
 
bool Classic::operator<(const Classic &rhs) const{
    std::cout << "< called from Classic" << std::endl;
    //-	Classics (‘D’) are sorted by Director, then Title
    
    return (this->getYear() < rhs.getYear()) && ( this->getReleaseMonth() < rhs.getReleaseMonth() ) && (this->getMajorActor() < rhs.getMajorActor());
    
};

bool Classic::operator>(const Classic &rhs) const{
    return (this->getYear() > rhs.getYear()) && ( this->getReleaseMonth() > rhs.getReleaseMonth() ) && (this->getMajorActor() > rhs.getMajorActor());
    
};

bool Classic::operator>=(const Classic &rhs) const{
    return (this->getYear() >= rhs.getYear()) && ( this->getReleaseMonth() >= rhs.getReleaseMonth() ) && (this->getMajorActor() >= rhs.getMajorActor());
    
};

bool Classic::operator<=(const Classic &rhs) const{
    return (this->getYear() <= rhs.getYear()) && ( this->getReleaseMonth() <= rhs.getReleaseMonth() ) && (this->getMajorActor() <= rhs.getMajorActor());
    
};

bool Classic::operator==(const Classic &rhs) const{
    return (this->getYear() == rhs.getYear()) && ( this->getReleaseMonth() == rhs.getReleaseMonth() ) && (this->getMajorActor() == rhs.getMajorActor());
    
};

bool Classic::operator!=(const Classic &rhs) const{
    return !(*this == rhs);
};

 
 */

void Classic::setMajorActorFirst(std::string firstName){
    this->major_actor_firstName = firstName;
};
std::string Classic::getMajorActorFirst() const{
    return this->major_actor_firstName;
};
void Classic::setMajorActorLast(std::string lastName){
    this->major_actor_lastName = lastName;
};

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
/*
 Given an vector/array of data, populate the current movie object with its respective elements
 
 */
void Classic::makeMovie(std::vector<std::string> array){
    
    std::vector<std::string> extra_classic_data = Helper_Functions::string_split(array[4], ' ');
    
   // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    int year = atoi(extra_classic_data[4].c_str());
    int stock = atoi(array[1].c_str());
    
    this->setYear(year);
    this->setDirector(array[2]);
    this->setTitle(array[3]);
    this->setStock(stock);
    this->setMajorActorFirst(extra_classic_data[1]);
    this->setMajorActorLast(extra_classic_data[2]);
}

//output operator work around, flow transition.
void Classic::print(std::ostream& output) const{
        output << getYear() << " " << getTitle() << " " << getDirector() << " " << getStock();
    //output <<"Year: " << " " << getYear() << "  Title: " << getTitle() << "   " << "Director: " << getDirector() << "   " <<"STOCK: " << getStock() <<  "   Major Actor: " << getMajorActor() << "   Get month: " << getReleaseMonth();
    
}