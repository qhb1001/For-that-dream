#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
typedef long long ll;
vector<int>G[MAX];
vector<int>scc[MAX];
int low[MAX], num[MAX], cnt, sccCnt, belong[MAX], n, m, cost[MAX], s[MAX], top;
void trajan(int u) {
    num[u] = low[u] = ++cnt;
    s[++top] = u;
    int v, len = G[u].size(); 
    for (int i = 0; i < len; ++i) {
        v = G[u][i]; 
        if (!num[v]) {
            trajan(v);
            low[u] = min(low[u], low[v]);
        } else if (!belong[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u] == low[u]) {
        int x; ++sccCnt;
        while (true) {
            x = s[top--];
            belong[x] = sccCnt;
            scc[sccCnt].push_back(x);
            if (x == u) break;
        }
    }
}
int times[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n; for (int i = 1; i <= n; ++i)  cin >> cost[i];
    cin >> m; for (int i = 1, u, v; i <= m; ++i) {cin >> u >> v; G[u].push_back(v);}
    for (int i = 1; i <= n; ++i) if (!num[i])   trajan(i);

    long long ans1 = 0, ans2 = 1;
    for (int i = 1; i <= sccCnt; ++i) {
        int Min = 1<<30, len = scc[i].size(), u;
        for (int j = 0; j < len; ++j) {
            u = scc[i][j];
            if (Min > cost[u])  Min = cost[u], times[i] = 1;
            else if (Min == cost[u])    times[i]++;
        }
        ans1 += Min;
    }

    for (int i = 1; i <= sccCnt; ++i) ans2 = ans2 * times[i] % MOD;
    cout << ans1 << ' ' << (ans2 + MOD) % MOD << endl;
}