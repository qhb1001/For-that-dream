#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#define before 1
#define invert 2
#define after 3
using namespace std;
const int MAX = 5005;
char s[MAX];
int dp[MAX][MAX][4], len;
int get(int i, int status) {
    if (status == before || status == after)    return s[i] == '(';
    return s[i] == ')';
}
int dfs(int i, int l, int status) {
    if (dp[i][l][status] != -1) return dp[i][l][status];
    if (i == len + 1)   {
        if (i - 1 - l == l) return 1;
        return 0;
    }
    
    if (i - 1 - l > l) return dp[i][l][status] = 0;

    if (status == before)   dp[i][l][status] = dfs(i + 1, l + get(i, status), status) || dfs(i, l, invert);
    else if (status == invert)  dp[i][l][status] = dfs(i + 1, l + get(i, status), status) || dfs(i, l, after);
    else dp[i][l][status] = dfs(i + 1, l + get(i, status), status);

    return dp[i][l][status];
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    while (scanf("%s", s + 1) != EOF) {
        memset(dp, -1, sizeof(dp));
        len = strlen(s + 1);
        if (dfs(1, 0, before) == 1) printf("possible\n");
        else printf("impossible\n");
    }
}
