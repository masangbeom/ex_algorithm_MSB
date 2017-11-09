//
// Created by sangbeom ma on 2017. 11. 2..
//
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
double powSum(int a, int b){
    return pow(a,2) + pow(b,2);
}
int main(){
    string filePath1 = "/Users/sangbeomma/CLionProjects/ex_algorithm1/2.inp";
    int numInput;
    vector<int> v;
    ifstream inFile(filePath1);
    inFile >> numInput;
    int inputArr[numInput];
    int tempArr[numInput];
    int count = 0;
//    cout << numInput << endl;
    for(int i = 0; i<numInput; i++)
        inFile >> inputArr[i];
    sort(inputArr, inputArr + numInput);
    int tempNum = numInput;
    for(int i = 0; i<tempNum; i++){
        for(int j = i+1; j<tempNum; j++){
            for(int k = tempNum-1; k>j; k--){
                if(powSum(inputArr[i], inputArr[j]) == inputArr[k]){
                        tempArr[count++];
                }
            }
        }
    }
    sort(v.begin(), v.end());
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    return 0;
}