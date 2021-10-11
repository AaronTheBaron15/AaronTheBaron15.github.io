//part2.cpp
//CS171-1 CS1
//Aaron Borjas
//10/15/18
//printing out different patterns with nested loops

#include <iostream>
using namespace std;

int main () {

    // ========= PATTERN 1 =========
    
    for(int row = 0; row <= 5; row++) { //code inside this is looped 6 times (0-5 is 6)
        for(int col = 0; col <= row; col++) { // code inside this loops from 1-6 times. If row is 1, the code loops once
            cout << ". "; //prints ". " 
        }
        cout << endl << endl; //adds two enters after the second loop is done printing
    }
    

    // ========= PATTERN 2 =========
    
     for(int row = 0; row <= 5; row++) { //row starts at 0 and goes until 5, making 6 rows (and looping 6 times)
         int maxSpaces = 10; //the most amount of spaces (at the first row), since the amount of spaces at the last row before the last . is 10
         for(int spaces = maxSpaces-(2*row); spaces > 0; spaces--) { //loop to create the correct number of spaces, which is always maxSpaces-(2*row)
             cout << " "; //prints a space
         }
         for(int col = 0; col <= row; col++) { //col starts at 0 and goes until col is greater than row. Code inside loops 6 times (because row doesn't go over 5 and 0-5 is 6)
            
             cout << ". "; //prints ". "
         }
         cout << endl << endl; //makes a new line 2 times once each row is done printing
     }
    

    // ========= PATTERN 3 =========
    
    //row starts at 1 and goes until it is greater than 7. Every time the code loops, row adds one more to its value
    for(int row = 1; row <= 7; row++) {

        //if row is less than or equal to four...
        if(row <= 4) {
            //cout << "first if"; //making sure it is running correctly

            //col starts at 0 and goes until it is greater than or equal to row. every time the code loops
            //col increments up by 1
            for(int col = 0; col < row; col++) {
                cout << ". "; //prints out ". "
            }
            cout << endl << endl; //makes two new lines after each row is created
        }

        //if row is greater than four...
        if(row > 4) {
            //cout << "second if"; //making sure it is running correctly 
            int maxRow = 4; //the row with the most dots
            //col starts at 7 and goes until it is less than row. Every time the code loops col decrements by 1
            for(int col = 7; col >= row; col--) {
                cout << ". ";//printsn out ". "
            }
            cout << endl << endl; //makes two new lines after each row is created
        }
    }
    

    // ========= PATTERN 4 =========
    
    //row starts at 1 and goes until it is greater than 5. adds one to row each time the code inside loops
    for(int row = 1; row <=5; row++) {
        //col starts at 0 and goes until it is greater than or equal to row. Every time the code loops
        //col increases by 1 
        for(int col = 0; col < row; col++) {
            cout << (col)+1 << " "; //prints out col+1 and then a space
        }
        cout << endl << endl; //makes two new lines after each row is created
    }
    

    // ========= PATTERN 5 =========
    
    //row starts at 1 and goes until it is greater than 5. adds one to row each time the code inside loops
    for(int row = 1; row <=5; row++) {
        //col starts at whatever row is equal to and goes until it is less than or equal to zero.
        //col decrements each time the code repeats
        for(int col = row; col > 0; col--) {
            cout << col << " "; //prints out col and a space
        }
        cout << endl << endl; //makes two new lines after each row is created.
    }
    

    // ========= PATTERN 6 =========
    
    //makes 6 rows, if row starts at 1 and goes until it is greater than 6. row increments up by 1
    //each time the code inside is complete and until row is greater than 6.
    for(int row = 1; row <= 6; row++) {

        if(row < 4) { //if row is less than 4

            //col is equal to whatever the row number is. the code is repeated until col is equal to or less than 0
            //col decrements each time the code runs.
            for(int col = row; col > 0; col--) {
                cout << col << " "; //prints col and a space
            }
            cout << endl << endl;//makes two new lines after each row is created.
        }
        else { //if row is greater than or equal to 4
            // switch(row) {
            //     case 4: 
            //         cout << "  ";
            //         break;
            //     case 5:
            //         cout << "    ";
            //         break;
            //     case 6:
            //         cout << "      ";
            //         break;
            // }
            if(row==4){ //if the current row is 4
                cout << "  "; //print out two spaces
            }
            else if(row==5) {//if the current row is 5
                cout << "    "; //print four spaces
            }
            else {//otherwise if row is 6 (because that's the only other option since row doesn't go above 6)
                cout << "      "; //print out six spaces
            }

            //col is equal to 6(maxrows) minus (row-1). This gives the correct starting 
            //col value for each row. Since 6 is the maximum number of rows and 6-4 is two, which is one less than
            //what we want, 1 is subtracted from row before row is subtracted from 6. 
            //the code inside this loop is continued while col is greater than zero
            //col-- subtracts 1 from col each time the loop happens.
            for(int col = 6-(row-1); col > 0 ; col--) { 
                cout << col << " ";//prints out col and then a space
            }
            cout << endl << endl; //makes two new lines after all the code for row runs.
        }
    }

}