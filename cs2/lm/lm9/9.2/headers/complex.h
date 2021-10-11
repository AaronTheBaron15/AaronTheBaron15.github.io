#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;

class Complex{
    private:
        float real; //the real portion of the complex number
        float fake;//the imaginary portion of the complex number
    public: 

        //empty constructor
        //sets both real and imaginary portions of the complex number to zero
        Complex();

        //complex number constructor that only takes in the real portion of the number
        //sets the real portion to the value of a and the imaginary portion to 0
        Complex(float a);

        //full constructor for complex number
        //sets the real portion to a and the imaginary portion to b
        Complex(float a, float b);

        //Copy constructor for a complex number
        //takes in a constant reference of another complex number
        //sets the copy-er's real portion to be the real portion of the other instance of a complex number, 
        //and sets the fake portion of this copy-er to be the value of the other complex number's imaginary portion
        Complex(const Complex & other);

        //this function rounds a number to the hundredths
        //inputs - takes in a floating point number 
        //outputs - returns a floating point number which is rounded to the hundredths
        float round(float var);

        //gets the absolute value (or distance from (0,0)) of the complex number (sqrt(real^2 + imaginary^2))
        //no inputs
        //returns the absolute value or distance from the origin of the complex number
        float abs();

        //prints the complex number in "a + bi" form
        //no inputs
        //returns the complex number as a string
        string toString();

        //gets the real portion of the complex number (the a in "a + bi")
        //no inputs
        //returns the real portion of the complex number
        float getRealComponent();

        //gets the imaginary portion of the complex number (the b in "a + bi"))
        //no inputs
        //returns the imaginary portion of the complex number
        float getImaginaryComponent();

        //operator overload for [] (index access), makes index 0 return the real portion, and 1 the imaginary
        //input - an integer which is either 0 or 1, to access the different parts of the complex number
        //outputs - returns the desired part of the complex number
        float operator[](int index);

        //operator overload for +, which adds two complex numbers together
        //takes in a reference to another complex number
        //returns a complex number that is the result of adding the two complex numbers
        Complex operator+(Complex& number);

        //operator overload for the subtraction operation, finds the difference of two complex numbers
        //takes in a reference to a complex number
        //returns a the difference of the two complex numbers as a complex number
        Complex operator-(Complex& number);
        
        //operator overload for the multiplication operation, finds the product of two complex numbers
        //takes in a reference to a complex number
        //returns a the product of the two complex numbers as a complex number
        Complex operator*(Complex& number);

        //operator overload for the division operation, finds the dividend of two complex numbers
        //takes in a reference to a complex number
        //returns a the dividend of the two complex numbers as a complex number
        Complex operator/(Complex& number);

        //operator overload for the plus equals operation, adds one number to the value stored in the first
        //takes in a reference to a complex number
        //no outputs but changes member variables
        Complex operator+=(Complex& number);

        //operator overload for the minus equals operation, subtracts one complex number from the value stored in the first complex number
        //takes in a reference to a complex number
        //returns the difference of the two complex numbers by putting changing the values of the first
        Complex operator-=(Complex& number);

        //operator overload for the times equals operation, multiplies one complex number by the value stored in the first complex number
        //takes in a reference to a complex number
        //returns the product of the two complex numbers by putting changing the values of the first
        Complex operator*=(Complex& number);

        //operator overload for the minus equals operation, subtracts one complex number from the value stored in the first complex number
        //takes in a reference to a complex number
        //returns the difference of the two complex numbers by putting changing the values of the first
        Complex operator/=(Complex& number);

        //operator overload for greater than, checks if the absolute value of one complex number is greater than another
        //inputs - a complex number that passes by reference
        //outputs - true or false depending on if one number is greater than the other
        bool operator>(Complex number);

        //operator overload for less than, checks if the absolute value of one complex number is less than another
        //inputs - a complex number that passes by reference
        //outputs - true or false depending on if one number is less than the other
        bool operator<(Complex number);

        //operator overload for greater than or equal to, checks if the absolute value of one complex number is greater than or equal to another
        //inputs - a complex number that passes by reference
        //outputs - true or false depending on if one number is greater than or equal the other
        bool operator>=(Complex number);

        //operator overload for less than or equal to, checks if the absolute value of one complex number is less than or equal to another
        //inputs - a complex number that passes by reference
        //outputs - true or false depending on if one number is less than or equal to the other
        bool operator<=(Complex number);

        //operator overload for equal to, checks if the absolute value of one complex number is equal to another
        //inputs - a complex number that passes by reference
        //outputs - true or false depending on if one number is equal to the other
        bool operator==(Complex number);

        //operator overload for not equal to, checks if the absolute value of one complex number is not equal to another
        //inputs - a complex number that passes by reference
        //outputs - true or false depending on if one number is greater than the other
        bool operator!=(Complex number);

        //operator overload for <<, overloads << for complex numbers to print to an output stream
        //inputs - an output stream reference and a complex number reference
        //outputs - inserts desired complex number into an output stream
        friend ostream& operator<<(ostream& out, Complex& number);

};

#endif