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
    return true;
};
bool Comedy::operator>(const Movie &rhs) const{
    return true;
};
bool Comedy::operator>=(const Movie &rhs) const{
    return true;
};
bool Comedy::operator<=(const Movie &rhs) const{
    return true;
};
bool Comedy::operator!=(const Movie &rhs) const{
    return true;
};

bool Comedy::operator==(const Movie &rhs) const{
    return true;
};
void Comedy::print(std::ostream& output) const{
    output << "Title: " << getTitle() << "\t" << "Year: " << getYear();
    
}

