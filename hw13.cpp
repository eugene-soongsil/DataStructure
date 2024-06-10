#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

struct node{
    int data;
    struct node* link;
};
struct linkedStack{
    struct node* top;
};
void push(struct linkedStack* pls, struct node* n){
    n->link = pls->top;
    pls->top = n;
}
struct node* pop(struct linkedStack* pls){
    struct node* tmp = pls->top;
    pls->top = pls->top->link;
    return tmp;
}
struct node* countStack(struct linkedStack* pls){
    struct node* tmp = pls->top;
    int cnt = 0;
    while(tmp != NULL){
        cnt = cnt + 1;
        tmp = tmp->link;
    }
    return cnt;
}
void display(struct linkedStack* pls){
    struct node* tmp = pls->top;
    printf("=====\n");
    while(tmp != NULL){
        printf("%d\n", tmp->data);
        tmp = tmp->link;
    }
    printf("=====\n");
}

int main(){
    struct linkedStack ls;
    ls.top = NULL;

    struct node n1;
    n1.data=10;
    n1.link = NULL;
    push(&ls, &n1);

    struct node n2;
    n2.data=20;
    n2.link = NULL;
    push(&ls, &n2);

    struct node n3;
    n3.data=30;
    n3.link = NULL;
    push(&ls, &n3);

    struct node n4;
    n4.data=40;
    n4.link = NULL;
    push(&ls, &n4);

    display(&ls);
    printf("# of data in the stack: %d\n", countStack(&ls));

    printf("pop! %d \n", pop(&ls)->data);
    printf("pop! %d \n", pop(&ls)->data);

    display(&ls);
    printf("# of data in the stack: %d\n", countStack(&ls));
}