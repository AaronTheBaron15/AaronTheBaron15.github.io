//This file is a template for a stack implemented with a vector
//Aaron Borjas
//10/27/2019
//CS273-1
//Instructor - Matt Bell
//this header file is a template for a stack implemented with a vector.
//it defines a few functions that are essential to use with a stack, but with vector functions
#include <iostream>
#include <vector>

#ifndef VECTORSTACK_H
#define VECTORSTACK_H

namespace Aaron {

    template <typename Type> //template with typename of Type for the class VectorStack
    class VectorStack { //creates a stack through adaptation of vector
        private:
            std::vector<Type> vStack; //creates a vector of type Type
            unsigned int size;
        public:
            //constructor for vectorStack, creates an empty vectorstack
            VectorStack() {}

            // //constructor for VectorStack, creates a VectorStack with a specified size
            // //input - a positive int s for desired size
            // //output - creates a vectorStack with specified size
            // VectorStack(unsigned int s) {
            //     size = s;
            //     vStack = std::vector<Type>(s);
            // }

            //function empty, checks if the stack is empty
            //inputs - none
            //outputs - returns a bool value based on if the stack is empty or not
            bool empty() {
                if(vStack.size() == 0) { //if the size of the (vector)stack is equal to zero
                    return true; //return true
                }
                return false; //return false
            }

            //function size, gives the size of the stack
            //input - none
            //output - returns the size of the stack
            unsigned int getSize() {
                return size;
            }

            //top gets the "top" of the stack, or the item at the end
            //inputs -none
            //outputs - returns the top element of the stack
            Type& top() {
                return vStack.back(); //returns the top element of the stack
            }

            //push adds an element to the stack
            //inputs - an element t of type Type
            //outputs - adds a new element to the end of the stack, increments the size of the stack
            void push(const Type &t) {
                vStack.push_back(t);
                size++;
            }

            //pop removes an element from the stack
            //inputs - none
            //outputs - removes the last element from the stack, decrements the size
            void pop() {
                vStack.pop_back();
                size--;
            }

    };
}
#endif