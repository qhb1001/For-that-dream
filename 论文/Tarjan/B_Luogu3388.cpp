#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
    int to, nex;
}e[MAX<<1];
int head[MAX], cnt = 0;
int scc[MAX], number[MAX], low[MAX];
void dfs(int u, int fa) {
    number[u] = low[u] = ++cnt;
    int v, child = 0;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!number[v]) {
            dfs(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            if (low[v] >= number[u])    ++scc[u];
        } else if (number[v] < number[u] && v != fa) {
            low[u] = min(low[u], number[v]);
        }
    }

    if (fa == -1 && child == 1) scc[u] = 0;
}
void add(int u, int v) {
    ++cnt;
    e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt;
    ++cnt;
    e[cnt].to = u; e[cnt].nex = head[v]; head[v] = cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        add(u, v);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (number[i] == 0) dfs(i, -1);
        if (scc[i]) ++ans;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)   {
        if (scc[i]) {
            cout << i << " ";
        }
    }
    cout << '\n';
}
