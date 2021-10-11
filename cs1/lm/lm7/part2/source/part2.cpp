//part2.cpp
//CS171-1 CS1
//Aaron Borjas
//10/30/18
//this program calculates all palindrome primes between 0 and 10,000 using 3 functions: reverseIt(), primeCheck(), and paliPrime().
//reverseIt() reverses the digits of a number, primeCheck() checks if a number is prime, and
// paliPrime() checks if a number is a palindrome (reverseIt(num) == num) AND if the number is a prime number
// Then it prints the numbers with a reserved 4 spaces

#include <iostream> //cout
#include <iomanip> //setw()
using namespace std;


//Function reverse 
//reverse takes a number and reverses the digits, for example 1567 would turn to 7651
//Inputs: a positive integer
//Output: a positive integer that has the reversed digits of the input
int reverseIt(int num) {
    int rev=0; //number to hold the digits of the number while it is being reversed
    while(num != 0) { //while num is not 0 
        rev = rev*10 + num%10; //rev is equal to rev*10 + num%10. Basically, it the final digit of num to the end of rev until num is equal to 0
        num = num/10; //num divides by 10, gets rid of the final digit and makes the next digit the final digit
    }
    return rev; //returns rev (the whole reversed number) once the while loop is done
}

//Function primeCheck (from LM6 part 1)
//primeCheck is a function that takes a number and checks if it is prime or not
//Inputs: num - positive integer
//Output: True - if num is prime / false - if not prime
bool primeCheck(int num) {
    for(int x = 2; x < num; x++) { //x starts at 2 and goes until is greater than or equal to num
        if(num == 0 || num == 1) { //if num is 0 or 1
            return false; //0 and 1 are not prime numbers, return false
        }
        else if(num%x == 0) { //otherwise if num modulus x is 0, num is not prime
            return false; //if num is evenly divisible by any number other than 1 and itself, it is not prime
        }
    }
    return true; //it is prime if the loop goes from start to finish and doesn't return true
}

//Function paliPrime
//paliPrime is a function that takes a number and checks if it is prime AND a palindrome
//Inputs: num - positive integer
//Output: True - if num is prime and a palindrome / false - if not prime or not a palindrome
bool paliPrime(int num) {
    if(num == 0) { //if num is 0
        return false; //return false
    }

    if(num==1) { //if num is 1
        return false; //return false
    }

    if(primeCheck(num) && (reverseIt(num)==num)) { // if num is prime and is a palindrome...
        //cout << "true";
        return true; //return true
    }
    //cout << "false";
    return false; //otherwise return false
}


int main() {
    int perRow = 0; //counter for current number of palindrome primes per row
    for(int lim=0; lim < 10000; lim++) { //code inside starts at lim = 0 and increments by one each time the code runs, and goes until lim is 10,000
        if(perRow < 8) { // if perRow is less than 8 (happens 8 times)
            if(paliPrime(lim)) { //if lim is a palindromic prime...
                //use setw(5) to reserve 5 spaces for the number (since the number can't be more than 5 spaces)
                // and prints out the number in those 5 spaces. for example, 11 would be printed like this: "   11" with 3 spaces
                //being whitespace and two spaces being 11.
                cout << setw(5) << lim; 
                perRow++;
            }
        }
        else { //if perRow is greater than or equal to 8
            cout << endl; //add a new line
            perRow = 0; //set row equal to 0
        }
    }
}