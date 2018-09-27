#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
const ll mod = 1e9 + 7;
int head[MAX], cnt;
struct Edge {
    int to, nex, c;
}e[MAX<<1];
void add(int u, int v, int c) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].c = c;
    head[u] = cnt;
}
ll sum;
int n, dp[MAX];
int dfs1(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (v == fa)    continue;
        dp[u] += dfs1(v, u) + 1;   
    }
    return dp[u];
}
void dfs2(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (v == fa)    continue;
        sum += (1LL*(n - dp[v] - 1) * e[i].c * (dp[v] + 1))% mod;
        sum %= mod;
        dfs2(v, u);
        // cout << "here:" << sum  << ' ' << n << ' ' << dp[v] << ' ' << v << endl;
    }
}
ll fac[MAX];
void init() {
    memset(head, 0, sizeof(head));
    memset(dp, 0, sizeof(dp));
    cnt = 0;
    sum = 0;
}
int main() {
    fac[0] = 1;
    for (int i = 1; i < MAX; ++i) fac[i] = fac[i - 1] * i % mod;
    int u, v, c;
    while (scanf("%d", &n) != EOF) {
        init();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d%d", &u, &v, &c);
            add(u, v, c);
            add(v, u, c);
        }

        dfs1(1, -1);
        dfs2(1, -1);
        // for (int i = 1; i <= n; ++i)    cout << dp[i] << ' ';
        // cout << endl;
        ll ans = ((2 * fac[n-1] % mod) * sum % mod + mod) % mod;
        printf("%lld\n", ans);
    }

}
