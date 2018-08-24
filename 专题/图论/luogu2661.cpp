#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e5 + 5;
int ans, head[MAX], cnt, in[MAX];
bool vis[MAX];
struct Edge {
    int to, nex;
}e[MAX];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}

void delete_(int u) {
    int v = e[head[u]].to;
    vis[u] = 1;
    if (in[v] == 1) delete_(v);
    else --in[v];
}

int fa[MAX], cnt_[MAX];
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
} 
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    if (cnt_[v] > cnt_[u])  swap(u, v);
    cnt_[u] += cnt_[v];
    fa[v] = u;
}
int main() {
    freopen("in", "r", stdin);
    ans = 1<<30;
    int n, v;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v);
        add(i, v);
        in[v] += 1;
    }

    for (int i = 1; i <= n; ++i) if (!in[i]) delete_(i);

    for (int i = 1; i <= n; ++i)    fa[i] = i, cnt_[i] = 1;
    for (int i = 1; i <= n; ++i) {
        v = e[head[i]].to;
        if (!vis[v] && !vis[i]) unit(i, v); 
    }

    for (int i = 1; i <= n; ++i)    if (!vis[i] && fa[i] == i)  ans = min(ans, cnt_[i]);
    printf("%d\n", ans);
}