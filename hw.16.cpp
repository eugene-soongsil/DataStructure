#include <iostream>
using namespace std;

class Node{
    int data;
    Node* link;

public:
    Node(int d = 0){
        data = d;
    }
    void setData(int d){data = d;}
    int getData(){return data;}
    Node* getLink(){return link;}
    void setLink(Node* n){link = n;}
};

class LinkedQueue{
    Node* front;
    Node* rear;

public:
    LinkedQueue(){
        front = rear = NULL;
    }
    void enqueue(Node* n){
        if(front == NULL && rear == NULL){
            front = n;
            rear = n;
        }
        else{
            rear->setLink(n);
            rear = n;
        }
    }
    Node* dequeue(){
        Node* tmp = front;
        front = front->getLink();
        return tmp;
    }
    void display(){
        Node* tmp = front;
        while(tmp != NULL){
            cout << "========" << endl;
            while(tmp != NULL){
                cout << tmp->getData() << endl;
                tmp = tmp->getLink();
            }
            cout << "========" << endl;
        }
    }
};

int main(){
    LinkedQueue q;
    q.enqueue(new Node(10));
    q.enqueue(new Node(20));
    q.enqueue(new Node(30));
    q.enqueue(new Node(40));

    q.display();
    cout << "DeQ! " << q.dequeue()->getData() << endl;
    cout << "DeQ! " << q.dequeue()->getData() << endl;

    q.display();
    q.enqueue(new Node(50));
    q.display();
}