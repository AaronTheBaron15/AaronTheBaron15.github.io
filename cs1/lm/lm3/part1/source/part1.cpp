//part1.cpp
//CS171-1, CS1
//Aaron Borjas
//9/28/18
// this program gets a random operator, either +, -, *, or /, and then 
//uses that operator to add two random numbers.


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {

    int ans; //declaring an integer variable for later so that the user's answer can be stored somewhere

    srand(time(NULL)); //seed the random library with the current time
    int x = rand()%100; //rand() evaluates to a pseudo-random float value with 2 decimals
                        //the modulus keeps 0 <= number <100
                        //then assigned it to x
    int y = rand()%100;

    int randOp = (rand()%5)+1; //the value for a random operator is defined by this floating point variable
 
    switch(randOp)
    {
        //if randOp is equal to 1, the operator is +
        case 1:
            cout << "What is " << x << " + " << y << "? "; // asking the question so user knows what to input
            cin >> ans; //ask user for what they think x+y is equal to
            cout << "*user inputs " << ans << "*" << endl; //clarification

            if(ans != (x+y)) //if user's answer is not equal to x+y
            {
                cout << "You messed up! The correct answer was " << x+y << endl; //print failure message
            }
            else // if user's answer is equal to x+y
            {
                cout << "Good job! You got the answer right!" << endl; //print out congrats message
            }
            break; //stop the process so only the text in case 1 is printed
            
        //if randOp is equal to 2, the operator is -
        case 2:
            cout << "What is " << x << " - " << y << "? "; // asking the question so user knows what to input
            cin >> ans;//ask user for what they think x-y is equal to
            cout << "*user inputs " << ans << "*" << endl;//clarification

            if(ans != (x-y)) //if user's answer is not equal to x-y
            {
                cout << "You messed up! The correct answer was " << x-y << endl;//print failure message
            }
            else// if user's answer is equal to x-y
            {
                cout << "Good job! You got the answer right!" << endl; //print out congrats message
            }
            break;//stop the process so only the text in case 2 is printed
            
        //if randOp is equal to 3, the operator is *
        case 3:
            cout << "What is " << x << " * " << y << "? ";// asking the question so user knows what to input
            cin >> ans;//ask user for what they think x*y is equal to
            cout << "*user inputs " << ans << "*" << endl;//clarification

            if(ans != (x*y)) //if user's answer is not equal to x*y
            {
                cout << "You messed up! The correct answer was " << x*y << endl;//print failure message
            }
            else// if user's answer is equal to x*y
            {
                cout << "Good job! You got the answer right!" << endl;//print out congrats message
            }
            break;//stop the process so only the text in case 3 is printed
            
        //if randOp is equal to 4, the operator is /
        case 4:
            cout << "What is " << x << " / " << y << "? ";// asking the question so user knows what to input
            cin >> ans;//ask user for what they think x/y is equal to
            cout << "*user inputs " << ans << "*" << endl;//clarification

            if(ans != (x/y)) //if user's answer is not equal to x/y
            {
                cout << "You messed up! The correct answer was " << x/y << endl;//print failure message
            }
            else// if user's answer is equal to x/y
            {
                cout << "Good job! You got the answer right!" << endl;//print out congrats message
            }
            break;//stop the process so only the text in case 4 is printed
            
        //if randOp is equal to 5, the operator is %
        case 5:
            cout << "What is " << x << " % " << y << "? ";// asking the question so user knows what to input
            cin >> ans;//ask user for what they think x%y is equal to
            cout << "*user inputs " << ans << "*" << endl;//clarification

            if(ans != (x%y))  //if user's answer is not equal to x%y
            {
                cout << "You messed up! The correct answer was " << x % y << endl;//print failure message
            }
            else// if user's answer is equal to x%y
            {
                cout << "Good job! You got the answer right!" << endl;//print out congrats message
            }
            break;//stop the process so only the text in case 5 is printed
    }
}