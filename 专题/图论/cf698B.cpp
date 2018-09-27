#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 2e5 + 5;
int num[MAX], low[MAX], s[MAX], top, sccCnt, belong[MAX], cnt, a[MAX], ans;
vector<int>scc[MAX], G[MAX], b[MAX];
void dfs(int u, int fa) {
    num[u] = low[u] = ++cnt;
    s[++top] = u;
    for (int v : G[u]) if (v != fa) {
        if (!num[v]) {
            dfs(v, fa);
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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        G[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) if (!num[i]) dfs(i, -1);

    cnt = 0;
    for (int i = 1; i <= sccCnt; ++i) {
        if (scc[i].size() != 1) scc[++cnt] = scc[i];
        if (scc[i].size() == 1 && a[scc[i][0]] == scc[i][0])    scc[++cnt] = scc[i];
    }
    sccCnt = cnt;

    if (sccCnt == 1 && scc[1].size() == 1) {
        cout << ans << '\n';
        for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
        cout << '\n';
        return 0;
    }
    ans = sccCnt - 1;
    int root = -1;
    for (int i = 1; i <= sccCnt; ++i) if (scc[i].size() == 1) root = scc[i][0];
    if (root == -1) {root = scc[1][0]; a[root] = root; ++ans;}
    for (int i = 1; i <= sccCnt; ++i) a[scc[i][0]] = root;

    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
}