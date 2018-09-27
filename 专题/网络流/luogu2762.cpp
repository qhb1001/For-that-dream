#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 155;
struct Edge {
    int from, to, nex, flow;
}E[MAX*MAX], e[MAX*MAX];
int head[MAX], level[MAX], cnt, n, m, s, t;
vector<int>concerned;
void init() {
    memset(head, -1, sizeof(head));
    cnt = -1;
}
inline void add(int u, int v, int flow) {
    E[++cnt] = (Edge) {u, v, head[u], flow};
    head[u] = cnt;
    if (u > n && v == t) concerned.push_back(cnt);
    E[++cnt] = (Edge) {v, u, head[v], 0};
    head[v] = cnt;
}
bool bfs() {
    queue<int>q;
    q.push(s);
    memset(level, 0, sizeof(level));
    level[s] = 1;
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

    int v, flow = 0, now;
    for (int i = head[u]; i != -1; i = e[i].nex) {
        v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].flow) {
            now = dfs(v, min(Min, e[i].flow));

            flow += now;
            e[i].flow -= now;
            e[i^1].flow += now;
            Min -= now;
        }
    }
    if (!flow)   level[u] = 0;
    return flow;
}
int dinic(int idx) {
    memcpy(e, E, sizeof(e));
    if (idx != -1) e[idx].flow = 0;

    int ans = 0;
    while (bfs()) ans += dfs(s, 1<<30);
    return ans;
}

bool vis[MAX];
vector<int>a[MAX];
int sum;
void input() {
    scanf("%d%d", &n, &m);
    s = 0; t = n + m + 1;
    init();
    for(int i=1; i<=n; i++)
    {
        int x;
        char c;
        scanf("%d",&x);
        sum += x;
        add(s,i,x);
        while(1)
        {
            scanf("%d%c",&x,&c);
            a[i].push_back(x + n);
            add(i,x + n,1<<30);
            if(c=='\n'||c=='\r')break;
        }
    }

    for (int i = 1, w; i <= m; ++i) {
        scanf("%d", &w);
        add(i + n, t, w);
    }
}
int main() {
    input();

    int flow = dinic(-1), ans = sum - flow;
    for (int i = 0, idx, len = concerned.size(); i < len; ++i) {
        idx = concerned[i];
        if (E[idx].flow + dinic(idx) == flow) {
            flow -= E[idx].flow;
            E[idx].flow = 0;
            vis[E[idx].from] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (int j = 0, len = a[i].size(); j < len; ++j) {
            if (!vis[a[i][j]]) {flag = false; break;}
        }
        if (flag)   printf("%d ", i);
    }
    puts("");

    for (int i = n + 1; i <= n + m; ++i) if (vis[i]) printf("%d ", i - n);
    printf("\n%d\n", ans);
}