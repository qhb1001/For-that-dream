#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1005;
typedef long long ll;
ll dp[MAX][10][2], a[MAX];
int n, m, k;
string f;
void init() {
    for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= m; ++j) {
        dp[i][j][0] = -(1LL<<50);
        dp[i][j][1] = 1LL<<50;
    }
}
ll work(ll x,char now,ll y){
    if(now=='+') return x+y;
    if(now=='-') return x-y;
    if(now=='*') return x*y;
    if(now=='\\') return x/y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> m >> k; init();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cin >> f;

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 0) {
                    dp[j][i][0] = min(dp[j][i][0], work(k, f[i], a[j]));
                    dp[j][i][1] = max(dp[j][i][1], work(k, f[i], a[j]));
                } else {
                    if (j != 1) {
                        dp[j][i][0] = min(dp[j][i][0], min(work(dp[j - 1][i - 1][0], f[i], a[j]), work(dp[j - 1][i - 1][1], f[i], a[j])));
                        dp[j][i][1] = max(dp[j][i][1], max(work(dp[j - 1][i - 1][0], f[i], a[j]), work(dp[j - 1][i - 1][1], f[i], a[j])));
                    }
                }
                if (j != 1) {
                    dp[j][i][0] = min(dp[j][i][0], dp[j - 1][i][0]);
                    dp[j][i][1] = max(dp[j][i][1], dp[j - 1][i][1]);
                }
            }
        }

        ll ans = -(1LL<<50);
        for (int i = 1; i <= n; ++i) ans = max(ans, dp[i][m - 1][1]);
        cout << ans << endl;
    }
}