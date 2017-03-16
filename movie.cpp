//
//  movie.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - movie  abstract class
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
 ++===========================================================================*/

#include <stdio.h>
#include "movie.h"
#include<iomanip>
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - compare two movies to see if they are the same
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns true if they are the same false otherwise
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/


bool Movie::compare(const Movie &rhs){
    if(getYear ()== rhs.getYear() && getTitle() == rhs.getTitle()){
        return true;
    }
    else{
        return false;
    }
}
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - default constructor movie
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
 ++===========================================================================*/

Movie::Movie(){
    //std::cout << "Movie Consturctor called"<< std::endl;
    title = "";
    director = "";
    year = 0;
    max_stock = 10;
    current_stock = 10;
}
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - destructor of the movie
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
 ++===========================================================================*/

Movie::~Movie(){}
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - removes teh stock from the current movie (-1) stock, cehcks to make
 ||     sure you do not over borrow
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - stock is removed,
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Movie::removeStock(int amount){
    if((current_stock - amount) >= 0){
        current_stock-=amount;
        return true;
    }else{
        std::cout << "ERROR Out of Stock: " << getTitle() << std::endl;
        return false;
    }
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - add stock to the current movie (+1) , and checks to make sure
 ||     we do not add more than our capacity of stock.
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - stock is added to the current movie
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Movie::addStock(int amount){
    if( (current_stock + amount) <= max_stock){
        current_stock+=amount;
        return true;
    }else{
        std::cout << "ERROR Reached Max_capacity of Stock: "
        << getTitle() << std::endl;
        return false;
    }
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - set a new max capacity of the stock
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - capcity is changed
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

bool Movie::setNewStock(int amount){
    max_stock += amount;
    return true;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - get the current movie year
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns an interger of the movie current year
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

int Movie::getYear() const{
    return this->year;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - set the current movie year
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
 ++===========================================================================*/

void Movie::setYear(int year){
    this->year = year;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - get the director of this movie
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns a string of the current movie director
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

std::string Movie::getDirector() const{
    return this->director;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - set director
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
 ++===========================================================================*/

void Movie::setDirector(std::string director){
    this->director = director;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      -
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
 ++===========================================================================*/

std::string Movie::getTitle() const{
    return this->title;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - set the current movie title
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
 ++===========================================================================*/

void Movie::setTitle(std::string title){
     this->title = title;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - get the current movie stock amount
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
 ++===========================================================================*/

int Movie::getStock() const{
    return this->current_stock;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - set the stock max and the current stock , used to initalize the 
 ||     Movie stock
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
 ++===========================================================================*/

void Movie::setStock(int stock){
    this->max_stock = stock;
    this->current_stock = stock;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - get the major actor this is a virtual function.
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
 ++===========================================================================*/

std::string Movie::getMajorActor() const{
    return "";
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - get released Month a virtual method
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns the integer of the month released
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

int Movie::getReleaseMonth() const{
    return 0;
};
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - add a major actor to the major actors array list
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
 ++===========================================================================*/

void Movie::addMajorActorToList(std::string) {
    // rely on classic.cpp overloaded function
}
/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - operator output for when displaying the movie showing the title
 ||     and the current stock amount
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
 ++===========================================================================*/

std::ostream& operator<<(std::ostream &output, const Movie &rhs){
   // rhs.print();
    output << "  " <<std::left <<std::setw(38)<< rhs.getTitle()
    <<std::right << std::setw(3) << rhs.getStock();
    //rhs.print(output);
    return output;
};

