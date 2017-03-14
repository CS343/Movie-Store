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


/*
 
 Notes to refactor, check for similar types in transaction and movie gettes
 and method names
 
 */
#include "store.h"

using namespace std;
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
Store::Store(){

    
}

std::vector<std::string> Store::string_split(std::string s, const char delimiter)
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


void Store::showInventory() const {
    std::cout << std::endl;
    std::cout << "Classic Inventory" << std::endl;
    std::cout << this->_classicStorage << std::endl;
    std::cout << std::endl;
    std::cout << "Comedy Inventory" << std::endl;
    std::cout << this->_comedyStorage << std::endl;
    std::cout << std::endl;
    std::cout << "Drama Inventory" << std::endl;
    std::cout << this->_dramaStorage << std::endl;
    
    std::cout << std::endl;
    std::cout << "SHOW CUSTOMERS" << std::endl;
    customerHashTable.showAllItems();
    
}


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
bool Store::readMovies(ifstream& infile){
/*
 This ReadMovies method works as follows , as you make a Movie parent class, given a command or action pass that to the Movie constructor
 which will return a movie type , now check what the movie type is and insert that movie into the corresponding binary tree storage
 -> inside the insert method of the binary tree there is a check that check wether a element has been found, if found, then increment
    its quntitty, and check for success checker if not success means quntitt updateed and we delete the duplicate movie object
 */
    string result;
    while(getline(infile,result)){
        if(result.at(0) != 'C' && result.at(0) != 'D' && result.at(0) != 'F'){ //|| result.at(0) != 'F' || result.at(0) != 'D'){
            //another approach is to get the first char, then pass the ret of the ifstream to a Movie object to populate itself
            cout << "ERROR: (Recieved an invalid command) " << result << endl;
            continue;
        }
        vector<string> split_movie_array = string_split(result, ',');
        
        Movie *moviePtr;
        char action = split_movie_array[0].c_str()[0];
        //c_str() makes strings into a char array(split), indexing the zero element give me the first split char
        moviePtr = Movie_Factory::make_movie(action);
        //give the array with data to the respective object makeMovie method
        moviePtr->makeMovie(split_movie_array);
        
        //insert the movie object
        //check for success if it was successful it was inserted if it was not
        //it either was duplicate, so we need to increment the quntity and delete the made object
        
        bool success = false;
        switch (action) {
            case 'F':
                //insert into comedy bintree
                success = _comedyStorage.insert(moviePtr);
                break;
            case 'D':
                success = _dramaStorage.insert(moviePtr);
                break;
            case 'C':
                success = _classicStorage.insert(moviePtr);
            default:
                break;
        }
        if (!success){
            
            //cout << "deleteing: " << *moviePtr << endl;
            delete moviePtr;
        }
        /*else{
            std::cout << "successfully inserted: " << *moviePtr << std::endl;
        }
         */
    }
    return true;
}

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


bool Store::readCustomers(ifstream& infile){
    string id,firstName, lastName;
    for(;;){
        if (infile.eof()){
            break;    
        }
        //grab the customer data from file
        infile >> id >> firstName >> lastName;
        //create the customer object given the data;
        Customer *customerObj = new Customer(id, firstName, lastName);
        
        //insert the customer into the store object, and customer hashmap
        
        //customerHashTable.insert(customerObj->getCustomerID(), customerObj);
        customerStorage.put(std::atoi(customerObj->getCustomerID().c_str()), customerObj);
    }
    return true;
}

/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
bool Store::readTransactions(ifstream& infile){
    string result;
    
    // get char 'command' throw char to transaction Factory
    //the factory reads teh given char
    //makes a query to getLine, to get tht one specific line
    //the factory also takes an output stream,
    //deending on the command, makes the approperiate Transactions Subclass object
    //returns the subclass HERE, and we enqueue that result.
    char command;
    for(;;){
        infile >> command;//take the char in the beginning of the line
        if (infile.eof()){ break;}
                            //check wether the valid commands are polled
        if(command != 'B' && command != 'R' && command!= 'I' && command !='H'){
            getline(infile, result); // throw away line
            cout << "ERROR: (Recieved bad data) " << command << " "<<result << endl;
            continue;
        }
        
        //error data checked, now populate the objects
        
        Transaction *transactionPtr;
        transactionPtr  = TransactionFactory::makeTransaction(infile, command);
        
        /*
        Customer *temp = nullptr;
        
        temp = this->customerStorage.get(std::atoi(transactionPtr->getCustomerID().c_str()));
        if(temp == nullptr){
            //what if the transaction is an I no customer ID
            std::cout << "Customer ID does not exist@NEW :" << transactionPtr->getCustomerID()<< std::endl;
        }
         */
        /*
        if(!(this->customerHashTable.retrieveCustomer(transactionPtr->getCustomerID(), temp))){
            
            std::cout << "Customer ID does not exist: " << transactionPtr->getCustomerID() << std::endl;
        }
        */
        //std::cout << std::endl;
        //transactionPtr->doTransaction();
    
        transactionQueue.push(transactionPtr);
  
    }
    return true;
};

/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */

bool Store::doTransactions(){
    //HYE BARDIA
    while(!(this->transactionQueue.empty())){
        Transaction *ptr;
        ptr = this->transactionQueue.front();
        //BinTree &classicDB, BinTree &comedyDB, BinTree &dramaDB, HashTable &customerDB
        ptr->doTransaction(this->_classicStorage, this->_comedyStorage, this->_dramaStorage, this->customerStorage);
        
        //std::cout << (successful ? "poped a transaction" : "failed to pop")<< std::endl;
        //ptr->print();
        //std::cout << "poping an item" << std::endl;
        //std::cout << "performing command: " << ptr->getTransactionType() << std::endl;
        this->transactionQueue.pop();
        //std::cout << "finished outputting the data" << std::endl;
    }
    return true;
    
}
/*
bool Store::searchInventory(char movieGenre){
    switch (movieGenre) {
        case 'C':
            
            break;
        case 'F':
            break;
        case 'D':
            
            break;
        default:
            break;
    }
    return true;
}
 
*/

/*
 +==============================================================================-
 ||
 ||   Function_Description:
 ||       -
 ||   Preconditions:
 ||       -
 ||       -
 ||   Postconditions:
 ||      -
 ||       -
 ||
 ||   Assumptions:
 ||       -
 +==============================================================================-
 */
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

