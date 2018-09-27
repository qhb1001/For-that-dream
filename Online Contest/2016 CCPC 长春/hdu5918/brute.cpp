#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int a[20], b[20], n, m, p;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.b", "w", stdout);
    cin >> n >> n >> m >> p;
    for (int i = 1; i <= n; ++i)    cin >> a[i];
    for (int j = 1; j <= m; ++j)    cin >> b[j];

    cout << "Case #1: ";
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i + (m - 1) * p > n)    break;
        bool flag = true;
        for (int j = 0; j < m; ++j) if (a[i + j * p] != b[j + 1])   {flag = false; break;}
        ans += flag;
    }
    cout << ans << endl;
}