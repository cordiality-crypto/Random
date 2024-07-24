#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
/**
 * @class Stack
 * @brief A class that represents a stack data structure.
 * 
 * The Stack class provides basic operations such as push, pop, peek, size, isEmpty, and isFull.
 * It uses an array to store the elements and supports dynamic resizing.
 * 
 * @tparam T The type of elements stored in the stack.
 */
class Stack {
    private:
        T* stack; ///< Pointer to the array that stores the elements.
        int top; ///< Index of the top element in the stack.
        int capacity; ///< Maximum capacity of the stack.
    public:
        /**
         * @brief Constructs a new Stack object with the specified size.
         * 
         * @param size The initial size of the stack. Default is 10.
         */
        Stack(int size = 10) {
            stack = new T[size];
            capacity = size;
            top = -1;
        }
        
        /**
         * @brief Destroys the Stack object and frees the memory.
         */
        ~Stack() {
            delete[] stack;
        }
        
        /**
         * @brief Pushes an element onto the top of the stack.
         * 
         * @param data The element to be pushed onto the stack.
         */
        void push(T data) {
            if (isFull()) {
                cerr << "Stack is full" << endl;
                return;
            }
            top++;
            stack[top] = data;
        }
        
        /**
         * @brief Removes and returns the top element from the stack.
         * 
         * @return The top element of the stack.
         * @note If the stack is empty, -1 is returned.
         */
        T pop() {
            if (isEmpty()) {
                cerr << "Stack is empty" << endl;
                return T();
            }
            return stack[top--];
        }
        
        /**
         * @brief Returns the top element of the stack without removing it.
         * 
         * @return The top element of the stack.
         * @note If the stack is empty, -1 is returned.
         */
        T peek() {
            if (isEmpty()) {
                cerr << "Stack is empty" << endl;
                return T();
            }
            return stack[top];
        }
        
        /**
         * @brief Returns the number of elements in the stack.
         * 
         * @return The number of elements in the stack.
         */
        int size() {
            return top + 1;
        }
        
        /**
         * @brief Checks if the stack is empty.
         * 
         * @return True if the stack is empty, false otherwise.
         */
        bool isEmpty() {
            return top == -1;
        }
        
        /**
         * @brief Checks if the stack is full.
         * 
         * @return True if the stack is full, false otherwise.
         */
        bool isFull() {
            return top == capacity - 1;
        }
};

#endif //STACK_H