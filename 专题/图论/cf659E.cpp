#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int head[MAX], cnt1, low[MAX], num[MAX], cnt2, s[MAX], top, belong[MAX];
bool flag = false;
struct Edge {
    int to, nex;
}e[MAX<<2];
inline void add(int u, int v) {
    e[++cnt1] = (Edge) {v, head[u]};
    head[u] = cnt1;
}
void trajan(int u, int fa) {
    num[u] = low[u] = ++cnt2;
    s[++top] = u;
    for (int i = head[u], v; i; i = e[i].nex) {
        v = e[i].to; if (v == fa)   continue;
        if (!num[v]) {
            trajan(v, u);
            low[u] = min(low[u], low[v]);
        } else  if (!belong[v]) low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        int x, cnt = 0;
        while (true) {
            x = s[top--];
            ++cnt;
            if (x == u) break;
        }
        if (cnt != 1)   flag = true;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {cin >> u >> v; add(u, v); add(v, u);}

    int ans = 0;
    for (int i = 1; i <= n; ++i) if (!num[i]) {flag = false; trajan(i, -1); ans += !flag;}

    cout << ans << endl;
    
}