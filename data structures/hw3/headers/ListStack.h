//This file is a template for a stack implemented with a linked list
//Aaron Borjas
//10/27/2019
//CS273-1
//Instructor - Matt Bell
//this header file is a template for a stack implemented with a linked list.
//it includes a node struct for navigating the list, as well as the typical stack functions
#include <list>
#ifndef LISTSTACK_H
#define LISTSTACK_H

namespace Aaron {

    template<typename Type>
    class ListStack {
        private:

            //this struct is used to organize the data of the linked list for this stack.
            //this struct was taken and modified from CS273 Doubly_Linked_Listpart_2
            struct Node {
                Node* next; //the next node
                Type data; //the data held in the node

                //creates the node
                Node(const Type &item, Node *next = NULL) :
				data(item), next(next) {} 
            };

            Node* head;
            int numItems;
        public:
            //constructor for ListStack, creates an empty listStack 
            ListStack(){
                head = NULL; //sets the head to null; there is no head
                numItems = 0; //sets number of items to zero
            }

            // //constructor for listStack, creates a listStack with elements in it
            // //input - an unsigned integer representing size
            // //output - creates a listStack with a size, changes the member variable for size
            // ListStack(unsigned int s) {
            //     lStack = std::list(s);
            //     size = s;
            // }

            //function empty, checks if the stack is empty
            //inputs - none
            //outputs - returns a bool value based on if the stack is empty or not
            bool empty() {
                if(numItems == 0) { //if number of items is equal to zero
                    return true; //return true;
                }
                return false; //return false
            }

            //function empty, gives the size of the stack
            //input - none
            //output - returns the size of the stack
            int getSize() {
                return numItems; //returns the number of items in the stack
            }

            //top gets the "top" of the stack, or the item at the end
            //inputs -none
            //outputs - returns the top element of the stack
            Type& top() {
                return head->data;
            }

            //push adds an element to the stack
            //inputs - an element t of type Type
            //outputs - adds a new element to the end of the stack, increments the size of the stack
            void push(const Type& t) {
                head = new Node(t, head); //creates a new head which is equal to a new node with data being t and the next item being head (the old one)
                numItems++; //increment numItmes
            }

            //pop removes an element from the stack
            //inputs - none
            //outputs - removes the last element from the stack, decrements the size
            void pop() {
                Node* oldHead = head; //creates a new node for the old head, set it to head
                head = head->next; //set head to be the next element in the list;
                delete oldHead; //delete the old head
                numItems--; //decrement numItems
            }
    };
}
#endif