#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 405;
bool G[MAX][MAX];
int n, m, d[MAX];

int bfs() {
    queue<int>q;
    bool vis[MAX] = {0};
    int u, v; 
    q.push(1);
    d[1] = 0;
    vis[1] = 1;;
    
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (v = 1; v <= n; ++v) if (G[u][v] && !vis[v]) {d[v] = d[u] + 1; vis[v] = 1; q.push(v);}
    }
    return d[n];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    if (n == 2) {cout << -1 << endl; return 0;}

    if (G[1][n] == 1) {
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) if (i != j)   G[i][j] = 1 - G[i][j];
    }

    if (bfs() == 0) cout << -1 << endl; 
    else cout << d[n] << endl;
}