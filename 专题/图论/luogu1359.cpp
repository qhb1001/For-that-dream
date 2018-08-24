#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int MAX = 210;
int G[MAX][MAX], d[MAX], n;
void dijkstra() {
    priority_queue<pair<int, int> >q;
    q.push(make_pair(0, 1));
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[1] = 0;
    pair<int, int> now;
    int u;
    while (q.empty() == 0) {
        now = q.top(); q.pop();
        u = now.second;
        if (d[u] < now.first)  continue;
        for (int v = u + 1; v <= n; ++v) {
            if (d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                q.push(make_pair(d[v], v));
            }
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%d", &G[i][j]);
        }
    }
    dijkstra();
    printf("%d\n", d[n]);
}