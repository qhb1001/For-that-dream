#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 2e5 + 5;
vector<int>G[MAX];
int num[MAX], idx[MAX], cnt, a[MAX];
int dfs(int u) {
    num[u] = 1; a[++cnt] = u; idx[u] = cnt;
    for (int v : G[u]) num[u] += dfs(v);
    return num[u];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q, l, r; cin >> n >> q;
    for (int u = 2, v; u <= n; ++u) {
        cin >> v;
        G[v].push_back(u);
    }

    dfs(1);
    while (q--) {
        cin >> l >> r;
        if (r > num[l]) {cout << -1 << '\n';}
        else {cout << a[idx[l] + r - 1] << '\n';}
    }
}