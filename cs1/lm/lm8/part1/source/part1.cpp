//part1.cpp
//CS171-1 CS1
//Aaron Borjas
//11/6/18
//calculates grade by breaking the final grade into three parts, Learning Module scores, Exam scores
//and the score of the final. Then it multiplies the LM score and exam score by 0.4 and the final score by 0.2
//and adds all of these together. Then it divides this final answer by 3 since there are three different grades being weighed.
//Once this happens, it checks the grade (which was the previous calculation) and determines the letter grade based on that

//set up variables
//collect input from user and testing
//collect subscores
    //LM
    //Tests
    //Final project
//final weight ----> total number grade ----> total letter grade
//display grade

//char/string lettergrade(float numGrade) 
    //if numgrade is between 90 and 100
        //return 'A' OR return "A+"
    //if numgrade is between 80 and 89
        //return 'B" or return "B-"""
    //etc

#include <iostream>
#include <cstdlib> //rand()
#include <time.h> //time for srand()
using namespace std;


//function userLMScore
//Gets 11 total scores for each learning module, one out of 50 and the rest out of 100
//Inputs - none
//outputs a total score, which will later be used to calculate a score out of the maximum score for learning modules
float userLMScore() { 

    float totalScore = 0; //totalScore starts at 0 
    float userScore; //placeholder for userScore
    
    srand(time(NULL)); //sets the seed for rand()

    for(int lmNum = 1; lmNum <= 11; lmNum++) { //lmNum starts at 1 and increments by one until it is greater than 11
        if(lmNum != 5) { //if lmNum is not lm5
            // cout << "What score did the student get out of 100 on LM" << lmNum << "? ";
            // cin >> userScore;
            // if(userScore > 100) {
            //     cout << "Enter a score out of 100: ";
            //     cin >> userScore;
            // }
            userScore = rand() % 101; //get a random score
            totalScore += userScore; //adds the random score to the value of totalScore
        }
        else { //if lmNum is lm5
            // cout << "What score did the student get out of 50 on LM5? ";
            // cin >> userScore;
            // if(userScore > 50) {
            //     cout << "Enter a score out of 50: ";
            //     cin >> userScore;
            // }
            userScore = rand() % 51; //get a random number between 0 and 51 (0-50)
            totalScore += userScore; //adds userScore to the value of totalScore
        }
    }
    return totalScore; //returns total score once lms are done calculating
}

//function lmTotal
//gets the total grade out of 1050 (the maximum grade) for all the learning modules
//inputs - the total correct out of 1050 (float)
//outputs the grade percent for all the learning modules
float lmTotal(float userScore) { 
    const float totalLM = 1050; //maximum possible score for all the learning modules

    float lmGrade = userScore/totalLM; //divides userScore by totalLM (1050) to get the amount correct out of 1050
    lmGrade = lmGrade * 100; //multiplies lmGrade by 100 to get the decimal to a percent out of 100
    return lmGrade; //returns the percent correct out of 1050
}

//function userExamScore
//gets the score for each exam out of their respective amounts, 57 for the first and 100 for the second
//inputs - none
//outputs - the total score of all the exams, which will be used later
float userExamScore() {
    float totalScore = 0; //totalScore starts at 0
    float userScore; //placeholder for user's score

    srand(time(NULL));//setting the seed for rand()

    for(int numExams = 1; numExams <= 2; numExams++) { //numExams starts at 1 and increments by one until it is greater than two
        if(numExams == 1) { //if the current exam is exam 1
            // cout << "What score did the student get out of 57 on Exam 1? ";
            // cin >> userScore;
            userScore = rand() % 58; //get a random number from 0 and 57 and assign it to userScore
            //cout << "userScore exam 1: " << userScore << endl;
        }
        else { //if the current exam is exam 2
            // cout << "What score dit he student get out of 100 on Exam 2? ";
            // cin >> userScore;
            userScore = rand() % 101; //get a random number between 0 and 100 and assign it to userScore
            //cout << "userScore exam 2: " << userScore << endl;
        }
        totalScore += userScore; //add userScore to totalScore
    }
    //cout << "totalScore exam 1 + exam 2: " << totalScore << endl;

    return totalScore; //return the total exam score
}

//function lmTotal
//gets the total grade out of 1050 (the maximum grade) for all the learning modules
//inputs - the total correct out of 1050 (float)
//outputs the grade percent for all the learning modules
float examTotal(float userScore) {
    const float totalExam = 157; //the maximum score for exams
    float examGrade = (userScore/totalExam) * 100; //multiplies userScore/totalExam by 100 for a percent out of 100
    return examGrade; //returns the percent out of 100
}

//function finalTotalScore
//gets the total grade out of 100 (max grade for the final)
//inputs - none
//outputs the grade percent for the final
float finalTotalScore() {
    const float finalTotal = 100; //max score of the final
    float finalScore;

    srand(time(NULL)); //setting the seed for rand()

    finalScore = rand() % 101; //user's final score is a random number between 0 and 100

    // cout << "What score did the student get out of 100 on the final? ";
    // cin >> finalScore;

    return (finalScore/finalTotal) * 100; //returns the user's score divided by the max score, then multiplied by 100 for a percent out of 100
}

//function weighGrades
//takes each seperate total grade and adds them together, while weighing each part respectively
//inputs - the total grade of all the learning modules (float), the total of the exams (float), and the score of the final (float)
//outputs - the weighed percentage of the class, the total grade
float weighGrades(float LMGrade, float examGrade, float finalGrade) {
    float weighedGrades; //placeholder for weighed grade

    //weighedGrades is equal to LMGrade * 0.4 + examGrade * 0.4 + finalGrade * 0.2. Then, that answer is divided by 3, since 3 items are being weighed.
    weighedGrades = ((LMGrade * 0.4) + (examGrade * 0.4) + (finalGrade * 0.2))/3;

    return weighedGrades;//returns weighed grades
}

//function letterGrade
//this function turns the finalScore of a class into a letter grade
//inputs - the final score (float)
//outputs the grade as a letter (char)
char letterGrade(float finalScore) {
    if(90 <= finalScore) { //if the score is greater than 90
        return 'A'; //return A
    }
    else if((80 <= finalScore) && (finalScore < 90)) { //if the score is greater than or equal to 80 or less than 90
        return 'B'; //return B
    }
    else if((70 <= finalScore) && (finalScore < 80)) { //if the score is greater than or equal to 70 or less than 80
        return 'C'; //return C
    }
    else if((60 <= finalScore) && (finalScore < 70)) {//if the score is greater than or equal to 60 or less than 70
        return 'D'; //return D
    }
    else if(finalScore < 60) {//if the score is less than 60
        return 'F'; //return F
    }
    return 'A'; //otherwise return A
}

int main() {
    const float totalLM = 1050; //max score for learning modules (const so I don't accidentally change it)
    const float totalExam = 157;//max score for exams (const so I don't accidentally change it)
    const float finalTotal = 100; //max score for the final (const so I don't accidentally change it)

    float userLM = userLMScore(); //calling userLMScore() and assigning the value to a variable so I don't use a random number every single time I call the function
    float userExam = userExamScore(); //calling userExamScore() and assigning the value to a variable so I don't use a random number every single time I call the function
    float finalScore = finalTotalScore(); //calling finalTotalScore() and assigning the value to a variable so I don't use a random number every single time I call the function

    //printing the previous 3 initializations for visual confirmation and seeing some of the background tasks
    cout << "Total learning module score is " << userLM << "/" << totalLM << ", or " << lmTotal(userLM) << "%" << endl;
    cout << "Total exam score is " << userExam << "/" << totalExam << ", or " << examTotal(userExam) << "%" << endl;
    cout << "Final exam score is " << finalScore << "/" << finalTotal << ", or " << (finalScore/finalTotal) * 100 << "%" << endl;

    //printing total weighed grade as a percent
    cout << "The total grade, where LMs are worth 40%, both exams combined are 40%, and the final grade is worth 20%, is: " << weighGrades(userLM, userExam, finalScore) << "%" << endl;

    //printing the total weighed grade as a letter grade based on the percent
    cout << "The final letter grade, based on the previous precent, is a " << letterGrade(weighGrades(userLM, userExam, finalScore));
}