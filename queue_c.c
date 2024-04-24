#include <stdio.h>
#define MAX 5
#define PUSH 1
#define POP 2

#define _CRT_SECURE_NO_WARNINGS

struct Queue{
    int front;
    int rear;
    int lastOp;
    int data[MAX];
};

int isFull(struct Queue* p){
    if(p->front == p->rear && p->lastOp == PUSH)
        return 1;
    else
        return 0;
}

int isEmpty(struct Queue* p){
    if(p->front == p->rear && p->lastOp != PUSH){
        printf("Q is empty!!\n");
        return 1;
    }
    else
        return 0;
}

void enqueue(struct Queue* p, int data){
    if(!isFull(p)){ //isFull 함수 호출된다. -> full이라면 massege print !!
        printf("%d is queue.\n", data);
        p->rear = ((p->rear+1)%MAX); //data 삽입 전에 pointer변경, rear의 값이 MAX를 넘지 않도록 한다.(원형 index 유지, 원래의 rear가 4였으면 4+1 % 5 = 0이 된다.)
        p->data[p->rear] = data;
        p->lastOp = PUSH;
    }
    else{
        printf("Can't enqueue. It's full !!!!!\n");
    }
}

int dequeue(struct Queue* p){
    if(!isEmpty(p)){//isEmpty함수 호출된다. -> Empty라면 Q is empty가 호출 된다 !!! 새로 안 사실 !
        printf("DeQ!\n");
        p->lastOp = POP;
        int tmp = (p->front + 1)%MAX;
        p->front = ((p->front+1)%MAX);
        return p->data[tmp];
    }
    return 0;
}

void printQ(struct Queue* p){
    int numberOfQ;
    numberOfQ = p->rear > p->front ? (p->rear - p->front) : ((p->rear + MAX) - p->front); //rear가 0이 되는 경우이기 때문에 MAX를 더해준다.
    int index = p->front+1; //index의 초기값을 queue data가 처음으로 담긴 곳으로 대입 (%MAX를 왜 안했는지 모르겠는데 해야할듯 -> 어차피 아래에서 MAX연산하는구나)
    for(int i=0; i < numberOfQ; i++)
        printf("%d ", p->data[(index+i)%MAX]);
    printf("\n");
}

int main(){
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    q.lastOp = 0;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    printQ(&q);

    printf("%d \n", dequeue(&q));
    enqueue(&q, 60);
    printQ(&q);


    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));
    printf("%d \n", dequeue(&q));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    printQ(&q);
}