//
// Created by sangbeom ma on 2017. 11. 9..
//

#include <iostream>
using namespace std;
int N;
int dp[3];
int arr[2200][2200];
void plusDP(int num){
    switch(num){
        case -1:{
            dp[0]++;
            break;
        }
        case 0:{
            dp[1]++;
            break;
        }
        case 1:{
            dp[2]++;
            break;
        }
    }
}
int divide(int x, int y, int N) {
    int check = -1;
    if(N==3){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(arr[x][y] != arr[x+i][y+j]) {
                    check = 1;
                    break;
                }
            }
        }
        if(check == -1){
            plusDP(arr[x][y]);
            return 0;
        }else {
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    plusDP(arr[x+i][y+j]);
                }
            }
        }
    } else {
        divide(x, y, N/3);
        divide(x, y+(N/3), N/3);
        divide(x, y+(2*(N/3)), N/3);
        divide(x+(N/3), y, N/3);
        divide(x+(N/3), y+(N/3), N/3);
        divide(x+(N/3), y+(2*(N/3)), N/3);
        divide(x+(2*(N/3)), y,N/3);
        divide(x+(2*(N/3)), y+(N/3),N/3);
        divide(x+(2*(N/3)), y+(2*(N/3)),N/3);
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin>>arr[i][j];
        }
    }
    divide(0,0,N);
    cout<<dp[0]<<endl<<dp[1]<<endl<<dp[2]<<endl;
}
