#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
const int MAX = 105;
const int INF = 1<<30;
typedef long long ll;
using namespace std;
int head[MAX], cnt, day, K, m, n, d[MAX], t1, t2, w[MAX][MAX];
ll dp[MAX];
bool ok[MAX][MAX], vis[MAX];
struct Edge {
    int to, nex, cost;
}e[MAX*MAX*2];
void add(int u, int v, int c) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].cost = c;
    head[u] = cnt;
}
void input() {
    scanf("%d%d%d%d", &day, &n, &K, &m);
    int u, v, c, l, r;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
        add(v, u, c);
    }
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d%d", &u, &l, &r);
        for (int i = l; i <= r; ++i)    ok[u][i] = 1;
    }
}
bool inRange(int i) {
    for (int j = t1; j <= t2; ++j) if (ok[i][j])    return false;
    return true;
}
int spfa() {
    if (inRange(1) == 0)    return INF;
    for (int i = 1; i <= n; ++i)    d[i] = INF, vis[i] = 0;
    d[1] = 0;
    queue<int>q; q.push(1);
    vis[1] = 1;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop(); vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to; if (!inRange(v))   continue;
            if (d[v] > d[u] + e[i].cost) {
                d[v] = d[u] + e[i].cost;
                if (!vis[v]) {
                    vis[v] = 1; q.push(v);
                }
            }
        }
    }
    return d[n];
}

int main() {
    input();
    for (int i = 1; i <= day; ++i) for (int j = i; j <= day; ++j)   {
        t1 = i; t2 = j;
        w[i][j] = spfa();
    }


    for (int i = 1; i <= day; ++i) {
        dp[i] = (ll)i * w[1][i];
        for (int j = 1; j < i; ++j) 
            dp[i] = min(dp[i], dp[j] + K + (ll)w[j + 1][i] * (i - j));
    }

    printf("%lld\n", dp[day]);
}