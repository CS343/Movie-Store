//
//  transactionfactory.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#include <stdio.h>

#include "transactionfactory.h"

Transaction* TransactionFactory::makeTransaction(std::ifstream &input, char command){
    Transaction *trans;
    std::string result;
    switch (command) {
        case 'B':
        {
            //std::cout << "borrow" << result << std::endl;
            getline(input, result);
            std::string ayyo = result.substr(1, 5);// gets the ID[a,b)
            std::string ayyo1 = result.substr(1,10);//get the first half, if the last
            //index contains a number good we have quantity, if not, bad we have default to
            //borrowing 1 quntity.
            
            std::vector<std::string> first_half = Helper_Functions::string_split(ayyo1, ' ');
            std::cout << first_half[3] << std::endl;
            
            std::cout << "borrow" << result << std::endl;
            std::cout << ayyo1 << std::endl;
            //std::cout << result[1] << std::endl;
            
            trans = new Borrow;
            trans->setCustomerID(first_half[0]);
            
            trans->setTransactionType(command);
            //each string in c++ is a string array of chars
            trans->setMediaType(first_half[1][0]);
            
            
            if(isdigit(first_half[3][0])){
                int amt = std::atoi(first_half[3].c_str());
                std::cout << "we have a digit: " << amt<< std::endl;
                trans->setTransactionAmount(amt);
            }else{
                trans->setTransactionAmount(1);
                std::cout << "we have a alpha: " << first_half[3][0] << std::endl;
            }
            
            break;
        }
        case 'R':
            getline(input, result);
            std::cout << "RENT" << result << std::endl;
            break;
            
        case 'H':
            getline(input, result);
            std::cout << "HISTORY" << result << std::endl;
            break;
        case 'I':
            getline(input, result);
            std::cout << "Inventory" << result << std::endl;
            //inventory print
            
            //trans = Vew
            break;
            
        default:
            break;
    }
    
    
    
    return trans;
    
    
    
}

