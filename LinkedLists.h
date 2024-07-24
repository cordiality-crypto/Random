#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H
#define NULL nullptr

#include <iostream>
using namespace std;

template <typename T>
/**
 * @brief A class representing a linked list.
 * 
 * This class provides basic operations for manipulating a linked list, such as appending, prepending, inserting, removing, and accessing elements.
 * It also provides functions to get the size of the list, check if it is empty, and retrieve the first and last elements.
 * 
 * @tparam T The type of data stored in the linked list.
 */
class LinkedLists {
    private:
        /**
         * @brief A struct representing a node in the linked list.
         * 
         * Each node contains a data element and a pointer to the next node in the list.
         */
        struct Node {
            T data;         // The data element stored in the node
            Node* next;     // Pointer to the next node in the list
        };
        
        Node* head;         // Pointer to the first node in the list
        Node* tail;         // Pointer to the last node in the list
        int size;           // The number of elements in the list
        
    public:
        /**
         * @brief Default constructor.
         * 
         * Initializes an empty linked list.
         */
        LinkedLists() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        
        /**
         * @brief Constructor with initial data element.
         * 
         * Initializes a linked list with a single node containing the specified data element.
         * 
         * @param data The data element to be stored in the list.
         */
        LinkedLists(T data) {
            head = new Node;
            head->data = data;
            head->next = nullptr;
            tail = head;
            size = 1;
        }
        
        /**
         * @brief Constructor with initial data element, head, and tail.
         * 
         * Initializes a linked list with a single node containing the specified data element,
         * and sets the head and tail pointers to the specified nodes.
         * 
         * @param data The data element to be stored in the list.
         * @param head Pointer to the first node in the list.
         * @param tail Pointer to the last node in the list.
         */
        LinkedLists(T data, Node *head, Node *tail) {
            head = new Node;
            head->data = data;
            head->next = nullptr;
            tail = head;
            size = 1;
        }
        
        /**
         * @brief Destructor.
         * 
         * Deallocates memory for all nodes in the linked list.
         */
        ~LinkedLists() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        
        /**
         * @brief Appends a new element to the end of the list.
         * 
         * Creates a new node with the specified data element and adds it to the end of the list.
         * 
         * @param data The data element to be appended.
         */
        void append(T data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }
        
        /**
         * @brief Prepends a new element to the beginning of the list.
         * 
         * Creates a new node with the specified data element and adds it to the beginning of the list.
         * 
         * @param data The data element to be prepended.
         */
        void prepend(T data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            size++;
        }
        
        /**
         * @brief Inserts a new element at the specified index.
         * 
         * Creates a new node with the specified data element and inserts it at the specified index in the list.
         * If the index is out of bounds, an error message is printed and the function returns.
         * 
         * @param data The data element to be inserted.
         * @param index The index at which to insert the element.
         */
        void insert(T data, int index) {
            if (index < 0 || index > size) {
                cerr << "Index out of bounds" << endl;
                return;
            }
            if (index == 0) {
                prepend(data);
                return;
            }
            if (index == size) {
                append(data);
                return;
            }
            Node* newNode = new Node;
            newNode->data = data;
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
        
        /**
         * @brief Removes the element at the specified index.
         * 
         * Removes the element at the specified index from the list.
         * If the index is out of bounds, an error message is printed and the function returns.
         * 
         * @param index The index of the element to be removed.
         */
        void remove(int index) {
            if (index < 0 || index >= size) {
                cerr << "Index out of bounds" << endl;
                return;
            }
            Node* current = head;
            if (index == 0) {
                head = head->next;
                delete current;
                size--;
                return;
            }
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
        
        /**
         * @brief Retrieves the element at the specified index.
         * 
         * Retrieves the element at the specified index in the list.
         * If the index is out of bounds, an error message is printed and a default-constructed element is returned.
         * 
         * @param index The index of the element to be retrieved.
         * @return The element at the specified index.
         */
        T get(int index) {
            if (index < 0 || index >= size) {
                cerr << "Index out of bounds" << endl;
                return T();
            }
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data;
        }
        
        /**
         * @brief Returns the size of the list.
         * 
         * @return The number of elements in the list.
         */
        int getSize() {
            return size;
        }
        
        /**
         * @brief Prints the elements of the list.
         * 
         * Prints the elements of the list separated by a space.
         */
        void print() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
        
        /**
         * @brief Returns the first element of the list.
         * 
         * If the list is empty, an error message is printed and a default-constructed element is returned.
         * 
         * @return The first element of the list.
         */
        T front() {
            if (head == nullptr) {
                cerr << "List is empty" << endl;
                return T();
            }
            return head->data;
        }
        
        /**
         * @brief Returns the last element of the list.
         * 
         * If the list is empty, an error message is printed and a default-constructed element is returned.
         * 
         * @return The last element of the list.
         */
        T back() {
            if (tail == nullptr) {
                cerr << "List is empty" << endl;
                return T();
            }
            return tail->data;
        }
        
        /**
         * @brief Checks if the list is empty.
         * 
         * @return True if the list is empty, false otherwise.
         */
        bool isEmpty() {
            return size == 0;
        }
        
        /**
         * @brief Removes the last element from the list.
         * 
         * If the list is empty, an error message is printed and the function returns.
         */
        void popBack() {
            if (head == nullptr) {
                cerr << "List is empty" << endl;
                return;
            }
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
            size--;
        }
        
        /**
         * @brief Removes the first element from the list.
         * 
         * If the list is empty, an error message is printed and the function returns.
         */
        void popFront() {
            if (head == nullptr) {
                cerr << "List is empty" << endl;
                return;
            }
            Node* current = head;
            head = head->next;
            delete current;
            size--;
        }
};

#endif // LINKED_LISTS_H