//
//  movie.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include <stdio.h>
#include "movie.h"


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
