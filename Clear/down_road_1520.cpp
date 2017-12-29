//
// Created by sangbeom ma on 2017. 12. 29..
//
#include <iostream>

using namespace std;

int mov[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int dp[501][501], map[501][501], N, M;
bool visited[501][501];

int solve(int x, int y)
{
    if (x == N && y == M)
        return 1;
    if (visited[x][y])
        return dp[x][y];

    visited[x][y] = true;
    int ret = 0,a,b;
    for (int i = 0; i < 4; i++) {
        a = x + mov[i][0];
        b = y + mov[i][1];
        if (0 < a &&a <= N && 0 < b && b <= M && map[x][y] > map[a][b])
            ret += solve(a, b);
    }
    return dp[x][y] = ret;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> map[i][j];
    cout << solve(1, 1);
}