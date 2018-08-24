#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1005;
vector<int>G[MAX];
int n;
void input() {
    cin >> n;
    int t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        G[i].push_back(t);
    }
}

int vis[MAX], ans, cnt;
void dfs(int u) {
    vis[u] = cnt;

    int v = G[u][0];
    if (vis[v] == cnt) {
        ans = v;
        return ;
    }
    
    dfs(v);
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        ++cnt;
        dfs(i);
        cout << ans << ' ';
    }
    cout << endl;
}
int main() {
    input();
    solve();
}