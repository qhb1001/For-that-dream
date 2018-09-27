#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e4 + 5;
const int MOD = 1e9+7;
typedef long long ll;
int num[MAX], val[MAX], n, q;
ll dp[MAX];
vector<int>a;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> q;
        memset(dp, 0, sizeof(dp));
        a.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> val[i] >> num[i];
            int base = 1;
            while (num[i]) {
                if (num[i] & 1) a.push_back(base * val[i]);
                base *= 2;
                num[i] >>= 1;
            }
        }

        dp[0] = 1;
        for (int i = 0, len = a.size(); i < len; ++i) {
            for (int j = 10000; j >= a[i]; --j) {
                if (dp[j - a[i]]) dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
            }
        }

        int qq;
        while (q--) {
            cin >> qq;
            cout << dp[qq] << '\n';
        }
    }
}