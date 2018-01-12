//
// Created by sangbeom ma on 2018. 1. 12..
//

#include <iostream>

using namespace std;
int N;
int arr[64][64];

void divideAndConquer(int x, int y, int size){
    int cur = arr[x][y];
    bool chk = true;
    for( int i=x;i<x+size;i++){
        if(!chk)break;
        for(int j=y;j<y+size;j++) {
            if(!chk)break;
            if (cur != arr[i][j]) chk = false;
        }
    }

    if(chk){
        cout<<cur;
    }
    else{
        int temp = size/2;
        cout << "(";
        divideAndConquer(x, y, temp);
        divideAndConquer(x, y+temp, temp);
        divideAndConquer(x+temp, y, temp);
        divideAndConquer(x+temp, y+temp, temp);
        cout << ")";
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    divideAndConquer(0, 0, N);
}

