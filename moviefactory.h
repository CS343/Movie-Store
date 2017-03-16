//
//  moviefactory.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "movie.h"
#include <stdio.h>

#include "comedy.h"
#include "classic.h"
#include "drama.h"

class Movie_Factory{
public:
    //make a movied based off the char command and
    //return that movie pointer to the caller
    static Movie* make_movie(char choice);
};
#endif /* MOVIE_FACTORY_H */
