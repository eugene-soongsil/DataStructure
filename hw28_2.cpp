#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

inline void error(const char* str){
    fprintf(stderr, "%s\n", str);
    exit(1);
};

#define MAX_QUEUE_SIZE 100
#define INF 9999
#define MAX_VTXS 256

class AdjMatGraph{
protected:
    int size;
    char vertices[MAX_VTXS];
    int adj[MAX_VTXS][MAX_VTXS];
public:
    AdjMatGraph(){reset();}
    ~AdjMatGraph(){}
    
    char getVertex(int i){return vertices[i];}
    int getEdge(int i, int j){return adj[i][j];}
    void setEdge(int i, int j, int val){adj[i][j] = val;}
    bool isEmpty(){return size == 0;}
    bool isFull(){return size >= MAX_VTXS;}
    
    void reset(){
        size = 0;
        for(int i = 0; i < MAX_VTXS; i++)
            for(int j =0; j<MAX_VTXS; j++)
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
        for(int i = 0; i<size; i++){
            printf("%c ", getVertex(i));
            for(int j=0; j<size; j++)
                printf(" %5d", getEdge(i, j));
            printf("\n");
        }
    }
    
    void load(int g[][7], int c){
        for(int i=0; i<c; i++){
            insertVertex('A'+i);
            for(int j = 0; j<c; j++){
                adj[i][j] = g[i][j];
            }
        }
    }
};

class WGraph : public AdjMatGraph{
public :
    WGraph(){}
    ~WGraph(){}
    
    bool hasEdge(int i, int j){return (getEdge(i, j)<INF);}
    
    void insertEdge(int u, int v, int weight){
        if(weight == INF) weight = INF;
        setEdge(u, v, weight);
    }
};

class WGraphDijkstra : public WGraph{
    int previous[MAX_VTXS];
    int dist[MAX_VTXS];
    int found[MAX_VTXS];
public :
    WGraphDijkstra(void){}
    ~WGraphDijkstra(void){}
    
    void PrintDistance(){
        for(int i=0; i<size; i++)
            printf("%5d,%c", dist[i], (dist[i]!=9999?(getVertex(previous[i])):32));
        printf("\n");
    }
    
    void printPath(int start){
        int tmp;
        for(int n = 0; n<size; n++){
            if(start==n){
                cout << getVertex(n) << ", Distance:" << dist[n] << endl;
            }
            else{
                cout << getVertex(n) << " ";
                tmp = previous[n];
                while(tmp!=start){
                    cout << getVertex(tmp) << " ";
                    tmp = previous[tmp];
                }
                cout << getVertex(tmp) << ", Distance:" << dist[n] << endl;
            }
        }
    }
    
    int chooseVertex(){
        int min = INF;
        int minpos = -1;
        for(int i=0; i<size; i++)
            if(dist[i] < min && !found[i]){
                min = dist[i];
                minpos = i;
            }
        return minpos;
    }
    
    void ShortestPath(int start){
        for(int i=0; i<size; i++){
            dist[i] = getEdge(start, i);
            previous[i] = start;
            found[i] = 0;
        }
        found[start] = 1;
        dist[start] = 0;
        
        for(int i = 0; i<size; i++){
            printf("Step%2d:", i + 1);
            for(int j=0; j<size; j++){
                printf("%c", found[j] ? getVertex(j) : 32);
            }
            PrintDistance();
            int u = chooseVertex();
            found[u] = 1;
            
            for(int w = 0; w<size; w++){
                if(found[w] == 0){
                    if(dist[u] + getEdge(u, w)<dist[w]){
                        dist[w] = dist[u] + getEdge(u, w);
                        previous[w] = u;
                    }
                }
            }
        }
    }
};