#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1e3 + 5;
vector<pair<int, int> >G[MAX], G_[MAX];
int n, m, s, e, k, t, d[MAX], vis[MAX];
void input() {
    scanf("%d%d%d%d", &s, &e, &k, &t);
    for (int i = 1; i <= n; ++i) {G[i].clear(); G_[i].clear();}
    for (int i = 1, u, v, c; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back(make_pair(v, c));
        G_[v].push_back(make_pair(u, c));
    }
}
void dijkstra() {
    queue<int>q;
    q.push(e);
    int len, u, v;
    for (int i = 1; i <= n; ++i) d[i] = 1<<30, vis[i] = false;
    vis[e] = 1;
    d[e] = 0;
    while (!q.empty()) {
        u = q.front(); q.pop(); vis[u] = false;

        len = G_[u].size();
        for (int i = 0; i < len; ++i) {
            v = G_[u][i].first;
            if (d[v] > d[u] + G_[u][i].second) {
                d[v] = d[u] + G_[u][i].second;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
struct Node {
    int h, g, u;
    Node(int a = 0, int b = 0, int c = 0) {
        h = a; g = b; u = c;
    }
    bool operator < (const Node b) const {
        return h + g > b.h + b.g;
    }
}now;

priority_queue<Node>q;
int solve() {
    while (!q.empty()) q.pop();

    q.push(Node(0, d[s], s));
    memset(vis, 0, sizeof(vis));

    int len, u, v;
    while (!q.empty()) {
        now = q.top(); q.pop(); u = now.u;
        vis[u]++;
        if (u == e && vis[u] == k)   return now.h;
        if (now.h > t)  continue;
        len = G[u].size();
        if (vis[u] <= k) for (int i = 0; i < len; ++i) {
            v = G[u][i].first;
            q.push(Node(G[u][i].second + now.h, d[v], v));
        }
    }

    return -1;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        input();
        dijkstra();
        if (d[s] == 1<<30)  {printf("Whitesnake!\n"); continue;}
        int now = solve();
        
        if (now != -1 && now <= t) printf("yareyaredawa\n");
        else printf("Whitesnake!\n");
    }
}
