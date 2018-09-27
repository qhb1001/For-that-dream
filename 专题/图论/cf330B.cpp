#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e3 + 5;
bool vis[MAX];
int main() {
    int n, m, u, v;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        vis[u] = vis[v] = 1;
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        cout << n - 1 << endl;
        for (int j = 1; j <= n; ++j) if (j != i) cout << i << ' ' << j << '\n';
        return 0;
    }
    
}