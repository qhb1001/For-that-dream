#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 210;
int head[MAX], cnt, match[MAX<<2], vis[MAX<<2], n;
struct Edge {
    int to, nex;
}e[MAX*MAX];
void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
void init() {
    memset(match, -1, sizeof(match));
    memset(head, 0, sizeof(head));
    cnt = 0;
}
bool hungury(int u) {
    vis[u] = 1;
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (match[v] == -1 || (!vis[match[v]]&&hungury(match[v]))) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
int solve() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (match[i] == -1) {
        memset(vis, 0, sizeof(vis));
        if (hungury(i)) ++ans;
    }  
    return ans;
}
bool isStu[MAX], isStay[MAX];
int main() { 
    int T;
    cin >> T;
    while (T--) {
        init();
        cin >> n;
        int t = 0;
        for (int i = 1; i <= n; ++i)    cin >> isStu[i];
        
        for (int i = 1; i <= n; ++i)    {cin >> isStay[i]; if (isStu[i] && isStay[i]) add(i, i + MAX);}

        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {cin >> t; if (isStu[i] && !isStay[i])    continue; if (t && isStu[j]) add(i, j + MAX);}

        t = 0;
        for (int i = 1; i <= n; ++i) if (!isStu[i] || (isStu[i] && isStay[i])) ++t;

        int t1 = solve();

        if (t1 == t)   cout << "^_^\n";
        else    cout << "T_T\n";
    }
}