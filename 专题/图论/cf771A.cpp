#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 15e4 + 5;
int n, m, fa[MAX], cnt[MAX];
vector<int>G[MAX];
int find(int x) {
    if (x == fa[x]) return x;
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
    for (int i = 1; i <= n; ++i) fa[i] = i, cnt[i] = 1;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        G[u].push_back(v); 
        G[v].push_back(u);
        unit(u, v);
    }

    for (int i = 1; i <= n; ++i) if (cnt[find(i)] - 1 != G[i].size())   {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}