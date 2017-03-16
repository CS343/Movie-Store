//
//  viewinventory.cpp
//  movie Store
//
//  Created by Danny Ly and Bardia Borhani on 3/9/17.
//  Copyright © 2017 Danny Ly and Bardia Borhani. All rights reserved.
//


#include "viewinventory.h"

/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- This function intakes the bintrees and the list of customers
||      - and prints the inventory of all the items in the store
||      - the hashtable is not used but needs to be passed as the function is
||      - an overloaded function. All the movies in the store are outputted
||      - In order of all comedy, all drama, then all classics
||      -
||
||	Precondition:
||		- Intakes 3 bintree objects and a hashtable object
||		- The trees need to contain all the movies in the store
||
||	Postcondition:
||		- Outputs all of the movies in the store
||		- In order of all comedy, all drama, then all classics
||	Assumptions:
||		- The movies are stored in the BST according to the title
++===========================================================================*/
bool ViewInventory::doTransaction(BinTree &classicDB, BinTree &comedyDB,
                                 BinTree &dramaDB, OpenHashTable &customerDB){
std::string format ="|=========================================|\n";
format+="|View Inventory                    |\n";
//std::cout << format << std::endl;
std::cout<<"|==================================================|"<<std::endl;
std::cout<<"|                   COMIDIES                       |"<<std::endl;
    // prints out all of the comedy movies in order traversal
std::cout<< comedyDB << std::endl;
std::cout<<"|==================================================|"<< std::endl;
std::cout<<"|                     DRAMAS                       |"<<std::endl;
      // prints out all of the drama movies in order traversal
std::cout<< dramaDB << std::endl;
std::cout<<"|==================================================|"<< std::endl;
std::cout<<"|                   CLASSICS                       |"<<std::endl;

      // prints out all of the classic movies in order traversal
    std::cout << classicDB << std::endl;

    return true;
}


/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- overloaded function from Transaction class
||
||	Precondition:
||		- Intakes two parameters - first one is a string and the second one is
||		- the transaction type. The first parameter is not used because a 
||      - when a customer wants to view the inventory, no special tasks
||      - need to be done. But it is included because it has to as a 
||      - overloaded function
||	Postcondition:
||		- The transaction type of this class is set to the passed transaction
||      - which is "I"
||		-
||	Assumptions:
||		- None
++===========================================================================*/
void ViewInventory::makeTransaction(std::string result, char transactionType){
     
    // sets this ViewIntentory's Transaction type to the value of the 2nd
    // parameter which is "I"
    this->setTransactionType(transactionType);
    
};


