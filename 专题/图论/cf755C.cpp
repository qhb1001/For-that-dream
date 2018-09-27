#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
int n, fa[MAX], cnt[MAX];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return ;
    if (cnt[u] < cnt[v])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)    fa[i] = i, cnt[i] = 1;

    for (int i = 1, t; i <= n; ++i) {
        cin >> t;
        unit(i, t);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) if (fa[i] == i)    ++ans;
    cout << ans << endl;
}