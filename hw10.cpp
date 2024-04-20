#include <iostream>
#define MAX 3
using namespace std;

class Student{
    int id;
    string name;
    string dept;

    public:
    Student(int i = 0, string n = "", string d = ""){
        id = i;
        name = n;
        dept = d;
    }
    void setID(int i){
        id = i;
    }
    int getID(){
        return id;
    }
    void setName(string n){
        name = n;
    }

    string getName(){
        return name;
    }
    void setDept(){
        return dept;
    }
    void display(){
        cout << "ID:" << id << ", Name:" << name << ", Department:" << dept << endl;
    }
};

class Stack{
    int top;
    Student* data[MAX];

    public:
    Stack(){
        top = -1;
    }
    void push(Student* stud){
        if(top == 2){
            cout << "The stack is full." << endl;
        }
        else{
            top++;
            data[top] = stud;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"The stack is empty."<< endl;
        }
        else{
            data[top--]->display();
        }
    }
    void diplay(){
        cout <<"--------"<<endl;
        for(int i = top; i >= 0; i--){
            data[i]->display();
        }
        cout <<"--------"<<endl;
    }
};

int main(){
    Stack s;

    s.push(new Student(2019, "Park", "EE"));
    s.push(new Student(2020, "Kim", "EE"));
    s.push(new Student(2021, "Lee", "CS"));
    s.push(new Student(2022, "Choi", "EECS"));

    s.diplay();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.diplay();
}