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

class LinkedStack{
    Node* top;

public:
    LinkedStack(){
        top = NULL;
    }
    void push(Node* n){
        n->setLink(top);
        top = n;
    }
    Node* pop(){
        Node* tmp = top;
        top = top->getLink();
        return tmp;
    }
    void display(){
        Node* tmp = top;
        cout << "=========" << endl;
        while(tmp != NULL){
            cout << tmp->getData() << endl;
            tmp = tmp->getLink();
        }
        cout << "=========" << endl;
    }
};

int main(){
    LinkedStack ls;
    ls.push(new Node(10));
    ls.push(new Node(20));
    ls.push(new Node(30));
    ls.push(new Node(40));

    ls.display();

    cout << "pop! " << ls.pop()->getData() << endl;
    cout << "pop! " << ls.pop()->getData() << endl;

    ls.display();
}