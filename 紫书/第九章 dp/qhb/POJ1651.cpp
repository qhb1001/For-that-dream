#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[105][105];
const int INF = 0x3f3f3f3f;
struct Node {
	int row, col;
}A[105];
int dfs(int l, int r) {
	if (dp[l][r] != INF)	return dp[l][r];
	if (l == r)	return 0;
	for (int k = l; k < r; ++k) {
		dp[l][r] = min(dp[l][r], dfs(l, k) + dfs(k + 1, r) + A[l].row * A[k].col * A[r].col);
	}
	return dp[l][r];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		int a[105];
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i < n; ++i) A[i].row = a[i], A[i].col = a[i + 1];
		cout << dfs(1, n - 1) << '\n';
	}
}
