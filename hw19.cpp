#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

struct Node{
    int data;
    Node* link;
};

struct LinkedList{
    struct Node org;
    int size;
};

struct Node* getEntry(LinkedList* pList, int pos){
    Node* tmp = &(pList->org);
    for(int i = -1; i<pos; i++){
        tmp = tmp->link;
    }
    return tmp;
};

void insert(LinkedList* pList, int pos, Node* d){
    Node* prev;
    prev = getEntry(pList, pos - 1);
    d->link = prev->link;
    prev->link = d;
    pList->size++;
}

Node* remove(LinkedList* pList, int pos){
    Node* tmp;
    Node* prev;
    prev = getEntry(pList, pos - 1);
    tmp = prev->link;
    prev->link = prev->link->link;
    pList->size--;
    return tmp;
}

void display(LinkedList* pList){
    printf("total number of the list:%d\n", pList->size);
    for(Node* p = (pList->org.link); p != NULL; p=p->link)
        printf("%d ", p->data);
    printf("\n");
}

int main(){
    LinkedList list;
    list.org.data = 999;
    list.org.link = NULL;
    list.size = 0;

    Node* node;

    node = (Node*)malloc(sizeof(Node));
    node->data = 10;
    node->link = NULL;
    insert(&list, 0, node);

    node = (Node*)malloc(sizeof(Node));
    node->data = 20;
    node->link = NULL;
    insert(&list, 0, node);

    node = (Node*)malloc(sizeof(Node));
    node->data = 30;
    node->link = NULL;
    insert(&list, 0, node);

    node = (Node*)malloc(sizeof(Node));
	node->data = 40;
	node->link = NULL;
	insert(&list, 0, node);

	display(&list);

	node = (Node*)malloc(sizeof(Node));
	node->data = 50;
	node->link = NULL;
	insert(&list, 1, node);

    display(&list);

    remove(&list, 3);
    display(&list);
}