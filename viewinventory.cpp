//
//  viewinventory.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "viewinventory.h"


bool ViewInventory::doTransaction(BinTree &classicDB, BinTree &comedyDB, BinTree &dramaDB, HashTable &customerDB){
    
}

void ViewInventory::makeTransaction(std::string result, char transactionType){
   // std::cout << "making command" << std::endl;
    
    this->setTransactionType(transactionType);
  };


bool ViewInventory::doTransaction() {
    //
    std::ostringstream ss;
    
    ss << "\nTransaction Type: " << this->getTransactionType();
    std::cout << ss.str() << std::endl;
    return true;
}
