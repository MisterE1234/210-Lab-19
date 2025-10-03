//COMSC-210|Lab-19|Ethan Aylard
//IDE used: Visual Studio Code
//This program uses a Movie class to display different movie review information by using linked lists and an external file.

#include <iostream>
#include <fstream>
using namespace std;

struct Review{
double rating;
string comment;
Review *next;
};

class Movie{
string title;
Review *review;
};



