#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX = 210;
const ll INF = -(1LL<<50);
ll a[MAX][MAX], dp[MAX][MAX], row, col;
ll dfs(ll i, ll j) {
    if (dp[i][j] != INF)    return dp[i][j];
    if (i == 0) return 0;
    if (j == 1) dp[i][j] = max(dfs(i - 1, j), dfs(i - 1, j + 1)) + a[i][j];
    else if (j == col) dp[i][j] = max(dfs(i - 1, j), dfs(i - 1, j - 1)) + a[i][j];
    else dp[i][j] = max(max(dfs(i - 1, j), dfs(i - 1, j - 1)), dfs(i - 1, j + 1)) + a[i][j];
    return dp[i][j];
}
int main() {
    cin >> row >> col;
    if (col == 1) {
        ll ans = 0;
        for (int i = 1; i <= row; ++i)  {
            cin >> col;
            ans += col;
        }
        cout << ans << endl;
        return 0;
    }
    for (ll i = 0; i <= row + 1; ++i) for (ll j = 0; j <= col + 1; ++j)   dp[i][j] = INF;
    for (ll i = 1; i <= row; ++i) for (ll j = 1; j <= col; ++j)   cin >> a[i][j];
    
    cout << dfs(row + 1, (col >> 1) + 1) << endl;
}