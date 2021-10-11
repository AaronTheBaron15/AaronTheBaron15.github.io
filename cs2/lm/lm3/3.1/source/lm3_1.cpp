//lm3_1.cpp
//CS172-1 CS2
//Aaron Borjas
//2/24/19
//using the string class, using string.size(), string.at(), string.back(), and string.append(). Also,
//has functions that checks for anagrams and reverses all words in a string
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;
//THIS IS IMPLEMENTED FROM LM 5.1
//binarySearch, which searches a sorted array of integers for a specific number and returns the index of the number. if the number does not exist, returns the negative index of where it should be
//inputs - an integer array, whose length is determinded by a start point and end point (indeces), and an integer desiredNum that is the number being searched for in the array
//outputs - returns the index of the desired number, but if the number is not in the array, prints where it would go
int binarySearch(string str, int start, int end, char desiredChar) {
    int midIndex = ((end-start)/2)+start;//the middle index is equal to end index minus start index, divided by two, and then addings start index to that value
    if(end < start) {
        return -1*(start+1); //otherwise if the number is not in the array, return the "negative" index of the number (instead of 0 indexing, it indexes to -1. for example, the negative indeces of the array are -1, -2, -3, -4, etc.)
    }
    //else if(str[midIndex] < desiredChar) { //if the array at midIndex is less than desiredNum
    //scott edit:
    else if(str[midIndex] > desiredChar) {
        return binarySearch(str, midIndex+1, end, desiredChar); //check the upper half of the array from midIndex+1 (since we already "searched" the mid index) to the end index
    }
    //else if(str[midIndex] > desiredChar) { //otherwise if the array at midIndex is greater than desired num, 
    //scott edit:    
    else if(str[midIndex] < desiredChar) {
        return binarySearch(str, start, midIndex-1, desiredChar); //check the lower half of the array from start to midIndex-1 (since we already checked the mid index)
    }
    else if(str[midIndex] == desiredChar) { //otherwise, if array at midIndex is equal to the desired number
        return midIndex; //return the desired number
    }
    return 0;
}

//THIS IS IMPLEMENTED FROM LM5.1
//insertElement, which is a function that inserts a given number into a certain position of an array with a predetermined length
//inputs - three integers, pos is the index of where the value is to be placed (positive), value is the value to put into the array, and length is the length of the array. The last input is an array of integers called arr
//outputs - changes the values of the array and inserts the chosen value into the chosen position
//void insertElement(int pos, int value, string& str, int length) {
//Scott Edit:
void insertElement(int pos, char value, string& str, int length) {

    //Scott Edit:
    if(pos < 0){
        pos = (pos*-1)-1;
    }
    cout << "Inserting pos" << pos;
    cout << "Value: " << value << endl;


    for(int i = length-1; i > pos; i--) { //iterates through the array
        str[i] = str[i-1]; //sets the value of the array at index i to the value of the array at index i-1
        //cout << "arr[" << i << "] is: " << arr[i] << endl;
    }
    str[pos] = value; //sets the value of array at index pos to value
}

//sortArray is a function that sorts an array using a binary search to figure out where each number goes
//inputs - a string that is unsorted and length of the string that is a positive integer
//outputs - sorts the array of integers
void sortString(string& str, int length) {
    string sortedArr = ""; //creates a sorted array of length str.length(), which is filled with zeros
    //sortedArr[0] = str[0];
    //Scott edit:
    sortedArr.append(1,str[0]);//the first value of sortedArr is set to the first value of arr
    //cout << "sorted arr[0] is: " << sortedArr[0] << endl; //bug testing
    int incrementor = 0; //an integer called incrementor which increments through the course of the function

    for(int i = 1; i < length; i++) { //iterates through first arr
        cout << "sortedArray2: " << sortedArr << endl;
        cout << "str         : " << str << endl;
        int index = binarySearch(sortedArr, 0, incrementor, str[i]); //creates an integer called index, which is the index where the value of arr[i] goes inside a subsection of the sorted array, which is from 0 to incrementor
        cout << "Index: " << index << endl;
        //cout << "Index is: " << index << endl; //bug testing
        if( (index < 0) /*&& !(str[-1*(index+1)] == ' ')*/) { //if index is less than zero
            index = -1*(index+1);//changes index to an actual index of the array
            insertElement(index, str[i], sortedArr, length); //inserts the value of arr[i] into the sorted array at index index
        }
        else if( (index > 0) /* && (str[index] == ' ')*/) { //if index is greater or equal to zero
            insertElement(index, str[i], sortedArr, length); //inserts the value of arr[i] into the sorted array at index index
        }

        incrementor++; //increments the incrementor

    }
    for(int i = 0; i < length; i++) { //iterates through the arrays
        str[i] = sortedArr[i]; //sets array at index i to the value of sorted array at index i
    }
}

//uses functions from LM5.1 (binary search and sort)
//anagramCheck, a function that checks if one string is an anagram of the other. This means that the letters in one string can be scrambled to create another word
//inputs - string one and string two, both are strings of any length
//outputs - true if the strings are anagrams, false if not
bool anagramCheck(string& one, string& two) {
    sortString(one, one.length()); //sorts the first string
    sortString(two, two.length()); //sorts the second string

    cout << one << endl;//prints one
    cout << two << endl;//prints two

    int i = 0; //creates new integer called i and sets it to zero
    int j = 0; //creates new integer called j and sets it to zero
    while(one[i] == ' ') { //while one at index i is equal to a space
        i++; //increments i
    }

    while(two[j] == ' ') { //while two at index j is equal to a space
        j++;//increment j
    }

    // cout << "i is: " << i << endl;
    // cout << "i is: " << i << endl;

    while( (i <= one.length()) || (j <= two.length())) { //while i is less than one.length() or while j is less than two.length()
        if(one[i] != two[j]) {
            // cout << one << endl;
            // cout << two << endl;
            // cout << "one[" << i << "] is: " << one[i] << endl;
            // cout << "two[" << j << "] is: " << two[j] << endl;
            //cout << "WHAT" << endl;

            return false; //return false
        }
        else {
            // cout << "one[" << i << "] is: " << one[i] << endl;
            // cout << "two[" << j << "] is: " << two[j] << endl;
            i++; //increment i
            j++; //increment j
        }
    }
    return true; //return true
}


//function reverseWord, which reverses a string. eg "hello" turns into "olleh"
//inputs - takes a string that passes by reference, which means that the string is directly changed by the function
//no outputs, but directly changes the input string
void reverseWord(string& str) 
{ 
    int n = str.length(); //makes the length of the string a variable
    for (int i = 0; i < n / 2; i++) { //iterates through half of the string
        swap(str[i], str[n - i - 1]); //uses the swap function to swap the characters at index i with the characters at the final index minus i minus one
    }
} 

//function reverseWords, which takes a sentence and reverses all the words individually, excluding any non-letters and non-numbers
//inputs - a string called str, which can be a sentence or more, that passes by reference, which means that it can be changed from within the function
//outputs- none, but does change the contents of str
void reverseWords(string& str) {
    for(int i = 0; i < str.length(); i++) { //iterates through the string
        //cout << "start i: " << i << endl; //testing where i starts at
        //if the string at index i is not a space and is a letter/number...
        if((str.at(i) != ' ') && ((isalpha(static_cast<int>(str.at(i)))) || (isdigit(static_cast<int>(str.at(i))))) ){
            int length = 0; //create a new integer to contain the distance between the start of a word and end of a work
            int fakeI = i; //placeholder for iterating through the array without messing up i

            //while the string at index i is not a space and is a letter/number (this is iterating through an individual word of the string)
            while( (str.at(fakeI) != ' ') && ((isalpha(static_cast<int>(str.at(fakeI)))) || (isdigit(static_cast<int>(str.at(fakeI)))))) {
                //cout << "str at " << fakeI << " is: " << str.at(fakeI) << endl; //testing what the character of str at index fakeI is
                length++; //increment length
                fakeI++;//increment fakeI
                //cout << "Length : " << length << " and fakeI: " << fakeI << endl; //prints the length and fakeI for testing
            }
            //cout << "i+Length : " << i+length << endl; //prints what i+length is (i misunderstood how to use substr, i thought the second number was supposed to be the ending position of the string to grab. this is part of my misunderstanding)

            string specificString = str.substr(i, length); //creates a new string called specificString, which holds the current word of str (used with a substring that starts at i and goes length characters after that)
            //cout << "specific string: " << specificString <<  endl;//testing what specific string is
            reverseWord(specificString); //calls reverseWord on specificString, reversing the characters in it
            //cout << "reversed string: " << specificString << endl; //testing what reversed string it

            str.replace(i, length, specificString); //replaces old word with the reversed word (i is the starting position, length is the number of characters to replace, and specificString is the string to replace the old substring with)
            i+=length; //add length to the value of i so the next word is at the current index
        }
        //cout << "end i: " << i << endl; //testing i after the if statement
    }
}



int main() {
    string constructorOne = string(); //first constructor 
    string constructorTwo = string("constructor two!");//second constructor
    string constructorThree = string("constructor three!", 0, 18); //third constructor (substring)

    char charArray[] = {':', ')'}; //a character array with ':' and ')' in it, making it :)
    string constructorFour = string(charArray);//fourth constructor
    string constructorFive = string(charArray, 2);//fifth constructor
    string constructorSix = string(6, 'A'); //seventh constructor
    

    //=============
    //string.size()
    //=============
    string strOne = "Hello there😄"; //string that says "hello there" with an emoji at the end
    string strTwo = "Hello there"; //string that says "hello there" without an emoji

    //gets the size of string one in terms of bytes, one character is 1 byte
    cout << "The size of string one is: " << strOne.size() << " characters." << endl;

    //gets the size of string two in terms of bytes, one character is 1 byte
    cout << "The size of string two is: " << strTwo.size() << " characters." << endl;

    if(strOne.size() > strTwo.size()) { //if string one's byte size is larger than string two's byte size
        //the reason why strOne has a larger size is because of the emoji, which is not ASCII but unicode, which has a larger byte size
        cout << "String one has a large size by " << strOne.size()-strTwo.size() << " bytes!" << endl; //say how much larger string one's byte size is
    }
    else { //if string two's byte size is larger than string one's byte size
        cout << "String two has a large size by " << strTwo.size()-strOne.size() << " bytes!" << endl; //say how much larger string two's byte size is
    }

    cout << endl;

    //===========
    //string.at()
    //===========
    string testAt = "Testing At!"; //a string to test the string.at() function on

    cout << "the string testAt looks like this: " << testAt << endl;

    for(int i = 0; i < testAt.length(); i++) { //iterating through testAt
        cout << testAt.at(i) << " "; //prints out the character at index i, plus a space afterwards to show that testAt.at() works
    }
    cout << endl << endl;

    //=============
    //string.back()
    //=============
    string testBack = "tHiS Is tEsTiNg ThE bAcK fUnCtIoN?"; //a string to test string.back() on
    cout << "testBack is: " << testBack << endl;
    cout << "The last character of string testBack is: " << testBack.back() << endl; //gets the last character in testBack

    testBack.back() = '!';

    cout << "The new last character of string testBack is: " << testBack.back() << endl; //gets the last character in testBack


    string reversedString = "!1/?!/!NoItCnUf KcAb EhT gNiTsEt sI SiHt"; //the reverse of the first string

    cout << "the reversed string is: " << reversedString << endl; //prints the reversed string
    cout << "The last character of the new testBack is: " << reversedString.back() << endl; //prints the last character in reversedString

    cout << endl;

    //===============
    //string.append()
    //===============

    string appendTest = "I enjoy "; //makes a string that contains "I enjoy " in it

    cout << "The appendTest string is currently: " << appendTest << endl;//printing appendTest

    //appending a string
    appendTest.append("tacos "); //appends "tacos " to the end of appendTest

    cout << "The appendTest string is currently: " << appendTest << endl;//printing appendTest

    //appending a substring
    appendTest.append("a lot!", 0, 6); //appends the substring "a lot!" from character 0 to character 6. if 0 were to change to 1, it would append " lot!" to the end of appendTest

    cout << "The appendTest string is currently: " << appendTest << endl;//printing appendTest

    char smile[] = {' ', ':', 'D'}; //creates an array of characters which is composed of a space, a colon, and a capital d. It's a smiley face :D

    appendTest.append(smile); //appends the character string smile to the end of appendTest

    cout << "The appendTest string is currently: " << appendTest << endl; //printing appendTest


    
    char newChar = 'D'; //makes a character with the value 'D' in it

    int randomNum = (rand()%8)+1; //random number from 1 to 8

    //appending a character newChar randomNum amount of times
    appendTest.append(randomNum, newChar); //appends the letter 'D' to appendTest

    cout << "The appendTest string is currently: " << appendTest << endl; //printing appendTest

    cout << endl;

    string stringone = "dog";
    string stringtwo = "god";
    
    if(anagramCheck(stringone, stringtwo)) { //checks if dog and god are anagrams of each other 
        cout << "god and dog are anagrams!" << endl;
    }
    else{ //if they arent anagrams...
        cout << "god and dog are not anagrams!" << endl; //false
    }

    cout << endl;

    stringone = "i am lord voldemort";
    stringtwo = "tom marvolo riddle";

    if(anagramCheck(stringone, stringtwo)) { //checks if wee and eww are anagrams of each other
        cout << stringone << " and " << stringtwo << " are anagrams!" << endl; //true
    }
    else{ //if they aren't anagrams...
        cout << stringone << " and " << stringtwo << " are not anagrams!" << endl; //false
    }
    cout << endl;

    string testRevWords = "CS2 is the best class ever!"; //creates the string to reverse
    cout << "testRevWords is: " << testRevWords << endl; //prints the string so we know what it begins as
    reverseWords(testRevWords); //calls reverseWords on testRevWords (to reverse the words)
    //testRevWords.replace(0, 2, "Calc");//testing how to use replace
    cout << "the reverse of testRevWords is: " << testRevWords << endl; //printing the testRevWords with reversed words
}