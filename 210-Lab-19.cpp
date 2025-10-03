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
private:
string title;
Review *head;

public:

//getters:
string getTitle() const {return title;}
Review* getReview() const {return review;}

//setters:
void setTitle(string t) {title = t;}

//constructor:
Movie(){
    title = "No Title";
    head = nullptr;
}

Movie(string t){
    title = t;
    review = nullptr;
}

Movie(string t, double r, string c){
    title = t;
    review = new Review;
    review->rating = r;
    review->comment = c;
    review->next = nullptr;
}

//other methods:
//adds a review to the linked list of reviews. If there are no reviews, the new review becomes the first review.
void addReview(double r, string c){
    Review *newReview = new Review;
    newReview->rating = r;
    newReview->comment = c;
    newReview->next = nullptr;

    if (review == nullptr){
        review = newReview;
    }
    else{
        Review *temp = ;
        
    }
}



};
