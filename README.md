# Movie-Store
CS343 Final Project

This Project simulates a Movie Inventory system.
To start this project
populate movie, customer, and transaction objects with a text file
Respectivly following the same format as the provided test text file if you would like to change the type of movie name and customer names/ids

for this project we use these data structures:
 - a an open HashTable to hold customers for fast and easy look up. 
 - a queue for the populated transactions to execute them inorder
 - a queue for each customer to record each history of their transactions and be able to reply them from most recent to earliest transactions.
 - an array to hold each transaction within the system manager.
 
 This system has been throughly test for dupliate Customer ID's for the hashtable and zero memory leaks.
