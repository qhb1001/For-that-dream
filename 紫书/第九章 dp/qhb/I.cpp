#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int len, n, a[55];
int dp[55][55];
int dfs(int l, int r) {//由于切割编号就已经含有了区间长度的信息，所以无所谓
	if (dp[l][r] != INF)	return dp[l][r];
	if (l + 1 == r)	return 0;

	for (int i = l + 1; i < r; ++i) {
		dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i, r) + a[r] - a[l]);
	}

	return dp[l][r];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> len && len) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		a[n + 1] = len;
		memset(dp, INF, sizeof(dp));
		cout << "The minimum cutting is " << dfs(0, n + 1) << ".\n";
	}
}
