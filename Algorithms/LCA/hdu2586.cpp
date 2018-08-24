#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 4e4 + 5;
int head[MAX], cnt, fa[MAX], n, q, d[MAX];
bool vis[MAX];
vector<pair<int, int> >query[MAX];
vector<pair<int, int> >ans;
struct Edge {
    int to, nex, cost;
}e[MAX<<1];
void add(int u, int v, int cost) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].cost = cost;
    head[u] = cnt;
}
void init() {
    ans.clear();
    memset(head, 0, sizeof(head));
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++i)    {
        fa[i] = i;
        query[i].clear();
    }
    cnt = 0;
}
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    fa[v] = u;
}
void dfs1(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (v != fa) {
            d[v] = d[u] + e[i].cost;
            dfs1(v, u);
        }
    }
}
void dfs2(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!vis[v] && v != fa) {
            dfs2(v, u);
            vis[v] = 1;
            unit(u, v);
        }
    }

    int len = query[u].size();
    pair<int, int> now;
    for (int i = 0; i < len; ++i) {
        now = query[u][i];
        if (vis[now.first])     {
            ans.push_back(make_pair(now.second, d[now.first] + d[u] - 2*d[find(now.first)]));
            // cout << u << ' ' << now.first << ' ' << find(now.first) << endl;
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, u, v, cost; cin >> T;
    while (T--) {
        cin >> n >> q;
        init();
        for (int i = 1; i < n; ++i) {
            cin >> u >> v >> cost;
            add(u, v, cost);
            add(v, u, cost);
        }
        for (int i = 1; i <= q; ++i) {
            cin >> u >> v;
            query[u].push_back(make_pair(v, i));
            query[v].push_back(make_pair(u, i));
        }
        dfs1(1, -1);
        dfs2(1, -1);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < q; ++i) cout << ans[i].second << '\n';
        // cout << '\n';
    }
}