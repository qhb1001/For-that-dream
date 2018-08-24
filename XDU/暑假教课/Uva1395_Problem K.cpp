#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e2 + 5;
struct Edge {
    int from, to, cost;
    bool operator < (const Edge b) const {
        return cost < b.cost;
    }
}e[MAX * MAX];

int fa[MAX], cnt[MAX];
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
bool unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (cnt[u] < cnt[v]) swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
    return true;
}
void init() {
    for (int i = 1; i <= 100; ++i) {
        fa[i] = i;
        cnt[i] = 1;
    }
}

int n, m;
void input() {
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].from >> e[i].to >> e[i].cost;
    }
    sort(e + 1, e + 1 + m);
}

int deal() {
    int ans = 1<<30, k, j;
    for (int i = 1; i <= m; ++i) {
        init();
        k = 1;
        for (j = i; j <= m; ++j) {
            if (find(e[j].from) != find(e[j].to)) {
                unit(e[j].from, e[j].to);
                ++k;
            }
            if (k == n) break;
        }

        if (j == m + 1) break;
        ans = min(ans, e[j].cost - e[i].cost);
    }

    if (ans == (1<<30)) return -1;
    return ans;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n >> m && n) {
        input();
        cout << deal() << '\n';
    }
}