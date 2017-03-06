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
#include "helper_functions.h"

class Classic: public Movie{
public:
    
    Classic();
    ~Classic() {};
    bool operator==(const Classic &) const;
    bool operator!=(const Classic &) const;
    bool operator<(const Classic &) const;
    bool operator>(const Classic &) const;
    bool operator<=(const Classic &) const;
    bool operator>=(const Classic &) const;
    void print(std::ostream &) const;
    void setMajorActorFirst(std::string);
    std::string getMajorActorFirst() const;
    
    void setMajorActorLast(std::string);
    
    std::string getMajorActorLast() const;
    
    void setReleaseMonth(int month);
    
    int getReleaseMonth() const;
    
    std::string getMajorActor() const;
    
    
    
    void makeMovie(std::vector<std::string>);
private:
    std::string major_actor_firstName;
    std::string major_actor_lastName;
    
    int release_month;

    
    
};
#endif /* classic_hpp */
