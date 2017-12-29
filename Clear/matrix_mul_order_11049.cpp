#include <iostream>
using namespace std;

pair<int, int> mat[501];
int dp[501][501];
#define INF 2147483647;
int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int r, c;
        cin >> r >> c;
        mat[i] = make_pair(r, c);
    }

    for (int i=0; i<n-1; ++i) {
        dp[i][i+1] = mat[i].first * mat[i].second * mat[i+1].second;
    }

    for (int k=2; k<n; ++k) {
        for (int i=0; i<n-k; ++i) {
            int j = i+k;
            dp[i][j] = INF;
            for (int x=i; x<j; ++x) {
                if (dp[i][j] > dp[i][x] + dp[x+1][j] + mat[i].first*mat[x].second*mat[j].second) {
                    dp[i][j] = dp[i][x] + dp[x+1][j] + mat[i].first*mat[x].second*mat[j].second;
                }
            }
        }
    }

    cout << dp[0][n-1];

    return 0;
}