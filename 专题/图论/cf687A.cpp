#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int color[MAX], head[MAX], cnt;
struct Edge {
    int to, nex;
}e[MAX<<1];
inline void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
bool dfs(int u, int now) {
    int v;
    color[u] = now;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!color[v] && !dfs(v, -now))  return false;
        else if (color[v] && color[v] == color[u])   return false;
    }
    return true;
}
vector<int>ans[2];
int main() {
    int n, m, u, v;
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> m;
    while (m--) {cin >> u >> v; add(u, v); add(v, u);}
    for (int i = 1; i <= n; ++i) if (!color[i] && !dfs(i, 1)) {
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 1; i <= n; ++i) if (color[i] == 1) ans[0].push_back(i); else ans[1].push_back(i);

    int len = ans[0].size();
    cout << len << '\n';
    for (int i = 0; i < len; ++i) cout << ans[0][i] << ' ';

    len = ans[1].size();
    cout << endl << len << '\n';
    for (int i = 0; i < len; ++i)   cout << ans[1][i] << ' ';
}