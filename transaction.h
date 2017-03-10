/*-------Class description------
A Transaction object is created for all the transactions in the
data4commands.txt file. Each line in the text file represents a transaction.

A ifstream variable in the main function intakes
the text file then passes it to the Store class. The Store class owns a
queue of transactions. The readTransactions function in the store class
works with the TransactionFactory to create a new Transaction object to be
stored in the Store class' "transactions" queue.

The Borrow, Return, and ViewInventory class all extend this class
*/
class Transaction {

    
private:

    // Contains the title of the movie 
    std::string movieTitle;
	
	// Indicates, by a user's ID, which Customer completes this transaction
	int userID;
	
	// Indicates the type of transaction - Borrow, Return, or Inventory
	char transactionType;
	
	char format;
	
	char genre;
	
	// The year the movie was released
	int year;
	
	// The amount of copies the store owns for this movie
	int amount;
	
	// the name of a major in the movie
    std::string actor;

public:

    // returns the title of the movie
    std::string getMovieTitle();

    //std::string print() const;
    void setMovieTitle(std::string movieTitle);

	int getUserID();

	void setUserID(int userID);

	char getTransactionType();

	void setTransactionType(char transactionType);

	char getFormat();

	void setFormat(char format);

	char getGenre();

	void setGenre(char genre);

	int getYear();

	void setYear(int year);

	int getAmount();

	void setAmount(int amount);

    std::string getActor();

    void setActor(std::string actor);

	bool doTransaction();
};
