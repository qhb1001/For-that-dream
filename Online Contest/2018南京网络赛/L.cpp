#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
const ll INF = 1e18;
ll dp[MAX][11];
int n, m, k, head[MAX], cnt;
struct Edge {
    int to, nex, cost;
}e[MAX<<1];

struct Node{
    int u,tt;ll sum;
    bool operator<(const Node& b)const{
        return sum>b.sum;
    }
    Node(int a=0,int b=0,ll c=0):u(a),tt(b),sum(c){}
}now,nex;

void add(int u, int v, int c) {
    e[++cnt] = (Edge) {v, head[u], c};
    head[u] = cnt;
}

void init() {
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= k; ++j)   dp[i][j] = INF;
    cnt = 0;
}
void input() {
    int u, v, c;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c); add(u, v, c);
    }
}
void solve() {
    dp[1][0] = 0;
    priority_queue<Node >q;
    now.u=1;now.tt=0;now.sum=0;
    q.push(now);
    int u, v, tt;
    ll t;
    while (!q.empty()) {
        now = q.top(); q.pop(); u = now.u; tt = now.tt;
        if(dp[u][tt]<now.sum) continue;
         for (int i = head[u]; i; i = e[i].nex) {
             v = e[i].to;
             if (tt == 0) {
                 if (dp[v][0] > dp[u][0] + e[i].cost) {
                    dp[v][0] = dp[u][0] + e[i].cost;
                    q.push(Node(v,0,dp[v][0]));
                 }
                 if (k >= 1 && dp[v][1] > dp[u][0]) {
                     dp[v][1] = dp[u][0];
                     q.push(Node(v,1,dp[v][1]));
                 }
             } else {
                 t = min(dp[u][tt] + e[i].cost, dp[u][tt - 1]);
                 if (dp[v][tt] > t) {
                     dp[v][tt] = t;
                     q.push(Node(v,tt,dp[v][tt]));
                 }
                 if (k >= tt + 1 && dp[v][tt + 1] > dp[u][tt]) {
                     dp[v][tt + 1] = dp[u][tt];
                     q.push(Node(v,tt+1,dp[v][tt+1]));
                 }
             }
         }
    }
}
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        init();
        input();

        solve();
        ll ans = INF;
        for (int i = 0; i <= k; ++i)    ans = min(ans, dp[n][i]);
        printf("%lld\n", ans);
    }

}
