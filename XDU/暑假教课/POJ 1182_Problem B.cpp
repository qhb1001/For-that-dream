#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 5e4 + 5;
int fa[MAX * 3], cnt[MAX * 3];
int n, m;
void init() {
    for (int i = 1; i <= 3 * n; ++i) {
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
    if (u == v) return ;
    if (cnt[u] < cnt[v])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    int u, v, type;
    int ans = 0;
    while (m--) {
        scanf("%d%d%d", &type, &u, &v);
        if (u > n || v > n) {
            ++ans;
            continue;
        }

        if (type == 2 && u == v) {
            ++ans;
            continue;
        }

        if (type == 1) {
            // u eats v
            if (find(u) == find(v + n) || find(u + n) == find(v + 2 * n) || find(u + 2 * n) == find(v)) {
                ++ans;
                continue;
            }
            // v eats u
            if (find(v) == find(u + n) || find(v + n) == find(u + 2 * n) || find(v + 2 * n) == find(u)) {
                ++ans;
                continue;
            }

            unit(u, v);
            unit(u + n, v + n);
            unit(u + 2 * n, v + 2 * n);
        } else {
            // u is same with v
            if (find(u) == find(v) || find(u + n) == find(v + n) || find(u + 2 * n) == find(v + 2 * n)) {
                ++ans;
                continue;
            }

            //v eats u
            if (find(v) == find(u + n) || find(v + n) == find(u + 2 * n) || find(v + 2 * n) == find(u)) {
                ++ans;
                continue;
            }

            unit(u, v + n); unit(u + n, v + 2 * n); unit(u + 2 * n, v);
        }
    }

    printf("%d\n", ans);
}