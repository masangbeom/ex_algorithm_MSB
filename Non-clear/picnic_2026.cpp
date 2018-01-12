//
// Created by sangbeom ma on 2018. 1. 5..
//

#include <iostream>

using namespace std;

int K;
int N;
int F;
int tempK;

//int arr[901][901];
bool visitedDFS[901][901];

void DFS(int goN){
    for(int next=1; next<=N; next++){
        if(K && !visitedDFS[next]){
            cout <<next << " ";
            DFS(next);
        }
    }
}

int main(){
    cin >> K >> N >> F;
    tempK = K;
    for(int i=1; i<=F; i++){
        int F1, F2;
        cin >> F1 >> F2;
        visitedDFS[F1][F2] = true;
        visitedDFS[F2][F1] = true;
    }

    DFS(1);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << visitedDFS[i][j] << " ";
        }
        cout << endl;
    }
}