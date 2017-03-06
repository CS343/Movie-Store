//
//  drama.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "drama.h"

Drama::Drama(){
    
   // std::cout << "Drama constr called" << std::endl;
}

bool Drama::operator<(const Movie &rhs) const{
   // std::cout << "< called from Drama" << std::endl;
    //-	dramas (‘D’) are sorted by Director, then Title

    return (this->getDirector() < rhs.getDirector()) && (this->getTitle() < rhs.getTitle());
    
};

bool Drama::operator>(const Movie &rhs) const{
    return (this->getDirector() > rhs.getDirector()) && (this->getTitle() > rhs.getTitle());
};

bool Drama::operator>=(const Movie &rhs) const{
    return (this->getDirector() >= rhs.getDirector()) && (this->getTitle() >= rhs.getTitle());
};

bool Drama::operator<=(const Movie &rhs) const{
    return (this->getDirector() <= rhs.getDirector()) && (this->getTitle() <= rhs.getTitle());
};

bool Drama::operator==(const Movie &rhs) const{
    return (this->getDirector() == rhs.getDirector()) && (this->getTitle() == rhs.getTitle());
};

bool Drama::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};
/*
 Given an vector/array of data, populate the current movie object with its respective elements
 
 */
void Drama::makeMovie(std::vector<std::string> array){
   // std::cout << "Make Movie for Comed called" << std::endl;
    //index 0: command | 1: qutity | 2:Director | 3: Title |4: actor and year
    int year = atoi(array[4].c_str());
    int stock = atoi(array[1].c_str());
    this->setYear(year);
    this->setDirector(array[2]);
    this->setTitle(array[3]);
    this->setStock(stock);
    
}

//output operator work around, flow transition.
void Drama::print(std::ostream& output) const{
        output << getYear() << " " << getTitle() << " " << getDirector() << " " << getStock();
    //output <<"Year: " << "   "<< getYear() << "Title: " << getTitle() << "   " << "Director: " << getDirector() << "   " <<"STOCK: " << getStock();
    
}