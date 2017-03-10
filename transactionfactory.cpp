//
//  transactionfactory.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "transactionfactory.h"

Transaction* TransactionFactory::makeTransaction(std::ifstream &input, char command){
    Transaction *transactionPtr;
    std::string result;
    
    

    std::getline(input, result);
    //std::string ayyo = result.substr(1, 5);// gets the ID[a,b)
    std::string ayyo1 = result.substr(1,10);//get the first half, if the last
    std::string ayoo2 = result;
    //index contains a number good we have quantity, if not, bad we have default to
    //borrowing 1 quntity.
    
    std::vector<std::string> first_half = Helper_Functions::string_split(ayyo1, ' ');
    
    switch (command) {
        case 'B':
        {
    
            transactionPtr = new Borrow();
            /* new */
            
            //give it the resulting string, and teh genre
            //within the method it will do all the splitting depedent on
            //what genere is specified.
            //transactionPtr->makeTransaction(result, command);
            break;
        }
            
        case 'R':
            transactionPtr = new Return();
            break;
            
        case 'H':
            transactionPtr = new History();
            break;
        case 'I':
            transactionPtr = new ViewInventory();
            break;
            
        default:
            break;
    }
    
    
    transactionPtr->makeTransaction(result, command);
    //std::cout << std::endl;
    //transactionPtr->doTransaction();
    return transactionPtr;
    
    //return NULL;
    
}

