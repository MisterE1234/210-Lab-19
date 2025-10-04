//COMSC-210|Lab-19|Ethan Aylard
//IDE used: Visual Studio Code
//This program uses a Movie class to display different movie review information by using linked lists, an external file, and random ratings.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
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

    //getter:
    string getTitle() const {return title;}
   
    //setters:
    void setTitle(string t) {title = t;}

    //constructor:
    Movie(){
        title = "No Title";
        head = nullptr;
    }


    //other methods:
    //adds a review to the front of the linked list of reviews.
    void addReview(double r, string c){
        //Create a new review node.
        Review *newReview = new Review;
        newReview->rating = r;
        newReview->comment = c;
        newReview->next = nullptr;
        //Insert the new review at the front of the list.
        if (head == nullptr){
            head = newReview;
        }
        else{
            Review *temp = head;
            newReview->next = temp;
            head = newReview;
        }
    }
    //prints all reviews for the movie with the ratings only displaying up to 1 decimal point.
    void printReviews() {
        Review *temp = head;
        int count = 0;
        //Check if there are no reviews.
        if (temp == nullptr){
            cout << "No reviews available." << endl;
            return;
        }
        //Display each review's rating and comment.
        while (temp != nullptr){
            count++;
            cout << fixed << setprecision(1);
            cout << "Rating #" << count << ": " << temp->rating << endl;
            cout << "Comment: " << temp->comment << endl << endl;
            temp = temp->next;
        }
    }

    void calculateAverageRating(){
        Review *temp = head;
        double sum = 0.0;
        int count = 0;

        if (temp == nullptr){
            cout << "No reviews available to calculate average rating." << endl;
            return;
        }

        while (temp != nullptr){
            sum += temp->rating;
            count++;
            temp = temp->next;
        }

        double average = sum / count;
        cout << "Average Rating: " << average << endl;
    }

    void deleteReviews() {
        Review *temp = head;
        while (temp != nullptr){
            Review *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        head = nullptr;
    }
};
//function to generate a random double rating between 1.0 and 5.0.
//requires nothing
//returns a double
double getRandomRating() {
    // return a random double in the interval [1.0, 5.0]
    double rating = 1.0 + static_cast<double>(rand()) / RAND_MAX * 4.0; // 1.0 + [0.0,4.0]
   
    return rating;
}


int main(){
    int const size = 4;
    ifstream inFile;
    string movieTitle;
    double movieRating;
    string movieComment;
    Movie movies[size];
    //seed random number generator
    srand((time(0)));

    //open file
    //check if file opened correctly
    inFile.open("movies.txt");
    if (!inFile){
        cout << "Error opening file." << endl;
        return 1;
    }

       //Set movie titles and add 3 reviews for each movie from the file with random ratings.

       //Batman Begins:
        movies[0].setTitle("Batman Begins");

        for (int j = 0; j < 3; j++){
            //random double rating between 1 and 5
            movieRating = (getRandomRating());
            getline(inFile, movieComment);
            movies[0].addReview(movieRating, movieComment);
        }

        //Inception:
        movies[1].setTitle("Inception");
        for (int j = 0; j < 3; j++){
            movieRating = (getRandomRating()); //random double rating between 1 and 5
            getline(inFile, movieComment);
            movies[1].addReview(movieRating, movieComment);
        }

        //Interstellar:
        movies[2].setTitle("Interstellar");
        for (int j = 0; j < 3; j++){
            movieRating = (getRandomRating()); //random rating between 1 and 5
            getline(inFile, movieComment);
            movies[2].addReview(movieRating, movieComment);
        }
        
        //Tenet:
        movies[3].setTitle("Tenet");
        for (int j = 0; j < 3; j++){
            movieRating = (getRandomRating()); //random rating between 1 and 5
            getline(inFile, movieComment);
            movies[3].addReview(movieRating, movieComment);
        }
    

    //close file
    inFile.close();

    //Display each movie's title, reviews, and average rating.
    for (int i = 0; i < size; i++){
        cout << "Movie Title: " << movies[i].getTitle() << endl;
        movies[i].printReviews();
        movies[i].calculateAverageRating();
        cout << "----------------------------------------" << endl;
    }

    //Deallocate all dynamic memory used for the reviews linked list for each movie.
    for (int i = 0; i < size; i++){
        movies[i].deleteReviews();
    }
}