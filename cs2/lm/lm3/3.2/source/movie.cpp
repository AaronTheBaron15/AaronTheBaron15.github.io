#include "../headers/movie.h"
using namespace std;

Movie::Movie() {
    
}

Movie::Movie(Budget newBudget, Director newDirector, Script newScript, Actor newLead, Actor newSupport, string newRelease, string newRating, string newTitle) {
    lead = newLead;
    support = newSupport;
    budget = newBudget;
    director = newDirector;
    script = newScript;
    releaseDate = newRelease;
    rating = newRating;
    title = newTitle;
}

void Movie::getLead() {
    lead.print();
}

void Movie::getSupport() {
    support.print();
}

void Movie::getBudget() {
    budget.print();
}

void Movie::getDirector() {
    director.print();
}

string Movie::getRelease() {
    return releaseDate;
}

string Movie::getRating() {
    return rating;
}

string Movie::getTitle() {
    return title;
}

void Movie::print() {
    cout << "The title of the movie is: " << title << endl;
    cout << title << "'s lead actor is: " << lead.getName() << endl;
    cout << title << "'s budget is: " << budget.getTotalBudget() << endl;
    cout << title << "'s director is: " << director.getName() << endl;
    cout << title << "'s release date is: " << releaseDate << endl;
    cout << title << "'s rating is: " << rating << endl;
}
