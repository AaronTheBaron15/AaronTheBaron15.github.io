//part1.cpp
//CS171-1 CS1
//Aaron Borjas
//10/19/18
//calculating primes

#include <iostream>
using namespace std;

//Function primeCheck
//primeCheck is a function that takes a number and checks if it is prime or not
//Inputs: num - positive integer
//Output: True - if num is prime / false - if not prime
bool primeCheck(int num) {
    for(int x = 2; x < num; x++) {
        if(num == 0 || num == 1) {
            return false;
        }
        else if(num%x == 0) {
            return false;
        }
    }
    return true;
}

//Function allPrimes
//allPrimes is a function that prints out all the primes between 0 and the user input max number
//Inputs: max - positive integer that defines what the largest number to prime check is.
//Outputs: no return values, but prints out all the numbers that are prime between 0 and max
void allPrimes(int max) {
    for(int start = 0; start < max; start++) {
        if(primeCheck(start)) {
            cout << start << " ";
        }
    }
}

int main() {
    int max;

    cout << "Hey! Welcome to Prime Printer! We calculate primes up to a maximum value that is selected by YOU!" << endl;

    cout << "First, enter your max number: ";
    cin >> max;

    cout << "Great! Your max number is: " << max << endl;

    cout << "Now we're going to print all the primes between 0 and your number! Here we go..." << endl;

    allPrimes(max);
}