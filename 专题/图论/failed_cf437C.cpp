#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
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
int deal() {
    int Min = 1<<30, now, idx;

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        now = 0;
        for (int j = head[i]; j; j = e[j].nex)  if (!vis[e[j].to])    now += val[e[j].to];
        if (Min > now) {Min = now; idx = i;}
        else if (Min == now && val[i] > val[idx]) idx = i;
    }
    vis[idx] = 1;
    return Min;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= n; ++i)    cin >> val[i];
    while (m--) {
        cin >> u >> v;
        add(u, v); add(v, u);
    }


    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        int t = deal();
        cout << t << endl;
        ans += t;
    }
    cout << ans << endl;
}