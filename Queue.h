#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
/**
 * @class Queue
 * @brief A class that represents a queue data structure.
 * 
 * The Queue class provides functionality to enqueue and dequeue elements, as well as check the size and
 * whether the queue is empty or full.
 */
class Queue {
    private:
        T* queue; /**< Pointer to the array that stores the elements of the queue. */
        int front; /**< Index of the front element in the queue. */
        int rear; /**< Index of the rear element in the queue. */
        int capacity; /**< Maximum number of elements that the queue can hold. */
    public:
        /**
         * @brief Constructs a new Queue object.
         * 
         * @param size The size of the queue (default is a random number between 0 and 100).
         */
        Queue(int size = int(ceil(rand() * 100))) {
            queue = new T[size];
            capacity = size;
            front = 0;
            rear = -1;
        }
        
        /**
         * @brief Destroys the Queue object and frees the memory.
         */
        ~Queue() {
            delete[] queue;
        }
        
        /**
         * @brief Adds an element to the rear of the queue.
         * 
         * @param data The element to be added to the queue.
         */
        void enqueue(T data) {
            if (isFull()) {
                cerr << "Queue is full" << endl;
                return;
            }
            rear = (rear + 1) % capacity;
            queue[rear] = data;
        }
        
        /**
         * @brief Removes and returns the front element of the queue.
         * 
         * @return The front element of the queue.
         */
        T dequeue() {
            if (isEmpty()) {
                cerr << "Queue is empty" << endl;
                return T();
            }
            T data = queue[front];
            front = (front + 1) % capacity;
            return data;
        }
        
        /**
         * @brief Returns the front element of the queue without removing it.
         * 
         * @return The front element of the queue.
         */
        T peek() {
            if (isEmpty()) {
                cerr << "Queue is empty" << endl;
                return T();
            }
            return queue[front];
        }
        
        /**
         * @brief Returns the number of elements in the queue.
         * 
         * @return The number of elements in the queue.
         */
        int size() {
            return (capacity - front + rear + 1) % capacity;
        }
        
        /**
         * @brief Checks if the queue is empty.
         * 
         * @return True if the queue is empty, false otherwise.
         */
        bool isEmpty() {
            return front == (rear + 1) % capacity;
        }
        
        /**
         * @brief Checks if the queue is full.
         * 
         * @return True if the queue is full, false otherwise.
         */
        bool isFull() {
            return size() == capacity - 1;
        }
};

#endif // QUEUE_H