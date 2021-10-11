//evennumber.h
//CS172-1 CS2
//Aaron Borjas
//2/19/19
//creates a class that represents only even numbers. Creates two of these numbers using the class, one that is 0 and another
//that is created based on user input. Then iterates from one to the next, printing all the even numbers from the first to second
#ifndef EVENNUMBER_h
#define EVENNUMBER_h
class EvenNumber {
    private:
        int currentNumber; //member variable for the value of the EvenNumber
        int previousNumber; //member variable for the value of the even number before the value of currentNumber even number
        int nextNumber; //member variable for the value of the even number after the value of currentNumber even number

    public:
        //class constructor EvenNumber()
        //creates an EvenNumber without input which starts at 0 and has a previous number of -2 and next number of 2
        EvenNumber();

        //class constructor EvenNumber(int num)
        //creates an EvenNumber with input of an even integer that has a previous number of num-2 and a 
        //next number of num+2
        EvenNumber(int num);

        //gets the value of the current number that is assigned to EvenNumber
        //no inputs
        //returns the current value of the EvenNumber
        int getValue();

        //gets the value of the previous number relative to that which is assigned to EvenNumber
        //no inputs
        //returns the number preceding the current value of EvenNumber
        int getPrevious();

        //gets the value of the next number relative to that which is assigned to EvenNumber
        //no inputs
        //returns the number after the current value of EvenNumber
        int getNextNumber();
};


#endif