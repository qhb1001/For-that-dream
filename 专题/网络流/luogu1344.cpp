#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
typedef long long ll;
#define INF 0x3f3f3f3f
#define P pair<int, int>
using namespace std;
const int MAX = 105;
struct Edge {
    int to, nex, flow;
}E[MAX*MAX*2], e[MAX*MAX*2];
int head[MAX], cnt, level[MAX], n, m, s, t;
inline void add(int u, int v, int flow) {
    E[++cnt] = (Edge) {v, head[u], flow};
    head[u] = cnt;
    E[++cnt] = (Edge) {u, head[v], 0};
    head[v] = cnt;
}
void init() {
    cnt = -1; memset(head, -1, sizeof(head));
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
ll dfs(int u, int Min) {
    if (!Min || u == t) return Min;

    int v;
    ll ans = 0, flow;
    for (int i = head[u]; i != -1; i = e[i].nex) {
        v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].flow > 0) {
            flow = dfs(v, min(Min, e[i].flow));

            ans += flow;
            e[i].flow -= flow;
            e[i^1].flow += flow;
            Min -= flow;
        }
    }
    if (!ans)   level[u] = 0;
    return ans;
}
ll Dinic(int idx) {
    memcpy(e, E, sizeof(E));

    if (idx != -1)  e[idx].flow = 0;
    ll ans = 0;
    while (bfs())   ans += dfs(s, INF);
    return ans;
}

vector<P> q;
bool cmp(P a, P b) {
    return a.first > b.first;
}
int main() {
    scanf("%d%d", &n, &m); s = 1; t = n; init();
    for (int i = 1, u, v, flow; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &flow);
        add(u, v, flow);
    } 

    for (int i = 0; i <= cnt; i += 2) q.push_back(P(E[i].flow, i));
    
    sort(q.begin(), q.end(), cmp);
    
    int ans = 0, len = q.size();
    ll flow = Dinic(-1), ans1 = flow, now;

    // cout << q[0].first << endl;
    for (int i = 0; i < len; ++i) {
        now = Dinic(q[i].second);
        if (now + E[q[i].second].flow == flow) {
            flow = now;
            E[q[i].second].flow = 0;
            ++ans;
        }
    }

    printf("%lld %d\n", ans1, ans);
}