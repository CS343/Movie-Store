//
//  helper_functions.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny and Bardia Borhani Ly. All rights reserved.
//

#include "helper_functions.h"

/*==========================< FUNCTION NAME >=================================
 ||
 ||   Function_Description:
 ||      - HELPER FUNCTIOON to split a specific string by the given delimiter
 ||     once split the returned item is given inside a vector of strings
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - returns a vector of the split string, given the delimiter
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++===========================================================================*/

std::vector<std::string> Helper_Functions::string_split(std::string s, const char delimiter)
{
    size_t start=0;
    //find the delimiter in the string, the first delimiter
    size_t end=s.find_first_of(delimiter);
    
    //make the return vector
    std::vector<std::string> output;
    
    while (end <= std::string::npos)
    {
        //comb through the string and check each sub string that
        //uses the delimiter
        output.emplace_back(s.substr(start, end-start));
        
        if (end == std::string::npos)
            break;
        
        start=end+1;
        end = s.find_first_of(delimiter, start);
    }
    
    return output;
}
