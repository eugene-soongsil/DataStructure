#include <iostream>
#include <stdio.h>
#define MAX 5
#define PUSH 1
#define POP 2
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class Queue{
    int front;
    int rear;
    int lastOp;
    int data[MAX];

    public:
    Queue(){
        front = 0;
        rear = 0;
        lastOp = 0;
    }

    int isFull(){
        if(front == rear && lastOp ==PUSH)
        return 1;
        else
        return 0;
    }

    int isEmpty(){
        if(front == rear && lastOp != PUSH){
            printf("Q is empty!!\n");
            return 1;
        }
        else return 0;
    }

    void enqueue(int data){
        if(!isFull()){
            printf("%d is queued.\n", data);
            rear = ((rear + 1) % MAX);
            this->data[rear] = data;
            lastOp = PUSH;
        }
        else{
            printf("Can't enqueue. It's full !!!!!\n");
        }
    }

    int dequeue(){
        if(!isEmpty()){
            printf("DeQ!\n");
            lastOp = POP;
            front = ((front + 1) % MAX);
            return data[front];
        }
        return 0;
    }
    
    void printQ(){
        int numberOfQ;
        numberOfQ = rear > front ? (rear - front) : ((rear + MAX) -front);
        int index = front + 1;
        for(int i=0; i <numberOfQ; i++)
            printf("%d ", data[(index + i) % MAX]);
        printf("\n");
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.printQ();

    cout << q.dequeue() << endl;
    q.printQ();

    q.enqueue(60);
    q.printQ();
}