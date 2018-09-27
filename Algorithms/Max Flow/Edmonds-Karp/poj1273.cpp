#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 210;
typedef long long ll;
int G[MAX][MAX], n, m, pre[MAX];
bool vis[MAX];
ll augmentPath() {
    queue<int>q;
    q.push(1); 
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    bool flag = false;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        if (u == n) {flag = true; break;}
        vis[u] = 1;
        for (v = 1; v <= n; ++v) if (!vis[v] && G[u][v]) {
            vis[v] = 1;
            pre[v] = u;
            q.push(v);
        }
    }
    if (!flag)  return 0;

    u = n;
    ll minFlow = 1LL<<50;
    while (pre[u]) {
        minFlow = min(minFlow, (ll)G[pre[u]][u]);
        u = pre[u];
    }

    u = n;
    while (pre[u]) {
        G[pre[u]][u] -= minFlow;
        G[u][pre[u]] += minFlow;
        u = pre[u];
    }
    return minFlow;
}
int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        memset(G, 0, sizeof(G));
        int u, v, c;
        while (m--) {
            scanf("%d%d%d", &u, &v, &c);
            G[u][v] += c;
        }

        ll ans = 0, t;
        while (true) {
            t = augmentPath(); 
            if (!t) break;
            ans += t;
        }

        printf("%lld\n", ans);
    }
}