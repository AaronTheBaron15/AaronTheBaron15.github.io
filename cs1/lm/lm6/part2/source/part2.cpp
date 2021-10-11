//part2.cpp
//CS171-1 CS1
//Aaron Borjas
//10/22/18
//Reimplementing relational operators

#include <iostream>
using namespace std;

//isPositive was taken from Scott Griffith to use in this program, which makes <, >, <=, >=, ==, and != as functions

//Function that tests if an input number is positive or not.
//This function considers 0 to be positive, be aware!
//  Input: a is an integer, positive or negative
//  Output: True if a is positive, false if a is negative
bool isPositive(int a){
    int pos = a; //Positive counter
    int neg = a; //Negative counter
 
    while(true){ //Infinite loop, loop until answer is found. Use sparingly, you can easily mess this kind of loop up.
        if(pos == 0){ //If the positive value reaches 0, it means the initial value of a is positive! Return true
            return true;
        }
        if(neg == 0){ //If the negative value reaches 0, it means the initial value of a is negative, Return false
            return false;
        }
        neg++; //Bring the negative number one step closer to 0 (i.e. if a= -5 slowly add to -5 until it is 0)
        pos--; //Bring the positive number one step closer to 0 (i.e. if a= 5  slowly subtract 1 until it is 0)
    }
}

// function greaterThan
//takes two input numbers and returns true if the first is greater than the second
//Inputs: num1 and num2 are both integers
//Outputs: True if num1-num2 is positive. False if num1-num2 is 0 or if num1-num2 is negative 
bool greaterThan(int num1, int num2) {
    if( (num1-num2) == 0) { // if num1-num2 is 0
        cout << num1 << " is not greater than " << num2 << endl << endl; //num1 is not greater than num2
        return false;
    }
    if( isPositive((num1-num2)) ) {//if num1-num2 is positive
        cout << num1 << " is greater than " << num2 << endl << endl; //num1 is greater than num2
        return true;
    }
    cout << num1 << " is not greater than " << num2 << endl << endl; //num1 is not greater than num2
    return false;
}

// function lessThan
//takes two input numbers and returns true if the first is less than the second
//Inputs: num1 and num2 are both integers
//Outputs: True if num1-num2 is negative. False if num1-num2 is 0 or if num1-num2 is positive 
bool lessThan(int num1, int num2) {
    if( (num1-num2) == 0) { //if num1-num2 equals 0
        cout << num1 << " is not less than " << num2 << endl << endl; //num1 is not less than num2
        return false;
    }
    if( !(isPositive((num1-num2))) ) { //if num1-num2 is negative
        cout << num1 << " is less than " << num2 << endl << endl; //num1 is less than num2
        return true;
    }
    cout << num1 << " is not less than " << num2 << endl << endl; //num1 is not less than num2
    return false;
}

// function greaterEqual
//takes two input numbers and returns true if the first is greater than or equal to the second
//Inputs: num1 and num2 are both integers
//Outputs: True if num1-num2 is positive or if num1-num2 is 0. False if num1-num2 is negative 
bool greaterEqual(int num1, int num2) {
    if( ((num1-num2) == 0) ) { //if num1-num2 is 0
        cout << num1 << " is greater than or equal to " << num2 << endl << endl; // num1 is greater than or equal to num2
        return true;
    }
    else if ((isPositive((num1-num2)))) { // if num1-num2 is positive
        cout << num1 << " is greater than or equal to " << num2 << endl << endl; //num1 is greater than or equal to num2
        return true;
    }
    cout << num1 << " is not greater than or equal to " << num2 << endl << endl; //num2 is not greater than or equal to num2
    return false;
}

// function lessEqual
//takes two input numbers and returns true if the first is less than or equal to the second
//Inputs: num1 and num2 are both integers
//Outputs: True if num1-num2 is negative or if num1-num2 is 0. False if num1-num2 is positive 
bool lessEqual(int num1, int num2) {
    if( ((num1-num2) == 0) ) {//if num1-num2 is 0
        cout << num1 << " is less than or equal to " << num2 << endl << endl; //num1 is less than or equal to num2
        return true;
    }
    else if (!(isPositive((num1-num2)))) { //if num1-num2 is negative
        cout << num1 << " is less than or equal to " << num2 << endl << endl; //num1 is less than or equal to num2
        return true;
    }
    cout << num1 << " is not less than or equal to " << num2 << endl << endl; //num1 is not less than or equal to num2
    return false;
}

// function equal
//takes two input numbers and returns true if the first is equal to the second
//Inputs: num1 and num2 are both integers
//Outputs: True if num1-num2 is 0. False if num1-num2 is negative or positive 
bool equal(int num1, int num2) {
    if((num1-num2) == 0) { //if num1-num2 is 0
        cout << num1 << " is equal to " << num2 << endl << endl; //num1 equals num2
        return true;
    }
    cout << num1 << " is not equal to " << num2 << endl << endl; //num1 is not equal to num2
    return false;
}

// function notEqual
//takes two input numbers and returns true if the first is notEqual to the second
//Inputs: num1 and num2 are both integers
//Outputs: True if num1-num2 is not 0. False if num1-num2 is 0
bool notEqual(int num1, int num2) {
    if(!((num1-num2) == 0)) { //if num1-num2 is not equal to 0
        cout << num1 << " is not equal to " << num2 << endl << endl; //num1 is not equal to num2
        return true;
    }
    cout << num1 << " is equal to " << num2 << endl << endl; //num1 is equal to num2
    return false;
}

int main() {
    int num1, num2; //num1 and num2 for later
    cout << "What is the first number? "; //telling the user what to enter
    cin >> num1; //user enters number for num1

    cout << "What is the second number? ";//telling the user what to enter
    cin >> num2; //user enters number for num2
    cout << endl; // new line

    cout << "Is num1 greater than num2? " << endl; //tells the user what is being print out next
    greaterThan(num1, num2); //calling the greaterThan function on num1 and num2

    cout << "Is num1 less than num2? " << endl;//tells the user what is being print out next
    lessThan(num1, num2);//calling the lessThan function on num1 and num2

    cout << "Is num1 greater than or equal to num2? " << endl;//tells the user what is being print out next
    greaterEqual(num1, num2);//calling the greaterEqual function on num1 and num2

    cout << "Is num1 less than or equal to num2? " << endl;//tells the user what is being print out next
    lessEqual(num1, num2);//calling the lessEqual function on num1 and num2

    cout << "Is num1 equal to num2? " << endl;//tells the user what is being print out next
    equal(num1, num2);//calling the equal function on num1 and num2

    cout << "Is num1 not equal to num2? " << endl;//tells the user what is being print out next
    notEqual(num1, num2);//calling the notEqual function on num1 and num2
}