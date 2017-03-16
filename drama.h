//
//  drama.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef DRAMA_H
#define DRAMA_H

#include <stdio.h>
#include "movie.h"

class Drama:public Movie{
    
public:
    //default constructor
    
    Drama();
    //default destructor
    ~Drama() {};
    //operator overloader to conpare the objects
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    

    //make movie called to make the current drama object
    void makeMovie(std::vector<std::string>);
};
#endif /* DRAMA_H */
