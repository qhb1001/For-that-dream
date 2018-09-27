#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
vector<int>G[MAX];
int n, dp[MAX], ans;
void dfs(int u, int fa) {
    dp[u] = 1;

    for (int v : G[u]) if (v != fa) {
        dfs(v, u);
        if (!(dp[v]&1) && !((n - dp[v])&1))    ++ans;
        dp[u] += dp[v];
    } 

}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, -1);
    if (n&1)   ans = -1;
    cout << ans << endl;
}