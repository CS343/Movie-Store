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


#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "store.h"
#include <sstream>


using namespace std;
/*
default constructor
Pre-condition:
Post-condition:
*/
Store::Store(){

    //HashTable* customerHashTable = new HashTable();
    //HashTable customerHashTable;
    
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


/*
read in the movies from the data file
Pre-condition:
Post-condition:
*/
bool Store::readMovies(ifstream& infile){

    string result;
    while(getline(infile,result)){
        
        if(result.at(0) != 'C' && result.at(0) != 'D' && result.at(0) != 'F'){ //|| result.at(0) != 'F' || result.at(0) != 'D'){
            //another approach is to get the first char, then pass the ret of the ifstream to a Movie object to populate itself
            
            
            cout << "ERROR: " << result << endl;
            continue;
        }
        
        
  
        
        vector<string> arr = string_split(result, ',');
        
        if(result.at(0) == 'C'){
            vector<string> cArray = string_split(arr[4], ' ');
            for(int i  = 0; i <= 4; i++){
                std::cout << cArray[i] << std::endl;
            }
        }
        

        //0 is command , 1 is qualitity, 2 is author
        
        //create a movie object and put into bst
        
       // Movie *newMovie  =
        cout << arr[1] << endl;
        //cout << result << endl;
    }
    /*
    for(;;){

        
        infile >> movieType;
        if(movieType != 'C' || movieType != 'F' || movieType != 'D'){
            //invalid command return/print an error code
            //get line
            //skip parsing line
            cout << "found an invalid char : " << movieType << endl;
            infile.getline(linee, 200);
            continue;
            
        }
        
        cout << "movie type " << movieType << endl;
        
        infile.getline(linee, 200);
        
        if(infile.eof()){
            break;
        }
    }
     */
    

    
    return true;
}

/*
read in the customers from the data file
Pre-condition:
Post-condition:
*/
bool Store::readCustomers(ifstream& infile){
    
    
    //char* charLine;
    string id;
    string firstName;
    string lastName;
    
    for(;;){
        
        
        if (infile.eof()){
            break;    
        }
        
        infile >> id >> firstName >> lastName;
        
        //cout << "first name: \t" << firstName << "   id: " << id << "lasdtName : " << lastName <<endl;
        
        
        
        /*
            ~Needs rework
                create default construcotr and call setter methods.
         */
        
        Customer* customerObj = new Customer(id, firstName, lastName);
        //cout<< "Customer object popualted: " << *customerObj << endl;
        /*
        customerObj->setCustomerID(id);
        customerObj->setFirstName(firstName);
        customerObj->setLastName(lastName); 
        */
        
        // customers is the HashTable name
        
        // CHECK - this function is for some reason private in the header file
        // shouldn't it be public? plus shouldn't the parameter be a of
        // type Customer? instead of just a customerID?
        
        
        /// insert newly created customer object into the hash Table storage
        int returnIndex = customerHashTable.hash(customerObj);
        
        /*
        if(returnIndex == atoi(customerObj->getCustomerID().c_str()) ){
            cout << returnIndex << " = " << customerObj->getCustomerID() << endl;
        } else{
            cout << "failed" << endl;
        }
        */
        
        /*
        Customer* cusPtr;
        cout << customerHashTable.retrieveCustomer(customerObj->getCustomerID(), cusPtr) << endl;
        
         */
        
        //customerHashTable.
    }
 
    
    
    
    /*
    char charLine[80];
    char* s;
    

    // may not work because "line" has to be a char*
    infile.getline (charLine, 1000);    // change to max
    
    //std::cout << charLine << std::endl;
    
    s = strtok (charLine," ");
    
    while(s != NULL){
        
        printf("%s\n", s);
        s = strtok(NULL, " ");
    }
    int i = 0;
    
    for(;;){
        if(s[i] == '\n'){
           break;
        }
        cout << s[i] << endl;
        i++;
    }
    */
    
    
    
    return true;
    
    
    
}

/*
read in the transactions from the data file
Pre-condition:
Post-condition:
*/
bool Store::readTransactions(ifstream& infile){
    return true;
}

/*
carry out all the transactions in the transactions queue
Pre-condition:
Post-condition:
*/
bool Store::doTransactions(){
    return true;
}

