#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include<queue>
const int MAX = 1e4 + 5;
const int MAXM = 1e5 + 5;
const int INF = 1<<30;
using namespace std;
int head[MAX], cnt, level[MAX], n, m, s, t;
struct Edge {
    int to, nex, flow;
}e[MAXM<<1];
void add(int u, int v, int c) {
    e[++cnt] = (Edge) {v, head[u], c};
    head[u] = cnt;
    e[++cnt] = (Edge) {u, head[v], 0};
    head[v] = cnt;
}
void init() {
    cnt = -1;
    memset(head, -1, sizeof(head));
}
bool bfs() {
    queue<int>q;
    memset(level, 0, sizeof(level));
    level[s] = 1;
    q.push(s);
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = head[u]; i != -1; i = e[i].nex) {
            v = e[i].to;
            if (!level[v] && e[i].flow > 0) {
                level[v] = level[u] + 1;
                q.push(v);
                if (v == t) return true;
            }
        }
    }

    return false;
}
int dfs(int u, int Min) {
    if (!Min || u == t) return Min;

    int v, ans = 0, plus;
    for (int i = head[u]; i != -1; i = e[i].nex) {
        v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].flow) {
            plus = dfs(v, min(Min, e[i].flow));

            ans += plus;
            e[i].flow -= plus;
            e[i^1].flow += plus;
            Min -= plus;
        }
    }
    if (!ans)   level[u] = 0;
    return ans;
}
int main() {
    // freopen("input.txt", "r", stdin);

    init();
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, c;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
    }
    int ans = 0;
    while (bfs()) ans += dfs(s, INF);
    printf("%d\n", ans);
}