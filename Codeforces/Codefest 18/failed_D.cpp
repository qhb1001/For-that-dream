#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 2e5 + 5;
vector<int>G[MAX];
int n, d[MAX], fa[MAX];
bool vis[MAX];
void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    d[1] = 0;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) if (!vis[G[u][i]]) {
            v = G[u][i];
            d[v] = d[u] + 1;
            vis[v] = 1;
            fa[v] = u;
            q.push(v);
        }
    }
}

int s[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs();
    for (int i = 1; i <= n; ++i) cin >> s[i];

    for (int i = 2; i <= n; ++i) if (d[s[i]] == d[s[i - 1]] || d[s[i]] == d[s[i - 1]] + 1) continue; else {cout << "NO\n"; return 0;}

    for (int i = 2; i <= n; ++i) {
        int u = s[i];
        int len = G[fa[u]].size(), t = fa[u];
        while (fa[s[i]] == t && len--) {++i;}
        if (len)    {cout << "NO\n"; return 0;}
        --i;
    }
    cout << "YES\n";
    return 0;
}