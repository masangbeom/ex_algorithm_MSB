//
// Created by sangbeom ma on 2017. 11. 23..
//

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
    string in;
    cin >> in;
    int size;
    int arr[in.size()];
    for(size = 0; size < in.size(); size++){
        arr[size] = (int)in[size] - 48;
    }
    sort(arr, arr+size, greater<int>());
    for(int i=0; i<size; i++)
        cout << arr[i];
}