//aaron Borjas
//2/24/2020
//CS278
//Dr. Bell
//this program checks if an input number has repeated 1's in its binary representation
#include <iostream>
#include <iterator>
#include <cmath>

bool checkRepeat(int num) {
    int bin [16] = {0};

    int i = 0;
    while(num > 0) {
        bin[i] = num % 2;
        num = num / 2;
        i++;

    }

    
    while(i >= 0) {
        std::cout << bin[i];
        i--;
    }

    std::cout << std::endl;
    

    int j = 0;
    while(j < 15) {
        int counter = 0;
        if(bin[j]==1 && (bin[j] == bin[j+1])) {
            counter++;
            return true;
        }
        j++;
    }
    return false;
}

int main() {

    int input = 0;
    std::cout << "Enter a decimal number between 0 and 32768: " << std::endl;
    std::cin >> input;

    std::cout << "Does " << input << " have 1's repeating in it's binary representation?: " << std::to_string(checkRepeat(input)) << std::endl;

    return 0;
}