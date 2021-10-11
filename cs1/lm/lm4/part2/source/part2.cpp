//part2.cpp
//CS171-1, CS1
//Aaron Borjas
//10/9/18
//computing interest in the future. gets user input for base amount, interest rate per year, and years
//the interest is compounded for and calculates the interest from one year to the next by multiplying the previous
//year's amount by (1+annual rate). After the calculation is finished, the difference from the final to 
//initial amount is calculated.

/* 
First step: Documentation
case: 4

variables:
int years;
float amount, annualRate

ask user for initial amount of money, return rate, and years to calculate

if user inputs 4 for years to calculate, initial amount of money is $10.00, and return rate is 0.1 (10%),

10*(1+0.1) = 11
    print out 11
    change amount to 11

11*(1+0.1)=12.1
    print out 12.1
    change amount to 12.1

12.1*(1+0.1)=13.31
    print out 13.31
    change amount to 13.31

13.31*(1+0.1)=14.64
    print out 14.64
    change amount to 14.64

the previous amount changes every time, along with the amount you end up with
the constants are the annual rate, the "1" in (1+annualRate), and the years it takes to calculate
*/

#include <iostream>
using namespace std;

int main() {

    int years; //integer for the amount of years, or how many times, the interest in calculated
    float principle, amount, annualRate; //floating point variables for the starting value (which changes to the previous year's value), and the rate at which the amount grows each year

    cout << "Welcome to Interest Calculator(TM)!" << endl; //Gives context for the values the user is asked for

    cout << "To begin, enter the amount of money you start with: "; //tells the user what amount to enter
    cin >> principle;//gets user input for the base amount that the interest starts at
    amount = principle; //the total amount is always at least the principle value, so amount is equal to whatever principle value is

    cout << "Great, you start with: $" << principle << "!" << endl; //tells the user what amount they start with

    cout << "Ok, now enter the rate at which the amount grows each year as a percentage: ";
    cin >> annualRate; //gets user input for the annual rate that the amount grows by
    annualRate = annualRate/100; //annualRate was asked for as a percentage, but 10% is 0.1, so if the user entered 10, that needs to be 0.1. Divide annualRate by 100 to get the right form.

    //tells the user the percentage that their amount grows by each year
    cout << "Awesome! Each year your amount grows by " << (annualRate*100) << "%!" << endl;

    cout << "Finally, enter how many years the interest will be compounding for: ";//tells the user what to input
    cin >> years; //gets user input for the number of years the interest compounds for

    //clarifies the amount, the annual rate, and the number of years the interest goes for
    cout << "Your amount, $" << principle << ", will be compounding by " << (annualRate*100) << "% every year for " << years << " years." << endl;

    int yearZ = 1; //the first year
    while(yearZ <= years) //only runs the code in the curly braces if yearZ, which defaults to 1, is less than years, which the user chose.
    {
        amount = amount*(1+annualRate); // reassigning amount to amount(which is the previous amount) times (1+annualRate), which calculates the interest from the previous year to the current year
        cout << "The amount after " << yearZ << " years is $" << amount << endl; //printing out what the amount is after x years of interest
        yearZ++; //adds 1 to yearZ so the loop doesn't go forever
    }

    //this tells the difference between the inital value and the final value. It is calculated by subtracting the principle from the final amount
    cout << "The total amount added after " << years << " years with " << annualRate*100 << "% interest, from base amount $" << principle << " is amount-principle, which is: $" << amount-principle << endl; 

}