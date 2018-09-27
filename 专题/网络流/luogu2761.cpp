#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define P pair<int, int>
#define INF 0x3f3f3f3f
using namespace std;
struct Node {
    int b1, b2, f1, f2, cost;
    Node(){}
    Node(int a, int b, int c, int d, int e): b1(a), b2(b), f1(c), f2(d), cost(e) {}
};
vector<Node>Patch;
int n, m, dis[2000005];
char a[210], b[210];
void dijkstra() {
    memset(dis, INF, sizeof(dis));
    dis[0] = 0;
    priority_queue<P, vector<P>, greater<P> >q;
    q.push(P(0, 0));
    P now;
    int u, v;
    while (!q.empty()) {
        now = q.top(); q.pop();
        u = now.second;
        if (dis[u] < now.first) continue;
        for (Node patch: Patch) {
            if ((u & patch.b1) != 0 || ((u & patch.b2) ^ patch.b2) != 0) continue;
            v = u | patch.f1;
            v &= patch.f2;
            if (dis[v] > dis[u] + patch.cost) {
                dis[v] = dis[u] + patch.cost;
                q.push(P(dis[v], v));
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int cost, b1 = 0, b2 = 0, f1 = 0, f2 = 0, len;
        scanf("%d %s %s", &cost, a, b);
        for (int j = 0; j < n; ++j) {
            if (a[j] == '+') b1 |= (1<<j);
            if (a[j] == '-') b2 |= (1<<j);
            if (b[j] == '-') f1 |= (1<<j);
            if (b[j] != '+') f2 |= (1<<j);
        }
        Patch.push_back(Node(b1, b2, f1, f2, cost));
    }

    dijkstra();
    if (dis[(1<<n) - 1] == INF) printf("0\n");
    else printf("%d\n", dis[(1<<n) - 1]);
}