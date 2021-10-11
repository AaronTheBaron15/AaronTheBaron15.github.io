//part3.cpp
//CS171-1, CS1
//Aaron Borjas
//9/25/18
/*This code uses user input to assign a temporary value to the integer variable "input". After that, 
the value of "input" is assigned to sum using the += operator, which means that the value of "input" is added
to the already defined value of sum. For example, if sum is currently equal to 7 and I did sum+=3, that
would be equivalent to sum = sum+3, or sum = 7+3. This action is done in the code for i number of times, where i
begins at 0 and ends at 4 (it performs this action 5 times)
*/

#include <iostream>
using namespace std;

int main() {
    int input; //initializes input as an integer and prepares it for later;
    int sum=0; //initializes sum as an integer and gives it the value of 0;
    int j = 5;//initializes j as 5, for use in the for loop and conditional if statement
    
    //loops through the code inside the curly brackets 5 times
    for(int i=0; i < j; i++)
    {
        cout << "What should the score be? "; //prints out the message in quotes
        cin >> input; //asks the user for the value of input and assigns the entered number to input
        cout << "*user inputs " << input << "*" << endl; //confirms what user input was
        sum+=input; //adds the new value of input to sum, which already has a value assigned to it

        if(i == (j-1) ) //if i is the final item
        {
            cout << endl << "The final sum is " << sum << endl; //print out the final sum

            //print out what the average score is, which is sum/j
            cout << "========================" << endl << "The average score is " << sum/j << endl << "========================" << endl;
        }
        else //if the current item is not the final item
        {
            cout << "Sum is now equal to " << sum << endl; //prints out what sum is now equal to
        }
    }
    
    return sum; //returns sum so other functions can use the output


}