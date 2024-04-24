#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAX 3
#define PUSH 1
#define POP 2

struct Student{
    int id;
    char name[50];
    char dept[50];
};

struct Queue{
    int front;
    int rear;
    int lastOp;
    struct Student* data[MAX];
};

int isFull(struct Queue* p){
    if(p->front == p->rear && p->lastOp == PUSH)
        return 1;
    else
        return 0;
}

int isEmpty(struct Queue* p){
    if(p->front == p->rear && p->lastOp != PUSH){
        printf("Q is Empty!!\n");
        return 1;
    }
    else
        return 0;
}

void enqueue(struct Queue* p, struct Student* data){
    if(!isFull(p)){
        printf("%d is queued.\n", data->id);
        p->rear = ((p->rear + 1)%MAX);
        p->data[p->rear] = data;
        p->lastOp = PUSH;
    }
    else{
        printf("Can't enqueue. It's full !!!!!\n");
    }
}

struct Student* dequeue(struct Queue* p){
    if(!isEmpty(p)){
        printf("DeQ!\n");
        p->lastOp = POP;
        int tmp = (p->front + 1) % MAX;
        p->front = ((p->front + 1)% MAX);
        return p->data[tmp];
    }
    return 0;
}

void printQ(struct Queue* p){
    int numberOfQ;
    numberOfQ = p->rear > p->front ? (p->rear - p->front) : ((p->rear + MAX ) - p->front);
    int index = p->front + 1;
    for(int i=0; i<numberOfQ; i++){
        printf("%d, name:%s, department:%s ", p->data[(index+i)%MAX]->id, p->data[(index+i)%MAX]->name, p->data[(index+i)%MAX]->dept); //포인터로 접근하는것만 추가
        printf("\n");
    }
}

int main(){
    struct Queue q;
    q.front = 0;
    q.rear = 0;
    q.lastOp = 0;

    struct Student stud1;
    stud1.id = 2019;
    strcpy(stud1.name, "Park");
    strcpy(stud1.dept, "EE");
    enqueue(&q, &stud1);

    struct Student stud2;
    stud2.id = 2020;
    strcpy(stud2.name, "Kim");
    strcpy(stud2.dept, "EE");
    enqueue(&q, &stud2);

    struct Student stud3;
    stud3.id = 2021;
    strcpy(stud3.name, "Lee");
    strcpy(stud3.dept, "CS");
    enqueue(&q, &stud3);

    struct Student stud4;
    stud4.id = 2022;
    strcpy(stud4.name, "Choi");
    strcpy(stud4.dept, "EECS");
    enqueue(&q, &stud4);

    printQ(&q);
    dequeue(&q);
    dequeue(&q);
    printQ(&q);
}