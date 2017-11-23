//
// Created by sangbeom ma on 2017. 11. 23..
//
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
int N;
int A[51];
int B[51];
int main(){
    int S = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    for(int i=0; i<N; i++){
        cin >> B[i];
    }
    sort(B, B+N, greater<int>());
    for(int i=0; i<N; i++){
        S += A[i]*B[i];
    }
    cout << S;
}
