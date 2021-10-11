//This file is the main file that gathers and runs all the parts for CS273-1 HW3
//Aaron Borjas
//10/29/2019
//CS273-1
//Instructor - Matt Bell
//this file declares a few stacks which are implemented with a linked list and a vector,
//also creates some functions, one for Infix to postfix and two for assisting the infix to 
//postfix function. Some infix to postfix expressions are then translated in the main function
#include <iostream>
#include <string>
#include "../headers/ListStack.h"
#include "../headers/VectorStack.h"
using namespace Aaron;

//precedence determines the "value" of an input operator for infix to postfix
//input - a character that is an operator, eg. *, /, +, -, (, or )
//output - returns the "value" of the operator. * and / are higher valued, + and - and lower, and ( and ) are lowest
int precedence(char token) {
    switch(token) { //uses a switch statement, which takes in the token
        case '*': //if multiplication
            return 2; //return 2
            break;
        case '/': //if division
            return 2; //return 2
            break;
        case '+': //if addition
            return 1; //return 1
            break;
        case '-': //if subtraction
            return 1; //return 1
            break;
        case '(': //if (
            return -1; //return -1
            break;
        case ')': //if )
            return -1; //return -1
            break;
        default: //if none of the cases are met
            std::cout << "Input token \"" << token << "\" was not an operator." << std::endl;
            break;
    }
    return 0;
}

//this function is based heavily on the example lectured on, from the StacksAndQueues slide set
//inputs - takes in an character operator "token" and a reference to a vectorStack of characters 
//outputs - updates the input stack based on the precedence of the token
void process_operator(VectorStack<char>& stack, char token, std::string& PFexpression) {
    if(stack.empty() || token == '(') { //if the stack is empty or the token is equal to an open parenthesis
        stack.push(token); //push the token to the stack
    }
    else if(precedence(token) > precedence(stack.top())) { //otherwise, if the precedence of token is greater than the precedence of the item at the top of the stack
        stack.push(token); //push the token to the stack
    }
    else { //otherwise,
        do { //do this stuff
            PFexpression += stack.top(); //append the top element of the stack to the postfix expression
            stack.pop();//pop the top of the stack
        } while( (stack.top() != '(') && (precedence(token) <= precedence(stack.top())) ); //while the top of the stack isnt '(' and the value of token is <= the value of the item at the top of the stack

        if(token == ')') { //if the token is a closing parenthesis
            stack.pop(); //pop the parenthesis from the stack
        }
        else { //otherwise,
            stack.push(token);//push the token to the stack
        }
    }
}

std::string IF2PF(std::string expression) {
    std::string postfix;
    VectorStack<char> operators;
    
    std::string::iterator it = expression.begin();
    while(it != expression.end()) {
        char currToken = static_cast<char>(*it);

        if(isdigit(currToken) || isalpha(currToken)) { //if the current token is a digit or a letter
            postfix += currToken; //append the current token to postfix
        }
        //if the current token is an operator
        else if(currToken == '*' || currToken == '/' || currToken == '+' || currToken == '-' || currToken == '(' || currToken == ')') {
            process_operator(operators, currToken, postfix); //process the operator 
        }
        else {
            std::cout << "Something was wrong with the syntax of the infix expression! Try again!" << std::endl;
        }
        ++it;
    }

    while(!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }
   
   return postfix;
}

int main() {
    //*****Testing VectorStack*****
    VectorStack<int> myNums; //create new vectorStack
    for(int i = 0; i < 10; i++) { //interate from 0 to 9 (incrementing by 1)
        myNums.push(i); //push i to the vectorStack
    }

    VectorStack<int> tempStack = myNums; //create a temporary vectorStack
    while(!tempStack.empty()) { //while the temporary stack is not empty
        std::cout << tempStack.top() << std::endl; //print the top element of the vector stack
        tempStack.pop(); //pop the top element of the vector stack
    }

    //*****Testing ListStack*****
    ListStack<int> myNums2; //create new ListStack
    for(int i = 0; i < 10; i++) { //iterate from 0 to 9 (incrementing by 1)
        myNums2.push(i); //push i to the ListStack
    }

    ListStack<int> temp = myNums2; //create a temporary listStack
    while(!temp.empty()) { //while the temporary stack is not empty
        std::cout << temp.top() << std::endl; //print the top element of the listStack
        temp.pop(); //pop the top element of the ListStack
    }

    //*****Testing infix to postfix translator*****
    std::string infix = "x/(h+j)-y*k";
    std::cout << "Translating infix \"" << infix << "\" to postfix..." << std::endl;
    std::cout << "The postfix is: " << IF2PF(infix) << std::endl;

    infix = "a+(b*(c-d)/e)";
    std::cout << "Translating infix \"" << infix << "\" to postfix..." << std::endl;
    std::cout << "The postfix is: " << IF2PF(infix) << std::endl;


}