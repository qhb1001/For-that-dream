#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 305;
int head[MAX], cnt, level[MAX], n, m, s, t, pre[MAX], nex[MAX];
struct Edge {
    int to, nex, flow;
}e[MAX*MAX];
inline void add(int u, int v, int c) {
    e[++cnt] = (Edge) {v, head[u], c};
    head[u] = cnt;
    e[++cnt] = (Edge) {u, head[v], 0};
    head[v] = cnt;
}
void init() {
    cnt = -1; memset(head, -1, sizeof(head));
    for (int i = 1; i <= n<<1; ++i) pre[i] = nex[i] = i;
}
bool bfs() {
    queue<int>q;
    memset(level ,0, sizeof(level));
    level[s] = 1;
    q.push(s);
    int v, u;
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

    int v, flow = 0, now;
    for (int i = head[u]; i != -1; i = e[i].nex) {
        v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].flow > 0) {
            now = dfs(v, min(Min, e[i].flow));

            if (now != 0 && u != s) pre[v] = u, nex[u] = v;
            flow += now;
            e[i].flow -= now;
            e[i^1].flow += now;
            Min -= now;
        }
    }

    if (!flow) level[u] = 0;
    return flow;
}

int main() {
    scanf("%d%d", &n, &m);
    s = 0; t = n*2 + 1; 
    int u, v, ans = 0; init();
    while (m--) {
        scanf("%d%d", &u, &v);
        add(u, v + n, 1);
    }

    for (int i = 1; i <= n; ++i) add(s, i, 1), add(i + n, t, 1);
    while (bfs()) ans += dfs(s, 1<<30);

    ans = n - ans;
    for (int i = 1; i <= n; ++i) if (pre[i] == i) {
        int x = i;
        printf("%d", x);
        x = nex[x];
        while (x != t) {
            if (x > n) x -= n;
            printf(" %d", x);
            x = nex[x];
        }
        printf("\n");
    }

    printf("%d\n", ans);
}
