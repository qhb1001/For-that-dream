#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int MAX = 5e3 + 5;
const int MAXM = 5e4 + 5;
int head[MAX], cnt, dis[MAX], n, m, pre[MAX], flow, cost;
struct Edge {
    int from, to, nex, flow, cost;
    Edge(){}
    Edge(int e, int a, int b, int c, int d): from(e), to(a), nex(b), flow(c), cost(d) {}
}e[MAXM<<2];
inline void add(int u, int v, int flow, int cost) {
    e[++cnt] = Edge(u, v, head[u], flow, cost);
    head[u] = cnt;
    e[++cnt] = Edge(v, u, head[v], 0, -cost);
    head[v] = cnt;
}
void init() {
    cnt = -1;
    memset(head, -1, sizeof(head));
}
void minCostFlow(int s, int t) {
    while (true) {
        memset(dis, INF, sizeof(dis));
        dis[s] = 0;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 1, v; i <= n; ++i) {
                for (int j = head[i]; j != -1; j = e[j].nex) {
                    v = e[j].to;
                    if (e[j].flow > 0 && dis[v] > dis[i] + e[j].cost) {
                        dis[v] = dis[i] + e[j].cost;
                        pre[v] = j;
                        flag = true;
                    }
                }
            }
        }
        if (dis[t] == INF)  break;
        
        int Min = 1<<30;
        for (int i = pre[t]; i; i = pre[e[i].from]) Min = min(Min, e[i].flow);
        for (int i = pre[t]; i; i = pre[e[i].from]) {
            e[i].flow -= Min;
            e[i^1].flow += Min;
        }
        flow += Min;
        cost += Min * dis[t];
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    
    init(); int s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1, u, v, flow, cost; i <= m; ++i) {
        scanf("%d%d%d%d", &u, &v, &flow, &cost);
        add(u, v, flow, cost);
    }

    minCostFlow(s, t);
    printf("%d %d\n", flow, cost);
}