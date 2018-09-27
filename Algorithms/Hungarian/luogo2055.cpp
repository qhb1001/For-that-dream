#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 55;
int isStu[MAX], isBack[MAX], vis[MAX*MAX], match[MAX*MAX], head[MAX], cnt, n, m;
struct Edge {
    int to, nex;
}e[MAX*MAX];
void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;   
}
bool dfs(int u) {
    vis[u] = 1;
    int v;
    for (int i= head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (match[v] == -1 || (!vis[match[v]] && dfs(match[v]))) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}
int hungry() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; ++i) if (match[i] == -1) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ++ans;
    }
    return ans;
}
void init() {
    memset(head, 0, sizeof(head));
    cnt = 0;
    m = 0;
}
int main() {
    int t, T; scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &isStu[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &isBack[i]);
        for (int i = 1; i <= n; ++i)    if (isStu[i] && !isBack[i])  add(i, i + MAX);

        for (int i = 1; i <= n; ++i) {
            if (!isStu[i]) ++m;
            else if (isStu[i] && !isBack[i]) ++m;
        }
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
            scanf("%d", &t); if (!t)    continue;
            if (isStu[i] && isBack[i])  continue;
            if (isStu[j])  add(i, j + MAX);
        }

        if (m == hungry()) printf("^_^\n");
        else printf("T_T\n");
    }
}