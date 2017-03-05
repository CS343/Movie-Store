/*---------- Class Description -----------
This class represents a binary search tree (BST) and the functions
represent the common actions of a BST such as a insertion and retrieval
of a node with the BST. This BST class holds Movie objects and the Store class
is what holds this BST class. In other words, the nodes in this class hold Movie
objects and a pointer to two other nodes (one on left side and right side of
the node in the tree)
The Movie class and Store class are also defined in this program.
The Store class owns one BST and the BST owns one to as many Movie objects.
The BST is ordered according the Movie objects' release year
*/
  
#include "movie.h"

class BST {

private:

    
    /*
    This defines the nodes that the BST contains. Each BST contains
    an Movie object and two pointers that point to two different nodes
    */
    struct Node{
        Movie data;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    /*
    Helper function for the insert function
    */
    void insert(Node* root, Movie source);
    
    /*
    Helper function for the remove function
    */
    bool remove(Node* root, Movie target);
    
    /*
    Helper function for the retrieve function
    */
    bool retrieve(Node* root, Movie target, Movie* out) const;
    
    /*
    Helper function for the makeEmpty function
    */
    void makeEmpty(Node* root);

    /* 
    This variable represents the root of the tree - the first Movie object
    that is inserted into the tree will be set to this variable
    */ 
    Node* root = nullptr;
    
    
    
public:

    /*
     This function intakes a ifsteam variable which reads the data4movies.txt
     file which contains the information all of the movies in the store. This 
     variable is created in the main function then is passed onto the Store 
     class' readMovies function to then be passed into this function.
     This function intakes the file and reads the lines. Each line will be 
     used to create one Movie object and that object will be placed into
     the BST. When the function ends, the class will hold all the movies
     in the store. 
     Number of lines in data4movies.txt == number of Movie objects created
    */
	bool buildTree(ifstream& infile);


    /*
    Intakes an Movie object and places it into the BST. The BST is ordered
    according the Movie's "year" field value
    */
	void insert(Movie source);

    /*
    Intakes an Movie object and searches the BST to find the object. If the 
    object is found, it is removed from the tree. The function then returns 
    a bool indicating whether or not the object was successfully deleted.
    */
    bool remove(Movie target);

    /*
    The retrieve function intakes two parameters.The first one is of type Movie.
    The function searches through the BST to see if there is a node whose's 
    Movie's name value matches the name value of the 
    Movie object passed through the parameter. 
    The second parameter is a pointer to an Movie object. 
    If the Movie object is found, the second parameter will
    point to that Movie object. If the Movie object is found within the BST, 
    the function will return true - otherwise it will return false.
    */
	bool retrieve(Movie target, Movie* out) const;


    /*
    This functions goes through the BST and deletes every Movie object
    and sets the root to NULL
    */
	void makeEmpty();
	
	

    
    
};
