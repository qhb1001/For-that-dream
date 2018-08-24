#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int head[MAX], cnt, s[MAX], top, number[MAX], low[MAX], belong[MAX], size[MAX], scc;
vector<int>G[MAX];
struct Edge {
    int to, nex;
}e[MAX];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
void trajan(int u) {
    number[u] = low[u] = ++cnt;
    s[++top] = u;
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!number[v]) {
            trajan(v);
            low[u] = min(low[u], low[v]);
        } else if (!belong[v]) {
            low[u] = min(low[u], number[v]);
        }
    }

    if (low[u] == number[u]) {
        int x;
        ++scc;
        while (true) {
            x = s[top--];
            belong[x] = scc;
            size[scc]++;
            G[scc].push_back(x);
            if (x == u) return ;
        }
    }
}
bool cycle[MAX], in[MAX];
int dp[MAX];

void dfs(int u) {
    if (dp[u])  return ;
    int v;
    dp[u] = 1;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (cycle[v])   dp[u] = dp[v] + 1;
        else if (dp[v]) dp[u] = dp[v] + 1;
        else {
            dfs(v);
            dp[u] = dp[v] + 1;
        }
    }
}
int main() {
    // freopen("input", "r", stdin);
    // freopen("output.a", "w", stdout);
    int n, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v);
        if (i != v) add(i, v);
        else dp[i] = 1;
        in[v] = 1;
    }

    cnt = 0;
    for (int i = 1; i <= n; ++i)    if (!number[i]) trajan(i);


    for (int i = 1; i <= scc; ++i) {
        if (G[i].size() != 1) {
            for (int j = 0; j < size[i]; ++j) {
                v = G[i][j];
                cycle[v] = 1;
                dp[v] = size[i];
            }
        }
    }

    for (int i = 1; i <= n; ++i)    {
        if (!cycle[i] && !dp[i])    dfs(i);
        printf("%d\n", dp[i]);
    }
}