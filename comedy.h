//
//  comedy.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <stdio.h>
#include <iomanip>
#include <vector>

class Comedy : public Movie{
public:
    
    //default constructor
    Comedy();
    //destructor
    ~Comedy(){};
    //operator overload to compare objects for the
    //bin tree
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    //use to make the movie/comedy populate the movie
    void makeMovie(std::vector<std::string>);
};
#endif /* COMEDY_H */
