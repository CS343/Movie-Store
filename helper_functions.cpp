//
//  helper_functions.cpp
//  movie Store
//
//  Created by Danny Ly on 3/5/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include "helper_functions.h"


/*
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 #   Function_Description:
 #       -
 #   Preconditions:
 #       -
 #       -
 #   Postconditions:
 #       -
 #       -
 #
 #   Assumptions:
 #       -
 $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
 */
std::vector<std::string> Helper_Functions::string_split(std::string s, const char delimiter)
{
    size_t start=0;
    size_t end=s.find_first_of(delimiter);
    
    std::vector<std::string> output;
    
    while (end <= std::string::npos)
    {
        output.emplace_back(s.substr(start, end-start));
        
        if (end == std::string::npos)
            break;
        
        start=end+1;
        end = s.find_first_of(delimiter, start);
    }
    
    return output;
}
