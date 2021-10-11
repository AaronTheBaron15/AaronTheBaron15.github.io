//Aaron Borjas
//2/24/2020
//CS278
//Dr. Bell
//this program adds on from part2 of sg3 and checks is there are repeated 1's in all the numbers from 0 to an input number minus 1
#include <iostream>
#include <iterator>
#include <cmath>

bool checkRepeat(int num) {
    int bin [16] = {0};

    int temp = num;
    int i = 0;
    while(temp > 0) {
        bin[i] = temp % 2;
        temp = temp / 2;
        i++;
    }
    //std::cout << "check 1" << std::endl;
    
    while(i >= 0) {
        std::cout << bin[i];
        i--;
    }
    std::cout << " <-- " << num << std::endl;

    //std::cout << "check 2" << std::endl;

    int j = 0;
    while(j < 15) {
        int counter = 0;
        //std::cout << "check 3" << std::endl;
        if(bin[j]==1 && (bin[j] == bin[j+1])) {
            counter++;
            //std::cout << "check 4" << std::endl;
            return true;
        }
        j++;
    }
    //std::cout << "check 5" << std::endl;
    return false;
}

int repeatCounter(int input) {
    int counter = 0;
    int currNum = 0;
    while(currNum < input) {
        //std::cout << "Currnum = " << currNum << std::endl;
        if(checkRepeat(currNum)) {
            //std::cout << "checkrepeat(currnum) = " << checkRepeat(currNum) << std::endl;
            counter++;

        }
        currNum++; 

    }
    return counter;
}

int main() {

    int input = 0;
    std::cout << "Enter a decimal number between 0 and 32768: " << std::endl;
    std::cin >> input;

    std::cout << "Number of repeats of numbers from 0 to " << input - 1 << ": " << std::to_string(repeatCounter(input)) << std::endl;

    return 0;
}