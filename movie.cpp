//
//  movie.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include <stdio.h>
#include "movie.h"

Movie::Movie(){
    std::cout << "Movie Consturctor called"<< std::endl;
    title = "";
    director = "";
    year = 0000;
    stock = 10;
}
Movie::~Movie(){
    
}

int Movie::getYear() const{
    return this->year;
}
void Movie::setYear(int year){
    this->year = year;
}
string Movie::getDirector() const{
    return this->director;
}
void Movie::setDirector(string director){
    this->director = director;
}
string Movie::getTitle() const{
    return this->title;
}
void Movie::setTitle(string title){
    this->title = title;
}

int Movie::getStock() const{
    return this->stock;
}
void Movie::setStock(int stock){
    this->stock = stock;
}
void Movie::addStock(int amount){
    this->stock += amount;
}


std::ostream& operator<<(std::ostream &output, const Movie &rhs){
   // rhs.print();
    //output <<"HELLO FRIOM MOVIE";
    rhs.print(output);
    return output;
}

/*

//------------------------- operator==,!= ------------------------------------
bool Movie::operator==(const Movie& rhs) const {
    return getTitle() == rhs.getTitle();
}

bool Movie::operator!=(const Movie& rhs) const {
    return getTitle() != rhs.getTitle();
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool Movie::operator<(const Movie& rhs) const {
    std::cout << "PUTA SMIT" << std::endl;
    return getTitle() < rhs.getTitle();
}

bool Movie::operator>(const Movie& rhs) const {
    return getTitle() > rhs.getTitle();
}

bool Movie::operator<=(const Movie& rhs) const {
    return getTitle() <= rhs.getTitle();
}

bool Movie::operator>=(const Movie& rhs) const {
    return getTitle() >= rhs.getTitle();
}
*/
