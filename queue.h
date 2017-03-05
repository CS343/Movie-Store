/*---------- Class Description -----------
This class is an implementation of a queue. It has three methods, one to push
an element into the queue, another to pop an element from the opposite end of
the queue, and the last to build the queue given a ifstream.

It must be kept in mind that the queue is FIFO, and is implemented using
a linked list with limited access.
*/

class Queue {


public:

    //push onto the top of the queue
	void push(Transaction transaction);
	
	//pop the last element, the first inserted, from the bottom of the queue.
	Transaction pop();

    //build the queue given an ifstream
	Transaction buildQueue(ifstream& infile);
};
