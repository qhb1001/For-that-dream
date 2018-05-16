#include <iostream>
#include <string>
using namespace std;
const int MAX = 5005;
int dp[MAX][MAX], f[MAX][MAX], a[MAX];
bool vis[MAX][MAX];
int deal(int l, int r) {
	if (vis[l][r])	return dp[l][r];

	vis[l][r] = 1;
	if (l == r) return dp[l][l] = f[l][l] = a[l];

	if (vis[l + 1][r] == 0)	deal(l + 1, r);
	if (vis[l][r - 1] == 0)	deal(l, r - 1);

	dp[l][r] = f[l][r] =  f[l][r - 1] ^ f[l + 1][r];
	dp[l][r] = max(dp[l][r], dp[l + 1][r]);
	dp[l][r] = max(dp[l][r], dp[l][r - 1]);
	return dp[l][r];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	int k, l, r;
	cin >> k;
	while (k--) {
		cin >> l >> r;
		cout << deal(l, r) << '\n';
	}
	return 0;
}
