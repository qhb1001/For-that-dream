#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int n, m, ans;
vector<int>G[MAX];
bool vis[MAX];
void dfs(int u, int tail) {
    vis[u] = true;
    int cnt = G[u].size();
    ans = max(ans, cnt * tail);
    for (int v : G[u]) if (v > u) dfs(v, tail + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int l, r;
    while (m--) {
        cin >> l >> r;
        G[l].push_back(r);
        G[r].push_back(l);
    }

    for (int i = 1; i <= n; ++i) if (!vis[i])   dfs(i, 1);

    cout << ans << endl;
}