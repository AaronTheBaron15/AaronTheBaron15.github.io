//part3.cpp
//CS171-1 CS1
//Aaron Borjas
//11/14/18
//Employee hour statistic tool

#include <iostream> //cout and cin
#include <iomanip> //setw and setfill
#include <cstdlib> //srand and rand
#include <ctime> //time
using namespace std;

const int employeeIndex = 10; //total of 10 employees
const int dayIndex = 7; //7 days in a week that employees work

//function fillArray
//Takes a 2D array and fills it with random values that represent the hours worked per day, per employee
//Inputs - integer array with 10 rows and 7 columns
//Outputs - No visible outputs, but assigns every value in the array to a random value between 0 and 13 (0 - 12)
void fillArray(int arr[employeeIndex][dayIndex]) {
    srand(time(NULL)); //seeding for rand
    for(int row = 0; row < employeeIndex; row++) { //row starts at 0 and increments by one until 10
        for(int col = 0; col < dayIndex; col++) { //col starts at 0 and increments by one until 7
            arr[row][col] = rand() % 13; //arr at row, col is a random value between 0 and 13
        }
    }
}

//function hoursPerWeek
//takes a 2D with all 10 rows and 7 columns assigned, and gets the total hours of a specified employee
//Inputs - integer array with 10 rows and 7 columns, and a positive integer from 0 to 10;
//Outputs an integer that is the number of hours the employee worked that week.
int hoursPerWeek(int arr[employeeIndex][dayIndex], int employee) {
    int totalHours = 0; //counter for total hours
    for(int day = 0; day < dayIndex; day++) { //i starts at 0 and increments by one until it reaches 7
        totalHours += arr[employee][day]; //total hours adds the amount at day "day" to its total value
    }
    return totalHours; //returns totalHours
}

//function printDays
//Sets up the top of the table to display the days and the total at the end.
//Inputs - none
//Outputs - Prints the top of the array, which indicates the values at each day and the total after all the days.
void printDays() {
    for(int row = 0; row < 2; row++) { //row starts at 0 and increments by one until it is at 2
        cout << "    "; //prints a space so that the top lines up with the values correctly
        for(int col = 0; col < dayIndex+1; col++) { //col starts at 0 and increments by one until while it is less than dayIndex+1 
            if(row == 0) { //if the current row is 0...
                if(col == 7) { //if the current column is 7...
                    cout << setw(6) << "Total"; //set six spaces for and have "Total" take up 5/6 of them
                }
                else { //otherwise, if current column is not 7...
                    cout << setw(2) << col+1 << " |"; //set 2 spaces and print col+1 and then " |" to seperate each value. for example: " 1 | 2 | 3 | etc"
                }
            }
            else { //otherwise if the current row is not 0...
                if(col == 7) { //if col is 7...
                    cout << "______"; //print out 7 underscores to seperate the day counters and the actual values
                }
                else { //otherwise if col is not 7
                    cout << "____"; //print out 4 underscores to seperate the day counters from the actual values
                }
            }
        }
        cout << endl; //print a new line
    }
}

//function printHoursPerDay
//prints out the left side of a table with the values of the employees' hours worked each day following
//Inputs - an integer array with 10 rows and 7 columns
//Outputs - prints the left side of the table indicating the employee number, and then prints all of the hours worked each day for each employee
void printHoursPerDay(int arr[employeeIndex][dayIndex]) {
    for(int row = 0; row < employeeIndex; row++) { //row starts and 0 and increments by one while it is less than employeeIndex, which is 10
        for(int col = 0; col <= dayIndex+1; col++) { //col starts at 0 and increments by one while it is less than or equal to dayIndex+1
            if(col == 0) { //if col is 0...
                cout << setw(2) << row+1 << " |"; //prints two spaces, which will be replaced with row+1. Then prints " |" to seperate each value
            }
            else if(col == dayIndex+1) { //otherwise if col is equal to dayIndex+1...
                cout << hoursPerWeek(arr, row); //prints the total time the employee worked that week
            }
            else { //otherwise, if col is not 0 or dayIndex+1...
                //set two spaces for the value at this spot and fill untaken spaces with 0. taken spaces are filled with the 2D array at 
                //current row, current col-1. Finally, " |" is placed after the value to seperate it from other answers
                cout << setw(2) << setfill('0') << arr[row][col-1] << " |"; 
            } 
        }
        cout << endl; //print a new line
    }
}

//function printArray
//takes an array and prints the whole table containing the 2D array in it
//Inputs - an integer array with 10 rows and 7 columns
//Prints out a complete table containing correct days and employee values, with their corresponding hours worked
void printArray(int arr[employeeIndex][dayIndex]) {
    printDays(); //calls the printDays function to print the top part of the table
    printHoursPerDay(arr); //calls the printHoursPerday function to print the left of the table and all the values of the 2D array
}

//function overtime
//Finds how many days with more than 8 hours worked each employee has and prints out that value
//Inputs - integer array with 10 rows and 7 columns
//Outputs - prints the days each employee has with more than 8 hours worked
void overtime(int arr[employeeIndex][dayIndex]) {
    for(int employees = 0; employees < employeeIndex; employees++) { //employees starts at the 0th employee and increments by one while employees is less than employeeIndex
        int overtimeCounter = 0; //placeholder for amount of days a worker has with 8+ hours worked
        for(int day = 0; day < dayIndex; day++) { //day starts at 0 and increments by 1 while day is less than dayIndex
            if(arr[employees][day] > 8) { //if the amount of time a worker works in a given day is greater than 8...
                overtimeCounter++; //add one to overtimeCounter
            }
        }
        //print out how many days with more than 8 hours worked each employee has, if that number is greater than 0
        if(overtimeCounter > 0) {
            cout << "Employee " << employees+1 << " has " << overtimeCounter << " days with more than 8 hours." << endl;
        }
    }
}

//function badWorker
//parses the 2D array of employees and if an employee has less than 20 hours worked in the 7 given days, says that that worker is a bad worker and how many hours they have
//inputs - integer array with 10 rows and 7 columns
//outputs - prints out which employees have less than 20 hours worked in the week and how many hours they have
void badWorker(int arr[employeeIndex][dayIndex]) {
    for(int employees = 0; employees < employeeIndex; employees++) { //employees starts at 0 and increments by one while employees is less than employeeIndex
        if(hoursPerWeek(arr, employees) < 20) { //if the hoursPerWeek of an employee is less than 20...
            //print out who that employee is and how many hours they have worked
            cout << "Employee " << employees+1 << " is a bad employee with only " << hoursPerWeek(arr, employees) << " hours. :(" << endl;
        }
    }
}

int main() {

    int workTime[employeeIndex][dayIndex]; //create a new array with 10 rows and 7 columns called workTime
    fillArray(workTime); //Fill that array with random values from 0 to 12

    //say how the table is being displayed for clarification
    cout << "The left side values are the employee number and the numbers on the top are the days that the employee worked." << endl;
    
    printArray(workTime); //print the array
    cout << endl << endl;//print two new lines

    overtime(workTime); //say who has worked overtime and if so, how many days they did so

    badWorker(workTime); //say who has been a bad worker and how many hours they worked.
    
}