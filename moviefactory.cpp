//
//  moviefactory.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "moviefactory.h"

/*
+==============================================================================-
 ||
 ||   Function_Description:
 ||       - Movie factory used to return a new movie based off the given 
 ||     commmand char that is presented,
 ||   Preconditions:
 ||       -valid command char , if not the new movie objet will be deallocated
 ||       -
 ||   Postconditions:
 ||      -returns a subclass of movie
 ||       -
 ||
 ||   Assumptions:
 ||       - None
+==============================================================================-
 */
Movie* Movie_Factory::make_movie(char choice){
    Movie *returnPtr;
    switch (choice) {
        case 'F':
            returnPtr = new Comedy();
            break;
        case 'D':
            returnPtr = new Drama();
            break;
        case 'C':
            returnPtr = new Classic();
            break;
        default:
            break;

    }
    return returnPtr;
};
