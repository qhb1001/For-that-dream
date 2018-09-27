#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1005;
typedef long long ll;
int head[MAX], cnt, in[MAX];
struct Edge {
    int to, nex;
    ll cost;
}e[MAX<<4];
int n, n1, n2;
ll d[MAX];
void add(int u, int v, ll c) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].cost = c;
    head[u] = cnt;
}
void input() {
    scanf("%d%d%d", &n, &n1, &n2);
    int u, v, c;
    for (int i = 1; i <= n1; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
    }
    for (int i = 1; i <= n2; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        add(v, u, -c);
    }
}
bool vis[MAX];
ll spfa() {
    queue<int>q;
    for (int i = 1; i <= n; ++i) d[i] = (1ll<<50);
    d[1] = 0;
    q.push(1);
    vis[1] = true;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop(); vis[u] = false;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (d[v] > d[u] + e[i].cost) {
                d[v] = d[u] + e[i].cost;
                if (!vis[v]) {
                    vis[v] = true;
                    in[v]++; if (in[v] == n + 1)    return -1;
                    q.push(v);
                }
            }
        }
    }
    if (d[n] == (1ll<<50))  return -2;
    return d[n];
}
int main() {
    input();
    printf("%lld\n", spfa());
}