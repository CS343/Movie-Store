//
//  customer.cpp
//  movie Store
//
//  Created by Danny Ly on 3/3/17.
//  Copyright © 2017 Danny Ly. Bardia Borhani All rights reserved.
//

#include "customer.h"
/*
 +====================	<DISPLAY HISTORY >	====================================-
 ||
 ||   Function_Description:
 ||       -This function  displays the history for this speicifc customer
 ||   Preconditions:
 ||       -None
 ||   Postconditions:
 ||      -Will output from the most recent borrow or return transaction to the 
 ||			Console.
 ||   Assumptions:
 ||       - The history vector has been intastalized.
 +==============================================================================-
 */
void Customer::displayHistory() const {
    std::string format =
		    "\n|==================================================|\n";
    format+="|HISTORY                   Customer ID: " + getCustomerID() + "       |\n";
    format+="|--------------------------------------------------|\n";
    format+="|Status | Title                                    |\n";
    format+="|--------------------------------------------------|";
    
    std::cout << format << std::endl;
    for(int i = history.size() - 1; i >= 0; i--){
        if(history[i]->getTransactionType() == 'B'){
            std::cout << " Borrowed " << history[i]->getMovieTitle() << std::endl;
        }else if(history[i]->getTransactionType() == 'R'){
            std::cout << " Returned " << history[i]->getMovieTitle() << std::endl;
        }
    }
};
/*
 +========================<ADD TRANSACTION ======================================-
 ||   Function_Description:
 ||       - Helper function that adds a transcation to the customers transaction
 ||			vector
 ||   Preconditions:
 ||       - None
 ||   Postconditions:
 ||      -Transaction pointer will be inserted into the history vector
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */
void Customer::addTransaction(Transaction *transaction){
    history.push_back(transaction);
};
/*
 +======================	DEFAULT CONSTRUCTOR ===============================-
 ||
 ||   Function_Description:
 ||       - default constructor used to initalize a defaulting customer object
 ||   Preconditions:
 ||       - None
 ||   Postconditions:
 ||      - Customer object will be initalitated.
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */
Customer::Customer(){};
/*
 +======================== PARAMETRIC DEFAULT CUSTRUCTOR =================-
 ||
 ||   Function_Description:
 ||       - constructor used to make object given ID, firstname, and lastname
 ||   Preconditions:
 ||       - all parameters must be of type string
 ||   Postconditions:
 ||      - Customer object has been initalized.
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */

Customer::Customer(std::string id, std::string firstName, std::string lastName){
    setCustomerID(id);
    setCustomerFirstName(firstName);
    setCustomerLastName(lastName);
};
/*
 +======================set CustomerID=========================================-
 ||
 ||   Function_Description:
 ||       - helper function to set customer ID
 ||   Preconditions:
 ||       - parameter must be valid string repersentation of customer ID
 ||   Postconditions:
 ||      - Customer id will be set to the parameter
 ||
 ||   Assumptions:
 ||       - Customer ID is a string type
 +==============================================================================-
 */
void Customer::setCustomerID(std::string customerID){
    this->customerID = customerID;
};
/*
 +====================set Customer FirstName===================================-
 ||
 ||   Function_Description:
 ||       - sets the customers first name
 ||   Preconditions:
 ||       -None
 ||   Postconditions:
 ||      - the customers first name will be set to the parameter given
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */
void Customer::setCustomerFirstName(std::string firstName){
    this->firstName = firstName;
};
/*
 +===========================SET CUSTOMER LAST NAME==================-
 ||
 ||   Function_Description:
 ||       - sets the customers last name of the current object
 ||   Preconditions:
 ||       -None
 ||   Postconditions:
 ||      - lastname is set to the given parameter
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */
void Customer::setCustomerLastName(std::string lastName){
    this->lastName = lastName;
};
/*
 +========================GET CUSTOMER ID ==================================-
 ||
 ||   Function_Description:
 ||       -gets the current customer ID, as a string
 ||   Preconditions:
 ||       - None
 ||   Postconditions:
 ||      - Returns a string repersentation of the customers ID
 ||
 ||   Assumptions:
 ||       - the calling function expects a string as return type 
 +==============================================================================-
 */
std::string Customer::getCustomerID() const{
    return this->customerID;
};
/*
 +==============================GET customer First name ========================-
 ||
 ||   Function_Description:
 ||       - returns the customers first name
 ||   Preconditions:
 ||       - None
 ||   Postconditions:
 ||      - returns the customers first name
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */
std::string Customer::getCustomerFirstName() const{
    return this->firstName;
};
/*
 +=========================MAKE CUSTOMER       ================================-
 ||
 ||   Function_Description:
 ||       - Given an input stream, make the current customer object
 ||     This works by taking the input stream and getting the line, it check
 ||     if there are three elements ID, First name, LastName
||      and checks if the ID is a digit, and once it is we popualte the Customer 
 ||     object
 ||   Preconditions:
 ||       - the customer object calling function is new'd and not populated
 ||   Postconditions:
 ||      - customer object is popualted
 ||   Assumptions:
 ||       - None
 +==============================================================================-
 */

bool Customer::makeCustomer(std::ifstream &infile){
	std::string result;
	//get a line from the infile stream
	std::getline(infile,result);
	//the array split by white space
	std::vector<std::string> customer_array = Helper_Functions::string_split(result,' ');



	//int ret = atoi(customer_array[0].c_str());
	if( (customer_array.size() == 3) && 
	(isdigit(customer_array[0][0])) && (
	atoi(customer_array[0].c_str()) >= 0) ) {	
		setCustomerID(customer_array[0]);
		setCustomerFirstName(customer_array[1]);
		setCustomerLastName(customer_array[2]);

		//std::cout << customer_array[0] << customer_array[1]<< std::endl;

//std::cout << std::isalpha(customer_array[3]) << std::endl;
		return true;
	}else{
	
		return false;
	}

}

/*==========================< FUNCTION NAME >==================================
 ||
 ||   Function_Description:
 ||      - Get the customer LastName
 ||
 ||   Preconditions:
 ||      - None
 ||      -
 ||   Postconditions:
 ||      - return customer last name string
 ||      -
 ||
 ||   Assumptions:
 ||      - None
 ++============================================================================*/

std::string Customer::getCustomerLastName() const{
    return this->lastName;
};
