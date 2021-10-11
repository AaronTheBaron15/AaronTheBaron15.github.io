/**
*	Recursive Binary Search
*	Reading: section 7.3
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

/**
*	Template function for performing the recursive binary search
*/
//this function is based heavily on my implementation of a binary search function from CS172 spring 2018
template <typename T>
int binarySearch(const vector<T> &items, int first, int last, T target) {
	int midIndex = ((last - first)/2) + first;//the middle index is equal to lastindex minus first index, divided by two, and then addings first index to that value
    if(last < first) {
        return -1*(first+1); //otherwise if the number is not in the array, return the "negative" index of the number (instead of 0 indexing, it indexes to -1. for example, the negative indeces of the array are -1, -2, -3, -4, etc.)
    }
    else if(items.at(midIndex) < target) { //if the array at midIndex is less than desiredNum
        return binarySearch(items, midIndex+1, last, target); //check the upper half of the array from midIndex+1 (since we already "searched" the mid index) to the lastindex
		
    }
    else if(items.at(midIndex) > target) { //otherwise if the array at midIndex is greater than desired num, 
        return binarySearch(items, first, midIndex-1, target); //check the lower half of the array from first to midIndex-1 (since we already checked the mid index)
    }
    else if(items.at(midIndex) == target) { //otherwise, if array at midIndex is equal to the desired number
        return midIndex; //return the desired number
    }
	return -1;
}

/**
*	Template function for invoking the recursive binary search function.
*	This is the function a user calls.
*/
template <typename T>
int binarySearch(const vector<T> &items, T target) {
	return binarySearch(items, 0, items.size()-1, target);
}

int main()
{
	/** TEST */
	vector<int> haystack;

	srand(1);
	for (int i = 0; i < 1000000; ++i) // initialize the vector with random values
		haystack.push_back(rand()%1000);

	sort(haystack.begin(), haystack.end()); // sort the contents of the vector

	bool retryflag = true;
	do {
		int needle;
		cout << "Enter a number to search for [-1 to exit]: ";
		cin >> needle; // get the value to search for in the vector
		if (needle == -1) {
			retryflag = false; // time to exit 
		} else {
			int idx = binarySearch(haystack, needle); // search for the needle in the haystack
			if (idx != -1) // found the index where the needle is located in the haystack
				cout << needle << " found at index " << idx << endl;
			else
				cout << needle << " is not in haystack\n";
		}
	} while (retryflag);

}