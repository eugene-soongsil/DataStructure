#include <iostream>
using namespace std;

class node{
    int data;
    node* link;
public:
    node(int d = 0){
        data = d;
        link = NULL;
    }
    void setData(int d){data=d;}
    int getData(){return data;}
    node* getLink(){return link;}
    void setLink(node* n){link = n;}
    void display(){
        cout << data << " ";
    }
    bool hasData(int val){
        return data == val;
    }
    void insertNext(node* n){
        n->link = link;
        link = n;
    }
    node* removeNext(){
        node* removeNode = link;
        if(removeNode != NULL) link = link->link;
        return removeNode;
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
        node* prev = getEntry(pos - 1);
        size++;
        prev->insertNext(n);
    }
    node* getEntry(int pos){
        node* tmp = &org;
        for(int i= -1; i<pos; i++){
            tmp = tmp->getLink();
        }
        return tmp;
    }
    node* remove(int pos){
        node* prev = getEntry(pos - 1);
        size--;
        return prev->removeNext();
    }
    void display(){
        cout << "total number of the list:" <<size<<endl;
        for(node* p= org.getLink(); p != NULL; p=p->getLink())
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
    list.remove(3);
    list.display();
}
