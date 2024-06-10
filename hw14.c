#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

struct node{
    int data;
    struct node* link;
};

struct linkedQueue{
    struct node* front;
    struct node* rear;
};

void enqueue(struct linkedQueue* q, struct node* n){
    if(q->front == NULL && q->front == NULL){
        q->front = n;
        q->rear = n;
    }
    else{
        q->rear->link = n;
        q->rear = n;
    }
}

struct node* dequeue(struct linkedQueue* q){
    struct node* tmp = q->front;
    q->front = q->front->link;
    return tmp;
}

int countQueue(struct linkedQueue* q){
    struct node* tmp = q->front;
    int cnt = 0;
    while(tmp != NULL){
        cnt = cnt +1;
        tmp = tmp->link;
    }
    return cnt;
}

void display(struct linkedQueue* q){
    struct node* tmp = q->front;
    printf("=====\n");
    while(tmp != NULL){
        printf("%d\n", tmp->data);
        tmp = tmp->link;
    }
    printf("=====\n");
}

int main() {
    struct linkedQueue lq;
    lq.front = lq.rear = NULL;

    struct node n1;
    n1.data = 10;
    n1.link = NULL;
    enqueue(&lq, &n1);

    struct node n2;
    n2.data = 20;
    n2.link = NULL;
    enqueue(&lq, &n2);

    struct node n3;
    n3.data = 30;
    n3.link = NULL;
    enqueue(&lq, &n3);

    struct node n4;
    n4.data = 40;
    n4.link = NULL;
    enqueue(&lq, &n4);

    display(&lq);

    printf("# of data in the queue:%d\n", countQueue(&lq));


    printf("DeQ! %d \n", dequeue(&lq)->data);
    printf("DeQ! %d \n", dequeue(&lq)->data);

    display(&lq);
    printf("# of data in the queue:%d\n", countQueue(&lq));

    struct node n5;
    n5.data = 50;
    n5.link = NULL;
    enqueue(&lq, &n5);

    display(&lq);
    printf("# of data in the queue:%d\n", countQueue(&lq));
}
