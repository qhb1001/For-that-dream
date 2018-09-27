#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define P pair<int, int>
typedef long long ll;
const int MAX = 1e5 + 5;
vector<P>G[MAX];
int num[MAX], ans, a[MAX], n;
int dfs(int u, int fa) {
    num[u] = 1;
    int v;
    for (P now : G[u]) {
        v = now.first;
        if (v == fa)    continue;
        num[u] += dfs(v, u);
    }
    return num[u];
}
void solve(int u, int fa, ll Min, ll sum) {
    int v;
    if (a[u] < sum - Min) {ans += num[u]; return ;}
    for (P now : G[u]) {
        v = now.first;
        if (v == fa)    continue;
        solve(v, u, min(Min, sum + now.second), sum + now.second);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, fa, c; i < n; ++i) {
        cin >> fa >> c;
        G[fa].push_back(P(i + 1, c));
        G[1 + i].push_back(P(fa, c));
    }
    dfs(1, -1);

    solve(1, -1, 0, 0);
    cout << ans << endl;
}