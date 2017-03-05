//
//  comedy.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "comedy.hpp"



bool Comedy::operator==(const Movie &rhs) const{
    return getTitle() == rhs.getTitle();
};
bool Comedy::operator!=(const Movie &rhs) const{
    return !(*this == rhs);
};
bool Comedy::operator<(const Movie &rhs) const{
    //-	comedy movies (‘F’) sorted by Title, then Year it released

    return (getTitle() < rhs.getTitle() ) && ( getYear() < rhs.getYear() );
};
bool Comedy::operator>(const Movie &rhs) const{
    return (getTitle() > rhs.getTitle() ) && ( getYear() > rhs.getYear() );
};
bool Comedy::operator<=(const Movie &rhs) const
{
    return (getTitle() <= rhs.getTitle() ) && ( getYear() <= rhs.getYear() );
};
bool Comedy::operator>=(const Movie &rhs) const{
    return (getTitle() >= rhs.getTitle() ) && ( getYear() >= rhs.getYear() );
};
