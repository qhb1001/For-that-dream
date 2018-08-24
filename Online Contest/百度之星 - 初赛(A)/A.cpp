#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define IO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int a[1005];
int main() {
    // freopen("in", "r", stdin);
    IO;
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; ++i)    cin >> a[i];
        bool flag = false;
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    if (a[j] + a[k] > a[i]) {
                        flag = true;
                        cout << a[i] + a[j] + a[k] << '\n';
                        break;
                    }
                }
                if (flag)   break;
            }
            if (flag)   break;
        }

        if (!flag)  cout << -1 << '\n';
    }

}