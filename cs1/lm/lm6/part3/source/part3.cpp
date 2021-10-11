//part3.cpp
//CS171-1 CS1
//Aaron Borjas
//10/23/18
//number manipulation function

#include <iostream>
using namespace std;

// function sumDigits
//takes an integer as an input and sums the digits and outputs that
//Inputs: any positive integer.
//Outputs: the value of all the digits added together
unsigned int sumDigits(unsigned int input) { 
    int sum; //the sum of all the digits starts at 0
    while( input != 0 ) { //while input isn't 0 (this means input has to decrement down to 0)
        sum += input % 10; //sum is equal to sum+(input%10). This always takes the last digit of the number and adds it to sum
        input = input/10; //input decrements by taking out the last digit by doing input/10. This always gives a whole number because of the "int" variable type
    }
    return sum; 
}

int main() {
    int unsigned input, output; //input numbers and output numbers
                       //intput should be positive
    cout << "What is your input? " << endl;
    cin >> input; //grab a number from the user

    output = sumDigits(input); //sum up the digits in the input

    cout << "The sum of the digits in " << input << " is " << output << endl;

    return 0;
}