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
class Comedy: public Movie{
    
    
public:
    
     bool operator==(const Movie &) const;
     bool operator!=(const Movie &) const;
     bool operator<(const Movie &) const;
     bool operator>(const Movie &) const;
     bool operator<=(const Movie &) const;
     bool operator>=(const Movie &) const;
    
};
#endif /* comedy_hpp */
