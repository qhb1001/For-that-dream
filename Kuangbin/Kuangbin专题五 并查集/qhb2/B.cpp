#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 3e4 + 5;
int n, m, fa[MAX], cnt[MAX];
void init() {
    for (int i = 0; i < n; ++i) {
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
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    while (cin >> n >> m) {
        if (!n && !m)   break;
        init();
        while (m--) {
            cin >> k;
            k--;
            int u, v;
            cin >> u;
            while (k--) {
                cin >> v;
                unit(u, v);
            }
        }

        cout << cnt[fa[0]] << '\n';
    }
}