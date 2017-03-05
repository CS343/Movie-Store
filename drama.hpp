//
//  drama.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef drama_hpp
#define drama_hpp

#include <stdio.h>
#include "movie.h"

class Drama: public Movie{
    
public:
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;
};
#endif /* drama_hpp */
