#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 1e5 + 5;
int fa[MAX], cnt[MAX], a[MAX], ans, n, sccCnt;
int find(int x) {
    return fa[x] == x? x : fa[x] = find(fa[x]);
}
void unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return ;
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}
void output() {
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';
}
vector<int>scc[MAX];
int mp[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) fa[i] = i, cnt[i] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        unit(i, a[i]);
    }

    for (int i = 1; i <= n; ++i) if (fa[i] == i) mp[i] = ++sccCnt;
    for (int i = 1; i <= n; ++i) scc[mp[find(i)]].push_back(i);

    int root = -1;
    for (int i = 1; i <= sccCnt; ++i) {
        for (int u : scc[i]) if (a[u] == u) root = u;
    }

    if (root == -1) {
        ans = sccCnt;
        int temp = -1;
        for (int u : scc[1]) {
            if (a[u] == u) temp = u;
        }
        if (temp == -1) root = scc[1][0];

        for (int i = 2; i <= sccCnt; ++i) {
            temp = -1;
            for (int v : scc[i]) {
                if (a[v] == v) temp = v;
            }
            if (temp == -1) a[scc[i][0]] = root;
            else a[temp] = root;
        }
    } else {
        ans = sccCnt - 1;
        int temp;
        for (int i = 1; i <= sccCnt; ++i) {
            temp = -1;
            for (int v : scc[i]) {
                if (a[v] == v) temp = v;
            }
            if (temp == -1) a[scc[i][0]] = root;
            else a[temp] = root;
        }
    }

    output();
}