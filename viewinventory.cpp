//
//  viewinventory.cpp
//  movie Store
//
//  Created by Danny Ly on 3/9/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//


#include "viewinventory.h"


bool ViewInventory::doTransaction(BinTree &classicDB, BinTree &comedyDB, BinTree &dramaDB, OpenHashTable &customerDB){
    std::string format ="|=========================================|\n";
    format+="|View Inventory                    |\n";
    std::cout << format << std::endl;
    std::cout << "Comedy" << std::endl;
    std::cout << comedyDB << std::endl;
    std::cout << "Drama" << std::endl;
    std::cout << dramaDB << std::endl;
    std::cout << "Classic" << std::endl;
    std::cout << classicDB << std::endl;

    return true;
}

void ViewInventory::makeTransaction(std::string result, char transactionType){
   // std::cout << "making command" << std::endl;
    
    this->setTransactionType(transactionType);
  };

void ViewInventory::print() const{
    std::cout << "Called InventoryView" << std::endl;
}
/*
bool ViewInventory::doTransaction() {
    //
    std::ostringstream ss;
    
    ss << "\nTransaction Type: " << this->getTransactionType();
    std::cout << ss.str() << std::endl;
    return true;
}
 
 */
