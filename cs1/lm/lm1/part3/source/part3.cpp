#include <iostream>
using namespace std;    

int main() {
    float total; //total check for meal
    int totalPeople; // number of people paying

    cout << "The total is: ";
    cin >> total;

    cout << "The number of people in your party is: ";
    cin >> totalPeople;

    float split = total / totalPeople; //total divided by total people
    cout << "The base amount that each person pays (check divided by number of people): " << split << endl;

    cout << "The amount each person should pay, including 10% tip, is: " << split * 1.1 << endl;
    cout << "The amount each person should pay, including 15% tip, is: " << split * 1.15 << endl;
    cout << "The amount each person should pay, including 20% tip, is: " << split * 1.2 << endl;
    cout << "The amount each person should pay, including 25% tip, is: " << split * 1.25 << endl;
}