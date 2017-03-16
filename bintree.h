#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <stdio.h>
#include "movie.h"
#include <sstream>	// to be able to use stringstream
/*
 //|===========================================================================|
 //|                                                                           |
 //|  Assignment2 Binary Search Tree                                           |
 //|                                                                           |
 //|  Created by Danny Ly and Bardia Borhani on 1/15/17.                       |
 //|  Copyright © 2017 Red Klouds. All rights reserved.                        |
 //|===========================================================================|
 
 //============================================================================|
 
 Program_Description:
 --File Name: bintree.h
 -- A program demonstrating the understanding of implmenting a Binary Search
 Tree This program also shows understanding of pointers, memory leaks, and
	object references.
 
 The Running time for Program, for:
 -- Searching: O(long(n))
 -- inserting: O(log(n))
 --	Reconstructing from array/binary tree: O(n)
 
	-> Abstract:
 This program is implemented using the Movie class, each node within
 the tree structure is a tree node which contains a Movie pointer.
 
 Program_Features:
 -- Defaults constructor of 1 parameter.
 -- Copy Constructor,initalizes this with a deep copy of rhs.
 -- operator=, 		assignment operator copyies(deep-copy) RHS to THIS.
 -- operator==, 	checks wether the two objects are the same.
 -- operator!=, 	check wether the two object are not the same.
 -- operator>>, 	output the current object in order traversal.
 -- insert, 		Inserts a Movie pointer into the binary tree.
 -- isEmpty, 		checks if the Object is empty.
 --	retrieve,		searchs for specific Movie target.
 -- bstreeToArray,	turns binary tree into an array.
 --	arrayToBstree,	turns array into binary tree.
 -- makeEmpty,		makes the object empty, deallocates all nodes
 -- displaysSideways,	displays the tree repersentation side ways.
 --	getHeight,		return the most-depth of a given Movie.
 
 Assumptions:
 -- iostream library's are visable and included packages for
 output functionalities.
 -- Movie is included within the program, to fufill the dependency this
 program has for Movie.
 -- Movie has correct implmentations of operator ==,!=, >, <, copy
 Constructor.
 
 
 
 //------------========================================================---------
 //------------========================================================---------
 */


class BinTree {
	// The BST nodes all contain a pointer to a movie 
	struct Node {
		Movie *data;
		Node *right = nullptr; // points to node on right side of branch
		Node *left = nullptr;
	};


	friend std::ostream& operator<<(std::ostream &output, 
	const BinTree &bintree);

public:
    
    //bool retrieveMovie(std::string targetAttribute, Movie*& returnPtr);
    //bool retrieveMovie(std::string targetAttribute, Movie*&, Node *) const;
    
    //bool retrieve(const Movie &, Movie *&) const;
    //bool retrieveHelper(const Movie &, Movie *&, Node *)const;

    /*=========================< DEFAULTCONSTRUCTOR >=========================|
     |	Function Name:
     |		-> Default constructor of BinTree
     |	Assumptions:
     |		-> None
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> root equals nullptr, object is intalized
     *========================================================================*/
	BinTree();

	/*=========================< DEFAULT DESTRUCTOR >=========================|
	|	Function Name:
	|		-> Default destructor to clean up and destroy all memory that was 
	|		used, called on main stack thread.
	|		-> prevents memory leak, by deallocating all tree nodes and 
	|		Movie
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Memory is free'd and cleaned/deallocated.
	*========================================================================*/
	~BinTree();

    
    /*=========================< COPY CONSTRUCTOR >===========================|
     |	Function Name:
     |		-> Copy constructor used to initalized a deep copy of rhs
     |	Assumptions:
     |		-> Movie copy constructor is implmented correctly
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> A deep copy of rhs is constructed as this.
     *========================================================================*/
    
    
	//BinTree(const BinTree &rhs);

	/*=========================< ASSIGNMENT OPERATOR >========================|
	|	Function Name:
	|		-> Assignment operator, used to make a deep copy of rhs from an
	|		already constructed binary tree
	|	Assumptions:
	|		-> Movie copy construcotor is implmented
	|		-> delete was not called on retrieveal of an Movie
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> a deep copy of all Movie from rhs is copied to this
	*========================================================================*/
	BinTree& operator=(const BinTree &rhs);

	/*===============================< INSERT >===============================|
	|	Function Name:
	|		-> Insert function, used to insert Movie pointer to the binary
	|		tree
	|	Assumptions:
	|		-> Movie comparision operators overloaded correctly
	|		-> Movie copy constructor implemented
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Returns boolean pertaining to the succession of inserting the 
	|		Movie, 
	|		-> Returns false if duplicate was attempted to be inserted, true
	|		otherwise
	*========================================================================*/
	bool insert( Movie *data);


	/*=============================< ISEMPTY >================================|
	|	Function Name: isEmpty
	|		-> check wether root points to nullptr, signafying empty tree.
	|	Assumptions:
	|		-> None.
	|	Preconditions:
	|		-> None.
	|	Postconditions:
	|		-> Returns a true if tree is empty, false otherwise.
	*========================================================================*/
	bool isEmpty() const;

	/*==========================< OPERATOR== >================================|
	|	Function Name: Operator==
	|		-> Overload of == operator
	|	Assumptions:
	|		-> Movie operator == implemented
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Returns true if this and rhs tree's are the same, false other-
	|		wise.
	*========================================================================*/
	bool operator==(const BinTree &rhs) const;

	/*==========================< OPERATOR!= >================================|
	|	Function Name:Operator!=
	|		-> Checks if two tree's are different
	|	Assumptions:
	|		-> Movie == operator implemented
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Returns true if the tree's are different, false otherwise.
	*========================================================================*/
	bool operator!=(const BinTree &rhs) const;
	/*=============================< RETRIEVE >===============================|
	|	Function Name:
	|		-> retrieve
	|	Assumptions:
	|		-> Second parameter point is not currently initalized to point to
	|		An object in the structure.
	|		-> User will not delete the returned Movie pointer
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Returns a boolean in reguards to wether the object was found
	|		-> Second Paramter pointer will point to the targetted Movie
	|		If found within the structure.
	|		-> If Target is not found, second parameter(pointer) will point
	|		to nullptr.
	*========================================================================*/

	bool retrieveMovie(const Movie &, Movie *&) const;

	/*=========================< BSTREETOARRAY >==============================|
	|	Function Name:
	|		-> BStreeToArray, used to convert the current binary tree to the
	|		given array, using an inorder traversale
	|	Assumptions:
	|		-> The Array given has been intalized with enough space to store
	|		all elements of the binary tree
	|	Preconditions:
	|		-> Movie pointer array has enough space to store all data 
	|	Postconditions:
	|		-> Binary tree is set to NULL, and emptied. the array now contains
	|		all Movie data that was previously in the tree
	*========================================================================*/
	void bstreeToArray(Movie *[]);
    
    /*=========================< ARRAYTOBSTREE ===============================|
     |	Function Name:
     |		-> array to bstree, used to convert an array into a *balenced 
	 |		binary search tree
     |	Assumptions:
     |		-> Node Data comparison operators implmented
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> Array index's are set to null, binary tree is reconstructed 
	 |		as a balenced binary search tree
     *========================================================================*/
    void arrayToBSTree(Movie *[]);
    


	/*=========================< MAKE EMPTY >==================================|
	|	Function Name:
	|		-> make empty, clears the current binary tree, empties out the tree
	|		deallocating all memory that was used
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> All memory allocated, from tree node and Movie is deallocated
	*========================================================================*/
	void makeEmpty();


	/*=========================< DISPLAY SIDEWAYS >===========================|
	|	Function Name:
	|		-> display sideways, to display the binary search tree sideways
	|		in the console
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> displays the binary tree sideways in the console
	*========================================================================*/
	void displaySideways() const;
    
    /*============================< GETHEIGHT >===============================|
     |	Function Name:
     |		->getheight, this function, counts the depth(number of subchildren)
	 |		at the given Node if found within the structure. starting at 1 if
	 |		found
     |	Assumptions:
     |		-> None
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> Returns 1+ the number of largest subchildren from the target
	 |		Movie
     *========================================================================*/
    
	int getHeight(const Movie &) const;
    
private:
    
    /*================================< CLEAR >===============================|
     |	Function Name:
     |		-> Clear, deallocates all Tree Nodes and Movie objects
     |	Assumptions:
     |		-> user sets the root to nullptr if called.
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> deallocates all memory
     *========================================================================*/
    
    void clear(Node *subtree);
    /*============================< GETHEIGHT HELPER >========================|
     |	Function Name:
     |		->getheight, this function, counts the depth(number of subchildren)
	 |		at the given Node if found within the structure. starting at 1 if
	 |		found
     |	Assumptions:
     |		-> None
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> Returns 1+ the number of largest subchildren from the target
	 |		Movie
     *========================================================================*/
	int getHeightHelper(Node *) const;
    
	/*=========================< GET NODE HELPER >============================|
     |	Function Name:
     |		-> Get Node helper, to return an interger of 1 if the node is
	 |		found as a helper series of getHeight
     |	Assumptions:
     |		-> None
     |	Preconditions:
     |		-> None
     |	Postconditions:
     |		-> Returns number of heights of the so found Movie
     *========================================================================*/
    
    int getNode(const Movie &, Node *) const;


	/*=========================< DISPLAY SizeWAYS >===========================|
	|	Function Name:
	|		-> Display the binary tree sidways
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Print the binary tree sideways
	*========================================================================*/
	void displaySidewaysHelper(Node *, int) const;
	/*=========================< GETSIZZEOFARRAY Helper >=====================|
	|	Function Name:
	|		-> get size of array helper, given an array of Movie pointers
	|		returns the number of elements inside that array
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> Returns an interger pertaining to the number of elements inside
	|		the array
	*========================================================================*/
	int getSizeOfArrayHelper(Movie *[]);

	/*=========================< ARRAY TO BSTREE HELPER >=====================|
	|	Function Name:
	|		-> bsttree to array facade
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> the array is set to all NULL, and BALAENCE BSTree is 
	|		constructed from the array
	*========================================================================*/
	Node* arrayToBSTreeHelper(Movie *[], int, int);

	/*=========================< DELETE Tree Node Helper >====================|
	|	Function Name:
	|		-> facade instead of deleting tree Node and Node Data this 
	|		helper deletes just the tree nodes.
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> all treeNodes are deallocated
	*========================================================================*/
	void deleteTreeNodesHelper(Node *);
	/*=========================< ARRATTOBSTREE helper >========================|
	|	Function Name:
	|		-> bstto array facade method
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> array is intialitated with enough data spaces to store all
	|		Movie elements in the array.
	|	Postconditions:
	|		-> All Movie elemets are inside the array, and bst tree is set
	|		to null.
	*========================================================================*/
	int bstreeToArrayHelper(Node *, Movie *[], int);


	/*=========================< RETRIEVE HELPER >============================|
	|	Function Name:
	|		-> retrieve helper facade function
	|	Assumptions:
	|		-> User does not delete the Movie returned by this functon
	|	Preconditions:
	|		-> The pointer of Movie has no reference to another object
	|	Postconditions:
	|		-> Returns a booleaning signifying if the ovject instered was
	|		a duplicate inside the tree, true if it was not a duplicate
	|		false otherwise. 
	|		-> The pointer of the secon parameter which is a reference 
	|		is now linked to the Movie object found inside.
	*========================================================================*/
	bool retrieveMovie(const Movie &, Movie *&, Node *)const;
	/*=========================< OUTPUT OVERLOAD OPERATOR >===================|
	|	Function Name:
	|		-> OUTPUT OVERator facade
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> outputs the elements in the binary tree in an inorder traversal
	|		to the output ostream and returns it.
	*========================================================================*/
	std::ostream& outputHelper(std::ostream &, Node *) const;

	/*=========================< COPY CONSTRUCTOR HELPER >====================|
	|	Function Name:
	|		-> facade method for copy construcotr
	|	Assumptions:
	|		-> None
	|	Preconditions:
	|		-> None
	|	Postconditions:
	|		-> initalizes the current object with a deep copy of rhs
	*========================================================================*/
	//Node* copyTreeHelper(Node *thisCurent, Node *rhsCurrent);

	/*=========================< EQUALS HELPER >==============================|
	|	Function Name:
	|		-> equals operator facade method
	|	Assumptions:
	|		-> Node data == operator is implemented
	|	Preconditio\s:
	|		->
	|	Postconditions:
	|		->
	*========================================================================*/
	bool equalsHelper( const Node *thisCurrent,const  Node *rhsCurrent) const;

	/*=========================< INSERT HELPER >==============================|
	|	Function Name:
	|		-> Insert facade helper
	|	Assumptions:
	|		-> NOne
	|	Preconditions:
	|		-> 
	|	Postconditions:
	|		->
	*========================================================================*/
	Node* insert(Node *subtree, Movie *dataPtr, bool&);

	//the root pointer of the binary tree.
	Node *root;
};

#endif /* BINTREE_H */
