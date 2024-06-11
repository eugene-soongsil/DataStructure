#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100
#define MAX_QUEUE_SIZE 100
#define MAX_VTXS 256

using namespace std;

inline void error(const char* str){
    fprintf(stderr, "%s\n", str);
    exit(1);
};

class AdjMatGraph{
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
public:
    AdjMatGraph(){reset();}
    ~AdjMatGraph(){ }

    char getVertex(int i){return vertices[i];}
    int getEdge(int i, int j){return adj[i][j];}
    void setEdge(int i, int j, int val){adj[i][j] = val;}
    bool isEmpty(){return size == 0;}
    bool isFull(){return size >= MAX_VTXS;}

    void reset(){
        size = 0;
        for(int i = 0; i<MAX_VTXS; i++)
            for(int j = 0; j<MAX_VTXS; j++)
                setEdge(i, j, 0);
    }

    void insetVertex(char name){
        if(!isFull()) vertices[size++] = name;
        else printf("Error: 그래프 정점의 개수 초과\n");
    }

    void insertEdge(int u, int v){
        setEdge(u, v, 1);
        setEdge(v, u, 1);
    }

    void display(){
        for(int i = 0; i < size; i++){
            printf("%c ", getVertex(i));
            for(int j = 0; j<size; j++)
                printf(" %3d", getEdge(i, j));
            printf("\n");
        }
    }

    void load(int g[][8], int c){
        for(int i = 0; i < c; i++){
            insetVertex('A' + i);
            for(int j = 0; j < c; j++){
                adj[i][j] = g[i][j];
            }
        }
    }
};

class Stack{
    int top;
    char data[MAX];
public:
    Stack(){
        top = -1;
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
    void display(){
        cout << "---------" << endl;
        for(int i = top; i>= 0; i--){
            cout << data[i] << endl;
        }
        cout << "---------" << endl;
    }
};

class SrchAMGraph : public AdjMatGraph{
    bool visited[MAX_VTXS];

public:
    void resetVisited(){
        for(int i = 0; i < size; i++)
            visited[i] = false;
    }
    bool isLinked(int u, int v){return getEdge(u, v)!=0;}

    void DFS(int v){
        visited[v] = true;
        printf("%c ", getVertex(v));
        
        for(int w = 0; w < size; w++)
            if(isLinked(v, w) && visited[w] == false)
                DFS(w);
    }

    void DFS_stack(int v){
        visited[v] = true;
        printf("%c ", getVertex(v));

        Stack sta;
        sta.push(v);

        while(!sta.isEmpty()){
            int v = sta.pop();
            for(int w = 0; w <size; w++)
                if(isLinked(v,w) && visited[w] == false){
                    visited[w] = true;
                    printf("%c ", getVertex(w));
                    sta.push(w);
                }
        }
    }
};

int main(){
    SrchAMGraph g;

    int AMG[8][8] = {{0,1,1,0,0,0,0,0},
                     {1,0,0,1,0,0,0,0},
                     {1,0,0,1,1,0,0,0},
                     {0,1,1,0,0,1,0,0},
                     {0,0,1,0,0,0,1,1},
                     {0,0,0,1,0,0,0,0},
                     {0,0,0,0,1,0,0,1},
                     {0,0,0,0,1,0,1,0}};

    g.load(AMG, 8);
    printf("인접 행렬로 표현한 그래프\n");
    g.display();

    printf("DFS by recursion ==> ");
    g.resetVisited();
    g.DFS(0);
    printf("\n");

    printf("DFS with stack   ==> ");
    g.resetVisited();
    g.DFS_stack(0);
    printf("\n");
}