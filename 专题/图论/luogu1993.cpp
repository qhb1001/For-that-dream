#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int MAX = 1e4 + 5;
int head[MAX], cnt, n, m, in[MAX], d[MAX]; bool vis[MAX];
struct Edge {
    int to, nex, cost;
}e[MAX<<2];
void add(int u, int v, int c) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].cost = c;
    head[u] = cnt;
}
void input() {
    scanf("%d%d", &n, &m);
    int type, u, v, c;
    while (m--) {
        scanf("%d%d%d", &type, &u, &v);
        if (type == 3) {add(v, u, 0); add(u, v, 0); continue;}
        scanf("%d", &c);
        if (type == 1)  add(u, v, c);
        else add(v, u, -c);
    }
}
bool spfa(int t) {
    queue<int>q;
    q.push(t);
    d[t] = 0; vis[t] = true;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop(); vis[u] = false;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (d[v] > d[u] + e[i].cost) {
                d[v] = d[u] + e[i].cost;
                if (!vis[v]) {
                    ++in[v]; vis[v] = true; q.push(v);
                    if (in[v] == n + 1) return false;
                }
            }
        }
    }
    return true;
}
int main() {
    input();
    for (int i = 1; i <= n; ++i) d[i] = 1<<30;
    for (int i = 1; i <= n; ++i) if (d[i] == (1<<30)) {
        if (!spfa(i))   {printf("No\n"); return 0;}
    }
    printf("Yes\n");
    return 0;
}