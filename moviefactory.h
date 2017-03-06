//
//  moviefactory.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef moviefactory_hpp
#define moviefactory_hpp
#include "movie.h"
#include <stdio.h>
#include "comedy.h"
#include "classic.h"
#include "drama.h"
class Movie_Factory{
public:
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
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    static Movie* make_movie(char choice);
};
#endif /* moviefactory_hpp */
