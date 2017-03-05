/*---------- Class Description -----------
 This is the main function/driver of the program. It opens the three data
 text files associated with the program (data4customers, data4commands,
 and data4movies). It assigns three ifstream variables to read the txt files.
 The initialized Store object then performs the readCustomers,
 readTransactions, and readMovies functions, respectively, to read the contents
 of each of the data files.
 */

#include "store.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    // Creates a new store class - the main class works directly with the Store
    // class - which acts as a manager class.
    Store store;
    
    // creates three new ifstream variables to read the three txt files
    ifstream customerFile;
    ifstream movieFile;
    ifstream transactionFile;
    
    //opens the data files
    customerFile.open("data4customers.txt");
    
    movieFile.open("data4movies.txt");
    transactionFile.open("data4commands.txt");
    
    //check to see if the files are open
    if (!customerFile || !movieFile || !transactionFile) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    //send them to the store object to be read into the appropriate data
    //structure
    store.readCustomers(customerFile);
    store.readMovies(movieFile);
    //store.readTransactions(transactionFile);
    
    //perform all operations
    //store.doTransactions();
    
    //closes the ifstreams
    customerFile.close();
    movieFile.close();
    transactionFile.close();
    
    // end of the main function
    return 0;
    
};
