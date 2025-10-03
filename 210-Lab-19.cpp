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
    Review* getReview() const {return head;}

    //setters:
    void setTitle(string t) {title = t;}

    //constructor:
    Movie(){
        title = "No Title";
        head = nullptr;
    }

    Movie(string t){
        title = t;
        head = nullptr;
    }

    Movie(string t, double r, string c){
        title = t;
        head = new Review;
        head->rating = r;
        head->comment = c;
        head->next = nullptr;
    }

    //other methods:
    //adds a review to the front of the linked list of reviews.
    void addReview(double r, string c){
        
        Review *newReview = new Review;
        newReview->rating = r;
        newReview->comment = c;
        newReview->next = nullptr;

        if (head == nullptr){
            head = newReview;
        }
        else{
            Review *temp = head;
            newReview->next = temp;
            head = newReview;
        }
    }

    void printReviews() {
        Review *temp = head;
        int count = 0;
     
        if (temp == nullptr){
            cout << "No reviews available." << endl;
            return;
        }
        while (temp != nullptr){
            count++;

            cout << "Rating #" << count << ": " << temp->rating << endl;
            cout << "Comment: " << temp->comment << endl << endl;        
            temp = temp->next;
        }
    }
};


int main(){
    int const size = 4;
    ifstream inFile;
    string movieTitle;
    double movieRating;
    string movieComment;
    Movie movies[size];
}