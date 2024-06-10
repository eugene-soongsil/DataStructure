#include <iostream>
#include <string>

#define MAX 100
using namespace std;

class Stack{
    int top;
    char data[MAX];

    public:
        Stack(){
            top = -1
        }
        void push(int d){
            data[++top] = d;
        }
        char pop(){
            return data[top--];
        }
        int isEmpty(){
            return top == -1;
        }

        void dispay(){
            cout << "---------" << endl;
            for(int i = top; i>= 0; i--){
                cout << data[i] << endl;
            }
            cout << "---------" << endl;
        }
};

bool isBalanced(string str, *c){
    Stack st;
    *c =0;

    for(char ch : str){
        if(ch == '(' || ch =='{' || ch == '['){
            st.push();
        }
        else if(ch == ')' || ch =='}' || ch == ']'){
            if(st.isEmpty()){
                return false;
            }
            char top = st.pop();
            if((ch==')'&&top != '(') || (ch =='}' && top != '{') || (ch == ']' && top != '[')){
                return false;
            }
            else
                (*c)++
        }
    }
    return st.isEmpty();
}

int main(){
    string str = "{{{{((  ))}}}}";

    int count = 0;

    if(isBalanced(str, &count)){
        cout << "괄호가 올바르게 쓰여졌습니다." << endl;
        cout << "Number of bracket pairs :" << count <<endl;
    }
    else{
        cout << "괄호가 올바르게 쓰여지지 않았습니다."  << endl;
    }

    return 0;
}