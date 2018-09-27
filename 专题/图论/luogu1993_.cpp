#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 1e4 + 5;
int head[MAX], cnt, n, m, in[MAX], d[MAX]; bool vis[MAX];
struct Edge {
    int to, nex, cost;
}e[MAX<<4];
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
        if (type == 1)  add(u, v, -c);
        else add(v, u, c);
    }
}
bool spfa(int u) {
    vis[u] = 1;
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (d[v] > d[u] + e[i].cost) {
            if (vis[v]) return false;
            d[v] = d[u] + e[i].cost;
            if (!spfa(v))    return false;
        }
    }
    vis[u] = 0;
    return true;
}
int main() {
    input();
    for (int i = 1; i <= n; ++i) {
        d[i] = 0;
        if (!spfa(i))   return 0 * printf("No\n");
    }
    printf("Yes\n");
}
