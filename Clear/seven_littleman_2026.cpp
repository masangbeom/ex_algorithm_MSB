//
// Created by sangbeom ma on 2018. 1. 5..
//

#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];

int sumOfRemain(int i, int j){
    int sum = 0;
    for(int k=0; k<9; k++){
        if(k != i && k != j)
            sum += arr[k];
    }
    return sum;
}

void bruteForce(){
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sumOfRemain(i, j) == 100){
                for(int k=0; k<9; k++){
                    if(k != i && k != j)
                        cout << arr[k] << endl;
                }
            }
        }
    }
}

int main()
{
    for(int i=0; i<9; i++)
    {
       cin >> arr[i];
    }
    sort(arr, arr + 9);
    bruteForce();
}