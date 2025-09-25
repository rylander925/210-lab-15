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

class Movie {
    public:
        //getters & setters
        void setWriter(string writer) { this->writer = writer; }
        void setYear(int year)        { this->year = year; }
        void setTitle(string title)   { this->title = title; }
        string getWriter() const      { return writer; }
        int getYear() const           { return year; }
        string getTitle() const       { return title; }

        void print();

    private:
        string writer;
        int year;
        string title;
};