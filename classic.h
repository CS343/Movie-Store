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
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    std::string getMajorActorLast() const;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    void setReleaseMonth(int month);
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    int getReleaseMonth() const;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    std::string getMajorActor() const;
     
    void setMajorActor(std::string firstName, std::string lastName);
    
    void addMajorActor(std::string actor);
    
    void addMajorActorToList(std::string majorActorName);

    
    void makeMovie(std::vector<std::string>);
    bool hasMajorActor(std::string) const;
private:
    int release_month;
    std::vector<std::string> list_major_actors;
    
    std::string major_actor_firstName;
    std::string major_actor_lastName;
    
    //int release_month;
    
};
#endif /* CLASSIC_H */
