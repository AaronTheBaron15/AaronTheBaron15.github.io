#include <iostream>
#include <string>
#include "budget.h"
#include "actor.h"
#include "director.h"
#include "script.h"
using namespace std;

#ifndef MOVIE_H
#define MOVIE_H

class Movie {
    private:
        Actor lead;
        Actor support;
        Budget budget;
        Director director;
        Script script;
        string releaseDate;
        string rating;
        string title;
    public:
        //empty movie constructor
        Movie();

        //movie constructor
        //creates a movie with a budget, director, script, lead and supporting actors, release date, rating, and title
        Movie(Budget newBudget, Director newDirector, Script newScript, Actor newLead, Actor newSupport, string newRelease, string newRating, string newTitle);

        //getLead, gets information about the lead character of the movie
        //no inputs
        //prints the information about the lead actor to the screen
        void getLead();

        //getSupport, gets the information about the supporting actor
        //no inputs 
        //prints the information about the supporting actor
        void getSupport();

        //getBudget, gets the information about the budget
        //no inputs
        //prints all the information about the budget
        void getBudget();

        //getDirector, gets all the information about the director
        //no inputs
        //prints the all information about the director
        void getDirector();

        //getScript, gets all the information about the script
        //no inputs
        //prints all the information about the script
        void getScript();

        //getRelease, gets the release date of the movie
        //no inputs
        //prints the release date of the movie
        string getRelease();

        //getRating, which gets the rating of the movie
        //no inputs
        //prints the rating of the the movie
        string getRating();

        //getTitle, which gets the title of the movie
        //no inputs
        //prints the title of the movie
        string getTitle();

        //print, prints all the movie information to the screen
        //no inputs
        //prints the information about the movie to the screen
        void print();
};

#endif