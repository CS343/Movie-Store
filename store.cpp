/*
This class represents the store itself. It has a Queue of the 
 transactions,
just like a movie store would have receipts for everything that was
borrowed and
returned. The store also has a HashTable of all the customer 
 accounts
associated with the store. Lastly, the store has a BST to contain 
the inventory of the movies that the store has in stock.

The store class has four methods. The main function creates 
Finally, all transactions that were just read
in are performed via doTransactions.
*/

/*
 
 Notes to refactor, check for similar types in transaction a
 nd movie gettes
 and method names
 
 */
#include "store.h"

using namespace std;

Store::~Store(){
    //first since the transaction queue will have poped all the transacitons 
	//out, the only place that ALL transactions have been inserted into are 
	//the customers
    //there are no two customers with the same transactions therefore, we 
	//will be
    //able to to call the hashTables Delete method, the Delete method will 
	//deliete all
    //transactions inside the customer, then delete the custoemr that 
	//are within each
    //index of the linked list, checking if the locaton is NULL ofc.
    
  	for(int i =0; i< transactionStorage.size(); i++){
		delete transactionStorage[i];
	}
	
}

/*==========================< DEFAULT CONSTRUCTOR >=============================
||
||   Function_Description:
||      - constructs Store object
||   Preconditions:
||      - None
||      -
||   Postconditions:
||      - intalize store object
||      -
||
||   Assumptions:
||      - None
++============================================================================*/
Store::Store(){

    
}


/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- creates a movie object for all movies stated in the movie file
||		- every movie is stored in a BST basde on its genre
||
||	Precondition:
||		- intakes a parameter of type ifstream that reads the movie file
||		-
||
||	Postcondition:
||		- Three BST are filled with movies
||		- Movie object is made for every movie in the movie txt file
||	Assumptions:
||		-
++===========================================================================*/
bool Store::readMovies(ifstream& infile){
/*
 This ReadMovies method works as follows , as you make a Movie parent class, 
 given a command or action pass that to the Movie constructor
 which will return a movie type , now check what the movie type is and insert
 that movie into the corresponding binary tree storage
 -> inside the insert method of the binary tree there is a check that check 
 wether a element has been found, if found, then increment
    its quntitty, and check for success checker if not success means quntitt
	updateed and we delete the duplicate movie object
 */
    string result;
    while(getline(infile,result)){
        if(result.at(0) != 'C' && result.at(0) != 'D' && result.at(0) != 'F'){
            //another approach is to get the first char, then pass the ret of
			//the ifstream to a Movie object to populate itself
            cout << "ERROR: (Recieved an invalid command) " << result << endl;
            continue;
        }
        //used to split all items in the string by delimiter ',' coma
        vector<string> split_movie_array = 
			Helper_Functions::string_split(result, ',');
        
        Movie *moviePtr;
        //access the action which is the first in the array, accessing
		//the zero element of this item gets us the char from the char array
        char action = split_movie_array[0].c_str()[0];
        //c_str() makes strings into a char array(split), indexing the zero 
		//element give me the first split char
        //call the movie factory to make a movie object either comedy, 
		//classic, or drama
        //given an action and return it
        moviePtr = Movie_Factory::make_movie(action);
        //give the array with data to the respective object makeMovie method
        moviePtr->makeMovie(split_movie_array);
        
        //insert the movie object
        //check for success if it was successful it was inserted if it was
		//not
        //it either was duplicate, so we need to increment the quntity and 
		//delete the made object
        
        //a boolean that check weather an item was successfullly inserted 
		//into the
        //respective databasess,
        //if a duplicate was found or an error occurred then the new'd
		//movie will be
        //deleted to prevent memory leak
        bool success = false;
        switch (action) {
            case 'F':
                // if the movie object is of type comedy hen store
                //it in the comedy BST
                success = _comedyStorage.insert(moviePtr);
                break;
            case 'D':
		// if the movie object is of type drama hen store it in the
                //drama BST
                success = _dramaStorage.insert(moviePtr);
                break;
            case 'C':
		// if the movie object is of type classic hen store it in
                //the classic BST
                success = _classicStorage.insert(moviePtr);
            default:
                break;
        }
        if (!success){
            delete moviePtr;
        }
    }
    return true;
}



/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- Intake a ifstream variable that reads the customer txt file
||		- read every line and create a customer object for every line
||		- store every customer object in a hashtable of customer objects
||		- the hastable is called "customerStorage"
||
||	Precondition:
||		- The parameter must be a ifstream variable
||		- it must read the customer txt file
||
||	Postcondition:
||		- hashtable of customers is filled
||		- a customer object is made for every customer in the txt file
||	Assumptions:
||		- NONE
++===========================================================================*/

bool Store::readCustomers(ifstream& infile){
    string id,firstName, lastName;
    for(;;){
		if(infile.eof()){
			break;
		}

		Customer *ptr = new Customer();

		bool successful = ptr->makeCustomer(infile);

		if(!successful){
			delete ptr;
		}else{
        	customerStorage.put(std::atoi(ptr->getCustomerID().c_str()),
			ptr);
		}
	}
    return true;
}

/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- Intake a ifstream variable that reads the command txt file
||		- read every line and create a transaction object for every line
||		- A object is created based on the type of transaction
||		- the objects are created in the call to the transactionFactory
||
||	Precondition:
||		-The parameter must be a ifstream variable
||		- it must read the file of commands
||
||	Postcondition:
||		- Every transaction object is stored in transactionStorage vector
||		-
||	Assumptions:
||		- NONE
++===========================================================================*/

bool Store::readTransactions(ifstream& infile){
    string result;
    
    // get char 'command' throw char to transaction Factory
    //the factory reads teh given char
    //makes a query to getLine, to get tht one specific line
    //the factory also takes an output stream,
    //depending on the command, makes the approperiate
    //Transactions Subclass object
    //returns the subclass HERE, and we enqueue that result.
    char command;
    for(;;){
        infile >> command;//take the char in the beginning of the line
        if (infile.eof()){ break;}
                            //check wether the valid commands are polled
        if(command != 'B' && command != 'R' && command!= 'I' && command !='H'){
            getline(infile, result); // throw away line
            cout << "ERROR: (Recieved bad data) " << command << " "
            <<result << endl;
            continue;
        }
        
        //error data checked, now populate the objects
       

        Transaction *transactionPtr;
        transactionPtr  = TransactionFactory::makeTransaction(infile, command);
        
        
        //transactionQueue.push(transactionPtr);
  
        //push the transaction to the transcation queue
        transactionStorage.push_back(transactionPtr);
    }
    return true;
};

/*==============================< FUNCTION NAME >==============================
||	Function Desction:
||		- after the other functinos have built the store, this function
||		- takes each Transaction object out of the vector and does what
||		- the object says it should do. the doTransactino function of the 
||		- transaction object is called to compelte the transaction
||		- 
||
||	Precondition:
||		- the other functions in this class need to be called
||		- before this function is called
||
||	Postcondition:
||		- All the transactions are completed
||		-
||	Assumptions:
||		- NONDE
++===========================================================================*/

bool Store::doTransactions(){
    Transaction *transPtr;
    for(int trans = 0; trans < transactionStorage.size(); trans++){
        //get the current transaction given q FIFO requirment
        transPtr = this->transactionStorage[trans];
        //called doTransaction from the current transaction Object(polymorphis)
        transPtr->doTransaction(this->_classicStorage, this->_comedyStorage,
			this->_dramaStorage, this->customerStorage);
    }
   
    return true;
    
}

