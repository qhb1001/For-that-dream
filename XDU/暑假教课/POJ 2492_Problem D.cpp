#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e3 + 5;
int fa[MAX * 2], cnt[MAX * 2], n, m;
void init() {
    for (int i = 1; i <= n * 2; ++i) {
        fa[i] = i;
        cnt[i] = 1;
    }
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
int main() {
    int T, kase = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        init();
        int u, v;
        bool flag = false;
        while (m--) {
            scanf("%d%d", &u, &v);
            if (flag || find(u) == find(v)) {
                flag = true;
                continue;
            }
            unit(u, v + n);
            unit(v, u + n);
        }

        printf("Scenario #%d:\n", kase++);
        if (flag) {
            printf("Suspicious bugs found!\n\n");
        } else {
            printf("No suspicious bugs found!\n\n");
        }
    }
}