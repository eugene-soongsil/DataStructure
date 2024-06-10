#include <iostream>
using namespace std;
class Student{
    int id;
    string name;
    string dept;
public:
    student(int i = 0, string n = "", string d = ""){
        set(i, n, d);
    }
    void set(int i, string n, string d){
        id = i;
        name = n;
        dept = d;
    }
    void display(){
        cout << 
    }
}

class Node {
    TreeNode* data;
    Node* link;
public:
    Node(TreeNode* d = NULL) {
        data = d;
        link = NULL;
    }
    TreeNode* getData() { return data; }
    Node* getLink() { return link; }
    void setLink(Node* n) { link = n; }
};

class LinkedQueue {
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(TreeNode* item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->setLink(newNode);
            rear = newNode;
        }
    }

    TreeNode* dequeue() {
        if (isEmpty()) {
            return NULL;
        } else {
            Node* temp = front;
            front = front->getLink();
            if (front == NULL) {
                rear = NULL;
            }
            TreeNode* data = temp->getData();
            delete temp;
            return data;
        }
    }
};
