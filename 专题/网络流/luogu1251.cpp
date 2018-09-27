#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define INF 0x3f3f3f3f
#define P pair<int, int>
using namespace std;
typedef long long ll;
const int MAX = 4e3 + 5;
const ll inf = 4557430888798830399;
struct Edge {
    int from, to, nex, flow, cost;
}e[MAX*MAX*2];
int head[MAX], cnt, n, m, s, t, pre[MAX], a[MAX];
inline void add(int u, int v, int flow, int cost) {
    e[++cnt] = (Edge) {u, v, head[u], flow, cost};
    head[u] = cnt;
    e[++cnt] = (Edge) {v, u, head[v], 0, -cost};
    head[v] = cnt;
}
ll flow, cost, h[MAX], dis[MAX];
void init() {
    cnt = -1; memset(head, -1, sizeof(head));
}
void minCostFlow() {
    pre[s] = -1;
    int u, v; P now;
    while (true) {
        memset(dis, 63, sizeof(dis));
        priority_queue<P, vector<P>, greater<P> >q;
        q.push(P(0, s));
        dis[s] = 0;
        while (!q.empty()) {
            now = q.top(); q.pop();
            if (dis[now.second] < now.first)    continue;

            u = now.second;
            for (int i = head[u]; i != -1; i = e[i].nex) {
                v = e[i].to;
                if (e[i].flow > 0 && dis[v] > e[i].cost + dis[u] + h[u] - h[v]) {
                    dis[v] = dis[u] + e[i].cost + h[u] - h[v];
                    q.push(P(dis[v], v));
                    pre[v] = i;
                }
            }
        }

        if (dis[t] == inf)  break;
        // cout << dis[t] << endl;
        for (int i = 0; i <= t; ++i) h[i] += dis[i];
        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[e[i].from]) Min = min(Min, e[i].flow);
        for (int i = pre[t]; i != -1; i = pre[e[i].from]) {
            e[i].flow -= Min; e[i^1].flow += Min;
        }
        flow += Min;
        cost += Min * h[t];
        // cout << flow << endl;
    }
}

int main() {
    scanf("%d", &n); s = 0; t = 2*n + 1; init();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        add(i, t, a[i], 0);
        add(s, i + n, a[i], 0);
    }
    int n1, n2, cost1, cost2, cost3;
    scanf("%d%d%d%d%d", &cost1, &n1, &cost2, &n2, &cost3);
    for (int i = 1; i <= n; ++i) {
        add(s, i, INF, cost1);
        if (i != n) add(i + n, i + 1 + n, INF, 0); //表示可以把今天多余的留给下一天
        if (i + n1 <= n)    add(i + n, i + n1, INF, cost2); //最多能给特定的天这么多干净餐巾
        if (i + n2 <= n)    add(i + n, i + n2, INF, cost3);
    }

    minCostFlow();
    printf("%lld\n", cost);
}