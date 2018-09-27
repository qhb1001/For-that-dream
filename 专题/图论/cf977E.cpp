#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 2e5 + 5;
int fa[MAX], cnt[MAX], n, m, degree[MAX];
vector<int>scc[MAX];
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return ;
    if (cnt[u] < cnt[v])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)    fa[i] = i, cnt[i] = 1;
    for (int i = 1, u, v; i <= m; ++i) {cin >> u >> v; unit(u, v); degree[u]++; degree[v]++;}

    for (int i = 1; i <= n; ++i) scc[find(i)].push_back(i);

    bool flag;
    int ans = 0;
    for (int i = 1, len; i < MAX; ++i) {
        len = scc[i].size(); if (len == 0)  continue;
        flag = true;
        for (int j = 0; j < len; ++j) if (degree[scc[i][j]] != 2) {flag = false; break;}
        ans += flag;
    }

    cout << ans << endl;
}
