// part4.cpp
// CS171-1, CS1
// Aaron Borjas
// 9/24/18
/*
This code chooses two pseudo-random numbers before 1000 and assign one each to x and y, which are integers.
Then it asks the user what x+y is equal to, and if the user is right, it congratulates the user.
If the user is wrong, it says that the user is incorrect.
*/

#include <iostream> //needed for cout
#include <cstdlib> //needed for rand
#include <ctime> //needed for time(NULL)
using namespace std;

int main() 
{
    float userAns;

    srand(time(NULL)); //seed the random library with the current time
    float x = rand()%100000 / 100.0; //rand() evaluates to a pseudo-random float value with 2 decimals
                           //the modulus keeps the number between 0 and 1000
                           //then assigned it to x
    float y = rand()%100000 / 100.0;

    cout << "X = " << x << endl; //prints value of x
    cout << "Y = " << y << endl; //prints value of y

    cout << "What is the answer for " << x << " + " << y << "? "; 
    cin >> userAns; //asks user for their guess of what x + y is equal to
    cout << "*user inputs " << userAns << "*" << endl; // prints the users answer for clarity

    if( userAns == (x+y) ) //if the users answer is equal to x+y...
    {
        //print out congrats message
        cout << "Correct! The asnwer is " << userAns << "!" << endl;
    }
    else //if users answer is not equal to x+y...
    {
        //prints out negative message with correct answer
        cout << "Nope, sorry! The answer for " << x << " + " << y << " is " << (x+y) << endl;
    }
}