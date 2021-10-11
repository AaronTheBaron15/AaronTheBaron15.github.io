//part1.cpp
//cs171-1 CS1
//Aaron Borjas
//10/14/2018
//a program that uses both a for and while loop to count from 0 to a number, limit, by a count of
//count. For example, if count is 10 and limit is 100, it prints out "0, 10 20 30 40 50 60 70 80 90 100"
//and then stops, since count will be above 100. This prints twice, once for each type of loop

#include <iostream> // cin, cout
using namespace std;

int main() { 
    int count, limit, whileVar = 0; //integers for how much the count goes up by and what it stops at

    cout << "This is the number counter! " << endl;//tells the user what this program is about

    cout << "To start, enter the amount to count up by: "; //gives the user context (var type) for count
    cin >> count; //asks the user for the value of count

    cout << endl << "The count goes up by " << count << " each time!" << endl; //tells the user what they input for count

    cout << "Ok, now enter the maximum amount for the number to go to: "; //gives the user context (var type) for limit
    cin >> limit; //asks the user for value of limit

    cout << endl << "The limit is " << limit << endl; // tells the user what they input for limit

    cout << "Time to do run this with a for loop! " << endl; //tells the user that the loop running is a for loop
    for(int number = 0; number <= limit; number+=count) { //i starts at 0, i doesnt go past limit, i adds count each time
        cout << number << " "; //print out number
    }

    cout << endl << "Sweet, now do it with a while loop!" << endl; //tells the user that the loop running is a while loop
    while(whileVar <= limit) { //while the whileLoop variable is less than or equal to limit
        cout << whileVar << " "; // print out whileVar
        whileVar+=count; //add count to whileVar
    }

}