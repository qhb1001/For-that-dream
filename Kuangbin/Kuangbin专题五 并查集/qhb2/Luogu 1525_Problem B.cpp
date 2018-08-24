#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
const int MAX = 2e4 + 5;
int fa[MAX * 2], cnt[MAX * 2];
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
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}

struct Node {
    int u, v, val;
}relation[100005];
bool cmp(Node a, Node b) {
    return a.val > b.val;
}
int main() {
    scanf("%d%d", &n, &m);
    init();

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &relation[i].u, &relation[i].v, &relation[i].val);
    }

    sort(relation + 1, relation + 1 + m, cmp);

    int u, v, val;
    for (int i = 1; i <= m; ++i) {
        u = relation[i].u;
        v = relation[i].v;
        val = relation[i].val;

        if (find(u) == find(v)) {
            printf("%d", val);
            return 0;
        } else {
            unit(v, u + n);
            unit(u, v + n);
        }
    }

    printf("0");
}