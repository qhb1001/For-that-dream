#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
const int MAX = 1e4 + 5;
using namespace std;
int n, m, s, t, vis[MAX], pre[MAX], G[MAX][MAX], cnt;
int augment() {
    deque<int>q;
    q.push_back(s);
    vis[s] = ++cnt;
    int u, v;
    bool flag = false;
    while (!q.empty() && !flag) {
        u = q.front(); q.pop_front();
        for (v = 1; v <= n; ++v) if (vis[v] != cnt && G[u][v]) {
            vis[v] = cnt;
            q.push_back(v);
            pre[v] = u;
            if (v == t) {flag = true; q.clear(); break;}
        }
    }
    if (!flag)  return 0;

    u = t;
    int Min = 1<<30;
    while (pre[u]) {
        Min = min(Min, G[pre[u]][u]);
        u = pre[u];
    }

    u = t;
    while (pre[u]) {
        G[pre[u]][u] -= Min;
        G[u][pre[u]] += Min;
        v = u;
        u = pre[u];
        pre[v] = 0;
    }
    return Min;
}
int main() {
    freopen("input.txt", "r", stdin);
    
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, c;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        G[u][v] += c;
    }

    int ans = 0, t;
    while (t = augment()) {
        // cout << t << endl;
        ans += t;
    }

    printf("%d\n", ans);
}