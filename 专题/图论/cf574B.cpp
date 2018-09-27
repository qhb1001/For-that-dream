#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 4e3 + 5;
struct Edge {
    int u, v;
}e[MAX];
bool G[MAX][MAX];
int  degree[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].u >> e[i].v;
        G[e[i].u][e[i].v] = G[e[i].v][e[i].u] = 1;
        degree[e[i].u]++; degree[e[i].v]++;
    }

    int ans = 1<<30;
    for (int i = 1, u, v; i <= m; ++i) {
        u = e[i].u; v = e[i].v;
        for (int j = 1; j <= n; ++j) if (j != u && j != v && G[j][u] && G[j][v]) ans = min(ans, degree[u] + degree[v] + degree[j]);
    }

     if (ans == 1<<30)  cout << -1 << endl;
     else cout << ans - 6 << endl;
     
}