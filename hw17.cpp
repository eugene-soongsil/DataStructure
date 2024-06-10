#include <string>
#include <iostream>

using namespace std;

class Student{
    int id;
    string name;
    string dept;
public:
    Student(int i=0, string n="", string d = ""){
        set(i, n, d);
    }
    void set(int i, string n, string d){
        id = i;
        name = n;
        dept = d;
    }
    void display(){
        cout << "ID:" << id << " Name:" << name << " Department:" << dept << endl;
    }
};

class Node : public Student{
    int data;
    Node* link;
public:
    Node(int id = 0, string n = "", string d =""){
        set(id, n, d);
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
            cout << "=======" << endl;
            while(tmp != NULL){
                tmp->display();
                tmp =tmp->getLink();
            }
            cout << "=======" << endl;
        }
    }
};

int main(){
    LinkedQueue q;

    q.enqueue(new Node(10, "Kim", "EE"));
    q.enqueue(new Node(20, "Park", "CS"));
    q.enqueue(new Node(30, "Choi", "EECS"));
    q.enqueue(new Node(40, "LEE", "EE"));

    q.display();
    cout << "DeQ! ";
    q.dequeue()->display();
    cout << "DeQ! ";
    q.dequeue()->display();

    q.display();

    q.enqueue(new Node(50, "Son", "CHEM"));

    q.display();
}
