//main.cpp
//CS172-1 CS2
//Aaron Borjas
//2/24/19
//implementing the movie class, along with all the other classes
#include <iostream>
#include "../headers/movie.h"
#include "../headers/actor.h"
#include "../headers/budget.h"
#include "../headers/director.h"
#include "../headers/script.h"
using namespace std;

int main() {
    //implementing a the movie class by making the Avengers: Infinity War movie

    //creates the actors, lead being robert downey jr and support being tom holland
    Actor firstLead = Actor("Robert Downey Jr.", 53, "Iron Man", true);
    Actor firstSupport = Actor("Tom Holland", 22, "Spiderman", true);

    //creates a budget based on the fact that the max estimated budget for Infinity War was 400,000,000
    Budget firstBudget = Budget(133333333, 133333333, 133333333);

    //creates a director for infinity war, with the corresponding information
    Director firstDirector = Director("Anthony Russo", 49, "Captain America: Winter Soldier");

    //creates a script for infinity war
    Script firstScript = Script("Avengers: Infinity War", "Christopher Markus", "Action", "Marvel Comics");

    //release date of the movie
    string firstRelease = "April 27, 2018";

    string firstRating = "PG-13";

    string firstTitle = "Avengers: Infinity War";

    Movie infinityWar = Movie(firstBudget, firstDirector, firstScript, firstLead, firstSupport, firstRelease, firstRating, firstTitle);

    cout << "Basic movie information: " << endl;

    infinityWar.print();

    cout << endl;

    cout << "Lead actor info: " << endl;
    infinityWar.getLead(); //prints all the information about the lead actor
    
    cout << endl;

    cout << "Supporting actor info: " << endl;
    infinityWar.getSupport(); //prints all the information about the supporting actor
    
    cout << endl;

    infinityWar.getBudget(); //prints all the information about the budget
    firstBudget.forcastReturn(50); //returns the forcasted return of 50% money spent
    
    cout << endl;

    infinityWar.getDirector(); //prints all the information about the director

    cout << endl;

    cout << "The release date of Avengers: Infinity War is: " << infinityWar.getRelease() << endl; //prints the release date of the movie

    cout << endl;

    cout << "The rating of Avengers: Infinity War is: " << infinityWar.getRating() << endl; //prints the MPAA rating of the movie (pg, pg-13, R, etc)

    cout << endl;

    cout << "The title of the movie is: " << infinityWar.getTitle() << endl; //prints the title of the movie;

    cout << endl;

//implementing a the movie class by making the Star Wars: the force awakens movie
    cout << "====================================" << endl;
    cout << "=========== Second Movie ===========" << endl;
    cout << "====================================" << endl << endl;

    //creates the actors, lead being daisy ridley and support being john boyega
    Actor secondLead = Actor("Daisy Ridley", 26, "Rey", true);
    Actor secondSupport = Actor("John Boyega", 26, "Finn", true);

    //creates a budget based on the fact that the max estimated budget for star wars was 306 million
    Budget secondBudget = Budget(102000000, 102000000, 102000000);

    //creates a director for star wars, with the corresponding information
    Director secondDirector = Director("J.J. Abrams", 52, "Star Treck Into Darkness");

    //creates a script for star wars
    Script secondScript = Script("Star Wars: The Force Awakens", "Lawrence Kasdan", "Action", "Star Wars");

    //release date of the movie
    string secondRelease = "April 27, 2018";

    string secondRating = "PG-13";

    string secondTitle = "Star Wars: The Force Awakens";

    Movie starWarsTFA = Movie(secondBudget, secondDirector, secondScript, secondLead, secondSupport, secondRelease, secondRating, secondTitle);

    cout << "Basic movie information: " << endl;

    starWarsTFA.print();

    cout << endl;

    cout << "Lead actor info: " << endl;
    starWarsTFA.getLead(); //prints all the information about the lead actor
    
    cout << endl;

    cout << "Supporting actor info: " << endl;
    starWarsTFA.getSupport(); //prints all the information about the supporting actor
    
    cout << endl;

    starWarsTFA.getBudget(); //prints all the information about the budget
    secondBudget.forcastReturn(50); //returns the forcasted return of 50% money spent
    
    cout << endl;

    starWarsTFA.getDirector(); //prints all the information about the director

    cout << endl;

    cout << "The release date of Avengers: Infinity War is: " << starWarsTFA.getRelease() << endl; //prints the release date of the movie

    cout << endl;

    cout << "The rating of Avengers: Infinity War is: " << starWarsTFA.getRating() << endl; //prints the MPAA rating of the movie (pg, pg-13, R, etc)

    cout << endl;

    cout << "The title of the movie is: " << starWarsTFA.getTitle() << endl; //prints the title of the movie;
}