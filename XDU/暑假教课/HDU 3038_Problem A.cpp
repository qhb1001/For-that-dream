#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int n, m;
const int MAX = 2e5 + 5;
int fa[MAX], val[MAX];

void init() {
    for (int i = 0; i <= n; ++i) {
        fa[i] = i, val[i] = 0;
    }
}

int find(int u) {
    if (fa[u] == u) return u;
    int t = find(fa[u]);
    val[u] += val[fa[u]];
    return fa[u] = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int u, v, value;
    while (cin >> n >> m) {
        init();
        int ans = 0, l, r;
        for (int i = 1; i <= m; ++i) {
            cin >> l >> r >> value;
            --l;
            int u = find(l), v = find(r);
            if (u == v) {
                if (val[r] - val[l] != value)   ++ans;
            } else {
                fa[v] = u;
                val[v] = val[l] + value - val[r];
            }
        }
        cout << ans << '\n';
    }
}