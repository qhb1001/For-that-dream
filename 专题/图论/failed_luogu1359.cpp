#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int MAX = 210;
int G[MAX][MAX], dp[MAX][MAX][MAX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%d", &G[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j)   dp[i][j][0] = G[i][j];

    int j;
    for (int k = 1; k < n; ++k) {
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i + len <= n; ++i) {
                j = i + len;
                dp[i][j][k] = 1<<30;
                for (int l = i; l < j; ++l) dp[i][j][k] = min(dp[i][j][k], dp[i][l][k - 1] + dp[l][j][0]);
            }
        }
    }

    int ans = 1<<30;
    for (int i = 0; i < n; ++i) ans = min(ans, dp[1][n][i]);
    printf("%d\n", ans);
}