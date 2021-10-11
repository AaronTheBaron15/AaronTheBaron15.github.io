#include "../headers/complex.h"
#include <string>
#include <iostream>
using namespace std;

Complex::Complex() {
    real = 0;
    fake = 0;
}

Complex::Complex(float a) {
    real = a;
    fake = 0;
}

Complex::Complex(float a, float b) {
    real = a;
    fake = b;
}

Complex::Complex(const Complex& other) {
    this->real = other.real;
    this->fake = other.fake;
}

string Complex::toString() {
    string complex = "";
    complex += to_string((this->real));
    complex += " + ";
    complex += to_string((this->fake));
    complex += "i";
    return complex;
}

float Complex::round(float var) {
    float value = (int)(var*100 + 0.5); //multiplies var by 100, then adds 0.5, and converts that answer to an int to cut off the decimal
    return (float)(value/100); //returns the previous number divided by 100, and converted to a float. this is the rounded answer
}

float Complex::abs() {
    return sqrt((pow(real, 2))+(pow(fake, 2))); //returns the square root of (real^2 + fake^2), which gives the distance from the origin
}

float Complex::getRealComponent() {
    return real; //returns the real component
}


float Complex::getImaginaryComponent() {
    return fake; //returns the fake component
}

float Complex::operator[](int index){
    if(index == 0) { //if index is 0
        return this->real; //return the real component
    }
    else if(index == 1) { //if index is 1
        return this->fake; //return the fake component
    }
    else {
        cout << "Invalid index, please enter either 0 or 1"  << endl; //say that the index was invalid
        return -1; //return -1 as an "error" number;
    }
}

Complex Complex::operator+(Complex& number) {
    float newReal = this->real + number.real; //creates a new real component which is the result of adding the real components of the two complex numbers
    float newFake = this->fake + number.fake;  //creates a new imaginary component which is the result of adding the imaginary components of the two complex numbers

    return Complex(newReal, newFake); //returns a new complex number with the real component being newReal and imaginary component being newFake
}

Complex Complex::operator-(Complex& number) {
    float newReal = this->real - number.real; //creates a new real component which is the result of subtracting the real components of the two complex numbers
    float newFake = this->fake - number.fake;  //creates a new imaginary component which is the result of subtracting the imaginary components of the two complex numbers

    return Complex(newReal, newFake); //returns a new complex number with the real component being newReal and imaginary component being newFake
}

Complex Complex::operator*(Complex& number) {
    //product of two complex numbers is (ac - bd) + (ad + bc)*i

    float a = this->real; //a is the real part of the first complex number
    float b = this->fake; //b is the imaginary part of the first complex number
    float c = number.real; //c is the real part of the second complex number
    float d = number.fake; //d is the imaginary part of the second complex number

    float newReal = ((a*c) - (b*d)); //finding the real part of the product of the two complex numbers
    float newFake = ((a*d) + (b*c)); //finding the imaginary part of the two complex numbers

    return Complex(newReal, newFake); //returns a complex number with the real part being newReal and the imaginary part being newFake
            
}

Complex Complex::operator/(Complex& number) {
            //making sure I understand what's going on
            //quotient of two complex numbers (a + bi)/(c + di), with conjugate being (c - di), is 
            //  (a + bi) * (c - di)
            //  -------------------
            //  (c + di) * (c - di) <---- this becomes a real number, so the answer becomes
            //
            //  real           imaginary
            //  (a*c - b*d) + (a*d + b*c)i                              real portion    imaginary portion
            //  -------------------------- which translates to just     ------------ +  ----------------- i
            //          (c*c - d*d)                                     real answer     real answer

    Complex conjugate = Complex(number.real, -(number.fake));

    Complex numerator = (*(this))*(conjugate); //the numerator is a complex number which is the product of the dividend and the conjugate of the divisor 
    Complex denominator = (number)*(conjugate); //the denominator is a complex number which is the product of the divisor and the conjugate of the divisor 

    float newReal = (numerator.real)/denominator.real; //the new real value of the quotient is the real portion of the numerator divided by the real portion of the denominator
    float newFake = (numerator.fake)/denominator.real; //the new imaginary value of the quotient is the imaginary portion of the numerator divided by the real portion of the denominator (because there is no imaginary portion)

    return Complex(newReal, newFake);
}

Complex Complex::operator+=(Complex& number) {
    *(this) = *(this)+number; //sets this to be this plus number
    return *(this); //returns (this) complex number plus
}

Complex Complex::operator-=(Complex& number) {
    *(this) = *(this) - number; //sets this to be this minus number
    return *(this); //return this
}

Complex Complex::operator*=(Complex& number) {
    *(this) = *(this)*number; //this equals this times number
    return *(this); //return this
}

Complex Complex::operator/=(Complex& number) {
    *(this) = *(this)/number; //this equals this divided by number
    return *(this); //return this
}

bool Complex::operator>(Complex number) {
    if((this->abs()) > number.abs()) { //if the absolute value of *(this) is greater than absolute value of number
        return true; //return true
    }
    return false; //return false
}

bool Complex::operator<(Complex number) {
    if(this->abs() < number.abs()) {//if the absolute value of *(this) is less than absolute value of number
        return true; //return true
    }
    return false; //return false
}

bool Complex::operator>=(Complex number) {
    if(this->abs() >= number.abs()) { //if the absolute value of *(this) is greater than or equal to the absolute value of number
        return true; //return true
    }
    return false; //return false
}

bool Complex::operator<=(Complex number) {
    if(this->abs() <= number.abs()) { //if the absolute value of *(this) is less than or equal to the absolute value of number
        return true; //return true
    }
    return false; //return  false
}

bool Complex::operator==(Complex number) {
    if(this->abs() == number.abs()) {//if the absolute value of *(this) is equal to the absolute value of number
        return true; //return true
    }
    return false; //return false
}

bool Complex::operator!=(Complex number) {
    if(this->abs() != number.abs()) { ////if the absolute value of *(this) is not equal to the absolute value of number
        return true; //return true
    }
    return false; //return false
}

ostream& operator<<(ostream& out, Complex& number) {
    out << number.toString() << endl;
    return out;
}


