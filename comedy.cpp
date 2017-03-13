//
//  comedy.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//
/*
 
 COMEDYS IS KEY STROKE F
 */
#include "comedy.h"

Comedy::Comedy(){};

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



bool Comedy::operator==(const Movie &rhs) const{
    return ( (this->getTitle() == rhs.getTitle() ) && (this->getYear() == rhs.getYear()) );
};

bool Comedy::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};
/*
 Given an vector/array of data, populate the current movie object with its respective elements
 
 */
void Comedy::makeMovie(std::vector<std::string> array){
   // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    int year = atoi(array[4].c_str());
    int stock = atoi(array[1].c_str());
    this->setYear(year);
    this->setDirector(array[2]);
    this->setTitle(array[3]);
    this->setStock(stock);
    
};

//output operator work around, flow transition.
void Comedy::print(std::ostream& output) const{
    output << getYear() << " " << getTitle() << " " << getDirector() << " " << getStock();
    //output <<"Year: " << "   " << getYear() << "Title: " << getTitle() << "   " << "Director: " << getDirector() << "   " <<"STOCK: " << getStock();
    
};

