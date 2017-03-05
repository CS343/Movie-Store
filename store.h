/*---------- Class Description -----------
This class represents the store itself. It has a Queue of the transactions,
just like a movie store would have receipts for everything that was
borrowed and
returned. The store also has a HashTable of all the customer accounts 
associated with the store. Lastly, the store has a BST to contain 
the inventory of the movies that the store has in stock.

The store class has four methods. The main function creates 
Finally, all transactions that were just read
in are performed via doTransactions.
*/

#include <queue>
#include "hashtable.h"
#include "bst.h"
#include <vector>
#include "bintree.h"

using namespace std;
class Store {

    
private:

    vector<string> string_split(string, const char);
    //queue of all transactions to perform
	//Queue transactions;
	
	//hashtable of all customer accounts
	HashTable customerHashTable;
	
	//bst of movie inventory currently in stock
	BST inventory;
    
    //use this one
    BinTree movieInventory;
    
    BinTree _cStore;
    BinTree _fStore;
    BinTree _dStore;

public:

    //default constructor
	Store();

    //read in the movies from the data file
	bool readMovies(ifstream& infile);

    //read in the customers from the data file
	bool readCustomers(ifstream& infile);

    //read in the transactions from the data file
    bool readTransactions(ifstream& infile);

    //carry out all the transactions in the transactions queue
	bool doTransactions();
};
