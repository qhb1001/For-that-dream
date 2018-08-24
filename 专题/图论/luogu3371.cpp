#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
const int N = 1e4 + 5, E = 5e5 + 5, INF = 2147483647;
using namespace std;
int head[N], cnt, n, m, s, d[N];
bool vis[N];
struct Edge {
    int to, nex, cost;
}e[E];
void add(int u, int v, int cost) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].cost = cost;
    head[u] = cnt;
}
void dijkstra() {
    for (int i = 1; i <= n; ++i)    d[i] = INF;
    d[s] = 0;
    int u, v, Min, idx;
    while (true) {
        Min = INF; idx = -1;
        for (int i = 1; i <= n; ++i) if (!vis[i] && d[i] < Min) {Min = d[i]; idx = i;}
        if (idx == -1)  break;
        vis[idx] = 1;
        u = idx;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (d[v] > d[u] + e[i].cost) {
                d[v] = d[u] + e[i].cost;
            }
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d%d%d", &n, &m, &s);
    int u, v, c;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
    }
    dijkstra();
    printf("%d", d[1]);
    for (int i = 2; i <= n; ++i)    {
        printf(" %d", d[i]);
    }
    
    printf("\n");
}

