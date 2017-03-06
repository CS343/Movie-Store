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
#include "movie.h"
#include <string>
#include <vector>
//testing Movie
#include "comedy.h"
#include "bintree.h"
#include "moviefactory.h"
//end test movie

/*  Testing    */
#include "hashTable.h"

/*   testing  */

#include "customer.h"
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
    
    store.showMovies();
    //store.readTransactions(transactionFile);
    
    //perform all operations
    //store.doTransactions();
    
    //closes the ifstreams
    customerFile.close();
    movieFile.close();
    transactionFile.close();
    
    // end of the main function
    
    /*      TESTING MOVIE       */
    
    BinTree comedyMovieStorage;
    Movie *movie = new Comedy();
    
    Movie *movie1 =  new Comedy();
    
    Movie *movie2 =  new Comedy();
    
    movie->setTitle("YO MAMA");
    movie->setStock(10);
    movie->setYear(1991);
    

    
    movie2->setTitle("YO MAMA");
    movie2->setStock(10);
    movie2->setYear(1991);
    
    
    movie1->setTitle("YO BABA");
    movie1->setStock(5);
    movie1->setYear(1990);
    std::cout << (*movie1 < *movie ? "YES THEY IZ" : "nah" ) << std::endl;
    //for insert the work flow is as follows:
    //-> do not insert duplicates,
    //-> we query the search tree for a matching title and year
    //->if one does not exist then add it,
    //->if one DOES exist, then take the current quantity number and add that to the retruieved movie object.
    /*
    comedyMovieStorage.insert(movie);
    comedyMovieStorage.insert(movie1);
    comedyMovieStorage.insert(movie2);
    
    //std::string testArray[10];
    vector<std::string> testArray;
    //testArray.insert(0, "F");
    testArray.push_back("F");
    testArray.push_back("10");
    testArray.push_back("DANNY LY");
    testArray.push_back("GREAT MANDINGO");
    testArray.push_back("1991");

    cout << testArray[2] << endl;
    Movie *movie3 = new Comedy();
    movie3->makeMovie(testArray);
    
    
    std::cout << comedyMovieStorage << std::endl;
    Movie *returnPtr;
    returnPtr = Movie_Factory::make_movie('D');
    
    cout << *movie3 << endl;
    
    */
    //C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942
    //C, 10, Victor Fleming, The Wizard of Oz, Judy Garland 7 1939
    
    Movie *test1 = new Classic();
    Movie *test2 = new Classic();
    test1->setYear(1942);
    test1->setStock(10);
    test1->setTitle("Casablanca");
    test1->setDirector("Michael Curtiz");
    
    
    test2->setYear(1939);
    test2->setStock(10);
    test2->setTitle("The Wizard of Oz");
    test2->setDirector("Victor Fleming");
    
    std::cout << (*test1 == *test2 ? "They are the same" : "not the same") << std::endl;
    //younger dates are first
    std::cout << ("71939" < "81942" ? "true" : "false") << std::endl;
    
    /*      END TESET MOVIE     */
    
    HashTable hashtable;
    Customer *testPtr;
    
    
    /*  Testing CustomerClass   */
    Customer *cust1 = new Customer("1111", "danny","ly");
    Customer *cust2 = new Customer("1010","Kevin","Ly");
    
    hashtable.insert(cust1->getCustomerID(), cust1);
    hashtable.insert(cust2->getCustomerID(), cust2);
    
    
    std::cout << (hashtable.retrieveCustomer("1010", testPtr) ? "Retrieved" : "not found" ) << std::endl;
    std::cout << *testPtr << std::endl;
    
    
    std::cout << *cust1 <<std::endl;
    
    std::cout << *cust2 <<std::endl;
    
    
    /*  End Testing Customer Class  */
         
    return 0;
    
};
