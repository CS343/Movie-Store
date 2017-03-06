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
using namespace std;

class Movie {
   
     friend ostream& operator<<(ostream &output, const Movie &movie);
public:
    
    
    Movie();          // default constructor, data is set to an empty string
    ~Movie();
    //Movie(const string title, string director, int year);      // data is set equal to parameter
    //Movie(const Movie &);    // copy constructor
    //Movie& operator=(const Movie &);
    
    // set class data from data file
    // returns true if the data is set, false when bad data, i.e., is eof
    
    //better route call setData to do the work using polyMorphism
    
    //Movie movie = new Comedy,Classic, OR drama
    
    //movie.setData(istream&);
    //virtual bool setData(istream&);
    
    
    virtual bool operator==(const Movie &) const =0;
    virtual bool operator!=(const Movie &) const =0;
    virtual bool operator<(const Movie &) const =0;
    virtual bool operator>(const Movie &) const =0;
    virtual bool operator<=(const Movie &) const =0;
    virtual bool operator>=(const Movie &) const =0;
    //we need to do this way because friend functiona are choosen at compile time
    //meaning at compile time the parent class 'abstract' is Movie
    //hence movie operator << will be called everytime, a different approach
    //to solving this problem is to relay the flow to another virutal
    //method that will, given an input stream, change it , based off the virutal
    //method of the choosen movie type.
    virtual void print(ostream &)const = 0;
    
    virtual void makeMovie(std::vector<std::string>) = 0;
    
    /*
    virtual bool operator==(const Movie &) const;
    bool operator!=(const Movie &) const;
    bool operator<(const Movie &) const;
    bool operator>(const Movie &) const;
    bool operator<=(const Movie &) const;
    bool operator>=(const Movie &) const;
     */
    
    //getter for the release year
	int getYear() const;

    //setter for the release year
	void setYear(int year);
    
    //getter for the title of the movie
	string getTitle() const;

    //setter for the title of the movie
	void setTitle(string title);

    //getter for the stock of the movie
	int getStock() const;

    //setter for the stock of the movie
	void setStock(int stock);

    //getter for the director of the movie
	string getDirector() const;

    //setter for the director of the movie
	void setDirector(string director);
    
    void addStock(int);
    
   // virtual int getReleaseMonth() const =0;
    
private:
    //year that the movie released
    int year;
    
    //title of the movie
    std::string title, director;
    
    //physical copies of the movie in stock
    int stock;
    
    //director of the movie
    
    
    
};



#endif /* MOVIE_H */
