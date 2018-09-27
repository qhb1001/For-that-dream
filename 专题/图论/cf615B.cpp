#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int dp[MAX];
vector<int>G[MAX];
int dfs(int u) {
    if (dp[u])  return dp[u];
    for (int v : G[u]) if (v < u) dp[u] = max(dp[u], dfs(v));
    return ++dp[u];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, l, r;  cin >> n >> m;
    while (m--) {
        cin >> l >> r;
        G[l].push_back(r);
        G[r].push_back(l);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, (long long)G[i].size() * dfs(i));
    cout << ans << endl;
}