/*
COMSC-210 | Lab 15 | Rylan Der
IDE Used: Visual Studio Code
*/

/*
Code a Movie class that has:
 the screen writer, the year released, and the title as its private member variables. It has the standard setters and getters for each private member variable. 
Also code a print() method which prints the object data in a simple format.
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int STREAM_IGNORE_CHARS = 100;

class Movie {
    public:
        //getters & setters
        void setWriter(string writer) { this->writer = writer; }
        void setYear(int year)        { this->year = year; }
        void setTitle(string title)   { this->title = title; }
        string getWriter() const      { return writer; }
        int getYear() const           { return year; }
        string getTitle() const       { return title; }

        //print movie info
        void print() const;

    private:
        string writer;
        int year;
        string title;
};

void InputMovies(vector<Movie>& movies, string filename);

int main() {
    
}

void Movie::print() const {
    cout << "Movie: " << title << endl;
    cout << "\tYear: " << year << endl;
    cout << "\tScreen writer: " << writer << endl;
}

/**
 * Retrieve movie data from file into a vector of movies 
 * @param movies Vector to input data to
 * @param filename File to retrieve movie data from
 */
void InputMovies(vector<Movie>& movies, string filename) {
    ifstream infile;
    string title;
    string writer;
    int year;
    Movie newMovie;

    infile.open(filename);
    if (!infile.good()) {
        cout << "ERROR: Could not open file \"" << filename << "\"" << endl;
        throw ios_base::failure("Invalid file name"); 
    }

    if (infile.good()) {
        while(getline(infile, title)) {
            getline(infile, writer);
            infile >> year;

            newMovie.setTitle(title);
            newMovie.setWriter(writer);
            newMovie.setYear(year);

            movies.push_back(newMovie);

            infile.ignore(STREAM_IGNORE_CHARS, '\n');
        }
    }
}