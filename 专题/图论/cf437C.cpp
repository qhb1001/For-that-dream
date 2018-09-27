#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1e3 + 5;
int n, m, head[MAX], cnt, val[MAX];
bool vis[MAX];
struct Edge {
    int to, nex;
}e[MAX<<2];
inline void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
pair<int, int> a[MAX];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {cin >> val[i]; a[i] = make_pair(val[i], i);}
    sort(a + 1, a + 1 + n, cmp);
    while (m--) {
        int u, v; cin >> u >> v;
        add(u, v); add(v, u);
    }

    long long ans_ = 0;

    for (int i = 1; i < n; ++i) {
        int u = a[i].second;
        for (int j = head[u]; j; j = e[j].nex) {
            if (!vis[e[j].to])  ans_ += val[e[j].to];
        }
        vis[u] = 1;
    }

    cout << ans_ << endl;
}