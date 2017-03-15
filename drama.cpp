//
//  drama.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "drama.h"

Drama::Drama(){};

bool Drama::operator<(const Movie &rhs) const{
   // std::cout << "< called from Drama" << std::endl;
    //-	dramas (‘D’) are sorted by Director, then Title
    
    if(getDirector() != rhs.getDirector()){
        return getDirector() < rhs.getDirector();
    }else{
        return getTitle() < rhs.getTitle();
    }
    /*
    if(this->getDirector() < rhs.getDirector()){
        return true;
    }else if(this->getDirector() == rhs.getDirector()){
        if(this->getTitle() < rhs.getTitle()){
            return true;
        }else{
            return false;
        }
    }
    //return (this->getDirector() < rhs.getDirector()) && (this->getTitle() < rhs.getTitle());
    return true;
     */
};

bool Drama::operator>(const Movie &rhs) const{
    // std::cout << "< called from Drama" << std::endl;
    //-	dramas (‘D’) are sorted by Director, then Title
    if(getDirector() != rhs.getDirector()){
        return getDirector() > rhs.getDirector();
    }else{
        return getTitle() > rhs.getTitle();
    }
    /*
    if(this->getDirector() > rhs.getDirector()){
        return true;
    }else if(this->getDirector() == rhs.getDirector()){
        if(this->getTitle() > rhs.getTitle()){
            return true;
        }else{
            return false;
        }
    }
    //return (this->getDirector() < rhs.getDirector()) && (this->getTitle() < rhs.getTitle());
    return true;
    
    //return (this->getDirector() > rhs.getDirector()) && (this->getTitle() > rhs.getTitle());
     */
};

bool Drama::operator==(const Movie &rhs) const{
    return (this->getDirector() == rhs.getDirector()) && (this->getTitle() == rhs.getTitle());
    /* && (this->getYear() == rhs.getYear()*/
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
    this->setDirector(array[2].substr(1,array[2].size()));
    this->setTitle(array[3].substr(1,array[3].size()));
    this->setStock(stock);
    
};

//output operator work around, flow transition.
void Drama::print(std::ostream& output) const{
    //not sure why i dont just leave this method inside the abstract parent class
        output << getYear() << " " << getTitle() << " " << getDirector() << " " << getStock();
};
