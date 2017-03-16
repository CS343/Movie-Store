//
//  classic.hpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef CLASSIC_H
#define CLASSIC_H

#include <stdio.h>

#include "movie.h"
#include "helper_functions.h"

class Classic: public Movie {
public:

    Classic();
    ~Classic(){};
    //Comparison operator over loades
    //these operators are coded to specificas that are required
    bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;
    

   //set the major actor
    void setMajorActorFirst(std::string);
    //get the major actors first name
    
    std::string getMajorActorFirst() const;
    //set the major actors lastName
    void setMajorActorLast(std::string);
    //get the major actions lastname
    std::string getMajorActorLast() const;
    //set the released month of the current calssic movie
    void setReleaseMonth(int month);
    //get the released month for classic movie
    int getReleaseMonth() const;
    //returns a combination of the actors first name
    //and the actors lastname with a space between them.
    std::string getMajorActor() const;
     //set the major actor given first and lastname
    void setMajorActor(std::string firstName, std::string lastName);
    
    void addMajorActor(std::string actor);
    //add major actor to the major actors list, mane classica have more than 1
    //major actor
    void addMajorActorToList(std::string majorActorName);

    //make movie
    void makeMovie(std::vector<std::string>);
    bool hasMajorActor(std::string) const;
    
    
    void setMajorActor(std::string actor);
private:
    int release_month;
    std::vector<std::string> list_major_actors;
    
    std::string major_actor;
    
    
    
    
    std::string major_actor_firstName;
    std::string major_actor_lastName;
    
    //int release_month;
    
};
#endif /* CLASSIC_H */
