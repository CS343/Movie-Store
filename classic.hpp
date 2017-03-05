//
//  classic.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef classic_hpp
#define classic_hpp

#include <stdio.h>
#include "movie.h"

class Classic : public Movie {
    //friend ostream& operator<<(ostream &output, const Movie &movie);

public:
    //bool setData(istream&);
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;
};
#endif /* classic_hpp */
