#ifndef MOVIE_H
#define MOVIE_H

/*---------- Class Description -----------
This class represents a movie in the store. It has many characterstics,
including the year of the movie's release, the title of the movie, and the
amount of the movie in stock.

Child classes of the movie class may have more attributes. The movie class
simply has the core attributes of any given movie.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

class Movie {
   
    friend std::ostream& operator<<(std::ostream &output, const Movie &movie);
public:
    
    
    Movie();          // default constructor, data is set to an empty string
    virtual ~Movie()=0;
    //Movie(const string title, string director, int year);      // data is set equal to parameter
    //Movie(const Movie &);    // copy constructor
    //Movie& operator=(const Movie &);
    
    // set class data from data file
    // returns true if the data is set, false when bad data, i.e., is eof
    
    //better route call setData to do the work using polyMorphism
    
    //Movie movie = new Comedy,Classic, OR drama
    
    //movie.setData(istream&);
    //virtual bool setData(istream&);
    //operator overload, these are all
    /*
     These are all pure virtual overloaded functions
     these functions are to be implemented more different
     given the speciifcs
     
     
     */
    virtual bool operator==(const Movie &) const =0;

    virtual bool operator!=(const Movie &) const =0;
    //operator < overload
    virtual bool operator<(const Movie &) const =0;
    /*$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%
     #description:overload for binary sorting
     #'=0' means pure virtual
     #which means base class says it wont need
     #to implement the code, but anything that
     #inherits from it better dam well implement
     #Assumption:
     #Parameters:
     $%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%$%*/
    virtual bool operator>(const Movie &) const =0;

    //we need to do this way because friend functiona are choosen at compile time
    //meaning at compile time the parent class 'abstract' is Movie
    //hence movie operator << will be called everytime, a different approach
    //to solving this problem is to relay the flow to another virutal
    //method that will, given an input stream, change it , based off the virutal
    //method of the choosen movie type.
    //make the current movie
    virtual void makeMovie(std::vector<std::string>) = 0;
    
    //getter for the release year
	int getYear() const;

    //setter for the release year
	void setYear(int year);

    //getter for the title of the movie
    std::string getTitle() const;

    //setter for the title of the movie
    void setTitle(std::string title);

    //getter for the stock of the movie
	int getStock() const;

    //setter for the stock of the movie
	void setStock(int stock);
    //set the stock
    bool setNewStock(int amount);

    //getter for the director of the movie
    std::string getDirector() const;

    //setter for the director of the movie
    void setDirector(std::string director);
    //virtual method to get released month
    virtual int getReleaseMonth() const ;
    //get major actor
    virtual std::string getMajorActor() const;
    
    //get released Date
    int getReleasedDate() const;
    //remove stock wtih paremeter 1
    bool removeStock(int=1);
    //add a stock default by 1
    bool addStock(int=1);
    //comapre two movie objects
    bool compare(const Movie &);
    //add a major actor to the vector major actors
    virtual void addMajorActorToList(std::string);
    
private:
    //year that the movie released
    int year;
    
    //title of the movie
    std::string title, director;
    
    //physical copies of the movie in stock
    int current_stock;
    
    int max_stock;
    //director of the movie
    
    
    
};



#endif /* MOVIE_H */
