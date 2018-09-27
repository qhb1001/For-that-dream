#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int ans[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, cnt = 1; cin >> n;
        for (int i = 1; i <= n; i += 2) {
            ans[i] = cnt++;
        }
        for (int i = 2; i <= n; i += 2) ans[i] = cnt++;

        cout << ans[1];
        for (int i = 2; i <= n; ++i) cout << ' ' << ans[i];
        cout << endl;
    }
}