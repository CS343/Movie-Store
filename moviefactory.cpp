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
 ||       - A make Movie Function that helps make a movie object given the 
 ||         Command
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */

/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
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
