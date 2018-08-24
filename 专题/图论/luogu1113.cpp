#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e4 + 5;
int head[MAX], cnt, cost[MAX], n;
bool in[MAX];
struct Edge {
    int to, nex;
}e[MAX*100];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}

void input() {
    cin >> n;
    int v;
    for (int i = 1; i <= n; ++i) {
        cin >> v >> cost[v];
        while (cin >> v && v)   add(v, i), in[i] = 1;
    }
}
int dp[MAX];
int dfs(int u) {
    if (dp[u])  return dp[u];
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        dp[u] = max(dp[u], dfs(v));
    }
    return dp[u] += cost[u];
}   
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    int ans = 1<<30;
    for (int i = 1; i <= n; ++i)    if (!in[i]) ans = min(ans, dfs(i));
    cout << ans << endl;
}