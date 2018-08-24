#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e6 + 5;
int head[MAX], cnt, scc, belong[MAX], size[MAX], low[MAX], number[MAX], s[MAX], top;
struct Edge {
    int to, nex;
}e[MAX];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
void dfs(int u) {
    number[u] = low[u] = ++cnt;
    s[++top] = u;
    for (int i = head[u]; i; i = e[i].nex) {
        int v = e[i].to;
        if (!number[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (number[v]) {
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
            if (x == u) break;
        }   
    }
}

int main() {
    // freopen("in", "r", stdin);
    int n, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v);
        add(i, v);
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!number[i]) dfs(i);
    }

    int ans = 1<<30;
    for (int i = 1; i <= scc; ++i)  if (size[i] != 1)   ans = min(ans, size[i]);
    printf("%d\n", ans);
}