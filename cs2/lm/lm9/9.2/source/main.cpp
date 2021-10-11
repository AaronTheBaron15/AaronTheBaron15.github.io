//main.cpp
//cs172-1 cs2
//aaron borjas
//4/20/2019
//this program uses operator overloads to create a complex number class with +, -, *, /, +=, -=, *=, /=, <, >, <=, >=, ==, !=, and []

#include <iostream>
#include "../headers/complex.h"
using namespace std;

int main() {
    Complex num1 = Complex(20, -4); //creates a complex number that looks like 20-4i
    Complex num2 = Complex(3, 2);   //creates a complex number that looks like 3+2i

    //operator overloading +, -, *, /
    cout << "The sum of the complex numbers " << num1.toString() << " and " << num2.toString() << " is: " << (num1+num2).toString() << endl;
    cout << "The difference of the complex numbers " << num1.toString() << " and " << num2.toString() << " is: " << (num1-num2).toString() << endl;
    cout << "The product of the complex numbers " << num1.toString() << " and " << num2.toString() << " is: " << (num1*num2).toString() << endl;
    cout << "The quotient of the complex numbers " << num1.toString() << " and " << num2.toString() << " is: " << (num1/num2).toString() << endl;
    
    cout << endl;

    //accessing real and imaginary components with operator overloading []
    cout << "The real component of num1(" << num1.toString() << ") is: " << num1[0] << endl;
    cout << "The imaginary component of num1(" << num1.toString() << ") is: " << num1[1] << endl;

    cout << endl;

    // operator overloading >, <, >=, <=, ==, !=

    //>
    cout << "Is num1(" << num1.toString() << ") > num2(" << num2.toString() << ")? (1 is true, 0 is false): " << (num1 > num2) << endl;

    //<
    cout << "Is num1(" << num1.toString() << ") < num2(" << num2.toString() << ")? (1 is true, 0 is false): " << (num1 < num2) << endl;

    //>=
    cout << "Is num1(" << num1.toString() << ") >= num1(" << num1.toString() << ")? (1 is true, 0 is false): " << (num1 >= num1) << endl;

    //<=
    cout << "Is num2(" << num2.toString() << ") <= num2(" << num2.toString() << ")? (1 is true, 0 is false): " << (num2 <= num2) << endl;

    //==
    cout << "Is num1(" << num1.toString() << ") == num1(" << num1.toString() << ")? (1 is true, 0 is false): " << (num1 == num1) << endl;

    // !=
    cout << "Is num1(" << num1.toString() << ") != num2(" << num2.toString() <<")? (1 is true, 0 is false): " << (num1 != num2) << endl;

    cout << endl;

    //operator overloading +=, -=, *=, /=

    //+=
    cout << num1.toString() << " += " << num2.toString() << " is: " << (num1+=num2).toString() << endl;
    cout << "num1 is now: " << num1.toString() << endl;

    //-=
    cout << num2.toString() << " -= " << num1.toString() << " is: " << (num2-=num1).toString() << endl;
    cout << "num2 is now: " << num2.toString() << endl;

    //*=
    cout << num1.toString() << " *= " << num2.toString() << " is: " << (num1*=num2).toString() << endl;
    cout << "num1 is now: " << num1.toString() << endl;

    // /=
    cout << num2.toString() << " /= " << num1.toString() << " is: " << (num2/=num1).toString() << endl;
    cout << "num2 is now: " << num2.toString() << endl;

    cout << endl;

    cout << "num1 printing with insertion operator: " << num1 << endl;
    cout << "num2 printing with insertion operator: " << num2 << endl;



}