#include<stdio.h>
#include <iostream>
using namespace std;
int fibonacci(int n, int *count0, int *count1) {
    if (n==0) {
        *count0 += 1;
        return 0;
    } else if (n==1) {
        *count1 += 1;
        return 1;
    } else {
        int temp1 = n-1;
        int temp2 = n-2;
        return fibonacci(temp1, count0, count1) + fibonacci(temp2, count0, count1);
    }
}
int main() {
    int testNum = 0;
    cin >>  testNum;
    int arrTest[testNum][2];
    for(int i=0; i<testNum; i++){
        cin >> arrTest[i][0];
        arrTest[i][1] = 0;
        arrTest[i][2] = 0;
        fibonacci(arrTest[i][0], &arrTest[i][1], &arrTest[i][2]);
        cout << arrTest[i][1] << " " << arrTest[i][2] << endl;
    }
    return 0;
}