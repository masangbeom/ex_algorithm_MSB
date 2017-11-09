#include <iostream>
using namespace std;
int dpMP[501][501];
int n;
int main()
{
    int arr[501][501];
    cin >> n;
    cin >> arr[1][1];
    dpMP[1][1] = arr[1][1];
    int resultMax = 0;
    for(int i=2; i<=n; i++)
        for(int j=1; j<=i; j++)
            cin >> arr[i][j];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dpMP[i][j] = max(dpMP[i-1][j-1], dpMP[i-1][j]) + arr[i][j];
            if(i==n){
                if(dpMP[i][j] > resultMax)
                    resultMax = dpMP[i][j];
            }
        }
    }
    cout << resultMax;
}