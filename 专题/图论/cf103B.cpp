#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 105;
vector<int>G[MAX];
int fa[MAX], cnt[MAX];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
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
    int n, m; cin >> n >> m;
    if (n != m) {cout << "NO\n"; return 0;}

    for (int i = 1; i <= n; ++i)    fa[i] = i, cnt[i] = 1;

    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        unit(u, v);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)    if (fa[i] == i) ++ans;
    if (ans != 1)   cout << "NO\n";
    else cout << "FHTAGN!\n";
}  