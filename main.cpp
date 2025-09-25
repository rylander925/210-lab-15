/*
COMSC-210 | Lab 15 | Rylan Der
IDE Used: Visual Studio Code
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

        /**
         * Outputs movie data to console
         */
        void print() const;

    private:
        string writer;
        int year;
        string title;
};

/**
 * Retrieve movie data from file into a vector of movies 
 * @param movies Vector to input data to
 * @param filename File to retrieve movie data from
 */
void InputMovies(vector<Movie>& movies, string filename);

int main() {
    const string FILENAME = "data.txt";
    vector<Movie> movies;

    InputMovies(movies, FILENAME);

    //Output data
    for (Movie movie : movies) {
        movie.print();
        cout << endl;
    }
}

void Movie::print() const {
    cout << "Movie: " << title << endl;
    cout << " > Year: " << year << endl;
    cout << " > Screen writer: " << writer << endl;
}

void InputMovies(vector<Movie>& movies, string filename) {
    ifstream infile;
    string title;
    string writer;
    int year;
    Movie newMovie;

    //Verify file opens properly
    infile.open(filename);
    if (!infile.good()) {
        cout << "ERROR: Could not open file \"" << filename << "\"" << endl;
        throw ios_base::failure("Invalid file name"); 
    }

    //Input data from file
    if (infile.good()) {
        //Retrieve file data; FORMAT:
        //Movie title
        //Year
        //Screen writer
        while(getline(infile, title)) {
            infile >> year;
            infile.ignore(STREAM_IGNORE_CHARS, '\n');
            getline(infile, writer);

            //Put data into a temporary movie object
            newMovie.setTitle(title);
            newMovie.setWriter(writer);
            newMovie.setYear(year);

            //Push movie to vector
            movies.push_back(newMovie);
        }
    }
}