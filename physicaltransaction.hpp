//
//  physicaltransaction.hpp
//  movie Store
//
//  Created by Danny Ly on 3/14/17.
//  Copyright © 2017 Danny Ly. All rights reserved.
//

#ifndef physicaltransaction_hpp
#define physicaltransaction_hpp

#include <stdio.h>
#include "transaction.h"

class PhysicalTransaction : public Transaction{
    
public:
    //void print() const;
    void makeTransaction(std::string, char);
    bool doTransaction(BinTree &, BinTree &, BinTree &, OpenHashTable &);
};
#endif /* physicaltransaction_hpp */


