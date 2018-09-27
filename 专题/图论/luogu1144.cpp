#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1e6 + 5;
const int MOD = 1e5 + 3;
vector<int>G[MAX];
int d[MAX], ans[MAX], n, m;
void input() {
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}
void solve() {
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[1] = 0;
    ans[1] = 1;
    queue<pair<int, int> >q;
    q.push(make_pair(0, 1));
    pair<int, int> now;
    int len, u, v;
    while (!q.empty()) {
        now = q.front(); q.pop();

        if (d[now.second] < now.first)  continue;
        u = now.second;
        len = G[u].size();
        for (int i = 0; i < len; ++i) {
            v = G[u][i];
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                ans[v] = ans[u];
                q.push(make_pair(d[v], v));
            } else if (d[v] == d[u] + 1) ans[v] = (ans[v] + ans[u]) % MOD;
        }
    }
}
int main() {
    input();
    solve();
    for (int i = 1; i <= n; ++i) printf("%d\n", (ans[i] + MOD) % MOD);
}