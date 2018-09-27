#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define INF 0x3f3f3f3f
#define P pair<int, int>
using namespace std;
const int MAX = 205;
int head[MAX], cnt, dis[MAX], h[MAX], n, m, s, t, pre[MAX];
struct Edge {
    int from, to, nex, flow, cost;
    Edge(){}
    Edge(int a, int b, int c, int d, int e): from(a), to(b), nex(c), flow(d), cost(e) {}
}e[MAX<<6];
inline void add(int u, int v, int flow, int cost) {
    e[++cnt] = Edge(u, v, head[u], flow, cost);
    head[u] = cnt;
    e[++cnt] = Edge(v, u, head[v], 0, -cost);
    head[v] = cnt;
}
int flow, cost;
void minCostFlow() {
    int u, v; P now; pre[s] = -1;
    while (true) {
        memset(dis, INF, sizeof(dis));
        priority_queue<P, vector<P>, greater<P> >q;
        q.push(P(0, s));
        dis[s] = 0;
        while (!q.empty()) {
            now = q.top(); q.pop();
            u = now.second;
            if (dis[u] < now.first) continue;
            for (int i = head[u]; i != -1; i = e[i].nex) {
                v = e[i].to;
                if (e[i].flow > 0 && dis[v] > dis[u] + e[i].cost + h[u] - h[v]) {
                    dis[v] = dis[u] + e[i].cost + h[u] - h[v];
                    q.push(P(dis[v], v));
                    pre[v] = i;
                }
            }
        }
        if (dis[t] == INF)  break;
        for (int i = 0; i <= n + 1; ++i)    h[i] += dis[i];

        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[e[i].from]) Min = min(Min, e[i].flow);
        for (int i = pre[t]; i != -1; i = pre[e[i].from]) {e[i].flow -= Min; e[i^1].flow += Min;}
        flow += Min;
        cost += Min * h[t];
    }
}
int a[MAX];
void init() {
    cnt = -1; memset(head, -1, sizeof(head));
}
int main() {
    init();
    scanf("%d", &n);
    s = 0; t = n + 1;
    int sum = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += a[i];
    sum /= n;
    for (int i = 1; i <= n; ++i) {
        if (a[i] - sum > 0)    add(s, i, a[i] - sum, 0);
        if (a[i] - sum < 0)    add(i, t, sum - a[i], 0);
        if (i != n) add(i, i + 1, INF, 1);
        else add(i, 1, INF, 1);

        if (i != 1) add(i, i - 1, INF, 1);
        else add(i, n, INF, 1);
    }

    minCostFlow();
    printf("%d\n", cost);

}