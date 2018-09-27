#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 5e3 + 5;
int n, m, head[MAX], cnt;
struct Edge {
    int to, nex;
}e[50005<<2];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
vector<int>scc[MAX];
void input() {
    scanf("%d%d", &n, &m);
    int u, v, t;
    while (m--) {
        scanf("%d%d%d", &u, &v, &t);
        if (t == 1) add(u, v);
        else add(u, v), add(v, u);
    }
}
int s[MAX], top, low[MAX], num[MAX], sccCnt, belong[MAX];
void tarjan(int u) {
    low[u] = num[u] = ++cnt;
    s[++top] = u;
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!num[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!belong[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        int x;
        ++sccCnt;
        while (true) {
            x = s[top--];
            scc[sccCnt].push_back(x);
            belong[x] = sccCnt;
            if (x == u) break;
        }
    }
}
vector<int>ans[MAX];
int main() { 
    input();
    for (int i = 1; i <= n; ++i)    if (!num[i])    tarjan(i);
    int Max = 0;
    for (int i = 1; i <= sccCnt; ++i) Max = max(Max, (int)scc[i].size());
    int len = 0;
    for (int i = 1; i <= sccCnt; ++i) if (scc[i].size() == Max) {
        ans[++len] = scc[i];
        sort(ans[len].begin(), ans[len].end());
    }

    int Min = 1<<30;
    for (int i = 1; i <= len; ++i) Min = min(Min, ans[i][0]);
    for (int i = 1; i <= len; ++i)  if (Min == ans[i][0]) {
        len = ans[i].size();
        printf("%d\n", len);
        printf("%d", ans[i][0]);
        for (int j = 1; j < len; ++j)   printf(" %d", ans[i][j]);
        return 0;
    }
    
}