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

    void insertVertex(char name){
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
            insertVertex('A' + i);
            for(int j = 0; j < c; j++){
                adj[i][j] = g[i][j];
            }
        }
    }
};

class SrchAMGraph : public AdjMatGraph{
public:
    bool visited[MAX_VTXS];
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
};

class ConnectedComponentGraph : public SrchAMGraph{
    int label[MAX_VTXS];

public:
    void labelDFS(int v, int color){
        visited[v] = true;
        label[v] = color;

        for(int w = 0; w<size; w++)
            if((isLinked(v,w) == 1) && (visited[w] == 0))
                labelDFS(w, color);
    }
    void findConnectedComponent(){
        int count = 0;
        for(int i = 0; i < size; i++){
            if(visited[i] == 0) labelDFS(i, ++count);
        }
        cout << endl << "그래프 연결성분 개수: " << count << endl;
        for(int i = 0; i<size; i++){
            cout << "Node " << i << " :" << label[i] << endl;
        }
        cout << endl;
    }
};

int main(){
    ConnectedComponentGraph g;

    for(int i = 0; i < 5; i++)
        g.insertVertex('A' + i);

    g.insertEdge(1, 0);
    g.insertEdge(2, 0);
    g.insertEdge(3, 4);
    printf("연결 성분 테스트 그래프\n");
    g.display();

    g.resetVisited();
    g.findConnectedComponent();
}