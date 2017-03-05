/*---------- Class Description -----------
This class represents a customer of the store. 
Each customer has two pieces of information.
The object contains two fields. One is "customerID" which represents
the customers ID number. The other is "name" which represnts the name 
of the customer. The Store class has a BST which contains Customer objects.
The BST reads the data4customers.txt file, extracts information about each
customer and creates an Customer object for each customer. 
*/

#include <iostream>
#include <string>

using namespace std;

class Customer {

    friend ostream& operator<<(ostream& output, const Customer customerObj);
    
private:
	string customerID;
	string firstName;
    string lastName;

public:
    
    Customer();
    Customer(string, string, string);

    // returns the customerID - used to find a customer in the hash table
	string getCustomerID() const;

    // passes in a parameter and sets the customerID field according to the
    // value of the parameter
	void setCustomerID(string customerID);

    // returns the name of the customer
	string getCustomerFirstName() const;
    string getCustomerLastName() const;

    // sets the name of the customer according to the value of the parameter.
	void setCustomerFirstName(string name);
    void setCustomerLastName(string name);
	
};
