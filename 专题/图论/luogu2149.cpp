#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1505;
const int INF = 0x3f3f3f3f;
int head[MAX], cnt, s[10], d[10][MAX];
struct Edge {
    int to, nex, cost;
}e[MAX<<3];

void add(int u, int v, int c) {
    e[++cnt] = (Edge) {v, head[u], c};
    head[u] = cnt;
}

void dijkstra(int idx) {
    d[idx][s[idx]] = 0;
    priority_queue<pair<int, int> >q;
    q.push(make_pair(0, s[idx]));
    pair<int, int> now;
    int u, v;
    while (!q.empty()) {
        now = q.top(); q.pop();
        u = now.second;
        if (d[idx][u] < now.first)  continue;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (d[idx][v] > d[idx][u] + e[i].cost) {
                d[idx][v] = d[idx][u] + e[i].cost;
                q.push(make_pair(d[idx][v], v));
            }
        }
    }
}
int main() {
    memset(d, 0x3f3f3f3f, sizeof(d));
    int n, m, u, v, c; scanf("%d%d", &n, &m);
    for (int i = 1; i <= 4; ++i)    scanf("%d", &s[i]);
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c); add(v, u, c);
    }
    for (int i = 1; i <= 4; ++i)    dijkstra(i);

    int ans = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        if (d[1][i] + d[2][i] != d[1][s[2]])    continue;
        if (d[1][j] + d[2][j] != d[1][s[2]])    continue;
        if (d[3][i] + d[4][i] != d[3][s[4]])    continue;
        if (d[3][j] + d[4][j] != d[3][s[4]])    continue;
        if (d[1][j] - d[1][i] == d[3][j] - d[3][i]) ans = max(ans, d[3][j] - d[3][i]);
    }
    printf("%d\n", ans);
}