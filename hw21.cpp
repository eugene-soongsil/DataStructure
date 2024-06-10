#include <iostream>
using namespace std;

class node{
    int data;
    node* link;
public:
    node(int d =0, node* l =NULL){
        data = d;
        link = NULL;
    }
    void setdata(int d){data = d;}
    int getdata(){return data;}
    node* getlink(){return link;}
    void setlink(node* n){link = n;}
    void display(){
        cout << data << " ";
    }
    bool hasdata(int val){
        return data == val;
    }
};

class linkedlist{
    node org;
    int size;
public:
    linkedlist(){
        size = 0;
    }
    void insert(int pos, node* n){
        node* prev = getentry(pos - 1);
        size++;
        n->setlink(prev->getlink());
        prev->setlink(n);
    }

    node* getentry(int pos){
        node* tmp = &org;
        for(int i = -1; i<pos; i++){
            tmp = tmp->getlink();
        }
        return tmp;
    }

    node* remove(int pos){
        node* prev = getentry(pos - 1);
        node* rem = prev->getlink();
        size--;
        prev->setlink(rem->getlink());
        return rem;
    }

    void display(){
        cout << "total number of the list:" << size << endl;
        for(node* p = org.getlink(); p != NULL; p=p->getlink())
            p->display();
        cout << endl;
    }
};

int main(){
    linkedlist list;
    list.insert(0, new node(10));
    list.insert(0, new node(20));
    list.insert(0, new node(30));
    list.insert(0, new node(40));
    list.display();
    list.insert(1, new node(50));
    list.display();
    list.remove(3)->display();
    list.display();
}