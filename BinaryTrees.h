#ifndef BINARY_TREES_H
#define BINARY_TREES_H
#define NULL nullptr

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTrees {
    private:
        struct Node {
            T data;
            Node *left, *right;
        };
        int size;
        Node* root;
    public:
        BinaryTrees() {
            root = NULL;
            size = 0;
        }
        BinaryTrees(T data) {
            root = new Node;
            root->data = data;
            root->left = NULL;
            root->right = NULL;
            size = 1;
        }
        void insert(T data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            if (root == NULL) {
                root = newNode;
            } else {
                queue<Node*> pendingNodes;
                pendingNodes.push(root);
                while (!pendingNodes.empty()) {
                    Node* front = pendingNodes.front();
                    pendingNodes.pop();
                    if (front->left == NULL) {
                        front->left = newNode;
                        break;
                    } else {
                        pendingNodes.push(front->left);
                    }
                    if (front->right == NULL) {
                        front->right = newNode;
                        break;
                    } else {
                        pendingNodes.push(front->right);
                    }
                }
            }
            size++;
        }
        void remove(T data) {
            if (root == NULL) {
                return;
            }
            if (root->data == data) {
                root = NULL;
                size = 0;
                return;
            }
            queue<Node*> pendingNodes;
            pendingNodes.push(root);
            Node* front = NULL;
            Node* lastNode = NULL;
            while (!pendingNodes.empty()) {
                front = pendingNodes.front();
                pendingNodes.pop();
                if (front->left != NULL) {
                    if (front->left->data == data) {
                        lastNode = front;
                    } else {
                        pendingNodes.push(front->left);
                    }
                }
                if (front->right != NULL) {
                    if (front->right->data == data) {
                        lastNode = front;
                    } else {
                        pendingNodes.push(front->right);
                    }
                }
            }
            if (lastNode != NULL) {
                if (lastNode->left != NULL && lastNode->left->data == data) {
                    lastNode->left = NULL;
                } else {
                    lastNode->right = NULL;
                }
                size--;
            }
        }
        int totalNodes() {
            return size;
        }
        void printLevelOrder() {
            if (root == NULL) {
                return;
            }
            queue<Node*> pendingNodes;
            pendingNodes.push(root);
            while (!pendingNodes.empty()) {
                Node* front = pendingNodes.front();
                pendingNodes.pop();
                cout << front->data << ": ";
                if (front->left != NULL) {
                    cout << "L: " << front->left->data << " ";
                    pendingNodes.push(front->left);
                }
                if (front->right != NULL) {
                    cout << "R: " << front->right->data << " ";
                    pendingNodes.push(front->right);
                }
                cout << endl;
            }
        }
        void printInOrder() {
            printInOrder(root);
            cout << endl;
        }
        void printPreOrder() {
            printPreOrder(root);
            cout << endl;
        }
        void printPostOrder() {
            printPostOrder(root);
            cout << endl;
        }
    private:    
        void printInOrder(Node* node) {
            if (node == NULL) {
                return;
            }
            printInOrder(node->left);
            cout << node->data << " ";
            printInOrder(node->right);
        }
        void printPreOrder(Node* node) {
            if (node == NULL) {
                return;
            }
            cout << node->data << " ";
            printPreOrder(node->left);
            printPreOrder(node->right);
        }
        void printPostOrder(Node* node) {
            if (node == NULL) {
                return;
            }
            printPostOrder(node->left);
            printPostOrder(node->right);
            cout << node->data << " ";
        }
};

#endif // BINARY_TREES_H