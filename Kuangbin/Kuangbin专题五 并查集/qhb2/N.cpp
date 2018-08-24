#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int fa[MAX], cnt[MAX];
void init() {
    for (int i = 0; i < MAX; ++i)
        fa[i] = i, cnt[i] = 1;
}
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (cnt[u] < cnt[v])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}

bool vis[MAX];
int main() {
    // freopen("input.txt", "r", stdin);

    int u, v, kase = 1;
    while (scanf("%d%d", &u, &v) && u != -1) {
        init();
        unit(u, v);
        memset(vis, 0, sizeof(vis));
        vis[u] = 1;
        vis[v] = 1;
        int maxn = max(u, v);

        bool flag = true;
        while (scanf("%d%d", &u, &v) && u) {
            vis[u] = vis[v] = 1;
            maxn = max(maxn, max(u, v));
            if (!flag)  continue;

            if (find(u) == find(v)) {
                flag = false;
            }

            unit(u, v);
        } 

        if (!flag) {
            cout << "Case " << kase++ << " is a not tree.\n";
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= maxn; ++i) {
            if (vis[i] && fa[i] == i) ++cnt;
        }
        
        if (cnt != 1) {
            printf("Case 1 is a tree.");
            continue;
        }

        cout << "Case " << kase++ << " is a tree.\n";
    }
}