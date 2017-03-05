/*---------- Class Description -----------
This class represents a movie in the store. It has many characterstics,
including the year of the movie's release, the title of the movie, and the
amount of the movie in stock.

Child classes of the movie class may have more attributes. The movie class
simply has the core attributes of any given movie.
*/
//dante
//fdsfads
//movie class
using namespace std;
class Movie {
   
private:
    //year that the movie released
	int year;
	
	//title of the movie
	string title;
	
	//physical copies of the movie in stock
	int stock;
	
	//director of the movie
	string director;

public:

    //getter for the release year
	int getYear();

    //setter for the release year
	void setYear(int year);
    
    //getter for the title of the movie
	string getTitle();

    //setter for the title of the movie
	void setTitle(string title);

    //getter for the stock of the movie
	int getStock();

    //setter for the stock of the movie
	void setStock(int stock);

    //getter for the director of the movie
	string getDirector();

    //setter for the director of the movie
	void setDirector(string director);
};
