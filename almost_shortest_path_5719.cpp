//
// Created by sangbeom ma on 2017. 12. 26..
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int N;
int M;
int S;
int D;
int arr[501][501];
int dp[501][501];
bool vis[501];
#define INF 2e8;

struct Node{
    int c,r,w;
    Node(int cc, int rr, int ww):c(cc), r(rr), w(ww){}
};

class Comparator {
    public:
    bool operator()(Node lhs, Node rhs){
            return lhs.w>rhs.w;
    }
};

int check(int sc, int sr){
    priority_queue<Node, vector<Node>, Comparator> pq;
    dp[sc][sr] = arr[sc][sr];
    pq.push(Node(sc,sr,dp[sc][sr]));
    while(!pq.empty()){
        int current = pq.top().r;
        pq.pop();
        for(int next = 0; next < current; next++){
            if(!vis[next]){
                vis[next] = true;
                cout << next << " ";
                pq.push(Node(next, current, dp[next][current]));
            }
        }
    }
}

int main(){
    while(1){
        N = 0;
        M = 0;
        S = 0;
        D = 0;
        for(int i=0; i<501; i++){
            vis[i] = false;
            for(int j=0; j<501; j++){
                arr[i][j] = 0;
                dp[i][j] = INF;
            }
        }
        cin >> N >> M;
        if(N==0 && M==0) break;
        cin >> S >> D;
        for(int i=0; i<M; i++){
            int fromV, atV, pLength = 0;
            cin >> fromV >> atV >> pLength;
            arr[fromV][atV] = pLength;
        }
        check(S,D);
//        for(int i=0; i<N; i++){
//            cout << endl;
//            for(int j=0; j<N; j++){
//                cout << dp[i][j] << " ";
//            }
//        }
    };

}