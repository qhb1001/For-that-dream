#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 305;
int G[MAX][MAX], n, m, s, t, level[MAX];
inline void add(int u, int v) {
    G[u][v] = 1;
    G[v][u] = 0;
    G[s][u] = 1;
    G[v][t] = 1;
}
void init() {
    memset(G, -1, sizeof(G));
}
bool bfs() {
    queue<int>q;
    memset(level, 0, sizeof(level));
    level[s] = 1;
    q.push(s);
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (v = 1; v <= t; ++v) if (level[v] == 0 && G[u][v] > 0) {
            level[v] = level[u] + 1;
            q.push(v);
            if (v == t) return true;
        }
    }
    return false;
}
int dfs(int u, int Min) {
    if (!Min || u == t) return Min;

    int ans = 0, plus;
    for (int v = 1; v <= t; ++v) if (level[v] == level[u] + 1 && G[u][v] > 0) {
        plus = dfs(v, min(Min, G[u][v]));
        ans += plus;
        G[u][v] -= plus;
        G[v][u] += plus;
        Min -= plus;
    }
    if (!ans)   level[u] = 0;
    return ans;
} 
int main() {
    init();
    scanf("%d%d", &m, &n);
    t = m + n + 1; s = 0;
    int u, v;
    while (scanf("%d%d", &u, &v) && u != -1) {
        add(u, v);
    }
    int ans = 0;
    while (bfs()) ans += dfs(s, 1<<30);
    if (!ans) {printf("No Solution!\n"); return 0;}

    printf("%d\n", ans);
    for (int i = 1; i <= m; ++i) 
    for (int j = m + 1; j <= m + n; ++j) if (G[i][j] == 0)  printf("%d %d\n", i, j);
}