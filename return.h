/*---------- Class Description -----------
This class extends the transaction class, and is specifically a 
transaction to return a movie to the store
*/

class Return : public Transaction {


public:

    //perform the transaction
	bool doTransaction();
    
    void makeTransaction();
};
