//part2.cpp
//CS171-1 CS1
//Aaron Borjas
//10/1/18
/* calculates when thanksgiving is, given what day the first of the month is on and that the earliest possible date 
 * for thanksgiving is November 22.
 * This is done by using a switch statement to evaluate the value of the first day of the month, 
 * based on the first day of the month, it assigns a value to daysFromThurs, which is how many days the first is from the 
 * first thursday of the month. Then, the value of thanksgiving is assigned by the calculation of (1+(7*3)) + daysFromThurs.
 * The (1+(7*3)) section calculates the base date for thanksgiving to be on, which is November 22. 7*3 is 3 weeks, and adding 1 makes the date
 * correct, since there is no 0th day of November and otherwise Thanksgiving would be on November 21, which isn't possible.
 * Then, the + daysFromThurs portion adds how many days away from thursday the first of the month is, which when combined with
 * (1+(7*3)), gives the correct date for thanksgiving based on the first of the month.
 */

#include <iostream> //include cout, cin
using namespace std;

int main() {
    int firstDay, daysFromThurs, thanksgiving; //initiate firstDay, daysFromThurs, and thanksgiving as integer variables for later

    // tells the user what to enter
    cout<< "Use a numbering system: 1=Sunday, 2=Monday, 3=Tuesday, 4=Wednesday, 5=Thursday, 6=Friday, and 7=Saturday ";
    cin >> firstDay; //asks the user for the value of firstDay

    //switch statement for the value of firstDay
    switch(firstDay) {
        case 1://if firstDay=1 or Sunday
        
            daysFromThurs = 4; //from sunday to thursday is 4 days
            cout << "*user entered 1 for Saturday*" << endl << "The first day of the month is Sunday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is
            break; //ends the switch statement so nothing else is printed

        case 2: //if firstDay=2 or Monday
        
            daysFromThurs = 3;//from monday to thrusday is 3 days
            cout << "*user entered 2 for Monday*" << endl << "The first day of the month is Monday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is            
            break;//ends the switch statement so nothing else is printed

        case 3: //if firstDay=3 or Tuesday

            daysFromThurs = 2;//from tuesday to thursday is 2 days
            cout << "*user entered 3 for Tuesday*" << endl << "The first day of the month is Tuesday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is            
            break;//ends the switch statement so nothing else is printed

        case 4://if firstDay=4 or Wednesday

            daysFromThurs = 1;//from wednesday to thursday is 1 day
            cout << "*user entered 4 for Wednesday*" << endl << "The first day of the month is Wednesday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is            
            break;//ends the switch statement so nothing else is printed

        case 5://if firstDay=5 or Thursday

            daysFromThurs = 0; //thursday to thursday is 0 days
            cout << "*user entered 5 for Thursday*" << endl << "The first day of the month is Thursday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is            
            break;//ends the switch statement so nothing else is printed

        case 6: //if firstDay=6 or Friday

            daysFromThurs = 6;//friday to thursday is 6 days
            cout << "*user entered 6 for Friday*" << endl << "The first day of the month is Friday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is            
            break;//ends the switch statement so nothing else is printed

        case 7://if firstDay=7 or Saturday

            daysFromThurs = 5; //saturday to thursday is 5 days
            cout << "*user entered 7 for Saturday*" << endl << "The first day of the month is Saturday!" << endl;// confirms user choice, says what the first day is because it wasnt displayed before
            thanksgiving = (1+(7*3)) + daysFromThurs;// calculates the date of thanksgiving based on how far from thursday the first of the month
            cout << "Thanksgiving will be on November " << thanksgiving << "!"; //prints out when thanksgiving is
            break;//ends the switch statement so nothing else is printed

        default: //if none of these conditions are met
            cout << "pick a number between 1 and 7!"; //print out an error message

    }
}