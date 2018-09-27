#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 10005;
int n, m, k, X[MAX], Y[MAX], dp[MAX][1005];
struct Pipe {
    int x, y1, y2;
    bool operator < (const Pipe b) const {
        return x < b.x;
    }
}p[10005];
int min(int a, int b) {
    if (a == -1)    return b;
    if (b == -1)    return a;
    if (a < b)  return a;
    return b;
}
bool inRange(int j, int y1, int y2) {
    if (y1 < j && j < y2)   return true;
    return false;
}
bool check(int i) {
    for (int j = 1; j <= m; ++j)    if (dp[i][j] != -1) return true;
    return false;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.a", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i)     scanf("%d%d", &X[i], &Y[i]);
    for (int i = 1; i <= k; ++i)    scanf("%d%d%d", &p[i].x, &p[i].y1, &p[i].y2);
    sort(p + 1, p + 1 + k);
    
    memset(dp, -1, sizeof(dp));
    p[k + 1].x = n + 1;
    for (int i = 1; i <= m; ++i)    dp[0][i] = 0;
    int cnt = 1, x, y;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        x = X[i - 1];
        y = Y[i - 1];

        if (i != p[cnt].x) {
            for (int j = 1; j <= m; ++j) if (dp[i - 1][j] != -1)    dp[i][min(j + x, m)] = min(dp[i][min(j + x, m)], dp[i - 1][j] + 1);
            for (int j = 1; j <= m; ++j)    if (dp[i][j] != -1) dp[i][min(j + x, m)] = min(dp[i][min(j + x, m)], dp[i][j] + 1);
            for (int j = m; j > y; --j) if (dp[i - 1][j] != -1) dp[i][j - y] = min(dp[i][j - y], dp[i - 1][j]);
            if (!check(i))  {
                flag = false;
                break;
            }
        } else {
            for (int j = 1; j <= m; ++j) if (dp[i - 1][j] != -1)    dp[i][min(j + x, m)] = min(dp[i][min(j + x, m)], dp[i - 1][j] + 1);
            for (int j = 1; j <= m; ++j)    if (dp[i][j] != -1) dp[i][min(j + x, m)] = min(dp[i][min(j + x, m)], dp[i][j] + 1);
            for (int j = 1; j <= m; ++j) if (!inRange(j, p[cnt].y1, p[cnt].y2)) dp[i][j] = -1;
            for (int j = m; j > y; --j) if (inRange(j - y, p[cnt].y1, p[cnt].y2) && dp[i - 1][j] != -1) dp[i][j - y] = min(dp[i][j - y], dp[i - 1][j]);
            for (int j = 1; j <= m; ++j) if (!inRange(j, p[cnt].y1, p[cnt].y2)) dp[i][j] = -1;
            if (!check(i))  {
                flag = false;
                break;
            }
            ++cnt;
        } 
    }

    if (!flag) printf("0\n%d\n", cnt - 1);
    else {
        int ans = 1<<30;
        for (int i = 1; i <= m; ++i)    if (dp[n][i] != -1) ans = min(ans, dp[n][i]);
        printf("1\n%d\n", ans);
    }

    for (int j = m; j >= 0; --j) {
        for (int i = 0; i <= n; ++i) printf("%10d ", dp[i][j]);
        cout << endl;
    }
}