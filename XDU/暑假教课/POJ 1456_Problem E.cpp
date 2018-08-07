#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
int fa[MAX];
void init() {
    for (int i = 0; i <= MAX; ++i) {
        fa[i] = i;
    }
}
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    fa[v] = u;
}

struct Node {
    int val, t;
    bool operator < (const Node b) const {
        return val > b.val;
    }
}good[MAX];
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &good[i].val, &good[i].t);
        }
        sort(good + 1, good + 1 + n);
        init();

        int ans = 0, t;
        for (int i = 1; i <= n; ++i) {
            t = find(good[i].t);
            if (t != 0) {
                unit(t - 1, t);
                ans += good[i].val;
            }
        }
        printf("%d\n", ans);
    }
}