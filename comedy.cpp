//
//  comedy.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "comedy.h"

Comedy::Comedy(){
    
    std::cout << "comedy constr called" << std::endl;
}

bool Comedy::operator<(const Movie &rhs) const{
    std::cout << "< called from COmedy" << std::endl;
    return (this->getTitle() < rhs.getTitle()) && (this->getYear() < rhs.getYear());

};

bool Comedy::operator>(const Movie &rhs) const{
    return (this->getTitle() > rhs.getTitle()) && (this->getYear() > rhs.getYear());
};

bool Comedy::operator>=(const Movie &rhs) const{
    return (this->getTitle() >= rhs.getTitle()) && (this->getYear() >= rhs.getYear());
};

bool Comedy::operator<=(const Movie &rhs) const{
    return (this->getTitle() <= rhs.getTitle()) && (this->getYear() <= rhs.getYear());
};

bool Comedy::operator==(const Movie &rhs) const{
    return (this->getTitle() == rhs.getTitle()) && (this->getYear() == rhs.getYear());
};

bool Comedy::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};

void Comedy::makeMovie(std::vector<std::string> array){
    std::cout << "Make Movie for Comed called" << std::endl;
}

//output operator work around, flow transition.
void Comedy::print(std::ostream& output) const{
    output << "Title: " << getTitle() << "\t" << "Year: " << getYear() << std::setw(10) <<"STOCK: " << getStock();
    
}

