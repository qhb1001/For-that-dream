#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
bool vis[20];
int len, a[20], ans;
bool check() {
    for (int i = 1; i < len; ++i) if (a[i] == a[i + 1] - 1) return false;
    if (a[len] == len - 2)  return false;
    return true;
}
void dfs(int idx) {
    if (idx == len + 1) {
        if (check()) {
            ++ans;
            for (int i = 1; i <= len; ++i)  cout << a[i] << ' ';
            cout << endl;
        }
        return ;
    }
    for (int i = 0; i < len - 1; ++i) {
        if (!vis[i] && (a[idx - 1] + 1) % len != i) {
            vis[i] = 1;
            a[idx] = i;
            dfs(idx + 1);
            vis[i] = 0;
        }
    }
}
int main() {
    for (int i = 1; i <= 10; ++i) {
        memset(vis, 0, sizeof(vis));
        len = i;
        ans = 0;
        a[1] = len - 1;
        vis[len - 1] = 1;
        dfs(2);
        cout << ans << endl;
    }
}
