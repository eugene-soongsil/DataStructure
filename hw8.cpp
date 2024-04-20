#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student{
    int id;
    char name[MAX];
    char dept[MAX];
};

struct Stack{
    int top;
    struct Student data [MAX];
};

void push(struct Stack* ps, struct Student stud);

struct Student pop(struct Stack * ps);

int main(){
    struct Stack s;
    s.top = -1;

    struct Student stud;

    stud.id = 2019;
    strcpy(stud.name, "Park");
    strcpy(stud.dept, "EE");
    push(&s, stud);

    stud.id = 2020;
    strcpy(stud.name, "Kim");
    strcpy(stud.dept, "EE");
    push(&s, stud);

    stud.id = 2021;
    strcpy(stud.name, "Lee");
    strcpy(stud.dept, "CS");
    push(&s, stud);

    stud.id = 2022;
    strcpy(stud.name, "Choi");
    strcpy(stud.dept, "EECS");
    push(&s, stud);

    display(&s);
}

void push(struct Stack* ps, struct student stud){
    ps -> top++;
    ps -> data[ps->top] = stud;
}

void display(struct Stack* ps){
    printf("--------\n");
    for(int i = ps->top; i >= 0; i--){
        printf("id:%d, Name:%s, Department:%s \n", ps -> data[i].id, ps ->data[i].name, ps->data[i].dept);
    }
    printf("--------\n");
}

struct Student pop(struct Stack* ps){
    return ps -> data[ps->top--];
}