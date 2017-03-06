//
//  comedy.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef comedy_hpp
#define comedy_hpp
#include "movie.h"
#include <stdio.h>
#include <iomanip>
#include <vector>

class Comedy : public Movie{
public:
    
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    Comedy();
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    ~Comedy(){};
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    void print(std::ostream &) const;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    void makeMovie(std::vector<std::string>);
};
#endif /* comedy_hpp */
