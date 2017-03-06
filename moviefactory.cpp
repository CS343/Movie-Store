//
//  moviefactory.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "moviefactory.h"

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
