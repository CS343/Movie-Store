//
//  movie.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include <stdio.h>
#include "movie.h"



bool Movie::compare(const Movie &rhs){
    if(getYear ()== rhs.getYear() && getTitle() == rhs.getTitle()){
        return true;
    }
    else{
        return false;
    }
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
Movie::Movie(){
    //std::cout << "Movie Consturctor called"<< std::endl;
    title = "";
    director = "";
    year = 0;
    max_stock = 10;
    current_stock = 10;
}
/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
Movie::~Movie(){}

bool Movie::removeStock(int amount){
    if((current_stock - amount) >= 0){
        current_stock-=amount;
        return true;
    }else{
        return false;
    }
};

bool Movie::addStock(int amount){
    if( (current_stock + amount) <= max_stock){
        current_stock+=amount;
        return true;
    }else{
        return false;
    }
};

bool Movie::setNewStock(int amount){
    max_stock += amount;
    return true;
};

int Movie::getYear() const{
    return this->year;
};
void Movie::setYear(int year){
    this->year = year;
};
std::string Movie::getDirector() const{
    return this->director;
};
void Movie::setDirector(std::string director){
    this->director = director;
};
std::string Movie::getTitle() const{
    return this->title;
};
void Movie::setTitle(std::string title){
     this->title = title;
};

int Movie::getStock() const{
    return this->current_stock;
};

void Movie::setStock(int stock){
    this->max_stock = stock;
    this->current_stock = stock;
};

std::string Movie::getMajorActor() const{
    return "";
};
int Movie::getReleaseMonth() const{
    return 0;
};

void Movie::addMajorActorToList(std::string) {
    // rely on classic.cpp overloaded function
}

std::ostream& operator<<(std::ostream &output, const Movie &rhs){
   // rhs.print();
    rhs.print(output);
    return output;
};

