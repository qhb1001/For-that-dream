#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdio>
const int MAX = 1e4;
using namespace std;
int head[MAX], cnt, level[MAX], n, k, s, t;
struct Edge {
    int to, nex, flow;
    Edge(){}
    Edge(int a, int b, int c): to(a), nex(b), flow(c) {}
}e[MAX*222];
void add(int u, int v, int flow) {
    e[++cnt] = Edge (v, head[u], flow);
    head[u] = cnt;
    e[++cnt] = Edge (u, head[v], 0);
    head[v] = cnt;
}
void init() {
    cnt = -1; memset(head, -1, sizeof(head));
}
bool bfs() {
    queue<int>q;
    memset(level, 0, sizeof(level));
    level[s] = 1;
    q.push(s); int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i = head[u]; i != -1; i = e[i].nex) {
            v = e[i].to;
            if (e[i].flow > 0 && !level[v]) {
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
        if (level[v] == level[u] + 1 && e[i].flow > 0) {
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

vector<int>ans[MAX];
int main() { 
    // freopen("input.txt", "r", stdin);

    int sum = 0;
    init(); scanf("%d%d", &k, &n); s = 0; t = n + k + 1;
    for (int i = 1, tt; i <= k; ++i) {
        scanf("%d", &tt);
        add(n + i, t, tt);
        sum += tt;
    }
    for (int i = 1, len, tt; i <= n; ++i) {
        scanf("%d", &len);
        for (int j = 1; j <= len; ++j) {
            scanf("%d", &tt);
            add(i, tt + n, 1);
        }
        add(s, i, 1);
    }

    int flow = 0;
    while (bfs()) flow += dfs(s, 1<<30);

    if (flow != sum) {
        puts("No Solution!");
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; j != -1; j = e[j].nex) if (e[j].flow == 0 && e[j].to > n) {
            ans[e[j].to - n].push_back(i);
            break;
        }
    }

    for (int i = 1; i <= k; ++i) {
        printf("%d:", i);
        int len = ans[i].size();
        for (int j = 0; j < len; ++j) printf(" %d", ans[i][j]);
        printf("\n"); 
    }
}