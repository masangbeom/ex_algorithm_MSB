//
// Created by sangbeom ma on 2017. 11. 17..
//

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
int G[MAX][MAX];
queue<int> q;
int numVertex, numEdge, startV;
bool visitedDFS[MAX];
bool visitedBFS[MAX];
int DFS(int nV){
    visitedDFS[nV] = true;
    for(int next=1; next<=numVertex; next++){
        if(G[nV][next] == 1 && !visitedDFS[next]){
                cout <<next << " ";
                DFS(next);
        }
    }
};
int BFS(int nV){
    q.push(nV);
    visitedBFS[nV] = true;
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int next = 1; next <= numVertex; ++next){
            if(G[current][next] && !visitedBFS[next]){
                visitedBFS[next] = 1;
                cout << next << " ";
                q.push(next);
            }
        }
    }
};
int main(){
    cin >> numVertex >> numEdge >> startV;
    for(int i=1; i<=numEdge; i++){
        int con1=0;
        int con2=0;
        cin >> con1 >> con2;
        G[con1][con2] = 1;
        G[con2][con1] = 1;
    }
    cout << startV << " ";
    DFS(startV);
    cout << endl;

    cout << startV << " ";
    BFS(startV);
}