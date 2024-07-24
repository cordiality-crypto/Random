#ifndef ARRAYLISTS_H
#define ARRAYLISTS_H

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief A dynamic array implementation that stores elements of type T.
 * 
 * The ArrayLists class provides various operations to manipulate and retrieve elements from the array.
 * It supports adding, removing, sorting, finding the largest/smallest element, calculating sum/average/median/mode/range/standard deviation/variance/frequency, and swapping elements.
 * 
 * @tparam T The type of elements to be stored in the array.
 */
template <typename T>
class ArrayLists {
    private:
        T *arr;       //This is the array where the data are supposed to be stored
        int size;       //This is the size of the array
        int capacity;   //This is the maximum size or capacity of the array
    public:
        /**
         * @brief Constructs an ArrayLists object with the specified size and capacity.
         * 
         * @param size The initial size of the array. Default is 0.
         * @param capacity The maximum capacity of the array. Default is 23.
         */
        ArrayLists(int size = 0, int capacity = 23) {
            this->size = size;
            this->capacity = capacity;
            arr = new T[capacity];
        }

        /**
         * @brief Destroys the ArrayLists object and frees the memory.
         */
        ~ArrayLists() {
            delete[] arr;
        }

        /**
         * @brief Adds an element to the end of the array.
         * 
         * @param data The element to be added.
         */
        void add(const T& data) {
            if(size < capacity) {
                arr[size] = data;
                size++;
            } else {
                cerr << "Array is full" << endl;
            }
        }

        /**
         * @brief Removes the element at the specified index from the array.
         * 
         * @param index The index of the element to be removed.
         */
        void remove(int index) {
            if(index < size) {
                for(int i = index; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
            } else {
                cerr << "Index out of bounds" << endl;
            }
        }

        /**
         * @brief Returns the size of the array.
         * 
         * @return The size of the array.
         */
        int getSize() {
            return size;
        }

        /**
         * @brief Returns the capacity of the array.
         * 
         * @return The capacity of the array.
         */
        int getCapacity() {
            return capacity;
        }

        /**
         * @brief Returns the element at the specified index.
         * 
         * @param index The index of the element to be retrieved.
         * @return The element at the specified index.
         */
        T get(int index) {
            if(index < size) {
                return arr[index];
            } else {
                cerr << "Index out of bounds" << endl;
                return T();
            }
        }

        /**
         * @brief Sets the element at the specified index to the given value.
         * 
         * @param index The index of the element to be set.
         * @param data The value to be set.
         */
        void set(int index, T data) {
            if(index < size) {
                arr[index] = data;
            } else {
                cerr << "Index out of bounds" << endl;
            }
        }

        /**
         * @brief Displays the elements of the array.
         */
        void display() {
            for(int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        /**
         * @brief Sorts the elements of the array in ascending order.
         */
        void sort() {
            std::sort(arr, arr + size);
        }

        /**
         * @brief Sorts the elements of the array using a custom comparison function.
         * 
         * @param compare The comparison function to be used for sorting.
         */
        void sort(bool (*compare)(T, T)) {
            std::sort(arr, arr + size, compare);
        };

        /**
         * @brief Finds the largest element in the array and prints it.
         * 
         * Note: This operation is not supported for strings.
         */
        void largest() {
            cerr << "Operation not supported for strings" << endl;
        }

        /**
         * @brief Finds the smallest element in the array and prints it.
         * 
         * Note: This operation is not supported for strings.
         */
        void smallest() {
            cerr << "Operation not supported for strings" << endl;
        }

        /**
         * @brief Calculates the sum of all elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings or characters.
         */
        void sum() {
            cerr << "Operation not supported for strings or characters" << endl;
        }

        /**
         * @brief Calculates the average of all elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings or characters.
         */
        void average() {
            cerr << "Operation not supported for strings or characters" << endl;
        }

        /**
         * @brief Calculates the median of all elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings or characters.
         */
        void median() {
            cerr << "Operation not supported for strings or characters" << endl;
        }

        /**
         * @brief Finds the mode of the elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings.
         */
        void mode() {
            cerr << "Operation not supported for strings" << endl;
        }

        /**
         * @brief Finds the range of the elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings or characters.
         */
        void range() {
            cerr << "Operation not supported for strings or characters" << endl;
        }

        /**
         * @brief Calculates the standard deviation of the elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings or characters.
         */
        void standardDeviation() {
            cerr << "Operation not supported for strings or characters" << endl;
        }

        /**
         * @brief Calculates the variance of the elements in the array and prints it.
         * 
         * Note: This operation is not supported for strings or characters.
         */
        void variance() {
            cerr << "Operation not supported for strings or characters" << endl;
        }

        /**
         * @brief Calculates the frequency of each element in the array and prints it.
         * 
         * Note: This operation is not supported for strings.
         */
        void frequency() {
            cerr << "Operation not supported for strings" << endl;
        }

        /**
         * @brief Swaps the elements at the specified indices in the array.
         * 
         * @param index1 The index of the first element to be swapped.
         * @param index2 The index of the second element to be swapped.
         */
        void swap(int index1, int index2) {
            if(index1 < size && index2 < size) {
                T temp = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = temp;
            } else {
                cerr << "Index out of bounds" << endl;
            }
        }
};

template <typename T>
void sort(T* arr, int size) {
    std::sort(arr, arr + size);
}

template <typename T>
void sort(T* arr, int size, bool (*compare)(T, T)) {
    std::sort(arr, arr + size, compare);
}

template <>
void sort<string>(string* arr, int size) {
    std::sort(arr, arr + size);
}

template <>
void sort<string>(string* arr, int size, bool (*compare)(string, string)) {
    std::sort(arr, arr + size, compare);
}

template <typename T>
void largest(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void smallest(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void sum(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void average(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void median(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void mode(T* arr, int size) {
    cerr <<endl; << endl
}

template <typename T>
void range(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void standardDeviation(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void variance(T* arr, int size) {
    cerr << << endl
}

template <typename T>
void frequency(T* arr, int size) {
    cerr <<endl; << endl
}

template <typename T>
void swap(T* arr, int index1, int index2) {
    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

#endif // ARRAYLISTS_H