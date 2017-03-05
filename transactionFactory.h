/*---------- Class Description -----------
This class is a factory for creating transactions. Since transactions
are an action, this is a proper use of the factory design pattern.
*/

class TransactionFactory {

private:
	
	// holds the type of transaction to be performed
	char transactionType;

public:
	// transactionType setter and getter
	char getTransactionType();
	
	void setTransactionType(char transactionType);

	// creates a transaction object of the requested type
	Transaction* createTransaction();
};
