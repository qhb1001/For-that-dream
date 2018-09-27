#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int weight[12], w, ans[1005], k;
int dif;
bool dfs(int cnt, int last, bool flag) {
    if (cnt == k + 1)   return true;
    for (int i = 1; i <= w; ++i) if (last != weight[i]) {
        if (flag && dif + weight[i] > 0)    {ans[cnt] = weight[i]; dif += weight[i]; if (dfs(cnt + 1, weight[i], !flag)) return true; dif -= weight[i]; }
        else if (!flag && dif - weight[i] < 0) {ans[cnt] = weight[i]; dif -= weight[i]; if (dfs(cnt + 1, weight[i], !flag)) return true; dif += weight[i]; }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string in; cin >> in >> k;
    for (int i = 0; i < 10; ++i) if (in[i] == '1') weight[++w] = i + 1;

    if (dfs(1, -1, 1))  {cout << "YES\n"; for (int i = 1; i <= k; ++i) cout << ans[i] << ' '; cout << endl;}
    else cout << "NO\n";
}