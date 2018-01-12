#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2e8;
int N, start;
int arr[16][16];
int dp[16][1<<16]; // 1<<16 = 2의16승 [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1]
int check(int cur, int visited) {
    if(visited == (1<<N)-1) return arr[cur][0]; // 외판원이 모든 지점을 방문을 했을 때 원래의 집으로 돌아 감
    int &ret = dp[cur][visited]; // ret의 값을 바꾸면 dp[cur][visited]의 값도 바꿀 수 있도록 함
    if(ret != 0) return ret; // 초기에 INF로 채워놓지않음(0으로 채워져있음), 즉 ret가 0이 아니면 방문을 했다는 것
    ret = INF;

    for(int i=0; i<N; i++) {
        if(visited & (1<<i)) continue; // BitMask로 visited 확인 하기
        if(arr[cur][i]==0) continue;
        ret = min(ret, check(i, visited| (1<<i))+arr[cur][i]); // visited에서 i의 지점을 방문했다고 하고 넘겨주는 것
    }
    return ret;
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>arr[i][j];
        }
    }
    cout<<check(0,1);
}