#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int head[MAX], cnt;
struct Edge {
    int to, nex;
}e[MAX];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
bool vis[MAX];
int dp[MAX];
void dfs(int u, int step) {
    if (vis[u]) return ;
    vis[u] = 1;
    int v = e[head[u]].to;
    if (vis[v]) dp[u] = dp[v] + step;
    else {
        dfs(v, step + 1);
        dp[u] = dp[v] + step;
    }
}
int main() {
    int n, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v);
        add(i, v);
    }
    for (int i = 1; i <= n; ++i)    {
        dfs(i, 1);
        printf("%d\n", dp[i]);
    }
}