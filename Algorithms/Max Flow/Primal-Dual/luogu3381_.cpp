#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define P pair<int, int>
using namespace std;
const int MAX = 5e3 + 5;
const int MAXM = 5e4 + 5;
struct Edge {
    int from, to, nex, flow, cost;
    Edge(){}
    Edge(int a, int b, int c, int d, int e): from(a), to(b), nex(c), flow(d), cost(e) {}
}e[MAXM<<3];
int head[MAX], cnt, dis[MAX], n, m, s, t;
inline void add(int u, int v, int flow, int cost) {
    e[++cnt] = Edge(u, v, head[u], flow, cost);
    head[u] = cnt;
    e[++cnt] = Edge(v, u, head[v], 0, -cost);
    head[v] = cnt;
}
int flow, cost, h[MAX], pre[MAX];
void init() {
    cnt = -1;
    memset(head, -1, sizeof(head));
}
void minCostFlow() {
    pre[s] = -1;
    int u, v; P now;
    while (true) {
        memset(dis, INF, sizeof(dis));
        priority_queue<P, vector<P>, greater<P> >q;
        q.push(P(0, s));
        dis[s] = 0;
        while (!q.empty()) {
            now = q.top(); q.pop();
            if (dis[now.second] < now.first)    continue;

            u = now.second;
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
        for (int i = 1; i <= n; ++i)    h[i] += dis[i];

        int Min = INF;
        for (int i = pre[t]; i != -1; i = pre[e[i].from]) Min = min(Min, e[i].flow);
        for (int i = pre[t]; i != -1; i = pre[e[i].from]) {e[i].flow -= Min; e[i^1].flow += Min;}
        flow += Min;
        cost += Min * h[t];
    }

}
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;    c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}
int main() {
    init();
    // scanf("%d%d%d%d", &n, &m, &s, &t);
    n = read(); m = read(); s = read(); t = read();
    for (int i = 1, u, v, flow, cost; i <= m; ++i) {
        // scanf("%d%d%d%d", &u, &v, &flow, &cost);
        u = read(); v = read(); flow  = read(); cost  = read();
        add(u, v, flow, cost);
    }

    minCostFlow();
    printf("%d %d\n", flow, cost);
}