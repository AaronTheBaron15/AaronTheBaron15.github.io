/////////////////////////////////////////////////////////////
// Learning Module 2, Part 2
// CS171 - Whitworth University
// Originally outlined by: Scott Griffith
//
// Modified by: 
// Last Modified: 
//
// Calculates information about a car ride based on user
// input. Grabs the miles and the average speed of the
// traveler and outputs the time it will take to arrive
// and the gallons and liters of gas used
/////////////////////////////////////////////////////////////

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Your work goes in between the student start/end comments
// Don't change anything else
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream> //Inport: cin, cout
using namespace std;

int main (){

    int distance; //Variable to hold the distance traveled in miles
    int speed; //Variable to hold the average speed in mph
    const float milesPerGallon = 24.8; //Average miles per gallon of new cars in US, https://phys.org/news/2016-11-average-fuel-economy-high-mpg.html
    const float litersPerGallon = 0.264172; //There is 0.26 liters per US Gallon

    //Grab user input
    cout << "How far is the trip in miles? ";
    cin >> distance; //Distance in miles traveled
    cout << "What is the average speed you are going to travel at in miles per hour? ";
    cin >> speed; //Average speed in miles per hour

    ///////////////////////////
    // Start of Student code //
    ///////////////////////////

	float totalGallons = distance/milesPerGallon;
    float totalLiters = totalGallons*litersPerGallon;
    int duration = static_cast<float>(distance)/speed;

    /////////////////////////
    // End of Student Code //
    /////////////////////////

    //Output relevant information
    cout << "Total amount of gas consumed: " << totalGallons << " gallons or " << totalLiters << " liters" << endl;
    cout << "Approximate time to destination: " << duration << " hours" << endl;
    
    // Optional Line of code you can include if you want to do the extra credit
    //cout << "Or ~" << hours << ":" << minutes << endl;

    return 0;
}