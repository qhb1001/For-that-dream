#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
bool vis[105];
void input() {
    cin >> n >> m;
    while (n--) {
        int l, r;
        cin >> l >> r;
        for (int i = l; i <= r; ++i)    vis[i] = 1;
    }
}
void output() {
    int ans = 0;
    for (int i = 1; i <= m; ++i) if (vis[i] == 0)   ++ans;
    cout << ans << endl;
    for (int i = 1; i <= m; ++i) if (vis[i] == 0)   cout << i << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    output();
}